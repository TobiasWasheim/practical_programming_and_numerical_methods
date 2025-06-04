#include"../hdr/hessian.h"
#include"../hdr/gradient.h"

#include<cmath>

matrix hessian(std::function<double(colVector)> f, colVector x) {
    int n = x.size();
    matrix H = matrix(n,n);
    colVector gfx = gradient(f,x);
    for (int j = 0; j < n; j++) {
        double dxj = (1 + std::abs(x[j])) * std::pow(2.0,-13.0);
        x[j] += dxj;
        colVector dgf = gradient(f,x) - gfx;
        for (int i = 0; i < n; i++) {
            H(i,j) = dgf[i]/dxj;
        }
        x[j] -= dxj;
    }
    return H;
}