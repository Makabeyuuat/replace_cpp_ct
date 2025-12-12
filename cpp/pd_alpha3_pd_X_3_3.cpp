#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha3_pd_X_3_3_()
{
double ret;
ret = (1 - c(s(t))*d(t))*Sec(thetap0(t))*((Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))/l1 - (Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t))*Tan(phi1(t)))/l1) + (1 - c(s(t))*d(t))*Sec(thetap0(t))*((Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)))/l1 + (Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)))/l1)*Tan(thetap0(t));
return ret;
}
