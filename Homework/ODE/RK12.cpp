#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "RK12.h"

std::vector<std::vector<double>> RK12::driver(double f, double a, std::vector<double> ya, double b, double h=0.125, double acc = 0.01, double eps=0.01)
{
    double x = a; 
    std::vector<double> y = ya;
    std::vector<double> xlist({x});
    std::vector<double> ylist({y});
    
    // return tuple
    std::vector<std::vector<double>> result;
    result.push_back(xlist);
    result.push_back(ylist);

    // Empty tuple
    std::vector<std::vector<double>> temp;

    while (true)
    {
        if (x >= b) {return result;}

        if (x + h > b) {h = b -x;}

        temp = stepper(f, x, y, h);
        
        double tol = (acc + eps * temp[0].norm()) * sqrt(h/(b-a));

        double err = temp[1].norm();

        if (err < tol) 
        {
            x += h;
            y = temp[0];
            result[0].push_back(x);
            result[1].push_back(y);
        }

        if (err > 0) {h *= std::min(std::pow((tol/err),0.25)*0.95,2.0);}

        else { h *= 2;}
        
    }
}

