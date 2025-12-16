#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_thetap9d_2_1_()
{
double ret;
ret = (-2*Power(l3,2)*lv*Derivative(1)(delta3d)(t))/(Power(l3,2)*Power(lv,2) + 4*Power(l3,2)*Power(delta3d(t),2)) - (2*delta3d(t)*Sqrt(Power(l3,2)*Power(lv,2) + 4*Power(l3,2)*Power(delta3d(t),2) - Power(-4*Power(l2,2) + Power(l3,2) + Power(lv,2)/4. + Power(delta3d(t),2),2))*Derivative(1)(delta3d)(t))/(Power(l3,2)*Power(lv,2) + 4*Power(l3,2)*Power(delta3d(t),2)) + ((-4*Power(l2,2) + Power(l3,2) + Power(lv,2)/4. + Power(delta3d(t),2))*(8*Power(l3,2)*delta3d(t)*Derivative(1)(delta3d)(t) - 4*delta3d(t)*(-4*Power(l2,2) + Power(l3,2) + Power(lv,2)/4. + Power(delta3d(t),2))*Derivative(1)(delta3d)(t)))/(2.*(Power(l3,2)*Power(lv,2) + 4*Power(l3,2)*Power(delta3d(t),2))*Sqrt(Power(l3,2)*Power(lv,2) + 4*Power(l3,2)*Power(delta3d(t),2) - Power(-4*Power(l2,2) + Power(l3,2) + Power(lv,2)/4. + Power(delta3d(t),2),2))) + Derivative(1)(uthetap10d)(t);
return ret;
}
