#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_dNHother_2_()
{
double ret;
ret = -(lv*Cos(theta1(t))*Cos(phiR1(t) + theta1(t))*Power(Derivative(1)(theta1)(t),2))/2. - (lv*Sin(theta1(t))*Sin(phiR1(t) + theta1(t))*Power(Derivative(1)(theta1)(t),2))/2. + Sin(phiR1(t) + theta1(t))*(Derivative(1)(phiR1)(t) + Derivative(1)(theta1)(t))*((lv*Sin(theta1(t))*Derivative(1)(theta1)(t))/2. + Derivative(1)(x1)(t)) - Cos(phiR1(t) + theta1(t))*(Derivative(1)(phiR1)(t) + Derivative(1)(theta1)(t))*(-(lv*Cos(theta1(t))*Derivative(1)(theta1)(t))/2. + Derivative(1)(y1)(t));
return ret;
}
