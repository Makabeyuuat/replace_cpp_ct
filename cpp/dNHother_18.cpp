#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_dNHother_18_()
{
double ret;
ret = 2*l1*Cos(Pi/6. - theta0(t))*Power(Derivative(1)(theta0)(t),2) + 2*Sin(theta3(t))*Derivative(1)(s3)(t)*Derivative(1)(theta3)(t) + Cos(theta3(t))*s3(t)*Power(Derivative(1)(theta3)(t),2);
return ret;
}
