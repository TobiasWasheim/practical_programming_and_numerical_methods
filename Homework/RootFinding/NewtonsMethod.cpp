#include<functional>
#include<limits>
#include<cmath>

#include"../../Matrix/matrix.h"
/* The Jacobian matrix */
matrix Jacobian(std::function<colVector(colVector)> f, colVector x) {
    
    double EPS = std::numeric_limits<double>::epsilon();
    double df;
    double dx;
    colVector fx = f(x);

    matrix J(x.size(),x.size());

    /* Entries for the Jacobian matrix*/
    for (int i = 0; i < x.size(); i++) {
        for (int k = 0; k < x.size(); k++) {
            dx = abs(x[k]) * std::sqrt(EPS);
            
            x[k] += dx;

            df = f(x)[i] - fx[i];

            x[k] -= dx;

            J(i,k) = dx/df;
        }
    }
    return J;
}

colVector NewtonsMethod(std::function<colVector(colVector)> f, colVector x) {
    matrix J = Jacobian(f,x);
    colVector fx = f(x);
    double lambda = 1;
    colVector dx = J * fx;
    colVector fxlamb = f(x - dx * lambda);

    
    
    while (norm(f(x - dx * lambda)) > (1 - lambda/2) * norm(fx) && lambda > 1/128.0) {
        lambda *= 0.5;
        x = x + dx * lambda;
    }
}

