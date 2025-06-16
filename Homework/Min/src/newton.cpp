#include"../hdr/newton.h"
#include"../hdr/gradient.h"
#include"../hdr/hessian.h"
#include"../../QR/hdr/QR.h"

#include<tuple>

colVector newton(std::function<double(colVector)> f, colVector x, double acc, int* counter, int maxsteps) {
    matrix H;
    colVector g;
    int nstep = 0;
    while (nstep < maxsteps) {
        g = gradient(f,x);
        if (norm(g) < acc) {
            break;
        }
        H = hessian(f,x);
        std::tuple<matrix,matrix> QR = decomp(H);
        colVector dx = solve(std::get<0>(QR),std::get<1>(QR),-1 * g);
        
        double lambda = 1.0;
        double fx = f(x);
        while (lambda > 1.0/512.0) {
            if (f(x + lambda * dx) < fx) {
                break;
            }
            lambda /= 2.0;
        }
        x = x + lambda * dx;
        if (counter != nullptr) {
            (*counter)++;
        }
        nstep++;
        
    }
    return x;
}