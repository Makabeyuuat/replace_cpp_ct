#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_d_SX_d_t_3_1_()
{
double ret;
ret = (c(s(t))*(u2 - (u1*c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t)))*Sin(thetap0(t)))/(1 - c(s(t))*d(t)) - (Power(Cos(thetap0(t)),2)*uact1(t)*Derivative(1)(c)(s(t)))/Power(1 - c(s(t))*d(t),2) + (c(s(t))*Cos(thetap0(t))*(-(c(s(t))*Sin(thetap0(t))*uact1(t)) - (Cos(thetap0(t))*d(t)*uact1(t)*Derivative(1)(c)(s(t)))/(1 - c(s(t))*d(t))))/Power(1 - c(s(t))*d(t),2);
return ret;
}
