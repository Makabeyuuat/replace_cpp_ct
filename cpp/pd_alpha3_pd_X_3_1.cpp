#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha3_pd_X_3_1_()
{
double ret;
ret = -(d(t)*Sec(thetap0(t))*((Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)))/l1 + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))/l1)*Derivative(1)(c)(s(t)));
return ret;
}
