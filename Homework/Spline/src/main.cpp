#include<cmath>
#include<iostream>
#include<vector>
#include <stdexcept>
#include <fstream>

#include"../hdr/spline.h"

/*Creates some datapoints for our splines*/
void data() {

    // Generate x-values
    int n = 21; // number of points
    std::vector<double> xs(n, 0);
    std::vector<double> ys(n, 0);

    double x = -5;
    for (int i = 0; i < n; i++) {
        xs[i] = x;
        ys[i] = std::exp(-x*x);      
        x += 0.5;   
    }

    // Initialize the splines
    lspline lspline(xs,ys);
    qspline qspline(xs,ys);
    cspline cspline(xs,ys);
    
    // create three blocks of data from the splines
    std::ofstream file;
    
    file.open("data/data.txt");




    for (double z = -4.9; z < 5; z+=0.3) {
        file << z << " " << lspline.evaluate(z) << " " << lspline.integrate(z) << "\n";
    }

    file << "\n";

    for (double z = -4.9; z < 5; z+=0.3) {
        file << z << " " << qspline.evaluate(z) << " " << qspline.derivative(z) << " " << lspline.integrate(z) << "\n";
    }

    file << "\n";

    for (double z = -4.9; z < 5; z+=0.3) {
        file << z << " " << cspline.evaluate(z) << " " << cspline.derivative(z) << " " << cspline.integrate(z) << "\n";
    }

    file << "\n";

    for (int i = 0; i < n; i++) {
        file << xs[i] << " " << ys[i] << "\n";
    }


    file.close();
}


int main() {
    data();
    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: Spline - part A" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "In part A, we have implemented the interpolation for the linear spline and the  " << "\n";
    std::cout <<" integral. To test that it works we have plotted the gaussian function and its   " << "\n";
    std::cout << "integral from x[0] to x                                                           " << "\n\n";
    
    std::cout << "f(x) = exp(-x^2),                                                               " << "\n";
    std::cout << "F(x) = 1/2 * sqrt(PI) * (erf(x) + erf(5))                                       " << "\n\n";
   
    std::cout << "Which can be seen  at 'plots/lspline.svg/'. There it can be seen that the       " << "\n\n";
    std::cout << "numerical and analytical result are close. The implementation of the linear     " << "\n";
    std::cout << "spline works!                                                                   " << "\n"; 
    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: Spline - part B" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "In part B the quadratic spline has been implemented. To test that it works we   " << "\n";
    std::cout << "have plotted the gaussian function, its integral, and its derivative.           " << "\n\n";
    
    std::cout << "f(x) = exp(-x^2),                                                               " << "\n";
    std::cout << "F(x) = 1/2 * sqrt(PI) * (erf(x) + erf(5))                                       " << "\n";
    std::cout << "f'(x) = -2 * x * exp(-x^2)                                                      " << "\n\n";

    std::cout << "It can be seen at 'plots/qspline.svg/' and it can be seen that the numerical   " << "\n";
    std::cout << "solution is close to the analytical solution.                                  " << "\n\n";

    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: Spline - part C" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";
    
    std::cout << "In part C, we have implemented the interpoklation of the cubic spline, its      " << "\n";
    std::cout << "derivative, and the integral of the gaussian function                           " << "\n\n";

    std::cout << "f(x) = exp(-x^2),                                                               " << "\n";
    std::cout << "F(x) = 1/2 * sqrt(PI) * (erf(x) + erf(5))                                       " << "\n";
    std::cout << "f'(x) = -2 * x * exp(-x^2)                                                      " << "\n\n";

    std::cout << "It can be seen at 'plots/cspline.svg/' that the numerical result is close to the" << "\n";
    std::cout << "analytical result. We also compare the cubic spline to Gnuplot's own cubic spline" << "\n";
    std::cout << "routine we see that the methods overlap substantially at 'plots/gnuplot.svg/'.  " << "\n";
    return 0;   
}
