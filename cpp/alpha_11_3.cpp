#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_alpha_11_3_()
{
double ret;
ret = ((1 - c(s(t))*d(t))*Sec(phi9(t))*Sec(thetap0(t))*(-(Cos(phi8(t) - phi9(t) + thetap8(t) - thetap9(t))*(-2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Cos(phi8(t) - thetap0(t) + thetap8(t))*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t)) - 2*Cos(phi8(t) - thetap0(t) + thetap8(t))*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)) - Sin(phi8(t) - thetap0(t) + thetap8(t))*(2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)) + 2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))))) + Sin(phi8(t) - phi9(t) + thetap8(t) - thetap9(t))*(-2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t))*Sin(phi8(t) - thetap0(t) + thetap8(t)) - 2*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Sin(phi8(t) - thetap0(t) + thetap8(t))*Tan(phi1(t)) + Cos(phi8(t) - thetap0(t) + thetap8(t))*(2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)) + 2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))) - 2*(-2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Cos(phi8(t) - thetap0(t) + thetap8(t))*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t)) - 2*Cos(phi8(t) - thetap0(t) + thetap8(t))*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)) - Sin(phi8(t) - thetap0(t) + thetap8(t))*(2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)) + 2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))))*Tan(phi8(t)))))/l3;
return ret;
}
