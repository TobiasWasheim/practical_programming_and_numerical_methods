#ifndef HAVE_NEWTON
#define HAVE_NEWTON

#include<functional>
#include<limits>
#include<cmath>
#include"../../Matrix/matrix.h"

matrix Jacobian(std::function<colVector(colVector)> f, colVector x);

colVector NewtonsMethod(std::function<colVector(colVector)> f, colVector x);


#endif