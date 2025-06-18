#ifndef HAVE_QNEWTON
#define HAVE_QNEWTON

#include"../../../Matrix/matrix.h"

colVector qnewton(std::function<double(colVector)> f, colVector x, double acc = 1e-3, int maxsteps = 10000);

#endif