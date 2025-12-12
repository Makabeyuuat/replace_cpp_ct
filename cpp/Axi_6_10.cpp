#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_Axi_6_10_()
{
double ret;
ret = -(lv*Cos(phiR2(t) + theta2(t))*Sin(theta2(t)))/2. + (lv*Cos(theta2(t))*Sin(phiR2(t) + theta2(t)))/2.;
return ret;
}
