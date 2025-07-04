#include <functional>
#include <limits>
#include <cmath>
#include <iostream>
#include "../hdr/integration.h"

std::tuple<double,double> adapt(std::function<double(double)> f, double a, double b, 
            double acc, double eps, 
            double f2, 
            double f3, int* counter)
{
    if (std::isinf(a) && std::isinf(b)) {
        return adaptInfiniteLimits(f,acc,eps,f2,f3,counter);
    } else if(std::isinf(a)) {
        return adaptInfiniteLimitsRight(f,b,acc,eps,f2,f3,counter);
    } else if (std::isinf(b)) {
        return adaptInfiniteLimitsLeft(f,a,acc,eps,f2,f3,counter);
    }
    
    
    
    if (counter != nullptr) (*counter)++;

    double f1 = f(a+(b-a) * 1.0/6.0);
    double f4 = f(a+(b-a) * 5.0/6.0);

    if (std::isnan(f2))
    {
        f2 = f(a+(b-a)* 2.0/6.0);
        f3 = f(a+(b-a)*4.0/6.0);
    }
    double Q = (2 * f1 + f2 + f3 + 2*f4)/6.0 * (b-a);
    double q = (f1 + f2 + f3 + f4)/4.0 * (b-a);
    
    double tol = acc + eps * std::abs(Q);
    double error = std::abs(Q-q);

    if (error < tol)
    {
        return std::make_tuple(Q,error);
    }
    else
    {
        std::tuple<double,double> Q1 = adapt(f,a,(a+b)/2.0,acc/std::sqrt(2),eps,f1,f2, counter);
        std::tuple<double,double> Q2 = adapt(f,(a+b)/2.0,b,acc/std::sqrt(2),eps,f1,f2, counter);

        double q1 = std::get<0>(Q1);
        double q2 = std::get<0>(Q2);

        double err1 = std::get<1>(Q1);
        double err2 = std::get<1>(Q2);

        return std::make_tuple(q1 + q2,std::sqrt(err1*err1+err2*err2));
    }
}

std::tuple<double,double> ClenshawCurtisAdapt( std::function<double(double)> f, 
                            double a, 
                            double b, 
                            double acc, 
                            double eps, 
                            double f2, 
                            double f3,
                            int* counter) 
{
    auto g = [&](double t){
		return f((a+b)/2+(b-a)/2*cos(t))*sin(t)*(b-a)/2;
		};
	std::tuple<double,double> Q=adapt(g,0,M_PI,acc,eps, std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), counter);
	return Q;
}

std::tuple<double,double> adaptInfiniteLimits( std::function<double(double)> f, 
                            double acc, 
                            double eps, 
                            double f2, 
                            double f3,
                            int* counter) 
{
    auto g = [&](double t) {
        return (f((1-t)/t) + f(-(1-t)/t))/(t*t);
    };
    std::tuple<double,double> Q=adapt(g,0,1,acc,eps, std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), counter);
	return Q;
}

std::tuple<double,double> adaptInfiniteLimitsLeft( std::function<double(double)> f,
                            double a,
                            double acc, 
                            double eps, 
                            double f2, 
                            double f3,
                            int* counter) 
{
    auto g = [&](double t) {
        return f(a+(1-t)/t) * 1/(t*t);
    };
    std::tuple<double,double> Q=adapt(g,0,1,acc,eps, std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), counter);
	return Q;
}

std::tuple<double,double> adaptInfiniteLimitsRight(  std::function<double(double)> f, 
                            double b,
                            double acc, 
                            double eps, 
                            double f2, 
                            double f3,
                            int* counter) 
{
    auto g = [&](double t) {
        return f(b-(1-t)/t) * 1/(t*t);
    };
    std::tuple<double,double> Q=adapt(g,0,1,acc,eps, std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), counter);
	return Q;
}