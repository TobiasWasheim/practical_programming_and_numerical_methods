#include"ANN.h"

#include<iostream>

int main() {
    
    // We have our function
    std::function<double(double)> f = [](double x) {return std::cos( 5*x-1 ) * std::exp(-x*x);};

    // train the function
    
    int n = 30;

    // data tables 
    colVector xs(n);
    colVector ys(n);

    for (int i = 0; i < n; i += 1) {
        double num = - 5 + i/3.0;
        xs[i] = num;
        ys[i] = f(num);
    }

    ann NN(15);

    NN.train(xs,ys);

    for (double x = -5; x < 5; x += 0.1) {
        std::cout << x << " " << NN.response(x) << " " << f(x) << "\n";
    }

    return 0;
}