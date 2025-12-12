#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_Axi_9_14_()
{
double ret;
ret = (lv*Cos(theta3(t))*Cos(phiR3(t) + theta3(t)))/2. + (lv*Sin(theta3(t))*Sin(phiR3(t) + theta3(t)))/2.;
return ret;
}
