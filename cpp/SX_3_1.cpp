#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_SX_3_1_()
{
double ret;
ret = -((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t)));
return ret;
}
