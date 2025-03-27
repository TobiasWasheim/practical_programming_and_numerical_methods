#include<functional>
#include<cmath>
#include<iostream>
#include<tuple>
#include"../Matrix/vector.h"
#include"../LinearEquations/QR.h"
#include"OLSFit.h"

/* 
Ordinary Least Squares Fit using QR-decomposition 

Returns vector of coefficients ck
*/
Vector lsfit(std::function<double(double)> fs[], Vector x, Vector y, Vector dy, int size) {
    
    int N = x.getSize(); // Size of dataset
    
    Matrix A(N, size);
    Vector b(N);

    for (int i = 0; i < N; i++) {
        b[i] = y[i]/dy[i];
        //std::cout << "test, i = " << i << "\n";
        for (int k = 0; k < size; k++) {
            A[i][k] = fs[k](x[i])/dy[i];
            //std::cout << "i,k =" << i << ", " << k << "\n";
        }
    }
    
    // Solves least square problem using QR-composition
    std::tuple<Matrix,Matrix> qr_decomp = decomp(A);

    Matrix Q = std::get<0>(qr_decomp);
    Matrix R = std::get<1>(qr_decomp);
    
    return solve(Q,R,b);
}