#include"../hdr/hessian.h"
#include"../hdr/gradient.h"

#include<cmath>

matrix hessian(std::function<double(colVector)> f, colVector x) {
    matrix H = matrix(x.size(),x.size());
    colVector gfx = gradient(f,x);
    for (int j = 0; j < x.size(); j++) {
        double dxj = (1 + std::abs(x[j])) * std::pow(2.0,-13.0);
        x[j] += dxj;
        colVector dgf = gradient(f,x) - gfx;
        for (int i = 0; i < x.size(); i++) {
            H(i,j) = dgf[i]/dxj;
        }
        x[j] -= dxj;
    }
    return H;
}