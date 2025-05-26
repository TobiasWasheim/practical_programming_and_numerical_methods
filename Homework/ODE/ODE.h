// Runge-Kutta 12 class
#include<vector>
#include<tuple>
#include<functional>
#include"../../Matrix/matrix.h"

std::tuple<colVector,std::vector<colVector>> driver(std::function<colVector(double, colVector)> f, double a, colVector ya, double b, double h=0.125, double acc=0.01, double eps=0.01);

std::tuple<colVector,colVector> rkstep12(std::function<colVector(double, colVector)> f, double x, colVector y, double h);
