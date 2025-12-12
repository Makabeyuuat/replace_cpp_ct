#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha4_pd_X_2_3_()
{
double ret;
ret = (1 - c(s(t))*d(t))*Sec(thetap0(t))*((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t)) + (Sec(phi2(t))*(Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) - Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(-Cos(phi1(t) - thetap0(t) + thetap1(t)) - 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))))/l2) + (1 - c(s(t))*d(t))*Power(Sec(thetap0(t)),3)*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi2(t))*(-(Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))) - Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t)) + 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))))/l2) + 2*(1 - c(s(t))*d(t))*Sec(thetap0(t))*((c(s(t))*Sin(thetap0(t)))/(1 - c(s(t))*d(t)) + (Sec(phi2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t))*Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t)) - Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Sin(phi1(t) - thetap0(t) + thetap1(t)) - 2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))))/l2)*Tan(thetap0(t)) + (1 - c(s(t))*d(t))*Sec(thetap0(t))*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi2(t))*(-(Cos(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))) - Sin(phi1(t) - phi2(t) + thetap1(t) - thetap2(t))*(Cos(phi1(t) - thetap0(t) + thetap1(t)) + 2*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))))/l2)*Power(Tan(thetap0(t)),2);
return ret;
}
