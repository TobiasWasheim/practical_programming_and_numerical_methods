#include"../hdr/gradient.h"

#include<cmath>

colVector gradient(std::function<double(colVector)> f, colVector x) {
    double fx = f(x);
    colVector gf = colVector(x.size());
    for (int i = 0; i < x.size(); i++) {
        double dxi = (1 + std::abs(x[i])) * std::pow(2.0,-26.0);
        x[i] += dxi;
        gf[i] = (f(x) - fx)/dxi;
        x[i] -= dxi;
    }
    return gf;
}