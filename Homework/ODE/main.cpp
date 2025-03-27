#include<vector>
#include<iostream>
#include<functional>
#include<tuple>
#include"../Matrix/vector.h"
#include"ODE.h"

// Define the harmonic oscillator as a coupled first order ODE
Vector HarmonicOscillator(double x, Vector y) {

    Vector dydx(2);

    dydx[0] = y[1];
    dydx[1] = -y[0];

    return dydx;
}


int main() {
    // We solve the ODE (Harmonic Oscillator) u'' = -u 

    // define boundary conditions:

    double a = 0;
    double b = 10;

    // Define initial conditions

    Vector ya(std::vector<double> {1.0,0});

    std::function<Vector(double,Vector)> f = HarmonicOscillator;
    std::tuple<Vector,std::vector<Vector>> result = driver(f,a,ya,b);

    Vector xlist = std::get<0>(result);
    std::vector<Vector> ylist = std::get<1>(result);

    // Print results (example)
    for (int i = 0; i < xlist.getSize(); ++i) {
        std::cout << xlist[i] << " " << ylist[i][0] << " " << ylist[i][1] << "\n";
    }
}