#include"ANN.h"
#include"../Minimization/hdr/newton.h"
#include"../Minimization/hdr/gradient.h"
#include"../Minimization/hdr/hessian.h"
#include"../LinearEquations/QR.h"

#include<functional>
#include<cmath>
#include<vector>
#include<random>
colVector gradientDescent(std::function<double(colVector)> f, colVector x, double acc = 1e-6, double alpha = 0.01, int max_steps = 10000, int* counter = nullptr) {
    int n = x.size();

    for (int step = 0; step < max_steps; step++) {
        colVector grad = gradient(f, x);
        if (norm(grad) < acc) {
            break;
        }
        double fx = f(x);
        colVector dx = -1 * grad;
        double lambda = 1.0;

        while (lambda > 1.0 / 1024.0) {
            if (f(x + lambda * dx) < fx) {
                break;
            }
            lambda /= 2.0;
        }

        x = x + lambda * dx;
        if (counter) {
            (*counter)++;
        }
    }
    return x;
}


    double ann::response(double x) {
        /* return the response of the network to the input signal x */
        return F(x,p);
    }

    void ann::train(colVector x, colVector y) {
        /* train the network to interpolate the given table {x,y} */

        // initial guess
        for (int i = 0; i < n; i++) {
            
            p[i] = x[0] + (x[x.size()-1] - x[0]) * i / (n-1);
            p[i+n] = 1;
            p[i+2*n] = 1;
        }
        std::function<double(colVector)> costFunction = [&x, &y,this](colVector z) {
            double result = 0;
            for (int k = 0; k < x.size(); k++) {
                result += std::pow(F(x[k],z)-y[k],2);
            }
            return result;
        };

        p = gradientDescent(costFunction, p);
        //p.print();
    };



