#ifndef OLSFit_H
#define OLSFit_H
#include<functional>
#include"../Matrix/vector.h"

Vector lsfit(std::function<double(double)> fs[], Vector x, Vector y, Vector dy, int size);

#endif