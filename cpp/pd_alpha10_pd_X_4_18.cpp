#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha10_pd_X_4_18_()
{
double ret;
ret = (1 - c(s(t))*d(t))*Sec(thetap0(t))*((Power(Sec(phi8(t)),3)*(-2*Cos(phi8(t) - thetap0(t) + thetap8(t))*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) - (1 + 2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))*Sin(phi8(t) - thetap0(t) + thetap8(t))))/l2 + (Sec(phi8(t))*(2*Cos(phi8(t) - thetap0(t) + thetap8(t))*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) + (1 + 2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))*Sin(phi8(t) - thetap0(t) + thetap8(t))))/l2 + (2*Sec(phi8(t))*(-(Cos(phi8(t) - thetap0(t) + thetap8(t))*(1 + 2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))) + 2*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Sin(phi8(t) - thetap0(t) + thetap8(t)))*Tan(phi8(t)))/l2 + (Sec(phi8(t))*(-2*Cos(phi8(t) - thetap0(t) + thetap8(t))*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) - (1 + 2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))*Sin(phi8(t) - thetap0(t) + thetap8(t)))*Power(Tan(phi8(t)),2))/l2);
return ret;
}
