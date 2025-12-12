#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_Axi_10_14_()
{
double ret;
ret = -(lv*Cos(phiR3(t) + theta3(t))*Sin(theta3(t)))/2. + (lv*Cos(theta3(t))*Sin(phiR3(t) + theta3(t)))/2.;
return ret;
}
