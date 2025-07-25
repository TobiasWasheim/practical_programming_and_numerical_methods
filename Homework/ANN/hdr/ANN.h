#include"../../../Matrix/matrix.h"

#include<functional>
#include<cmath>

class ann {
    public:
    
    /* number of hidden neurons */
    int n;

    /* activation function for hidden neurons */
    std::function<double(double)> f = [&](double x) {
        return x * std::exp(-x * x);};

    std::function<double(double)> f_deriv = [&](double x) {
        return (1 - 2 * x * x) * std::exp(-x*x);};
    

    std::function<double(double)> f_double_deriv = [&](double x) {
        return 2 * std::exp(-x*x)*x*(2*x*x-3);};

    std::function<double(double)> f_int = [&](double x) {
        return - std::exp(- x * x)/2;};
    
    
    std::function<double(double, colVector)> F = [this](double x, colVector z) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            double fi = f((x - z[i])/z[i+n]);
            sum += z[i+2*n] * fi;
        }
        return sum;
    };

    std::function<double(double, colVector)> F_deriv = [this](double x, colVector z) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            double fi = f_deriv((x - z[i])/z[i+n])/z[i+n];
            sum += z[i+2*n] * fi;
        }
        return sum;
    };

    std::function<double(double, colVector)> F_double_deriv = [this](double x, colVector z) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            double fi = f_double_deriv((x - z[i])/z[i+n])/z[i+n]/z[i+n];
            sum += z[i+2*n] * fi;
        }
        return sum;
    };

    std::function<double(double, colVector)> F_int = [this](double x, colVector z) {
        double sum = 0;
        int startpoint = 0;
        for (int i = 0; i < n; i++) {
            double fi = f_int((x - z[i]) / z[i+n]) * z[i+n];
            sum += z[i+2*n] * fi;
            sum -= z[i+2*n] * f_int((startpoint - z[i]) / z[i+n]) * z[i+n];
        }
        return sum;
    };

    



    /* network parameters */
    colVector p;

    ann(int neurons) {
        n = neurons;
        p = colVector(3*n);
    }

    double response(double x);
    double derivative(double x);
    double double_derivative(double x);
    double integrate(double x);
    void train(colVector x, colVector y);
};

