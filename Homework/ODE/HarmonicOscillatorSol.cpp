#include<cmath>
#include<functional>
#include "ODE_solver.h"
#include "../Matrix/vector.h"



int main() {
    std::function<Vector(double, Vector)> f = [](double x, Vector y) {return Vector{sin(x)};};

    // Limits
    double a = 0;
    double b = 4;

    Vector ya{0};    

    RK12 rk12;

    std::pair<std::vector<double>,std::vector<Vector>> sol = rk12.driver(f,a,ya,b);

    std::vector<double> xs = sol.first;
    std::vector<Vector> ys = sol.second;

}

