#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_aqd_3_()
{
double ret;
ret = asd*c(s(t)) + nu2(t) + Derivative(1)(c)(s(t))*Power(Derivative(1)(s)(t),2);
return ret;
}
