#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_g11_pd_X_1_()
{
double ret;
ret = (Cos(thetap0(t))*d(t)*Derivative(1)(c)(s(t)))/Power(1 - c(s(t))*d(t),2);
return ret;
}
