#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha7_pd_X_3_4_()
{
double ret;
ret = ((1 - c(s(t))*d(t))*Sec(phi5(t))*Sec(thetap0(t))*(2*Cos(phi5(t) - thetap0(t) + thetap5(t))*Sec(phi1(t))*Sin(Pi/6. - thetap0(t) + thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) - 2*Cos(phi5(t) - thetap0(t) + thetap5(t))*Power(Sec(phi1(t)),3)*Sin(Pi/6. - thetap0(t) + thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) - 4*Cos(phi1(t) - thetap0(t) + thetap1(t))*Cos(phi5(t) - thetap0(t) + thetap5(t))*Sec(phi1(t))*Sin(Pi/6. - thetap0(t) + thetap1(t))*Tan(phi1(t)) - 2*Cos(phi5(t) - thetap0(t) + thetap5(t))*Sec(phi1(t))*Sin(Pi/6. - thetap0(t) + thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Power(Tan(phi1(t)),2) - Sin(phi5(t) - thetap0(t) + thetap5(t))*(2*Cos(Pi/6. - thetap0(t) + thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) - 2*Cos(Pi/6. - thetap0(t) + thetap1(t))*Power(Sec(phi1(t)),3)*Sin(phi1(t) - thetap0(t) + thetap1(t)) - 4*Cos(Pi/6. - thetap0(t) + thetap1(t))*Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t))*Tan(phi1(t)) - 2*Cos(Pi/6. - thetap0(t) + thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Power(Tan(phi1(t)),2))))/l2;
return ret;
}
