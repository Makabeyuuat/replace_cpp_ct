#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha5_pd_X_2_9_()
{
double ret;
ret = ((1 - c(s(t))*d(t))*Sec(phi3(t))*Sec(thetap0(t))*(Sin(phi2(t) - phi3(t) + thetap2(t) - thetap3(t))*(-(Cos(phi1(t) - thetap0(t) + thetap1(t))*Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))) + Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Sin(phi1(t) - thetap0(t) + thetap1(t)) - 2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))) + Cos(phi2(t) - phi3(t) + thetap2(t) - thetap3(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t))*Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t)) + Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Sin(phi1(t) - thetap0(t) + thetap1(t)) - 2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))) - 2*(-(Cos(phi1(t) - thetap0(t) + thetap1(t))*Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))) + Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Sin(phi1(t) - thetap0(t) + thetap1(t)) - 2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))))*Tan(phi2(t)))))/l3 + ((1 - c(s(t))*d(t))*Sec(phi3(t))*Sec(thetap0(t))*(Sin(phi2(t) - phi3(t) + thetap2(t) - thetap3(t))*(Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) + Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t)) + 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))) + Cos(phi2(t) - phi3(t) + thetap2(t) - thetap3(t))*(-(Sin(phi1(t) - thetap0(t) + thetap1(t))*Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))) + Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t)) + 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))) - 2*(Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) + Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t)) + 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))))*Tan(phi2(t))))*Tan(thetap0(t)))/l3;
return ret;
}
