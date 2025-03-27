// Runge-Kutta 12 class
#include<vector>
#include<tuple>
#include<functional>
#include"../Matrix/vector.h"

std::tuple<Vector,std::vector<Vector>> driver(std::function<Vector(double, Vector)> f, double a, Vector ya, double b, double h=0.125, double acc=0.01, double eps=0.01);

std::tuple<Vector,Vector> rkstep12(std::function<Vector(double, Vector)> f, double x, Vector y, double h);
