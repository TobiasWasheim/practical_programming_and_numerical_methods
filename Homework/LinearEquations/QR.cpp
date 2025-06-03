#include"../../Matrix/matrix.h"
#include<tuple>
#include<iostream>
#include<iostream>
#include<stdexcept>



std::tuple<matrix,matrix> decomp(matrix A) {
    int n = A.cols();
    matrix Q = A;
    matrix R(n, n);

    for (int i = 0; i < n; i++) {
        R(i,i) = norm(Q.col(i));
        Q.col(i) = Q.col(i)/R(i,i);
        for (int j = i + 1; j < n; j++) {
            R(i,j) = dot(Q.col(i),Q.col(j));
            Q.col(j) = Q.col(j) - Q.col(i) * R(i,j);
        }  
    }
    return std::make_tuple(Q,R);
}

colVector solve(matrix Q, matrix R, colVector b) {
    /*
     Given a system of linear equations Q R x = b
     we can rewrite it R x = Q^T b and back-
     substitution to solve for x
    */

    // We start by calculating Q^T b

    colVector c = transpose(Q) * b;

    // Next, we implement the back-substitution algorithm

    for (int i = c.size()-1; i >= 0; i--) {
        double sum = 0.0;
        
        for (int k = i+1; k < c.size(); k++) {
            sum += R(i,k) * c[k];
        }
        c[i] = (c[i] - sum)/R(i,i);
    }

    return c;
}

double det(matrix R) {
    /*
        The determinant can be calculated from the upper right triangle as the
        product of the diagonal of R
    */
    double det = 1;
    for (int i = 0; i < R.cols(); i++) {
        det *= R(i,i);
    }
    return det;
}

matrix inverse(matrix A) {
    int n = A.cols();
    int m = A.rows();
    // Check if matrix A is square. else: exception.
    if (n != m) throw std::invalid_argument("Matrix is not a square");
        
    // We start by doing QR-decomposition of A
    std::tuple<matrix,matrix> qr_decomp = decomp(A);

    matrix Q = std::get<0>(qr_decomp);
    matrix R = std::get<1>(qr_decomp);
        
    matrix result(n,n);
    // We can solve for the inverse by
    for (int i = 0; i < n; i++) {
        // we create the unit matrix
        std::vector<double> v(n, 0.0);
        v[i] = 1.0;

        // Next, we solve for the ith column of inverse A
        colVector x = solve(Q,R,v);

        // attach the values to the inverse matrix
        for (int j = 0; j < n; j++) {
            result(j,i) = x[j];
        }
    }
    return result;
}
