#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_Axi_2_6_()
{
double ret;
ret = -(lv*Cos(phiR1(t) + theta1(t))*Sin(theta1(t)))/2. + (lv*Cos(theta1(t))*Sin(phiR1(t) + theta1(t)))/2.;
return ret;
}
