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
        std::tuple<double,double> Q = adapt(integrand,0,z,acc,0,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
        return 2/std::sqrt(M_PI) * std::get<0>(Q);
    } else {
        std::function<double(double)> integrand = [z](double x) {return std::exp(-pow(z+(1-x)/x,2))/x/x;};
        std::tuple<double,double> Q = adapt(integrand,0,1,acc,0,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
        return 1.0 - 2/std::sqrt(M_PI) * std::get<0>(Q);
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
    std::tuple<double,double> Q1 = adapt(f1,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
    std::tuple<double,double> Q2 = adapt(f2,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),&counter3);
    std::tuple<double,double> Q3 = adapt(f3,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN());
    std::tuple<double,double> Q4 = adapt(f4,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),&counter4);

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
    file << "\n";




    file.close();

    int counter1 = 0;
    int counter2 = 0;
    int counter5 = 0;


    std::tuple<double,double> gauss = adapt(gaussian,-std::numeric_limits<double>::infinity(),0);

    std::cout << "Value of gaussian integral: " << std::get<0>(gauss) << "\n";


    std::cout << "---------------------------------------------" << "\n";
    std::cout << "Homework: Integration - part A" << "\n";
    std::cout << "---------------------------------------------" << "\n\n";

    std::cout << "In part A I have implemented the open-4 Gauss" << "\n";
    std::cout << "quadrature. To test that it works, I have    " << "\n";
    std::cout << "used it to evaluate the four integrals given " << "\n";
    std::cout << "in part A.                                   " << "\n\n";

    std::cout << "integral of sqrt(x) from 0 to 1       = " << std::get<0>(Q1) << "\n";
    std::cout << "integral of 1/sqrt(x) from 0 to 1     = " << std::get<0>(Q2) << "\n";
    std::cout << "integral of sqrt(1-x*x) from 0 to 1   = " << std::get<0>(Q3) << "\n";
    std::cout << "integral of ln(x)/sqrt(x) from 0 to 1 = " << std::get<0>(Q4) << "\n\n";

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
    
    std::tuple<double,double> ccf2 = ClenshawCurtisAdapt(f2,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),&counter1);
    std::tuple<double,double> ccf4 = ClenshawCurtisAdapt(f4,0,1,0.001,0.01,std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),&counter2);

    std::cout << "integral of 1/sqrt(x) from 0 to 1 = " << std::get<0>(ccf2) << "\n";
    std::cout << "integral of ln(x)/sqrt(x) from 0 to 1 = " << std::get<0>(ccf2) << "\n\n";

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
    
    std::tuple<double,double> gaussinflimits = adapt(gaussian,-std::numeric_limits<double>::infinity(),0.001,0.01,std::numeric_limits<double>::infinity(),std::numeric_limits<double>::quiet_NaN(),std::numeric_limits<double>::quiet_NaN(),&counter5);
    std::tuple<double,double> gaussleftlimit = adapt(gaussian,0,std::numeric_limits<double>::infinity());
    std::tuple<double,double> gaussrightlimit = adapt(gaussian,-std::numeric_limits<double>::infinity(),0);
    std::cout << "from -infy to +infy = " << std::get<0>(gaussinflimits) << "\n";
    std::cout << "from 0 to +infy     = " << std::get<0>(gaussleftlimit) << "\n";
    std::cout << "from -infy to 0     = " << std::get<0>(gaussrightlimit) << "\n\n";

    std::cout << "The analytical result from -infy to infy is sqrt(pi) = 1.77.... From 0" << "\n";
    std::cout << "to +infy or -infy to 0 is sqrt(pi)/2 = 0.88...." << "\n";
    std::cout << "So we get the correct result in our test when using our integrator with infinite limits." << "\n\n";

    std::cout << "Comparing with scipy's integrator routine, we get that the number of iterations for our gaussian" << "\n";
    std::cout << "integral is " << counter5 << ". For scipy's integrator it uses roughly 90 iterations to compute the integral" << "\n";
    std::cout << "of the Gaussian integral." << "\n\n";




    std::cout << "---------------------------------------------" << "\n";
    std::cout << "Homework: Integration - part C" << "\n";
    std::cout << "---------------------------------------------" << "\n\n";

    std::cout << "It has been implemented that the integrator returns the estimate" << "\n";
    std::cout << "of the error. We investigate these estimates by comparing the numerical" << "\n";
    std::cout << "solution to the numerical solution for a couple of integrals." << "\n\n";

    std::cout << "We look at the following integrals:" << "\n";
    std::cout << "  ln(x) from 0 to 1 which is equal to -1,         (we call this function g1)" << "\n";
    std::cout << "  sqrt(x) from 0 to 1 which is equal to 2/3,      (we call this function g2)" << "\n";
    std::cout << "  1/sqrt(1-x) from 0 to 1 which is equal to 2,    (we call this function g3)" << "\n\n";

    std::function<double(double)> g1 = [](double x) {return std::log(x);};
    std::function<double(double)> g2 = [](double x) {return std::sqrt(x);};
    std::function<double(double)> g3 = [](double x) {return 1/std::sqrt(1-x);};

    std::tuple<double,double> Qg1 = adapt(g1,0,1);
    std::tuple<double,double> Qg2 = adapt(g2,0,1);
    std::tuple<double,double> Qg3 = ClenshawCurtisAdapt(g3,0,1);

    std::cout << "The solutions and errors are:" << "\n";
    std::cout << "Q_g1 = " << std::get<0>(Qg1) << " and error_g1 = " << std::get<1>(Qg1) << "\n";
    std::cout << "Q_g2 = " << std::get<0>(Qg2) << " and error_g2 = " << std::get<1>(Qg2) << "\n";
    std::cout << "Q_g3 = " << std::get<0>(Qg3) << " and error_g3 = " << std::get<1>(Qg3) << "\n";
    std::cout << "The absolute difference between the numerical value and analytical solution is" << "\n";
    std::cout << "|Q_g1-q_g1| = " << std::abs(std::get<0>(Qg1) + 1)<< "\n";
    std::cout << "|Q_g2-q_g2| = " << std::abs(std::get<0>(Qg2) - 2.0/3.0)<< "\n";
    std::cout << "|Q_g3-q_g3| = " << std::abs(std::get<0>(Qg3) - 2)<< "\n\n";

    std::cout << "We see that the errors are roughly equal to the difference (except for g1, but close)" << "\n\n\n";

    std::cout << "Python output:" << "\n";
    return 0;
}