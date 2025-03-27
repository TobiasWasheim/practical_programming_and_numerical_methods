#include <tuple>
#include <iostream>
#include<random>
#include "../Matrix/vector.h"
#include "../Matrix/matrix.h"
#include "QR.h"


int main()
{
    // Tests for part A

    // We generate a random tall matrix (n > m)
    int m = std::rand() % 5;
    int n = 5 + std::rand() % 10;

    Matrix A(n,m);

    // Now we generate the elements of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = std::rand() % 50;
        }
    }
    std::cout << "Print matrix A " << "\n";
    A.printMatrix();
    std::cout << "\n";


    std::cout << "\n";
    // Factorize A = QR
    std::tuple<Matrix,Matrix> qr = decomp(A);
    // Check that R is upper triangle
    Matrix R = std::get<1>(qr);
    std::cout << "Matrix R" << "\n";
    R.printMatrix();
    std::cout << "\n";

    // Check if Q^T Q = I
    Matrix Q = std::get<0>(qr);
    Matrix I = Q.transpose() * Q;

    std::cout << "Print matrix I = Q^T * Q" << "\n";
    I.printMatrix();
    std::cout << "\n";

    // Check if QR = A
    Matrix A_new = Q * R;
    std::cout << "Print matrix A = Q*R" << "\n";
    A_new.printMatrix();
    std::cout << "\n";

    // Tests for part B
    // Generate a random square matrix
    Matrix C(n,n);
    // Generate elements for matrix C
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = std::rand() % 50;
        }
    }
    // Now we calculate the inverse of C
    Matrix Cinv = inverse(C);
    
    Matrix Prod = Cinv * C;

    std::cout << "Print product C^-1*C = 1" << "\n";

    Prod.printMatrix();
}