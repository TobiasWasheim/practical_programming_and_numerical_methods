#include<functional>
#include<cmath>
#include<iostream>
#include<tuple>
#include<iostream>
#include"../LinearEquations/QR.h"
#include"OLSFit.h"

/* 
Ordinary Least Squares Fit using QR-decomposition 

Returns vector of coefficients ck
*/
std::tuple<colVector,matrix> lsfit(std::function<double(double)> fs[], colVector x, colVector y, colVector dy, int size) {
    
    int N = x.size(); // Size of dataset
    
    matrix A(N, size);
    colVector b(N);

    for (int i = 0; i < N; i++) {
        b[i] = y[i]/dy[i];
        //std::cout << "test, i = " << i << "\n";
        for (int k = 0; k < size; k++) {
            A(i,k) = fs[k](x[i])/dy[i];
            //std::cout << "i,k =" << i << ", " << k << "\n";
        }
    }
    
    // Solves least square problem using QR-composition
    std::tuple<matrix,matrix> qr_decomp = decomp(A);

    matrix Q = std::get<0>(qr_decomp);
    matrix R = std::get<1>(qr_decomp);

    // We calculate the corvariance matrix

    matrix coVar = inverse(transpose(A) * A);
    
    return std::make_tuple(solve(Q,R,b),coVar);
}