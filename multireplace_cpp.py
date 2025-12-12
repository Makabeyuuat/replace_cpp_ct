#!/usr/bin/env python3
import argparse
import csv
import re
from pathlib import Path
from time import perf_counter

###############################################################################
# Mapping loader
###############################################################################

def load_mapping(map_path):
    """
    Load replacements from a text file.
    Each non-empty, non-comment line should be: BEFORE / AFTER
    - Lines starting with # or // are ignored
    - '  #' or '  //' (two or more spaces then # or //) marks an inline comment
    """
    mapping = []
    with open(map_path, "r", encoding="utf-8") as f:
        for ln, line in enumerate(f, 1):
            raw = line.rstrip("\n")

            # 全部空か、先頭が # // の行は無視
            stripped = raw.strip()
            if not stripped or stripped.startswith("#") or stripped.startswith("//"):
                continue

            # 行末コメントを探す（"  #", "  //"）
            m_cmt = re.search(r"\s{2,}(#|//)", raw)
            if m_cmt:
                # コメントより左だけを残す（ただしこの時点では末尾スペースはまだ落とさない）
                raw = raw[:m_cmt.start()]

            # ここで「before / after」を分ける
            m = re.match(r"^(.*?)/(.*)$", raw)
            if not m:
                raise ValueError(f"Invalid mapping on line {ln}: expected 'before / after', got: {line!r}")

            left_part = m.group(1)  # "/" の左側（末尾スペースを残したい）
            right_part = m.group(2) # "/" の右側

            # 左側: 末尾の空白は「/ の前にある空白」なので落とす
            # でも「. 」みたいなパターンは user が狙ってるので、基本は rstrip() でOK
            before = left_part.rstrip()

            # 右側: 先頭の空白だけを削る（末尾は残す）
            after = right_part.lstrip()

            # 空ならエラー
            if not before:
                raise ValueError(f"Empty 'before' token on line {ln}")

            mapping.append((before, after))
    return mapping

###############################################################################
# Patterns
###############################################################################

IDENT_RE = re.compile(r"[A-Za-z_][A-Za-z0-9_]*$")

def build_pattern(before, case_insensitive=False):
    """
    If 'before' is a C/C++ identifier, require identifier boundaries.
    Else, literal substring.
    ※ ". " みたいなものもそのままリテラルでマッチする
    """
    is_ident = bool(IDENT_RE.match(before))
    flags = re.IGNORECASE if case_insensitive else 0
    if is_ident:
        patt = rf"(?<![A-Za-z0-9_]){re.escape(before)}(?![A-Za-z0-9_])"
    else:
        patt = re.escape(before)
    return re.compile(patt, flags)

###############################################################################
# C/C++ light tokenizer to skip comments & strings
###############################################################################

def split_cpp_code_regions(text):
    """Split C/C++ source into segments (text, is_code)."""
    NORMAL, SL_COMMENT, ML_COMMENT, STRING, CHAR, RAW_STRING = range(6)
    i = 0
    n = len(text)
    state = NORMAL
    buf = []
    segments = []
    string_quote = ""
    raw_delim = ""
    raw_end = ""

    def flush(is_code):
        if buf:
            segments.append(("".join(buf), is_code))
            buf.clear()

    while i < n:
        ch = text[i]
        if state == NORMAL:
            if ch == '/' and i+1 < n:
                nxt = text[i+1]
                if nxt == '/':
                    flush(True); state = SL_COMMENT; buf.append(ch); buf.append(nxt); i += 2; continue
                elif nxt == '*':
                    flush(True); state = ML_COMMENT; buf.append(ch); buf.append(nxt); i += 2; continue
            if ch == '"':
                if i > 0 and text[i-1] == 'R':
                    flush(True); i -= 1; buf.append(text[i]); buf.append(text[i+1]); i += 2
                    delim = []
                    while i < n and text[i] != '(':
                        delim.append(text[i]); buf.append(text[i]); i += 1
                    if i < n and text[i] == '(':
                        buf.append('('); i += 1
                        raw_delim = "".join(delim)
                        raw_end = ')' + raw_delim + '"'
                        state = RAW_STRING; continue
                    else:
                        state = STRING; string_quote = '"'; continue
                else:
                    flush(True); state = STRING; string_quote = '"'; buf.append(ch); i += 1; continue
            if ch == "'":
                flush(True); state = CHAR; string_quote = "'"; buf.append(ch); i += 1; continue
            buf.append(ch); i += 1; continue
        elif state == SL_COMMENT:
            buf.append(ch); i += 1
            if ch == '\n': flush(False); state = NORMAL
            continue
        elif state == ML_COMMENT:
            buf.append(ch); i += 1
            if ch == '*' and i < n and text[i] == '/':
                buf.append('/'); i += 1; flush(False); state = NORMAL
            continue
        elif state == STRING:
            buf.append(ch); i += 1
            if ch == '\\' and i < n: buf.append(text[i]); i += 1
            elif ch == string_quote: flush(False); state = NORMAL
            continue
        elif state == CHAR:
            buf.append(ch); i += 1
            if ch == '\\' and i < n: buf.append(text[i]); i += 1
            elif ch == string_quote: flush(False); state = NORMAL
            continue
        elif state == RAW_STRING:
            if raw_end and text.startswith(raw_end, i):
                buf.append(raw_end); i += len(raw_end); flush(False); state = NORMAL; raw_delim = raw_end = ""
            else:
                buf.append(ch); i += 1
            continue
    if buf: flush(state == NORMAL)
    return segments

