#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha3_pd_X_2_3_()
{
double ret;
ret = (1 - c(s(t))*d(t))*Sec(thetap0(t))*((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t)) - (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1) + (1 - c(s(t))*d(t))*Power(Sec(thetap0(t)),3)*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1) + 2*(1 - c(s(t))*d(t))*Sec(thetap0(t))*(-((Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)))/l1) + (c(s(t))*Sin(thetap0(t)))/(1 - c(s(t))*d(t)))*Tan(thetap0(t)) + (1 - c(s(t))*d(t))*Sec(thetap0(t))*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1)*Power(Tan(thetap0(t)),2);
return ret;
}
