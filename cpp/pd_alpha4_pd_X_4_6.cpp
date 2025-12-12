#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha4_pd_X_4_6_()
{
double ret;
ret = (1 - c(s(t))*d(t))*Sec(thetap0(t))*((Power(Sec(phi2(t)),3)*(-(Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))) - Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t)) + 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))))/l2 + (Sec(phi2(t))*(Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) + Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t)) + 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))))/l2 + (2*Sec(phi2(t))*(-(Sin(phi1(t) - thetap0(t) + thetap1(t))*Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))) + Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t)) + 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))))*Tan(phi2(t)))/l2 + (Sec(phi2(t))*(-(Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))) - Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t)) + 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))))*Power(Tan(phi2(t)),2))/l2);
return ret;
}
