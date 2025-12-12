#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_d_SX_d_t_2_1_()
{
double ret;
ret = Cos(thetap0(t))*(-((c(s(t))*Cos(thetap0(t))*uact1(t))/(1 - c(s(t))*d(t))) + uact2(t));
return ret;
}
