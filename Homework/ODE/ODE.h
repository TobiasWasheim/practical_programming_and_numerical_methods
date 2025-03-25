// Runge-Kutta 12 class
#include<vector>
#include<tuple>

class RK12
{
public:
    std::pair<std::vector<double>,std::vector<Vector>> driver(std::function<Vector(double, Vector)> f, double a, Vector ya, double b, double h=0.125, double acc=0.01, double eps=0.01);  
    std::vector<Vector> RK12::stepper(std::function<Vector(double, Vector)> f, double x, Vector y, double h);
};