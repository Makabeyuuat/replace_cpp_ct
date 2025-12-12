#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_dNHother_14_()
{
double ret;
ret = -2*l1*Sin(theta0(t))*Power(Derivative(1)(theta0)(t),2) + 2*Sin(theta1(t))*Derivative(1)(s1)(t)*Derivative(1)(theta1)(t) + Cos(theta1(t))*s1(t)*Power(Derivative(1)(theta1)(t),2);
return ret;
}
