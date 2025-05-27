#ifndef MONTECARLO_H
#define MONTECARLO_H

#include<tuple>
#include<functional>
#include"../../Matrix/matrix.h"

double nextDouble();
std::tuple<double, double> plainMC(std::function<double(colVector)> f, colVector a, colVector b, int N);


#endif