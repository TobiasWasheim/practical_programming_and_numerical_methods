#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <functional>
#include <limits>
#include<tuple>

std::tuple<double,double> adapt(   std::function<double(double)> f, 
                double a, 
                double b, 
                double acc=0.001, 
                double eps=0.01, 
                double f2 = std::numeric_limits<double>::quiet_NaN(), 
                double f3 = std::numeric_limits<double>::quiet_NaN(),
                int* counter = nullptr);

std::tuple<double,double> ClenshawCurtisAdapt( std::function<double(double)> f, 
                            double a, 
                            double b, 
                            double acc=0.001, 
                            double eps=0.01, 
                            double f2 = std::numeric_limits<double>::quiet_NaN(), 
                            double f3 = std::numeric_limits<double>::quiet_NaN(),
                            int* counter = nullptr);


std::tuple<double,double> adaptInfiniteLimits( std::function<double(double)> f, 
                            double acc=0.001, 
                            double eps=0.01, 
                            double f2 = std::numeric_limits<double>::quiet_NaN(), 
                            double f3 = std::numeric_limits<double>::quiet_NaN(),
                            int* counter = nullptr);

std::tuple<double,double> adaptInfiniteLimitsLeft( std::function<double(double)> f,
                            double a,
                            double acc=0.001, 
                            double eps=0.01, 
                            double f2 = std::numeric_limits<double>::quiet_NaN(), 
                            double f3 = std::numeric_limits<double>::quiet_NaN(),
                            int* counter = nullptr);

std::tuple<double,double> adaptInfiniteLimitsRight(  std::function<double(double)> f, 
                            double b,
                            double acc=0.001, 
                            double eps=0.01, 
                            double f2 = std::numeric_limits<double>::quiet_NaN(), 
                            double f3 = std::numeric_limits<double>::quiet_NaN(),
                            int* counter = nullptr);

#endif