#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_Axi_11_14_()
{
double ret;
ret = -(lv*Cos(theta3(t))*Cos(phiF3(t) + theta3(t)))/2. - (lv*Sin(theta3(t))*Sin(phiF3(t) + theta3(t)))/2.;
return ret;
}
