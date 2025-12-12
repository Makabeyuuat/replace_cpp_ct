#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_pd_W_pd_X_2_17_()
{
double ret;
ret = -((k1 + k2)*Derivative(List(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0))(Z21)(List(s(t),d(t),thetap0(t),phi1(t),thetap1(t),phi2(t),thetap2(t),phi3(t),thetap3(t),phi4(t),thetap4(t),phi5(t),thetap5(t),phi6(t),thetap6(t),phi7(t),thetap7(t),phi8(t),thetap8(t),phi9(t),thetap9(t),phi10(t),thetap10(t)))) - (k1*k2*Derivative(List(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0))(Z22)(List(s(t),d(t),thetap0(t),phi1(t),thetap1(t),phi2(t),thetap2(t),phi3(t),thetap3(t),phi4(t),thetap4(t),phi5(t),thetap5(t),phi6(t),thetap6(t),phi7(t),thetap7(t),phi8(t),thetap8(t),phi9(t),thetap9(t),phi10(t),thetap10(t))))/a(t);
return ret;
}
