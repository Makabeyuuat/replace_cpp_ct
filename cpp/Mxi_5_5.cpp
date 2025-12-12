#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_Mxi_5_5_()
{
double ret;
ret = Pattern(m,Blank(b)) + 2*Pattern(m,Blank(w));
return ret;
}
