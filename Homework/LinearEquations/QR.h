#ifndef QR_H
#define QR_H

#include<tuple>
#include "../Matrix/vector.h"
#include "../Matrix/matrix.h"



std::tuple<Matrix,Matrix> decomp(Matrix A);
Vector solve(Matrix Q, Matrix R, Vector b);
double det(Matrix R);
Matrix inverse(Matrix A);

#endif
