#ifndef HAVE_GRADIENT
#define HAVE_GRADIENT

#include<functional>
#include"../../../Matrix/matrix.h"

colVector gradient(std::function<double(colVector)> f, colVector x);

#endif