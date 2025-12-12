#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_d_SX_d_t_5_1_()
{
double ret;
ret = (c(s(t))*Sin(thetap0(t))*(-((c(s(t))*Cos(thetap0(t))*uact1(t))/(1 - c(s(t))*d(t))) + uact2(t)))/(1 - c(s(t))*d(t)) + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))*uact3(t))/l1 + (Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t))*((c(s(t))*Cos(thetap0(t))*uact1(t))/(1 - c(s(t))*d(t)) + (-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1)*uact1(t) - uact2(t) + uact3(t)))/l1 - (Power(Cos(thetap0(t)),2)*uact1(t)*Derivative(1)(c)(s(t)))/Power(1 - c(s(t))*d(t),2) + (c(s(t))*Cos(thetap0(t))*(-(c(s(t))*Sin(thetap0(t))*uact1(t)) - (Cos(thetap0(t))*d(t)*uact1(t)*Derivative(1)(c)(s(t)))/(1 - c(s(t))*d(t))))/Power(1 - c(s(t))*d(t),2);
return ret;
}
