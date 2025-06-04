#include"../hdr/newton.h"
#include"../hdr/gradient.h"
#include"../hdr/hessian.h"
#include"../../LinearEquations/QR.h"

#include<tuple>

colVector newton(std::function<double(colVector)> f, colVector x, double acc) {

    while (true) {
        colVector g = gradient(f,x);
        if (norm(g) < acc) {
            break;
        }
        matrix H = hessian(f,x);
        std::tuple<matrix,matrix> QR = decomp(H);
        colVector dx = solve(std::get<0>(QR),std::get<1>(QR),-1 * g);
        
        double lambda = 1.0;
        while (lambda > 1.0/1024.0) {
            if (f(x + lambda * dx) < f(x)) {
                break;
            }
            lambda /= 2.0;
        }
        x = x + lambda * dx;
    }
    return x;
}