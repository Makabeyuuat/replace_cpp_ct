#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha2_pd_X_1_3_()
{
double ret;
ret = -4*c(s(t))*(1 - c(s(t))*d(t))*Power(Sec(thetap0(t)),2)*Tan(thetap0(t)) - d(t)*Power(Sec(thetap0(t)),2)*Derivative(1)(c)(s(t));
return ret;
}
