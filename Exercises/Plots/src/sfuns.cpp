# include "sfuns.h"
# include <stdexcept>
# include <cmath>

double error_function(double x)
{
    return std::erf(x);
}

double sgamma(double x)
{
    if(x<0)return M_PI/std::sin(M_PI*x)/sgamma(1-x);
    if(x<9)return sgamma(x+1)/x;
    double lnsgamma=std::log(2*M_PI)/2+(x-0.5)*std::log(x)-x
        +(1.0/12)/x-(1.0/360)/(x*x*x)+(1.0/1260)/(x*x*x*x*x);
    return std::exp(lnsgamma);
}

double lngamma(double x)
{
    if(x<=0) throw new std::invalid_argument("lngamma: x<=0");
    if(x<9) return lngamma(x+1)-std::log(x);
    return x*std::log(x+1/(12*x-1/x/10))-x+std::log(2*M_PI/x)/2;
}