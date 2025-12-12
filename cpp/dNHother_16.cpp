#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_dNHother_16_()
{
double ret;
ret = -2*l1*Cos(Pi/6. + theta0(t))*Power(Derivative(1)(theta0)(t),2) + 2*Sin(theta2(t))*Derivative(1)(s2)(t)*Derivative(1)(theta2)(t) + Cos(theta2(t))*s2(t)*Power(Derivative(1)(theta2)(t),2);
return ret;
}
