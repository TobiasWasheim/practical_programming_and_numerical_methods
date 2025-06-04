#ifndef HAVE_NEWTON
#define HAVE_NEWTON

#include<functional>
#include"../../../Matrix/matrix.h"

colVector newton(std::function<double(colVector)> f, colVector x, double acc = 1e-3, int* counter = nullptr);

#endif