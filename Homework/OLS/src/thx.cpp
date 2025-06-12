#include<cmath>
#include<iostream>
#include"../hdr/OLS.h"


std::tuple<colVector,matrix> radioactivityFit()  {
    
    std::function<double(double)> f1 = [](double x) {return 1.0;};
    std::function<double(double)> f2 = [](double x) {return -x;};



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
    return lsfit(fs,x,y,dy,size);
 }

 int main() {
    std::tuple<colVector,matrix> fit = radioactivityFit();

    colVector c = std::get<0>(fit);
    matrix covariance = std::get<1>(fit);

    std::vector<double> xs = {1,2,3,4,6,9,10,13,15};
    // Fitting the function 
    for (double i = 0; i < xs[xs.size()-1]; i += 0.1) {
        std::cout << i << " " << std::exp(c[0]) * std::exp(-c[1]*i)  << "\n";
    }
    return 0;
 }