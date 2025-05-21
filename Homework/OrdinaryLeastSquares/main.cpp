#include<functional>
#include<cmath>
#include<iostream>
#include<tuple>
#include<vector>
#include"../../Matrix/matrix.h"
#include"../LinearEquations/QR.h"
#include"OLSFit.h"


double func1(double x) {
    return 1.0;
}

double func2(double x) {
    return -x;
}


double fit(double x, colVector c) {
    return c[0] - c[1] * x;
}

int main() {

    // Functions
    std::function<double(double)> f1 = func1;
    std::function<double(double)> f2 = func2;

    // Data
    std::vector<double> xs = {1,2,3,4,6,9,10,13,15};
    std::vector<double> ys = {117,100,88,72,53,29.5,25.2,15.2,11.1};
    std::vector<double> dys = {6,5,4,4,4,3,3,2,2};

    // Linearize the data
    std::vector<double> ln_ys(ys.size());
    std::vector<double> ln_dys(dys.size());

    for (int i = 0; i < ys.size(); i++) {
        ln_ys[i] = std::log(ys[i]);
        ln_dys[i]= dys[i]/ys[i];
    }

    // Define vectors
    colVector x(xs);
    colVector y(ln_ys);
    colVector dy(ln_dys);

    std::function<double(double)> fs[2];

    fs[0] = f1;
    fs[1] = f2;

    // define size of function set
    int size = 2;

    // do fitting
    std::tuple<colVector,matrix> fit = lsfit(fs,x,y,dy,size);

    colVector c = std::get<0>(fit);
    matrix coVar = std::get<1>(fit);

    // Print fitting result
    std::cout << "ln(a): " << std::exp(c[0]) << "\n";

    double halfLifeUncertainty = log(2)/c[1]/c[1] * coVar(1,1);
    std::cout << "lambda: " << c[1] << " plus-minus " << halfLifeUncertainty <<"\n";
    std::cout << "Half-life value of ThX: " << std::log(2)/c[1] << " days\n";
    std::cout << "Correct half-life: " << 3.66 << " days\n";
    // Fitting the function 
    for (double i = 0; i < xs[xs.size()-1]; i += 0.1) {
        std::cout << i << " " << std::exp(c[0]) * std::exp(-c[1]*i)  << "\n";
    }
}   