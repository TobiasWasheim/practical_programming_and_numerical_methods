#include <tuple>
#include <iostream>
#include "matrix.h"


class QR 
{
    std::tuple<Matrix, Matrix, Matrix> decomp(Matrix& A)
    {
        Matrix R(A.getCols(),A.getCols());
        Matrix Q = A;
        for (int i = 0; i < A.getCols(); i++) 
        {
         R.set(Q.getNorm(i),i,i);
         Q.getColumn(i) *= 1/R.get(i,i);
         for (int j = i + 1; j < A.getCols(); i++)
         {
            double value = Q.getColumn(j) * Q.getColumn(i).transpose();
            R.set(val,i,j);
         }
        }
    }

    Matrix solve(const Matrix& Q, const Matrix& R, const Matrix& b);

    double det(const Matrix& R);

    Matrix inverse(const Matrix& Q, Matrix& R);
};

