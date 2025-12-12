#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_Z3_pd_X_1_5_()
{
double ret;
ret = (Cos(phi1(t) - thetap0(t) + thetap1(t))*(1 - c(s(t))*d(t))*Sec(phi1(t))*Sec(thetap0(t)))/l1;
return ret;
}
