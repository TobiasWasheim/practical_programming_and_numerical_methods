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

     


     /**Part C:
      * Make your integrator estimate and return the integration error
      * Investigate the quality of this error estimate by calculating some difficult intergrals and comparing the estimated error with the actual error.
      */




}