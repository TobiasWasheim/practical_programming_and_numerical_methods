#include"../hdr/ANN.h"
#include"../hdr/qnewton.h"

#include<functional>
#include<cmath>
#include<vector>
#include<random>


    double ann::response(double x) {
        /* return the response of the network to the input signal x */
        return F(x,p);
    }

    double ann::derivative(double x) {
        // return 0;
        return F_deriv(x,p);
    }

    double ann::double_derivative(double x) {

        return F_double_deriv(x,p);
    }

    double ann::integrate(double x) {

        return F_int(x,p);
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

        p = qnewton(costFunction, p,0.1,10000);
    };


    



