#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_thetap8d_1_1_()
{
double ret;
ret = (5*Pi)/6. + ArcTan(4*Sqrt(1 - Power(lv + 2*l3*Sin(Pi/6. - thetap9(t) + uthetap10d(t)),2)/(16.*Power(l2,2))),(lv + 2*l3*Sin(Pi/6. - thetap9(t) + uthetap10d(t)))/l2) + uthetap10d(t);
return ret;
}
