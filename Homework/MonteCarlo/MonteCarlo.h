#ifndef MONTECARLO_H
#define MONTECARLO_H

#include<tuple>
#include<functional>
#include"../../Matrix/matrix.h"

double nextDouble();
double corput(int n, int b = 2);
std::vector<int> prime_numbers(int n);
bool isPrime(int num);

std::tuple<double, double> plainMC(std::function<double(colVector)> f, colVector a, colVector b, int N);
std::tuple<double, double> quasiMC(std::function<double(colVector)> f, colVector a, colVector b, int N);

#endif