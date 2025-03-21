// Runge-Kutta 12 class
#include <vector>

class RK12
{
public:
    std::vector<std::vector<double>> driver(double f, double a, std::vector<double> ya, double b, double h=0.125, double acc = 0.01, double eps=0.01);
    std::vector<std::vector<double>> stepper(double f, double x, double y, double h);

};