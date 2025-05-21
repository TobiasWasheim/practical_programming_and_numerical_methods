#include <tuple>
#include <iostream>
#include<random>
#include<string>
#include"QR.h"
#include "../../Matrix/matrix.h"

matrix generateRandomMatrix(int rows, int cols) {
    // We generate a random m x n matrix
    matrix A(rows,cols);
    int min = 10; 
    int max = 101;
    // Now we generate the elements of the matrix. each entry has a double that ranges from 1.0 to 10.0.
    int range = max - min + 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A(i,j) = (std::rand() % range + min) / 10.0;
        }
    }
    return A;
}

colVector generateRandomVector(int size) {
    // we generate a random 1xn vector
    colVector b(size);

    int min = 10; 
    int max = 100;
    // Now we generate the elements of the vector. each entry has a double that ranges from 1.0 to 10.0.
    int range = max - min + 1;
    for (int i = 0; i < size; i++) {
        b[i] = (std::rand() % range + min) / 10.0;
    }
    return b;
}


int main()
{
    std::string testStatus1 = "";
    std::string testStatus2 = "";
    std::string testStatus3 = "";
    std::string testStatus4 = "";
    
    // We generate a random tall matrix (n > m)
    int m = 7 + std::rand() % 10;
    int n = 1 + std::rand() % 5;
    matrix A = generateRandomMatrix(m,n);

    // Factorize A = QR and get the components Q and R. 
    std::tuple<matrix,matrix> qr = decomp(A);
    matrix R = std::get<1>(qr);
    matrix Q = std::get<0>(qr);

    // check that R is upper triangle
    testStatus1 = "true";
    for (int i = 0; i < R.rows(); i++) {
        for (int j = 0; j < i; j++) {
            if (R(i,j) > 1e-4) {
                testStatus1 = "false";
            }
        }
    }
    
    // Check that the product Q^T * T is equal to the identity matrix
    matrix I = transpose(Q) * Q;
    
    if (compare(id(I.cols()),I)) {
        testStatus2 = "true";
    } else {
        testStatus2 = "false";
    }

    // Check if QR = A
    matrix A_new = Q * R;
  
    if (compare(A,A_new)) {
        testStatus3 = "true";
    } else {
        testStatus3 = "false";
    }



    // Solve equation A x = b
    // generate a square matrix
    matrix M = generateRandomMatrix(10,10);
    
    // generate a random vector b
    colVector b = generateRandomVector(10);

    // do QR factorization
    std::tuple<matrix,matrix> M_qr = decomp(M);
    matrix M_R = std::get<1>(M_qr);
    matrix M_Q = std::get<0>(M_qr);

    // solve A x = b
    colVector x = solve(M_Q,M_R,b);
    
    // test if M * x = b
    if (compare(b,M * x)) {
        testStatus4 = "true";
    } else {
        testStatus4 = "false";
    }

  



    
    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: Linear Equations - part A" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part A we check that the methods decomp(matrix A) and solve(matrix Q, matrix R, colVector b) works as intended." << "\n";
    // Decomp method tests
    std::cout << "To check that the method decomp(matrix A) works we do as following" << "\n";
    std::cout << "  - generate a random tall mxn matrix A where m > n.";
    std::cout << "  - check that R is upper triangular" << "\n";
    std::cout << "  - check that Q^T * Q = I" << "\n";
    std::cout << "  - check that Q * R = A" << "\n\n";

    std::cout << "Test: R is upper triangular   - status: " << testStatus1 << "\n";
    std::cout << "Test: That I = Q^T * Q        - status: " << testStatus2 << "\n";
    std::cout << "Test: That A = Q * R          - status: " << testStatus3 << "\n\n\n";

    // solve method tests
    std::cout << "To check that the method solve(matrix Q, matrix R, colVector b) works as intended we do the following:" << "\n";
    std::cout << "  - generate a random 10x10 square matrix A" << "\n";
    std::cout << "  - generate a random 1x10 column vector b" << "\n";
    std::cout << "  - factorize A into QR" << "\n";
    std::cout << "  - solve QRx = b" << "\n";
    std::cout << "  - check that Ax = b" << "\n\n";

    std::cout << "Test: check that Ax = b       - status: " << testStatus4 <<"\n\n";
}