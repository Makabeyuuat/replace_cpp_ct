#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_aqd_10_()
{
double ret;
ret = athetap7d + asd*c(s(t)) + Derivative(1)(c)(s(t))*Power(Derivative(1)(s)(t),2);
return ret;
}
