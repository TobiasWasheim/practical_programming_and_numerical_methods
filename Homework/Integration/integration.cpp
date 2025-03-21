#include <functional>
#include <limits>
#include <cmath>
#include <iostream>
#include "integration.h"

double adapt(std::function<double(double)> f, double a, double b, 
            double acc, double eps, 
            double f2, 
            double f3)
{
    double f1 = f(a+(b-a) * 1.0/6.0);
    double f4 = f(a+(b-a) * 5.0/6.0);

    if (std::isnan(f2))
    {
        f2 = f(a+(b-a)* 2.0/6.0);
        f3 = f(a+(b-a)*4.0/6.0);
    }
    double Q = (2 * f1 + f2 + f3 + 2*f4)/6.0 * (b-a);
    double q = (f1 + f2 + f3 + f4)/4.0 * (b-a);
    
    double tol = acc + eps * std::abs(Q);
    double error = std::abs(Q-q);

    if (error < tol)
    {
        return Q;
    }
    else
    {
        double Q1 = adapt(f,a,(a+b)/2.0,acc/std::sqrt(2),eps,f1,f2);
        double Q2 = adapt(f,(a+b)/2.0,b,acc/std::sqrt(2),eps,f1,f2);
        return Q1 + Q2;
    }
}