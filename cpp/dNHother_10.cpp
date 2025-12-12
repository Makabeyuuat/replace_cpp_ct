#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_dNHother_10_()
{
double ret;
ret = -(lv*Cos(theta3(t))*Cos(phiR3(t) + theta3(t))*Power(Derivative(1)(theta3)(t),2))/2. - (lv*Sin(theta3(t))*Sin(phiR3(t) + theta3(t))*Power(Derivative(1)(theta3)(t),2))/2. + Sin(phiR3(t) + theta3(t))*(Derivative(1)(phiR3)(t) + Derivative(1)(theta3)(t))*((lv*Sin(theta3(t))*Derivative(1)(theta3)(t))/2. + Derivative(1)(x3)(t)) - Cos(phiR3(t) + theta3(t))*(Derivative(1)(phiR3)(t) + Derivative(1)(theta3)(t))*(-(lv*Cos(theta3(t))*Derivative(1)(theta3)(t))/2. + Derivative(1)(y3)(t));
return ret;
}
