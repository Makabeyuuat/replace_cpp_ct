#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_alpha_2_1_()
{
double ret;
ret = -(c(s(t))*(1 - c(s(t))*d(t))*Power(Sec(thetap0(t)),2)) - c(s(t))*(1 - c(s(t))*d(t))*Power(Tan(thetap0(t)),2) - d(t)*Tan(thetap0(t))*Derivative(1)(c)(s(t));
return ret;
}
