#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha3_pd_X_1_4_()
{
double ret;
ret = -((Power(1 - c(s(t))*d(t),2)*Sec(phi1(t))*Power(Sec(thetap0(t)),2)*Sin(phi1(t) - thetap0(t) + thetap1(t))*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1))/l1) + (Cos(phi1(t) - thetap0(t) + thetap1(t))*Power(1 - c(s(t))*d(t),2)*Sec(phi1(t))*Power(Sec(thetap0(t)),2)*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1)*Tan(phi1(t)))/l1 + (Cos(phi1(t) - thetap0(t) + thetap1(t))*Power(1 - c(s(t))*d(t),2)*Sec(phi1(t))*Power(Sec(thetap0(t)),2)*((Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)))/l1 + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))/l1))/l1 - c(s(t))*(1 - c(s(t))*d(t))*Sec(thetap0(t))*((Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)))/l1 + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))/l1)*Tan(thetap0(t)) - c(s(t))*((1 - c(s(t))*d(t))*Sec(thetap0(t))*((Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1 - (Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t))*Tan(phi1(t)))/l1) + (1 - c(s(t))*d(t))*Sec(thetap0(t))*((Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)))/l1 + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))/l1)*Tan(thetap0(t))) - d(t)*Sec(thetap0(t))*((Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)))/l1 + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))/l1)*Derivative(1)(c)(s(t));
return ret;
}
