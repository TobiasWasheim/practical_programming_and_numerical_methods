#include<cmath>
#include<iostream>
#include<iostream>

#include"../../QR/hdr/QR.h"
#include"../hdr/OLS.h"

/* 
Ordinary Least Squares Fit using QR-decomposition 

Returns vector of coefficients ck and covariance matrix
*/
std::tuple<colVector,matrix> lsfit(std::function<double(double)> fs[], colVector x, colVector y, colVector dy, int size) {
    
    int N = x.size(); // Size of dataset
    
    matrix A(N, size);
    colVector b(N);

    for (int i = 0; i < N; i++) {
        b[i] = y[i]/dy[i];
        for (int k = 0; k < size; k++) {
            A(i,k) = fs[k](x[i])/dy[i];
        }
    }
    
    // Solves least square problem using QR-composition
    std::tuple<matrix,matrix> qr_decomp = decomp(A);
    
    matrix Q = std::get<0>(qr_decomp);
    matrix R = std::get<1>(qr_decomp);

    // We calculate the corvariance matrix

    matrix covariance = inverse(transpose(A) * A);
    
    return std::make_tuple(solve(Q,R,b),covariance);
}