###############################################################################
# Function extraction (for header prototypes)
###############################################################################

STRIP_LEADING_QUALS_RE = re.compile(r'^(?:\s*\b(?:inline|constexpr|static|virtual|friend)\b\s*)+', re.IGNORECASE)
FUNC_DEF_RE = re.compile(
    r'''(?mx)
    ^
    (?:\s*\b(?:inline|constexpr|static|virtual|friend)\b\s+)*
    (?P<ret>[~\w:\<\>\[\]\*&\s]+?)
    \s+
    (?:(?P<scope>(?:[\w:]+)::))?
    (?P<name>[A-Za-z_]\w*)
    \s*
    \(
        (?P<params>[^()]*)                  # simplified: no nested parens
    \)
    \s*
    (?:const\b\s*)?
    (?:noexcept\b\s*)?
    (?:->\s*[\w:\<\>\[\]\*&\s]+)?
    \s*
    \{
    '''
)

def extract_function_prototypes_from_text(text):
    """Return a list of (return_type, name, params) from function definitions."""
    prototypes = []
    for seg, is_code in split_cpp_code_regions(text):
        if not is_code:
            continue
        for m in FUNC_DEF_RE.finditer(seg):
            ret = m.group('ret') or ''
            name = m.group('name') or ''
            params = (m.group('params') or '').strip()
            ret = STRIP_LEADING_QUALS_RE.sub('', ret).strip()
            ret = ' '.join(ret.split())
            if not ret:
                continue
            prototypes.append((ret, name, params))
    return prototypes

###############################################################################
# Replacement engine
###############################################################################

def process_file(src_path, dst_path, rules, skip_comments_strings=True):
    text = src_path.read_text(encoding="utf-8")
    total_changes = 0
    per_rule_counts = [(before, after, 0) for (before, after, _) in rules]

    if skip_comments_strings:
        segments = split_cpp_code_regions(text)
        out_parts = []
        for seg, is_code in segments:
            if is_code:
                seg_out = seg
                for idx, (before, after, patt) in enumerate(rules):
                    seg_out, n = patt.subn(after, seg_out)
                    if n:
                        b, a, cnt = per_rule_counts[idx]
                        per_rule_counts[idx] = (b, a, cnt + n)
                        total_changes += n
                out_parts.append(seg_out)
            else:
                out_parts.append(seg)
        out = "".join(out_parts)
    else:
        out = text
        for idx, (before, after, patt) in enumerate(rules):
            out, n = patt.subn(after, out)
            if n:
                b, a, cnt = per_rule_counts[idx]
                per_rule_counts[idx] = (b, a, cnt + n)
                total_changes += n

    dst_path.parent.mkdir(parents=True, exist_ok=True)
    dst_path.write_text(out, encoding="utf-8")
    return total_changes, per_rule_counts

###############################################################################
# Main
###############################################################################

