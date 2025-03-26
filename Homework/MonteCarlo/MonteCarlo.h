#ifndef MONTECARLO_H
#define MONTECARLO_H

#include<tuple>
#include<functional>
#include"../Matrix/vector.h"

double nextDouble();
std::tuple<double, double> plainMC(std::function<double(Vector)> f, Vector a, Vector b, int N);


#endif