#include"../hdr/newton.h"

#include<iostream>

int main() {

    std::function<double(colVector)> rosenbruck = [](colVector z) {
        double x = z[0];
        double y = z[1];
        double a = 5.0;
        double b = 100.0;
        return (a - x) * (a - x) + b * ( y - x * x) * (y - x * x);
    };

    std::function<double(colVector)> himmelblau = [](colVector z) {
        double x = z[0];
        double y = z[1];
        return (x * x + y - 11) * (x * x + y - 11) + (x + y * y - 7) * (x + y * y - 7);
    };

    colVector start = {0.1,0.1};
    double acc = 1e-3;

    colVector rosenbruckMin = newton(rosenbruck,start, acc);
    colVector himmelblauMin = newton(himmelblau, start, acc);

    

    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: Minimization - part A" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part A, Newton's method for minimization has been implemented" << "\n";
    std::cout << "and tested using the Rosenbrock- and Himmelblau function." << "\n";
    std::cout << "For the rosenbrock function" << "\n\n";
    
    std::cout << "f(x,y) = (a - x)^2 + b (y - x^2)^2," << "\n\n";
    
    std::cout << "the minimum is at (a,a^2). I have choosen a = 5 and b = 100." << "\n";
    std::cout << "Below you can see the minimum point that is computed numerically" << "\n";
    std::cout << "using Newton's minimization method." << "\n";
    rosenbruckMin.print();
    std::cout << "The himmelbalu function" << "\n\n";

    std::cout << "f(x,y) = (x^2 + y - 11)^2 + (x + y^2 - 7)^2," << "\n\n";
    std::cout << "has five extremum points. We are going to find the point" << "\n";
    std::cout << "(-0.27,-0.92) numerically. The numerical point can be seen below." << "\n";
    himmelblauMin.print();
    std::cout << "As we see, the numerical values are close to the analytical ones." << "\n"; 

    return 0;
}