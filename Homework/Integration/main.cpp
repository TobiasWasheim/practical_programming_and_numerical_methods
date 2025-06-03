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

    std::function<double(double)> gaussian = [](double x) {return std::exp(-x*x);};

    int counter3 = 0;
    int counter4 = 0;
    // Numerical integration of the functions
    double Q1 = adapt(f1,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
    double Q2 = adapt(f2,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),&counter3);
    double Q3 = adapt(f3,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
    double Q4 = adapt(f4,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),&counter4);

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

    int counter1 = 0;
    int counter2 = 0;
    int counter5 = 0;


    double gauss = adapt(gaussian,-std::numeric_limits<double>::infinity(),0);

    std::cout << "Value of gaussian integral: " << gauss << "\n";


    std::cout << "---------------------------------------------" << "\n";
    std::cout << "Homework: Integration - part A" << "\n";
    std::cout << "---------------------------------------------" << "\n\n";

    std::cout << "In part A I have implemented the open-4 Gauss" << "\n";
    std::cout << "quadrature. To test that it works, I have    " << "\n";
    std::cout << "used it to evaluate the four integrals given " << "\n";
    std::cout << "in part A.                                   " << "\n\n";

    std::cout << "integral of sqrt(x) from 0 to 1       = " << Q1 << "\n";
    std::cout << "integral of 1/sqrt(x) from 0 to 1     = " << Q2 << "\n";
    std::cout << "integral of sqrt(1-x*x) from 0 to 1   = " << Q3 << "\n";
    std::cout << "integral of ln(x)/sqrt(x) from 0 to 1 = " << Q4 << "\n\n";

    std::cout << "The accuracy is 0.01 so comparing to the" << "\n";
    std::cout << "analytical results, we see that the     " << "\n";
    std::cout << "accuracy of the numerical result is on  " << "\n";
    std::cout << "correct magnitude.                      " << "\n\n";

    std::cout << "Next, we plot the error function. This  " << "\n";
    std::cout << "plot can be seen at plots/erfValue.svg. " << "\n\n";
    
    std::cout << "At last, we calculate erf(1) for        " << "\n";
    std::cout << "different accuracies. I have plotted on " << "\n";
    std::cout << "log-log scale the accuracy vs. the      " << "\n";
    std::cout << "absolute difference between the         " << "\n";
    std::cout << "numerical and exact result at           " << "\n";
    std::cout << "plots/erfPrecision.svg.                 " << "\n";

    std::cout << "---------------------------------------------" << "\n";
    std::cout << "Homework: Integration - part B" << "\n";
    std::cout << "---------------------------------------------" << "\n\n";
    
    std::cout << "In part B I have implemented the Clenshaw-   " << "\n";
    std::cout << "Curtis open-4 quadrature. Calculating some   " << "\n";
    std::cout << "interesting integrals:                       " << "\n\n";
    
    std::cout << "integral of 1/sqrt(x) from 0 to 1 = " << ClenshawCurtisAdapt(f2,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),&counter1) << "\n";
    std::cout << "integral of ln(x)/sqrt(x) from 0 to 1 = " << ClenshawCurtisAdapt(f4,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),&counter2) << "\n\n";

    std::cout << "In part A we calculated the same integrals with" << "\n";
    std::cout << "the no variable transformation. Comparing the  " << "\n";
    std::cout << "the number of integrand evalulations we get that" << "\n";
    std::cout << "that for the first integral the Clenshaw-Curtis " << "\n";
    std::cout << "has " << counter1 << " iterations and the second" << "\n";
    std::cout << "integral has " << counter2 << " iterations." << "\n";
    std::cout << "The open-4 non-transformation for the first integral" << "\n";
    std::cout << "has " << counter3 << " iterations and the second" << "\n";
    std::cout << "integral has " << counter4 << " iterations." << "\n\n";

    std::cout << "Comparing to the number of iterations that Scipy has go" << "\n";
    std::cout << "to go through (is printed at the bottom under part C)" << "\n";
    std::cout << "we see that the number of iterations to integrate ln(x)/sqrt(x)" << "\n";
    std::cout << "is roughly 230. So our Clenshaw-Curits open4 integrator uses fewer" << "\n";
    std::cout << "iterations for this integral than Python scipy.integrate." << "\n\n";

    std::cout << "Next, I have implemented infinite limits. To test the integrator" << "\n";
    std::cout << "with infinite limits, I have integrated the gaussian function" << "\n";
    std::cout << "f(x) = exp(-x*x)." << "\n\n";
    
    std::cout << "from -infy to +infy = " << adapt(gaussian,-std::numeric_limits<double>::infinity(),0.001,0.01,std::numeric_limits<double>::infinity(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),&counter5) << "\n";
    std::cout << "from 0 to +infy     = " << adapt(gaussian,0,std::numeric_limits<double>::infinity()) << "\n";
    std::cout << "from -infy to 0     = " << adapt(gaussian,-std::numeric_limits<double>::infinity(),0) << "\n\n";

    std::cout << "The analytical result from -infy to infy is sqrt(pi) = 1.77.... From 0" << "\n";
    std::cout << "to +infy or -infy to 0 is sqrt(pi)/2 = 0.88...." << "\n";
    std::cout << "So we get the correct result in our test when using our integrator with infinite limits." << "\n\n";

    std::cout << "Comparing with scipy's integrator routine, we get that the number of iterations for our gaussian" << "\n";
    std::cout << "integral is " << counter5 << ". For scipy's integrator it uses roughly 90 iterations to compute the integral" << "\n";
    std::cout << "of the Gaussian integral." << "\n\n";

    std::cout << "Python output:" << "\n";
    return 0;
}