#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_alpha7_pd_X_2_2_()
{
double ret;
ret = -(c(s(t))*Sec(thetap0(t))*((c(s(t))*Sin(thetap0(t)))/(1 - c(s(t))*d(t)) + (Sec(phi5(t))*(2*Cos(phi1(t) - thetap0(t) + thetap1(t))*Cos(phi5(t) - thetap0(t) + thetap5(t))*Sec(phi1(t))*Sin(Pi/6. - thetap0(t) + thetap1(t)) + 2*Cos(Pi/6. - thetap0(t) + thetap1(t))*Cos(phi5(t) - thetap0(t) + thetap5(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) + Cos(phi5(t) - thetap0(t) + thetap5(t))*(1 - 2*Cos(Pi/6. - thetap0(t) + thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))) - 2*Sec(phi1(t))*Sin(Pi/6. - thetap0(t) + thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t))*Sin(phi5(t) - thetap0(t) + thetap5(t)) - (2*Cos(Pi/6. - thetap0(t) + thetap1(t))*Cos(phi1(t) - thetap0(t) + thetap1(t))*Sec(phi1(t)) - 2*Sec(phi1(t))*Sin(Pi/6. - thetap0(t) + thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))*Sin(phi5(t) - thetap0(t) + thetap5(t))))/l2)) - c(s(t))*Sec(thetap0(t))*(-((c(s(t))*Cos(thetap0(t)))/(1 - c(s(t))*d(t))) + (Sec(phi5(t))*(-2*Cos(phi5(t) - thetap0(t) + thetap5(t))*Sec(phi1(t))*Sin(Pi/6. - thetap0(t) + thetap1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)) - (1 - 2*Cos(Pi/6. - thetap0(t) + thetap1(t))*Sec(phi1(t))*Sin(phi1(t) - thetap0(t) + thetap1(t)))*Sin(phi5(t) - thetap0(t) + thetap5(t))))/l2)*Tan(thetap0(t));
return ret;
}
