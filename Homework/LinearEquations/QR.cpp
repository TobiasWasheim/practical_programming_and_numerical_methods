#include<tuple>
#include<iostream>
#include<iostream>
#include<stdexcept>
#include"../Matrix/vector.h"
#include"../Matrix/matrix.h"


std::tuple<Matrix,Matrix> decomp(Matrix A) {
    int m = A.getRows();
    int n = A.getCols();
    Matrix Q(m, n);
    Matrix R(n, n);

    for (int i = 0; i < n; i++) {
        Vector v = A.getColumn(i);
            
        for (int j = 0; j < i; j++) {
            R[j][i] = Q.getColumn(j).dot(A.getColumn(i));
            v -= Q.getColumn(j) * R[j][i];
        }
        R[i][i] = v.norm();
        Vector q = v * (1.0 / R[i][i]); 

        // Update k'th column of Q
        for (int k = 0; k < m; k++) {
            Q[k][i] = q[k];
        }
    }
    return std::make_tuple(Q,R);
}

Vector solve(Matrix Q, Matrix R, Vector b) {
    /*
     Given a system of linear equations Q R x = b
     we can rewrite it R x = Q^T b and back-
     substitution to solve for x
    */

    // We start by calculating Q^T b

    Vector c = Q.transpose() * b;

    // Next, we implement the back-substitution algorithm

    for (int i = c.getSize()-1; i >= 0; i--) {
        double sum = 0.0;
        
        for (int k = i+1; k < c.getSize(); k++) {
            sum += R[i][k] * c[k];
        }
        c[i] = (c[i] - sum)/R[i][i];
    }

    return c;
}

double det(Matrix R) {
    /*
        The determinant can be calculated from the upper right triangle as the
        product of the diagonal of R
    */
    double det = 1;
    for (int i = 0; i < R.getCols(); i++) {
        det *= R[i][i];
    }
    return det;
}

Matrix inverse(Matrix A) {
    int n = A.getCols();
    int m = A.getRows();
    // Check if matrix A is square. else: exception.
    if (n != m) throw std::invalid_argument("Matrix is not a square");
        
    // We start by doing QR-decomposition of A
    std::tuple<Matrix,Matrix> qr_decomp = decomp(A);

    Matrix Q = std::get<0>(qr_decomp);
    Matrix R = std::get<1>(qr_decomp);
        
    Matrix result(n,n);
    // We can solve for the inverse by
    for (int i = 0; i < n; i++) {
        // we create the unit matrix
        std::vector<double> v(n, 0.0);
        v[i] = 1.0;

        // Next, we solve for the ith column of inverse A
        Vector x = solve(Q,R,v);

        // attach the values to the inverse matrix
        for (int j = 0; j < n; j++) {
            result[j][i] = x[j];
        }
    }
    return result;
}
