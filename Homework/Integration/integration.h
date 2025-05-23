#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <functional>
#include <limits>

double adapt(std::function<double(double)> f, double a, double b, 
            double acc=0.001, double eps=0.01, 
            double f2 = std::numeric_limits<double>::quiet_NaN(), 
            double f3 = std::numeric_limits<double>::quiet_NaN());
#endif