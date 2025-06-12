#include<cmath>
#include<iostream>
#include<vector>
#include <stdexcept>


int main() {
    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: Spline - part A" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "In part A, we have implemented the interpolation for the linear spline and the  " << "\n";
    std::cout <<" integral. To test that it works we have plotted the cosine function and its     " << "\n";
    
    std::cout << "f(x) = cos(x),                                                                  " << "\n";
    std::cout << "F(x) = sin(x).                                                                  " << "\n\n";
   
    std::cout << "Which can be seen  at 'plots/lspline.svg/'. There it can be seen that the       " << "\n\n";
    std::cout << "numerical and analytical result are close. The implementation of the linear     " << "\n";
    std::cout << "spline works!                                                                   " << "\n"; 
    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: Spline - part B" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "In part B the quadratic spline has been implemented. To test that it works we   " << "\n";
    std::cout << "have plotted the cosine function, its integral, and its derivative.             " << "\n\n";
    
    std::cout << "f(x) = cos(x),                                                                  " << "\n";
    std::cout << "F(x) = sin(x).                                                                  " << "\n";
    std::cout << "f'(x) = -sin(x)                                                                 " << "\n\n";

    std::cout << "It can be seen at 'plots/qspline.svg/' and it can be seen that the numerical   " << "\n";
    std::cout << "solution is close to the analytical solution.                                  " << "\n";
    
    return 0;   
}