def main():
    ap = argparse.ArgumentParser(description="Batch replace variables in .cpp files under a source folder and write results to a destination folder.")
    ap.add_argument("--map", "-m", default="replacements.txt", help="Mapping file: each line 'before / after' (default: replacements.txt)")
    ap.add_argument("--src", "-s", default="cpp", help="Source folder containing .cpp files (default: cpp)")
    ap.add_argument("--dst", "-d", default="after", help="Destination folder for replaced files (default: after)")
    ap.add_argument("--case-insensitive", action="store_true", help="Case-insensitive matching")
    ap.add_argument("--report", "-r", default="replacement_report.csv", help="CSV report path (default: replacement_report.csv)")
    ap.add_argument("--no-report", action="store_true", help="Do not generate a CSV report")
    ap.add_argument("--report-all", action="store_true", help="Report zero-hit rules as well (default: only non-zero)")
    ap.add_argument("--progress-every", type=int, default=100, help="Print progress every N files (default: 100)")
    ap.add_argument("--replace-in-comments-strings", action="store_true",
                    help="If set, also replace inside comments and string/char/raw literals (default: skip them)." )
    ap.add_argument("--no-emit-funcs", action="store_true", help="Do not emit func.txt with extracted function prototypes")
    args = ap.parse_args()

    src = Path(args.src)
    dst = Path(args.dst)

    if not src.exists() or not src.is_dir():
        raise SystemExit(f"Source folder not found: {src}")

    mapping = load_mapping(args.map)
    if not mapping:
        raise SystemExit("No mappings loaded. Check your mapping file.")

    rules = [(before, after, build_pattern(before, args.case_insensitive)) for (before, after) in mapping]

    files = [p for p in src.rglob("*.cpp") if p.is_file()]
    if not files:
        print("No .cpp files found under", src)
        return

    start = perf_counter()
    total_files = 0
    total_repl = 0
    all_protos = []

    print(f"Found {len(files)} .cpp files under {src}. Starting replacement...")

    writer = None
    f_report = None
    if not args.no_report:
        f_report = open(args.report, "w", newline="", encoding="utf-8")
        writer = csv.writer(f_report)
        writer.writerow(("file", "rule_before", "rule_after", "count"))

    try:
        for idx_file, pth in enumerate(files, 1):
            rel = pth.relative_to(src)
            outp = dst / rel
            changed, per_rules = process_file(
                pth, outp, rules,
                skip_comments_strings=(not args.replace_in_comments_strings)
            )
            total_files += 1
            total_repl += changed

            # Extract prototypes from original source
            try:
                src_text = pth.read_text(encoding='utf-8')
                protos = extract_function_prototypes_from_text(src_text)
                if protos:
                    all_protos.extend([(str(rel),)+pr for pr in protos])
            except Exception:
                pass

            if writer:
                if args.report_all:
                    for (before, after, n) in per_rules:
                        writer.writerow((str(rel), before, after, str(n)))
                else:
                    for (before, after, n) in per_rules:
                        if n:
                            writer.writerow((str(rel), before, after, str(n)))

            if args.progress_every > 0 and idx_file % args.progress_every == 0:
                elapsed = perf_counter() - start
                print(f"Processed {idx_file}/{len(files)} files... (elapsed {elapsed:.1f}s)")

        # Emit func.txt unless disabled
        if not args.no_emit_funcs:
            seen = set()
            lines = []
            for (rel, ret, name, params) in all_protos:
                proto = f"{ret} {name}({params})".strip()
                proto = ' '.join(proto.split())
                if not proto.endswith(';'):
                    proto += ';'
                if proto not in seen:
                    seen.add(proto)
                    lines.append(proto)
            func_path = Path.cwd() / 'func.txt'
            func_path.write_text('\n'.join(lines) + ('\n' if lines else ''), encoding='utf-8')
            print(f"Function prototypes written to: {func_path}")

        elapsed_total = perf_counter() - start
        print(f"Processed {total_files} files. Total replacements applied: {total_repl}. (elapsed {elapsed_total:.1f}s)")
        print(f"Output written to: {dst.resolve()}")
        if writer:
            print(f"Report saved to: {Path(args.report).resolve()}")

    finally:
        if f_report:
            f_report.close()

if __name__ == "__main__":
    main()
