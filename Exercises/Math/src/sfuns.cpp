#include<cmath>
#include <iostream>
#include <iomanip>
#include "../headers/sfuns.h"


double fgamma(double x)
{
	if(x<0)return M_PI/std::sin(M_PI*x)/fgamma(1-x);
	if(x<9)return fgamma(x+1)/x;
	double lnfgamma=x*std::log(x+1/(12*x-1/x/10))-x+std::log(2*M_PI/x)/2;
	return std::exp(lnfgamma);
}

double sgamma(double x)
{
    if(x<0)return M_PI/sin(M_PI*x)/sgamma(1-x);
    if(x<9)return sgamma(x+1)/x;
    double lnsgamma=log(2*M_PI)/2+(x-0.5)*log(x)-x
        +(1.0/12)/x-(1.0/360)/pow(x,3)+(1.0/1260)/pow(x,5);
    return exp(lnsgamma);        
}

void table() 
{
    std::cout << "n     Γ(n)" << "\n";
    std::cout << "=============" << "\n";
    
    for (int i = 1; i <= 10; i++)
    {
        std::cout << std::setw(2) << "     " << fgamma(i) << "\n";
    }
}
