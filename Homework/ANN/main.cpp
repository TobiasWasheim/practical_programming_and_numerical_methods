#include"ANN.h"

#include<fstream>
#include<iostream>

int main() {
    
    // We have our function
    std::function<double(double)> f = [](double x) {
        
        
        return std::cos( 5*x-1 ) * std::exp(-x*x);};

    std::function<double(double)> f_deriv = [](double x) {
        
        
        return - 5 * std::exp(-x * x)*std::sin(5 * x -1) - 2 * x * std::exp(-x * x) * std::cos(5 * x - 1);};

    // train the function
    
    int n = 21;

    // data tables 
    colVector xs(n);
    colVector ys(n);

    for (int i = 0; i < n; i += 1) {
        double num = - 1 + i/(n-1.0)* 2.0 ;
        xs[i] = num;
        ys[i] = f(num);
    }
    ann NN(10);

    NN.train(xs,ys);
    std::ofstream file;

    file.open("data.txt");
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }

    for (double x = -1; x < 1; x += 0.1) {
        file << x << " " << NN.response(x) << " " << NN.derivative(x) << " " << f(x) << " " << f_deriv(x) << "\n";
    }

    file.close();


    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: ANN - part A" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part A, the artifical neural network (ANN) has been" << "\n";
    std::cout << "implemented. To test it, we try to interpolate the function" << "\n\n";
    
    std::cout << "f(x) = cos(5x - 1) exp(-x^2)," << "\n\n";

    std::cout << "We have plotted the interpolation and the function on the plot at" << "\n";
    std::cout << "plots/plot.svg." << "\n";

    return 0;
}