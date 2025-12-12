#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_dNHother_6_()
{
double ret;
ret = -(lv*Cos(theta2(t))*Cos(phiR2(t) + theta2(t))*Power(Derivative(1)(theta2)(t),2))/2. - (lv*Sin(theta2(t))*Sin(phiR2(t) + theta2(t))*Power(Derivative(1)(theta2)(t),2))/2. + Sin(phiR2(t) + theta2(t))*(Derivative(1)(phiR2)(t) + Derivative(1)(theta2)(t))*((lv*Sin(theta2(t))*Derivative(1)(theta2)(t))/2. + Derivative(1)(x2)(t)) - Cos(phiR2(t) + theta2(t))*(Derivative(1)(phiR2)(t) + Derivative(1)(theta2)(t))*(-(lv*Cos(theta2(t))*Derivative(1)(theta2)(t))/2. + Derivative(1)(y2)(t));
return ret;
}
