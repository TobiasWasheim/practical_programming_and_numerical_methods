#include"../hdr/hessian.h"
#include"../hdr/gradient.h"

#include<cmath>

matrix hessian(std::function<double(colVector)> f, colVector x) {
    int n = x.size();
    matrix H = matrix(n,n);
    colVector gfx = gradient(f,x);
    for (int j = 0; j < n; j++) {
        double dxj = std::max((1 + std::abs(x[j])) * 1e-6,1e-6);
        x[j] += dxj;
        colVector dgf = gradient(f,x) - gfx;
        for (int i = 0; i < n; i++) {
            H(i,j) = dgf[i]/dxj;
        }
        x[j] -= dxj;
    }
    return H;
}