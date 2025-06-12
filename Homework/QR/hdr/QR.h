#ifndef QR_H
#define QR_H


#include<tuple>

#include"../../../Matrix/matrix.h"


std::tuple<matrix,matrix> decomp(matrix A);
colVector solve(matrix Q, matrix R, colVector b);
double det(matrix R);
matrix inverse(matrix A);


#endif
