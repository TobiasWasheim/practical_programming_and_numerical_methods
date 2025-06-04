#include"../hdr/newton.h"

#include<iostream>
#include<cmath>
#include <fstream>


int main() {
    int counter_rosenbruck = 0;
    std::function<double(colVector)> rosenbruck = [](colVector z) {
        
        double x = z[0];
        double y = z[1];
        double a = 5.0;
        double b = 100.0;
        return (a - x) * (a - x) + b * ( y - x * x) * (y - x * x);
    };

    int counter_himmelblau = 0;
    std::function<double(colVector)> himmelblau = [](colVector z) {
        double x = z[0];
        double y = z[1];
        return (x * x + y - 11) * (x * x + y - 11) + (x + y * y - 7) * (x + y * y - 7);
    };

    colVector start = {0.1,0.1};
    double acc = 1e-3;

    colVector rosenbruckMin = newton(rosenbruck,start, acc, &counter_rosenbruck);
    colVector himmelblauMin = newton(himmelblau, start, acc, &counter_himmelblau);

    
    /**
     * 
     * 
     * Part B
     * 
     * 
    */
    // data

    

    


    std::function<double(colVector)> D = [](colVector z) {
        double E[] = {101, 103, 105, 107, 109, 111, 113, 115, 117, 119, 121, 123, 125, 127, 129, 131, 133, 135, 137, 139, 141, 143, 145, 147, 149, 151, 153, 155, 157, 159};

        double cross[] =  {-0.25, -0.30, -0.15, -1.71, 0.81, 0.65, -0.91, 0.91, 0.96, -2.52, -1.01, 2.01, 4.83, 4.58, 1.26, 1.01, -1.26, 0.45, 0.15, -0.91, -0.81, -1.41, 1.36, 0.50, -0.45, 1.61, -2.21, -1.86, 1.76, -0.50};

        double error[] = {2.0, 2.0, 1.9, 1.9, 1.9, 1.9, 1.9, 1.9, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.3, 1.3, 1.3, 1.3, 1.3, 1.3, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 0.9, 0.9, 0.9};

        auto F = [](double E,colVector x) {
        return x[2]/((E-x[0]) * (E-x[0]) + x[1] * x[1]/4);};
        

        double d = 0;

        for (int i = 0; i < 30; i++) {
            d += (F(E[i],z) - cross[i]) * (F(E[i],z)-cross[i])/(error[i] * error[i]);
            // std::cout << "i = " << i << "\n";
        }

        return d;
    };

    colVector higgs = newton(D,{125,2,5},1e-4,nullptr);
    
    auto F = [](double E,colVector x) {
        return x[2]/((E-x[0]) * (E-x[0]) + x[1] * x[1]/4);};

    std::ofstream file;

    file.open("new_data.txt");
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }
    for (int E = 101; E < 160; E++) {
        file << E << " " << F(E,higgs) << "\n";
    }

    file.close();




    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: Minimization - part A" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part A, Newton's method for minimization has been implemented" << "\n";
    std::cout << "and tested using the Rosenbrock- and Himmelblau function." << "\n";
    std::cout << "For the rosenbrock function" << "\n\n";
    
    std::cout << "f(x,y) = (a - x)^2 + b (y - x^2)^2," << "\n\n";
    
    std::cout << "the minimum is at (a,a^2). I have choosen a = 5 and b = 100." << "\n";
    std::cout << "Below you can see the minimum point that is computed numerically" << "\n";
    std::cout << "using Newton's minimization method." << "\n";
    rosenbruckMin.print();
    std::cout << "The number of iterations to find the minimum is " << counter_rosenbruck << ".\n";
    std::cout << "The himmelbalu function" << "\n\n";

    std::cout << "f(x,y) = (x^2 + y - 11)^2 + (x + y^2 - 7)^2," << "\n\n";
    std::cout << "has five extremum points. We are going to find the point" << "\n";
    std::cout << "(-0.27,-0.92) numerically. The numerical point can be seen below." << "\n";
    himmelblauMin.print();
    std::cout << "The number of iterations to find the minimum is " << counter_himmelblau << ".\n";
    std::cout << "As we see, the numerical values are close to the analytical ones." << "\n"; 



    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: Minimization - part B" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part B, the data for the Higgs-boson has been fitted" << "\n";
    std::cout << "to determine its mass, decay width, and scale factor." << "\n";
    std::cout << "These are the following:" << "\n\n";
    
    std::cout << "m = " << higgs[0] << " GeV, Γ = " << higgs[1] << " GeV, and A = " << higgs[2] << "\n\n";

    std::cout << "Additionally, the fit is plotted with the experimental data" << "\n";
    std::cout << "and can been seen at the folder plots/." << "\n";
    return 0;
}