#include <functional>
#include <cmath>
#include <iostream>
#include <limits>
#include <iomanip>
#include "../integration.h"

/*

    In this file we calculate how erf(1) changes for different precision requirements

*/

double erf(double x,double acc) {
    
    std::function<double(double)> integrand = [](double x) {return 2 / std::sqrt(M_PI) * std::exp(-x * x);};
    
    return adapt(integrand,0,1,acc,0,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
}

int main() {
    // Iterate through different precisions
    for (double acc = 0.000001; acc <= 1; acc *= 1.1) {
        double Q = erf(1,acc);

        // Print the precision and erf(1)
        std::cout << std::log10(acc) <<" " <<std::log10(Q) <<std::setprecision(20)<< "\n";
    }
}