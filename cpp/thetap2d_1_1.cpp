#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_thetap2d_1_1_()
{
double ret;
ret = (-3*Pi)/2. + ArcTan(4*Sqrt(1 - Power(lv + 2*l3*Cos(thetap3(t) - thetap4d(t)),2)/(16.*Power(l2,2))),(lv + 2*l3*Cos(thetap3(t) - thetap4d(t)))/l2) + thetap4d(t);
return ret;
}
