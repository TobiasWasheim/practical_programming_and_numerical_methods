#include<functional>

#include"NewtonsMethod.h"
#include"../ODE/hdr/ODE.h"

double rmin = 1e-3;
double rmax = 10;
double acc = 1e-6;   // accuracy for ODE
double eps = 1e-6;   // relative accuracy
double E_guess = -1.0;  // initial guess for energy (Hartree units)



    
    std::function<colVector(double, colVector)> f = [](double r, vector y) {
        
        colVector dydr;
        double E = -0.5;
        dydr[0] = y[1];
        dydr[1] = -2 * (E + 1/r) * y[0]; 
        
        return dydr;
    };



colVector M(double E) {
    colVector ymin = {rmin - rmin * rmin,1.0 - 2.0 * rmin};
    std::tuple<colVector,std::vector<colVector>> sol = driver(f, rmin, ymin, rmax);
    
    colVector ys = std::get<0>(sol);

    return ys;
}

double find_energy() {

    std::function<colVector(colVector)> m = [=](colVector E) {
        return colVector{M(E[0])};
    };

    return NewtonsMethod(m,E_guess)[0];
}
