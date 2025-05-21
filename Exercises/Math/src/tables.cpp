#include "../headers/sfuns.h"
#include<cmath>
#include <iostream>
#include <iomanip>

void gammaFunctionTable() 
{

    std::cout << "\n" << "n      Γ(n)      ln(Γ(n))" << "\n";
    std::cout << "============================" << "\n";
    
    for (int i = 1; i <= 10; i++)
    {
        std::cout <<std::setw(2) << i << "     "  << std::setw(6) << fgamma(i) << "    "<< std::setw(5) << lngamma(i) <<"\n";
    }
}
