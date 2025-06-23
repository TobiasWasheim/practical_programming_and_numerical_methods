#ifndef HAVE_HYDROGEN
#define HAVE_HYDROGEN

#include"../../Matrix/matrix.h"

std::function<colVector(double,colVector)> schrodinger(double E);
double M(double E);
double find_energy();

#endif