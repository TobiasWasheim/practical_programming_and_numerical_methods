#include <iostream>
#include <cmath>
#include <functional>
#include "../integration.h"

double erf(double z) {
    if (z < 0) {
        return -erf(-z);
    } else if (z >= 0 && z <= 1) {
        std::function<double(double)> integrand = [](double x) {return std::exp(-x*x);};
        return 2/std::sqrt(M_PI) * adapt(integrand,0,z);
    } else {
        std::function<double(double)> integrand = [z](double x) {return std::exp(-pow(z+(1-x)/x,2))/x/x;};
        return 1.0 - 2/std::sqrt(M_PI) * adapt(integrand,0,1);
    }

}

double int_erf(double x, double z) {
    if (x < 0) {
        return -1.0 * int_erf(-x,z);
    }

    if (x >= 0 && x <= 1) {
        return 2 / std::sqrt(M_PI) * std::exp(-x * x);
    }

    if (x > 1) {
        return 2/std::sqrt(M_PI) * std::exp((-1.0)*std::pow((z+(1-x)/x),2))/x/x;
    }
}

int main() {
    // Iterating over z-values from -3.5 to +3.5
    for (double z = -3.5; z <= 3.5; z += 0.1/8.0) {
        // Print the value of z and the error function erf(z)
        std::cout << z <<" "<< erf(z) << "\n";
    }
}