#include<vector>
#include<iostream>
#include<tuple>
#include<cmath>
#include <fstream>
#include"MonteCarlo.h"
#include"../OrdinaryLeastSquares/OLS.h"


double g(colVector v) {

    double x = v[0];
    double y = v[1];
    double z = v[2];

    return 1/(M_PI*M_PI*M_PI) * std::pow(1-cos(x)*cos(y)*cos(z),-1);
}

int main() {
    
    /**Part A:
     * Implement plain Monte Carlo multi-dimensional integration, e.g. along the following lines:
     * Calculate some interesting two-dimensional integrals with your Monte-Carlo routine
     *  Plot the estimated error and the actual error as functions of the number of sampling points. Check whether the actual error scales as  1/sqrt(N)
     * Try calculate the integral given in this homework for part A
    */

    // We calculate the area of the unit circle and the Gaussian function and the function given to us using plain monte carlo

    auto unitCircleFunction = [](colVector z) {return (z[0] * z[0] + z[1] * z[1] <= 1.0) ? 1.0 : 0.0;};
    auto gaussianFunction = [](colVector z) {return std::exp(-z[0] * z[0] - z[1] * z[1]);};
    std::function<double(colVector x)> f = [](colVector x) {return 1/(M_PI*M_PI*M_PI) * std::pow(1-cos(x[0])*cos(x[1])*cos(x[2]),-1);};

    std::function<double(double)> plainMCError[1];
    plainMCError[0] = [](double x) {return 1/std::sqrt(x);};

    // Data
    int size = 1e4;
    int npoints = 11;

    colVector N(npoints);
    colVector unitCircleArea(npoints);
    colVector unitCircleError(npoints);
    colVector gaussianArea(npoints);
    colVector gaussianError(npoints);
    colVector functionArea(npoints);
    colVector functionError(npoints);
    

    std::ofstream file;
    file.open("data.txt");
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }
    // file << "N, unit circle area, unit circle error, gaussian function area, gaussian function error" << "\n";
    for (int i = 0; i < npoints; i++) {

        N[i] = size;
        std::tuple<double,double> unitCircleResult = plainMC(unitCircleFunction,colVector{-1,-1},colVector{1,1},size);
        std::tuple<double,double> gaussianResult = plainMC(gaussianFunction,colVector{-3,-3},colVector{3,3},size);
        std::tuple<double,double> functionResult = plainMC(f,{0,0,0},{M_PI,M_PI,M_PI},size);

        unitCircleArea[i] = std::get<0>(unitCircleResult);
        unitCircleError[i] = std::get<1>(unitCircleResult);

        gaussianArea[i] = std::get<0>(gaussianResult);
        gaussianError[i] = std::get<1>(gaussianResult);

        functionArea[i] = std::get<0>(functionResult);
        functionError[i] = std::get<1>(functionResult);
        
        size += size;
    }

    std::tuple<colVector, matrix> circleUnitFit = lsfit(plainMCError,N,unitCircleError,unitCircleError * 0.01,1);
    std::tuple<colVector, matrix> gaussianFit = lsfit(plainMCError,N,gaussianError,gaussianError * 0.01,1);
    std::tuple<colVector, matrix> functionFit = lsfit(plainMCError,N,functionError, functionError * 0.01,1);

    colVector unitCircleCoefficients = std::get<0>(circleUnitFit);
    colVector gaussianCoefficients = std::get<0>(gaussianFit);
    colVector functionCoefficients = std::get<0>(functionFit);

    for (int i = 0; i < npoints; i++) {
        double circleFit = unitCircleCoefficients[0] * 1/std::sqrt(N[i]);
        double gaussianFit = gaussianCoefficients[0] * 1/std::sqrt(N[i]);
        file << N[i] << " " << unitCircleArea[i] << " " << unitCircleError[i] << " " << circleFit  << " " << gaussianArea[i] << " " << gaussianError[i] << " " << gaussianFit <<"\n";
    }

    file << "\n";
    // Solving the given integral from part A
    for (int i = 0; i < npoints; i++) {
        double functionFit = functionCoefficients[0] * 1/std::sqrt(N[i]);
        file << N[i] << " " << functionArea[i] << " " << functionError[i] << " " << functionFit << "\n";
    }


    file.close();


    /**Part B:
     * Implement a multidimensional Monte-Carlo integrator that uses low-discrepancy (quasi-random) sequences
     * Compare the scaling of the error with your pseudo-random Monte-Carlo integrator
    */

    std::tuple<double,double> unitCirclePlainMC = plainMC(unitCircleFunction,colVector{-1,-1},colVector{1,1},1000);
    std::tuple<double,double> unitCircleQuasiMC = quasiMC(unitCircleFunction,colVector{-1,-1},colVector{1,1},1000);


     /**Part C:
      * Make your integrator estimate and return the integration error
      * Investigate the quality of this error estimate by calculating some difficult intergrals and comparing the estimated error with the actual error.
      */

    std::cout << "---------------------------------------------" << "\n";
    std::cout << "Homework: Monte Carlo - part A" << "\n";
    std::cout << "---------------------------------------------" << "\n\n";

    std::cout << "In part A I have implemented the plain Monte " << "\n";
    std::cout << "Carlo integration method. To test that it    " << "\n";
    std::cout << "works, I have calculated the area of the     " << "\n";
    std::cout << "unit circle and the area under the Gaussian  " << "\n";
    std::cout << "function. The plots for the integral value   " << "\n";
    std::cout << "and error with the number of points on the   " << "\n";
    std::cout << "x-axis. They can seen in the folder plots/.  " << "\n";
    std::cout << "The error for both the unit circle area and  " << "\n";
    std::cout << "integral value of the Gaussian function goes " << "\n";
    std::cout << "as 1/sqrt(N).                                " << "\n";
    std::cout << "The integral values goes towards the exact   " << "\n";
    std::cout << "value as N increases.                        " << "\n\n";
    std::cout << "Lastly, the 3D integral given in the bottom  " << "\n";
    std::cout << "for part A can be seen on the plots          " << "\n";
    std::cout << "plots/functionError.svg and                  " << "\n";
    std::cout << "plots/functionValue.svg.                     " << "\n";
    std::cout << "---------------------------------------------" << "\n\n";
    std::cout << "Homework: Monte Carlo - part B" << "\n";
    std::cout << "---------------------------------------------" << "\n\n";

    std::cout << "In part B I have implemented the quasi-      " << "\n";
    std::cout << "random Monte Carlo integral method. I've     " << "\n";
    std::cout << "used the Van der Corput sequence and to      " << "\n";
    std::cout << "find the error, I have used to different     " << "\n";
    std::cout << "bases and subtracted the integral values     " << "\n";
    std::cout << "that are made up from the two bases.         " << "\n";
    std::cout << "Comparing the method to the plain MC method  " << "\n";
    std::cout << "for N = 1000 points we get that              " << "\n\n";

    std::cout << "Plain MC unit circle area = " << std::get<0>(unitCirclePlainMC) << "\n";
    std::cout << "Quasi MC unit circle area = " << std::get<0>(unitCircleQuasiMC) << "\n";

    std::cout << "Plain MC unit circle error = " << std::get<1>(unitCirclePlainMC) << "\n";
    std::cout << "Quasi MC unit circle error = " << std::get<1>(unitCircleQuasiMC) << "\n\n";

    std::cout << "The exact value is 3.14... so for the quasi- " << "\n";
    std::cout << "random Monte Carlo method we are close to the" << "\n";
    std::cout << "value and it also has a lower estimated error" << "\n";
    std::cout << "than the plain Monte Carlo method.           " << "\n";
}