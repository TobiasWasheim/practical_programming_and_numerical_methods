#include<cmath>
#include"spline.h"

int main() {

    //std::cout << "Hello, World" << "\n";

    int n = 32; // number of points
    std::vector<double> xs(n, 0);
    std::vector<double> ys(n, 0);

    double x = 0;
    int i = 0;
    while(n > i) { 
        //std::cout << "n = " << n << ", x = " << x << "\n";
        xs.at(i) = x;
        ys.at(i) = std::cos(x);       
        i++;
        x += 0.5;
    }

    lspline lspline(xs,ys);
    qspline qspline(xs,ys);
    


    for (double z = 0.1; z < n * 0.5 - 1; z += 0.2) {
        std::cout << z  <<" " << lspline.evaluate(z) << " " << lspline.integrate(z) << " " << qspline.evaluate(z) << " " << qspline.integrate(z) << " " << qspline.derivative(z) << "\n";
    }


    return 0;
}