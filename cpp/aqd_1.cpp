#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_aqd_1_()
{
double ret;
ret = Cos(thetap0(t) + thetat(t))*nu1(t) - Sin(thetap0(t) + thetat(t))*uact1(t)*(uact2(t) + c(s(t))*Derivative(1)(s)(t));
return ret;
}
