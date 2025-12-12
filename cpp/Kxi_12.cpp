#include "cooperative_transportation_4ws_backstepping/kinematics_solver.hpp"
#include "cooperative_transportation_4ws_backstepping/initial.hpp"
#include "cooperative_transportation_4ws_backstepping/mathFunc.h"
#include <array>
#include <iostream>

double KinematicsSolver::calc_Kxi_12_()
{
double ret;
ret = GRVY*(Pattern(m,Blank(b)) + 2*Pattern(m,Blank(w)))*Sin(rho);
return ret;
}
