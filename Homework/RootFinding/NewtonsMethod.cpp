#include<functional>
#include<limits>
#include<cmath>
#include<iostream>
#include"NewtonsMethod.h"
#include"../../Matrix/matrix.h"
/* The Jacobian matrix */

colVector NewtonsMethod(std::function<colVector(colVector)> f, colVector start, double acc, colVector dx) {

    colVector x = start;
    colVector fx = f(x);
    colVector z;
    colVector fz;

    double lambdaMin = 1.0/128.0;

    do {
        if (norm(fx) < acc) {
            break;
        }
        matrix J = Jacobian(f,x,fx,dx);
        std::tuple<matrix,matrix> QRJ = decomp(J);
        colVector Dx = solve(std::get<0>(QRJ),std::get<1>(QRJ),fx * (-1));
        double lambda = 1;
        do {
            z = x + lambda * Dx;
            fz = f(z);
            if (norm(fz) < (1 - lambda/2.0) * norm(fx)) {
                break;
            }
            if (lambda < lambdaMin) {
                break;
            }
            lambda /= 2.0;
        } while(true);
        x = z;
        fx = fz;
    } while(true);
    
    return x;

}

matrix Jacobian(std::function<colVector(colVector)> f, colVector x, colVector fx, colVector dx) {
    
    if (dx.isNull()) {
        std::function<double(double)> g = [](double x) {return std::abs(x) * std::pow(2,-26);};
        dx = x.map(g);
    }
    if (fx.isNull()) {
        fx = f(x);
    }
    matrix J(x.size(),x.size());
    for (int j = 0; j < x.size(); j++) {
        x[j] += dx[j];
        colVector df = f(x) - fx;
        for (int i = 0; i < x.size(); i++) {
            J(i,j) = df[i]/dx[j];
        }
        x[j] -= dx[j];
    }
    
    
    return J;
}

