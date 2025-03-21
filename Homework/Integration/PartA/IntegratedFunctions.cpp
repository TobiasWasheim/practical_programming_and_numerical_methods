#include <iostream>
#include <cmath>
#include <functional>
#include "../integration.h"

/*
    In this file we print the integral values of four different integrals given
    from the exercise 
*/
int main() {
    // Declaration of functions
    std::function<double(double)> f1 = [](double x) { return std::sqrt(x); };
    std::function<double(double)> f2 = [](double x) { return 1.0/std::sqrt(x); };
    std::function<double(double)> f3 = [](double x) { return 4*std::sqrt(1-x*x); };
    std::function<double(double)> f4 = [](double x) { return std::log(x)/std::sqrt(x); };

    // Numerical integration of the functions
    double Q1 = adapt(f1,0,1);
    double Q2 = adapt(f2,0,1);
    double Q3 = adapt(f3,0,1);
    double Q4 = adapt(f4,0,1);

    // Printing the functions
    std::cout << "Integral of f1 = " << Q1 << "\n";
    std::cout << "Integral of f2 = " << Q2 << "\n";
    std::cout << "Integral of f3 = " << Q3 << "\n";
    std::cout << "Integral of f4 = " << Q4 << "\n";
}