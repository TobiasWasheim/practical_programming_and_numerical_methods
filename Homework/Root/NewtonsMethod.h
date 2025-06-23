#ifndef HAVE_NEWTON
#define HAVE_NEWTON

#include<functional>
#include<limits>
#include<cmath>
#include"../../Matrix/matrix.h"
#include"../QR/hdr/QR.h"

matrix Jacobian(std::function<colVector(colVector)> f, colVector x, colVector fx = colVector(), colVector dx = colVector());

colVector NewtonsMethod(std::function<colVector(colVector)> f, colVector start, double acc = 1e-2, colVector dx = colVector());


#endif