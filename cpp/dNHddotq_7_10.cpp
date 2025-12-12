#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_dNHddotq_7_10_()
{
double ret;
ret = -(lv*Cos(theta2(t))*Cos(phiF2(t) + theta2(t)))/2. - (lv*Sin(theta2(t))*Sin(phiF2(t) + theta2(t)))/2.;
return ret;
}
