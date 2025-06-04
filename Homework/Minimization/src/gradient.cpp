#include"../hdr/gradient.h"

#include<cmath>

colVector gradient(std::function<double(colVector)> f, colVector x) {
    int n = x.size();
    double fx = f(x);
    colVector gf = colVector(n);
    for (int i = 0; i < n; i++) {
        double dxi = std::max((1 + std::abs(x[i])) * 1e-6,1e-6);
        x[i] += dxi;
        gf[i] = (f(x) - fx)/dxi;
        x[i] -= dxi;
    }
    return gf;
}