#ifndef HAVE_HESSIAN
#define HAVE_HESSIAN

#include<functional>
#include"../../../Matrix/matrix.h"

matrix hessian(std::function<double(colVector)> f, colVector x);

#endif