#ifndef OLSFit_H
#define OLSFit_H
#include<functional>
#include<tuple>
#include"../../../Matrix/matrix.h"


std::tuple<colVector,matrix> lsfit(std::function<double(double)> fs[], colVector x, colVector y, colVector dy, int size);


#endif