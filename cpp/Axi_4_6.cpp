#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_Axi_4_6_()
{
double ret;
ret = (lv*Cos(phiF1(t) + theta1(t))*Sin(theta1(t)))/2. - (lv*Cos(theta1(t))*Sin(phiF1(t) + theta1(t)))/2.;
return ret;
}
