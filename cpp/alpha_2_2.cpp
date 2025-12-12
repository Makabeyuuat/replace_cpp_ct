#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_alpha_2_2_()
{
double ret;
ret = (1 - c(s(t))*d(t))*Power(Sec(thetap0(t)),2);
return ret;
}
