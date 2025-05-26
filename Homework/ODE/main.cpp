#include<vector>
#include<iostream>
#include<functional>
#include<tuple>
#include <iostream>
#include<cmath>
#include <fstream>
#include"../../Matrix/matrix.h"
#include"ODE.h"

// Define the harmonic oscillator as a coupled first order ODE
colVector HarmonicOscillator(double x, colVector y) {

    colVector dydx(2);

    dydx[0] = y[1];
    dydx[1] = -y[0];

    return dydx;
}

colVector equatorialEquation1(double x, colVector y) {

    colVector dydx(2);

    dydx[0] = y[1];
    dydx[1] = 1 - y[0];

    return dydx;
}
colVector equatorialEquation2(double x, colVector y) {

    colVector dydx(2);

    dydx[0] = y[1];
    dydx[1] = 1 - y[0] + 0.01 * y[0] * y[0];

    return dydx;
}



int main() {
    // create a datafile called "data.txt" and put all the data we get from solving equations numerically

    std::ofstream file;

    file.open("data.txt");
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }
    
    
    
    /**Part A of homework ODE 
     * Implement stepper (RK12)
     * Implement adaptive step-size driver 
     * Solving the system u'' = -u
     * Reproducing the result of step (3) with scipy's integrator
     */
    double HO_boundary_a = 0;
    double HO_boundary_b = 10;

    colVector HO_ya(std::vector<double> {1.0,0}); // y(0) = 1 and y'(0) = 0
    std::function<colVector(double,colVector)> f_HO = HarmonicOscillator;
    std::tuple<colVector,std::vector<colVector>> HO_result = driver(f_HO,HO_boundary_a,HO_ya,HO_boundary_b);
    
    // collect the x-values, y-values, and y'-values
    colVector HO_xs = std::get<0>(HO_result);
    std::vector<colVector> HO_ys = std::get<1>(HO_result);
    
    // Put the solution into the data.txt file
    for (int i = 0; i < HO_xs.size(); i++) {
        file << HO_xs[i] << " " << HO_ys[i][0] << " " << HO_ys[i][1] << "\n";
    }


    /**Part B of homework ODE
     * Integrate the equatorial equation from QR for initial conditions eps = 0, u(0) = 1, u'(0) = 0
     * Integrate the equatorial equation from QR for initial conditions eps = 0, u(0) = 1, u'(0) = -0.5
     * Integrate the equatorial equation from QR for initial conditions eps = 0.01, u(0) = 1, u'(0) = -0.5
     */

    double EQ_boundary_a = 0;
    double EQ_boundary_b = 100;

    /* Part 1 of homework part B */
    colVector EQ_ya_part_1(std::vector<double> {1.0,0});

    std::function<colVector(double,colVector)> EQ_f_part_1 = equatorialEquation1;

    std::tuple<colVector,std::vector<colVector>> EQ_result_part_1 = driver(EQ_f_part_1,EQ_boundary_a,EQ_ya_part_1,EQ_boundary_b);

    colVector EQ_xs_part_1 = std::get<0>(EQ_result_part_1);
    std::vector<colVector> EQ_ys_part_1 = std::get<1>(EQ_result_part_1);

    file << "\n";
    for (int i = 0; i < EQ_xs_part_1.size(); ++i) {
        file << EQ_xs_part_1[i] << " " << EQ_ys_part_1[i][0] << " " << EQ_ys_part_1[i][1] << "\n";
    }

    /* Part 2 of homework part B */
    colVector EQ_ya_part_2(std::vector<double> {1.0,-0.5});

    std::function<colVector(double,colVector)> EQ_f_part_2 = equatorialEquation1;

    std::tuple<colVector,std::vector<colVector>> EQ_result_part_2 = driver(EQ_f_part_2,EQ_boundary_a,EQ_ya_part_2,EQ_boundary_b);

    colVector EQ_xs_part_2 = std::get<0>(EQ_result_part_2);
    std::vector<colVector> EQ_ys_part_2 = std::get<1>(EQ_result_part_2);

    file << "\n";
    for (int i = 0; i < EQ_xs_part_2.size(); ++i) {
        file << EQ_xs_part_2[i] << " " << EQ_ys_part_2[i][0] << " " << EQ_ys_part_2[i][1] << "\n";
    }

     /* Part 3 of homework part B */
    colVector EQ_ya_part_3(std::vector<double> {1.0,-0.5});

    std::function<colVector(double,colVector)> EQ_f_part_3 = equatorialEquation2;

    std::tuple<colVector,std::vector<colVector>> EQ_result_part_3 = driver(EQ_f_part_3,EQ_boundary_a,EQ_ya_part_3,EQ_boundary_b);

    colVector EQ_xs_part_3 = std::get<0>(EQ_result_part_3);
    std::vector<colVector> EQ_ys_part_3 = std::get<1>(EQ_result_part_3);

    file << "\n";
    for (int i = 0; i < EQ_xs_part_3.size(); ++i) {
        file << EQ_xs_part_3[i] << " " << EQ_ys_part_3[i][0] << " " << EQ_ys_part_3[i][1] << "\n";
    }

    file.close();


    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: ODE - part A" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";
    
    std::cout << "In part A of this homework I have implemented a" << "\n";
    std::cout << "stepper (RK12) and a driver with adaptive step-" << "\n";
    std::cout << "size. In order to show that it works, I have " << "\n";
    std::cout << "solved the ODE u'' = -u with initial conditions" << "\n";
    std::cout << "u(0) = 1 and u'(0) = 0. It can be seen at the" << "\n";
    std::cout << "location plots/HarmonicOscillator.svg/" << "\n\n\n";


    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: ODE - part B" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";
 
    std::cout << "In part B I have solved the equatorial equation" << "\n";
    std::cout << "from GR for motion around a star. I have plotted" << "\n";
    std::cout << "three cases:" << "\n";
    std::cout << "  - conditions ε = 0, u(0) = 1, u'(0) = 0" << "\n";
    std::cout << "  - conditions ε = 0, u(0) = 1, u'(0) = -0.5" << "\n";
    std::cout << "  - conditions ε = 0.01, u(0) = 1, u'(0) = -0.5" << "\n\n";

    std::cout << "The plots can be seen in the folder plots/." << "\n";

    return 0;
}