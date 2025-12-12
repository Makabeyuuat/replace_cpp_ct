#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha3_pd_X_1_2_()
{
double ret;
ret = -((Power(c(s(t)),2)*Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t))*Sec(thetap0(t)))/l1) - (2*c(s(t))*Cos(phi1(t) - thetap0(t) + thetap1(t))*(1 - c(s(t))*d(t))*Sec(phi1(t))*Power(Sec(thetap0(t)),2)*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1))/l1 - c(s(t))*(-(Power(c(s(t)),2)/(1 - c(s(t))*d(t))) - c(s(t))*Sec(thetap0(t))*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1))*Tan(thetap0(t)) - c(s(t))*(-(c(s(t))*Sec(thetap0(t))*(-((Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)))/l1) + (c(s(t))*Sin(thetap0(t)))/(1 - c(s(t))*d(t)))) - c(s(t))*Sec(thetap0(t))*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1)*Tan(thetap0(t))) + (Power(c(s(t)),2)*d(t)*Derivative(1)(c)(s(t)))/Power(1 - c(s(t))*d(t),2) - Sec(thetap0(t))*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1)*Derivative(1)(c)(s(t)) + (1 - c(s(t))*d(t))*Sec(thetap0(t))*((-2*Power(c(s(t)),2)*Cos(thetap0(t))*d(t)*Derivative(1)(c)(s(t)))/Power(1 - c(s(t))*d(t),3) - (2*c(s(t))*Cos(thetap0(t))*Derivative(1)(c)(s(t)))/Power(1 - c(s(t))*d(t),2)) - c(s(t))*Sec(thetap0(t))*(-((c(s(t))*Cos(thetap0(t))*d(t)*Derivative(1)(c)(s(t)))/Power(1 - c(s(t))*d(t),2)) - (Cos(thetap0(t))*Derivative(1)(c)(s(t)))/(1 - c(s(t))*d(t)));
return ret;
}
