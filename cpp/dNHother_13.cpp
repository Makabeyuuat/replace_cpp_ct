#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_dNHother_13_()
{
double ret;
ret = -2*l1*Cos(theta0(t))*Power(Derivative(1)(theta0)(t),2) + 2*Cos(theta1(t))*Derivative(1)(s1)(t)*Derivative(1)(theta1)(t) - s1(t)*Sin(theta1(t))*Power(Derivative(1)(theta1)(t),2);
return ret;
}
