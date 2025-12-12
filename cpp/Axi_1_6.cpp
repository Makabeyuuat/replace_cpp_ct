#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_Axi_1_6_()
{
double ret;
ret = (lv*Cos(theta1(t))*Cos(phiR1(t) + theta1(t)))/2. + (lv*Sin(theta1(t))*Sin(phiR1(t) + theta1(t)))/2.;
return ret;
}
