#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_dNHother_17_()
{
double ret;
ret = 2*l1*Sin(Pi/6. - theta0(t))*Power(Derivative(1)(theta0)(t),2) + 2*Cos(theta3(t))*Derivative(1)(s3)(t)*Derivative(1)(theta3)(t) - s3(t)*Sin(theta3(t))*Power(Derivative(1)(theta3)(t),2);
return ret;
}
