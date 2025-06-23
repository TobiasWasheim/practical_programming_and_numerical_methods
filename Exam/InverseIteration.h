#ifndef HAVE_INVERSE_ITERATION
#define HAVE_INVERSE_ITERATION

#include"../Matrix/matrix.h"


#include<tuple>
#include<random>
#include<cmath>

double rayLeighQuotient(colVector x0, colVector x1);
colVector randomVector(int size);
std::tuple<double,colVector> InverseAlgorithm(matrix A, double s, colVector x0 = colVector(), double acc = 1e-3);


#endif