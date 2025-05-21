#ifndef QR_H
#define QR_H

#include"../../Matrix/matrix.h"
#include<tuple>






void timesJ(matrix& A, int p, int q, double theta);
void Jtimes(matrix& A, int p, int q, double theta);
std::tuple<colVector,matrix> cyclic(matrix M);
std::tuple<matrix,matrix> ComputeDiagonalAndOrthogonalMatrix(matrix A);
#endif