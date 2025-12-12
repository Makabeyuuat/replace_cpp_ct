#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_Z10_pd_X_1_1_()
{
double ret;
ret = -(d(t)*Sec(thetap0(t))*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi8(t))*(-2*Cos(phi8(t) - thetap0(t) + thetap8(t))*Sec(phi1(t))*Sin(Pi/6. + thetap0(t) - thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) - (1 + 2*Cos(Pi/6. + thetap0(t) - thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))*Sin(phi8(t) - thetap0(t) + thetap8(t))))/l2)*Derivative(1)(c)(s(t))) + (1 - c(s(t))*d(t))*Sec(thetap0(t))*(-((c(s(t))*Cos(thetap0(t))*d(t)*Derivative(1)(c)(s(t)))/Power(1 - c(s(t))*d(t),2)) - (Cos(thetap0(t))*Derivative(1)(c)(s(t)))/(1 - c(s(t))*d(t)));
return ret;
}
