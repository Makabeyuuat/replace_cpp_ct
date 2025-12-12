#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha2_pd_X_1_1_()
{
double ret;
ret = c(s(t))*d(t)*Power(Sec(thetap0(t)),2)*Derivative(1)(c)(s(t)) - (1 - c(s(t))*d(t))*Power(Sec(thetap0(t)),2)*Derivative(1)(c)(s(t)) + c(s(t))*d(t)*Power(Tan(thetap0(t)),2)*Derivative(1)(c)(s(t)) - (1 - c(s(t))*d(t))*Power(Tan(thetap0(t)),2)*Derivative(1)(c)(s(t)) - d(t)*Tan(thetap0(t))*Derivative(2)(c)(s(t));
return ret;
}
