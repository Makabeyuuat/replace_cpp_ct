#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha7_pd_X_3_1_()
{
double ret;
ret = -((d(t)*Sec(phi5(t))*Sec(thetap0(t))*(-2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Cos(phi5(t) - thetap0(t) + thetap5(t))*Sec(phi1(t))*Sin(Pi/6. - thetap0(t) + thetap1(t)) - 2*Cos(phi5(t) - thetap0(t) + thetap5(t))*Sec(phi1(t))*Sin(Pi/6. - thetap0(t) + thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t)) - Sin(phi5(t) - thetap0(t) + thetap5(t))*(-2*Cos(Pi/6. - thetap0(t) + thetap1(t))*Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)) - 2*Cos(Pi/6. - thetap0(t) + thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Tan(phi1(t))))*Derivative(1)(c)(s(t)))/l2);
return ret;
}
