#include <functional>
#include <cmath>
#include <iostream>
#include <limits>
#include <iomanip>
#include <fstream>
#include"integration.h"

double erf(double z, double acc) {
    if (z < 0) {
        return -erf(-z, acc);
    } else if (z >= 0 && z <= 1) {
        std::function<double(double)> integrand = [](double x) {return std::exp(-x*x);};
        return 2/std::sqrt(M_PI) * adapt(integrand,0,z,acc,0,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
    } else {
        std::function<double(double)> integrand = [z](double x) {return std::exp(-pow(z+(1-x)/x,2))/x/x;};
        return 1.0 - 2/std::sqrt(M_PI) * adapt(integrand,0,1,acc,0,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
    }
}

int main() {

    // The four functions we need to integrate at the top of part A
    std::function<double(double)> f1 = [](double x) { return std::sqrt(x);};
    std::function<double(double)> f2 = [](double x) { return 1.0/std::sqrt(x);};
    std::function<double(double)> f3 = [](double x) { return 4*std::sqrt(1-x*x);};
    std::function<double(double)> f4 = [](double x) { return std::log(x)/std::sqrt(x);};

    // Numerical integration of the functions
    double Q1 = adapt(f1,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
    double Q2 = adapt(f2,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
    double Q3 = adapt(f3,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
    double Q4 = adapt(f4,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());

    std::ofstream file;

    file.open("data.txt");
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }


    

    // Iterating over z-values from -3.5 to +3.5
    for (double z = -3.5; z <= 3.5; z += 0.1/8.0) {
        // Print the value of z and the error function erf(z)
        file << z <<" "<< erf(z,0.001) << "\n";
    }
    file << "\n";
    for (double acc = 0.000001; acc <= 1; acc *= 1.1) {
        double Q = std::abs(erf(1,acc)-0.84270079294971486934 );

        // Print the precision and erf(1)
        file << acc <<" " << Q <<std::setprecision(20)<< "\n";
    }
    file.close();


    std::cout << "---------------------------------------------" << "\n";
    std::cout << "Homework: Integration - part A" << "\n";
    std::cout << "---------------------------------------------" << "\n\n";

    std::cout << "In part A..." << "\n";
    return 0;
}