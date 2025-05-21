#include<iostream>
#include<string>
#include"QR.h"

int main() {
    
    std::string testStatus = "";
    // Generate a random square matrix
    int n = 10;
    matrix A(n,n);
    // Generate elements for matrix A - each element has a value between 1.0 and 10.0. 
    int min = 1;
    int max = 100;
    int range = max - min + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A(i,j) = (std::rand() % range + min)/10.0;
        }
    }
    // Now we calculate the inverse of C
    matrix B = inverse(A);
    
    matrix I = A * B;

    if (compare(I,id(I.cols()))) {
        testStatus = "true";
    } else {
        testStatus = "false";
    }
    

    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: Linear Equations - part B" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part B we check that the method inverse(matrix A) for a square matrix works. We do the following:" << "\n";
    std::cout << "  - Generate a random 10x10 square matrix A" << "\n";
    std::cout << "  - Factorize A into QR" << "\n";
    std::cout << "  - Calculate the inverse A^-1 = B" << "\n";
    std::cout << "  - Check that A * B = I" << "\n\n";

    std::cout << "Test: R is upper triangular   - status: " << testStatus  << "\n";
    return 0;
}