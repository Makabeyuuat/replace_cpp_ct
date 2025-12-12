#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha2_pd_X_1_2_()
{
double ret;
ret = Power(c(s(t)),2)*Power(Sec(thetap0(t)),2) + Power(c(s(t)),2)*Power(Tan(thetap0(t)),2) - Tan(thetap0(t))*Derivative(1)(c)(s(t));
return ret;
}
