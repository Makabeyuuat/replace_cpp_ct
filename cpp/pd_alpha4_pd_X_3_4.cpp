#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha4_pd_X_3_4_()
{
double ret;
ret = ((1 - c(s(t))*d(t))*Sec(phi2(t))*Sec(thetap0(t))*(2*Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) + 2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t)) - 2*Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(-Sin(phi1(t) - thetap0(t) + thetap1(t)) + 2*Power(Sec(phi1(t)),2)*Sin(phi1(t) - thetap0(t) + thetap1(t)) + 2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))) + Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t)) + 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))) - Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(-Cos(phi1(t) - thetap0(t) + thetap1(t)) + 4*Cos(phi1(t) - thetap0(t) + thetap1(t))*Power(Sec(phi1(t)),2) - 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)) + 4*Power(Sec(phi1(t)),2)*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))))/l2;
return ret;
}
