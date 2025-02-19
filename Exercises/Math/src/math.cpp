#include <iostream>
#include <cmath>
#include "../headers/math.h"

void mathExpressions()
{
    std::cout << "sqrt(2)   = " << sqrt(2) << "\n";
    std::cout << "pow(2,0.2)= " << pow(2,0.2) << "\n";
    std::cout << "pow(e,pi) = " << pow(M_E,M_PI) << "\n";
    std::cout << "pow(pi,e) = " << pow(M_PI,M_E) << "\n";
}