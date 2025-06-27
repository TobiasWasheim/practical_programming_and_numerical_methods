#include<iostream>
#include<functional>

#include"NewtonsMethod.h"
#include"../ODE/hdr/ODE.h"
#include"hydrogen.h"


int main() {

    std::function<colVector(colVector)> rosenbrock = [](colVector z) {
        colVector r(2); 
        double x = z[0];
        double y = z[1];
        double a = 5;
        double b = 100;
        r[0] = 2*(a-x)*(-1)+b*2*(y-x*x)*(-1)*2*x;
        r[1]=b*2*(y-x*x);
        return r;
    };

    std::function<colVector(colVector)> himmelblau = [](colVector z) {
        colVector r(2);
        double x = z[0];
        double y = z[1];
        r[0] = 4 * x * (x * x + y - 11) + (2 * x + y * y - 7);
        r[1] = 2 * (x * x + y - 11) + 4 * y * (x + y * y - 7);
        return r;
    };

    colVector start({10,0.5});

    colVector newtonRosenbrock = NewtonsMethod(rosenbrock, start,1e-3,colVector());


    /* 
            Part B: Bound states of hydrogen atom with shooting method


            Boundary conditions: f(r_min) = r_min - r_min * r_min and f(r_max) = 0

            Let's say r_max = 8
    */





    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: Root Finding - part A" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part A Newton's method for finding roots" << "\n";
    std::cout << "has been inplemented. To test it, we use it" << "\n";
    std::cout << "to find the roots for the Rosenbrock- and  " << "\n";
    std::cout << "and Himmelblau function. " << "\n\n";
    
    std::cout << "Rosenbrock: f(x,y) = (a-x)^2 + b (y-x^2)^2" << "\n";
    std::cout << "Himmelblau: f(x,y) = (x^2+y-11)^2 + (x+y^2-7)^2" << "\n\n";
    
    std::cout << "where we have choosen a = 5 and b = 100. The roots" << "\n";
    std::cout << "for the Rosenbrock function are (a,a^2) = (5,25)." << "\n";
    std::cout << "Below, we are going to print the roots that we have" << "\n";
    std::cout << "calculated numerically using Newto's method:" << "\n";
    newtonRosenbrock.print();
    std::cout << "\n\n";
    
    std::cout << "The Himmelblau function has four local minima at (3,2), (-2.81,3.13), (-3.78,-3.28), and" << "\n";
    std::cout << "(3.58,-1.85). Below the four minima points are printed" << "\n";
    std::cout << "that are found numerically:" << "\n";
    // NewtonsMethod(himmelblau,{-0.27,-0.9},1e-6,colVector()).print();
    // std::cout << "\n";
    NewtonsMethod(himmelblau,{3,3},1e-3,colVector()).print();
    std::cout << "\n";
    NewtonsMethod(himmelblau,{-2,3},1e-3,colVector()).print();
    std::cout << "\n";
    NewtonsMethod(himmelblau,{-3,-3},1e-3,colVector()).print();
    std::cout << "\n";
    NewtonsMethod(himmelblau,{4,-2},1e-3,colVector()).print();
    std::cout << "\n\n" << "The roots found using Newton's method are close to the analytical values." << "\n"; 

    return 0;
}