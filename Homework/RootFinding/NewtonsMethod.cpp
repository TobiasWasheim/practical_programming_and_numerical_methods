#include<functional>
#include<limits>
#include<cmath>

#include"../Matrix/matrix.h"
#include"../Matrix/vector.h"
/* The Jacobian matrix */
Matrix Jacobian(std::function<Vector(Vector)> f, Vector x) {
    
    double EPS = std::numeric_limits<double>::epsilon();
    double df;
    double dx;
    Vector fx = f(x);

    Matrix J(x.getSize(),x.getSize());

    /* Entries for the Jacobian matrix*/
    for (int i = 0; i < x.getSize(); i++) {
        for (int k = 0; k < x.getSize(); k++) {
            dx = abs(x[k]) * std::sqrt(EPS);
            
            x[k] += dx;

            df = f(x)[i] - fx[i];

            x[k] -= dx;

            J[i][k] = dx/df;
        }
    }
    return J;
}

Vector NewtonsMethod(std::function<Vector(Vector)> f, Vector x) {
    Matrix J = Jacobian(f,x);
    Vector fx = f(x);
    double lambda = 1;
    Vector dx = J * fx;
    Vector fxlamb = f(x - dx * lambda);

    
    
    while (f(x - dx * lambda).norm() > (1 - lambda/2) * fx.norm() && lambda > 1/128.0) {
        lambda *= 0.5;
        x += dx * lambda;
    }
}

