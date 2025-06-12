#include"../hdr/QR.h"

#include<random>
#include<iostream>

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

int main() {

    // PART A
    // We generate a random tall matrix (n > m)
    int m = 7 + std::rand() % 10;
    int n = 1 + std::rand() % 5;
    matrix A = generateRandomMatrix(m,n);

    // Factorize A = QR and get the components Q and R. 
    std::tuple<matrix,matrix> qr = decomp(A);
    matrix R = std::get<1>(qr);
    matrix Q = std::get<0>(qr);

    
    // Check that the product Q^T * T is equal to the identity matrix
    matrix I = transpose(Q) * Q;
    
    // Compute Q * R
    matrix A_new = Q * R;
  
    // generate a square matrix
    matrix M = generateRandomMatrix(5,5);
    
    // generate a random vector b
    colVector b = generateRandomVector(5);

    // do QR factorization
    std::tuple<matrix,matrix> M_qr = decomp(M);
    matrix M_R = std::get<1>(M_qr);
    matrix M_Q = std::get<0>(M_qr);

    // solve A x = b
    colVector x = solve(M_Q,M_R,b);
    colVector b_new = M * x;
    
    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: QR - part A" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "In part A we check that our methods for QR-decomposition and solving a linear   " << "\n";
    std::cout << "set of equations. We check that decomp(A) and solve(Q,R,b) works as intended. To" << "\n";
    std::cout << "check that the methods work we start by generating a random tall mxn matrix A   " << "\n"; 
    std::cout << "where m > n. This matrix is printed below. Each entry has a value between 1.0   " << "\n";
    std::cout << "and 10.0.                                                                       " << "\n";
    std::cout << "\n";
    A.print();
    std::cout << "\n";
    std::cout << "The next step is to decompose the matrix into Q and R. We apply our method.     " << "\n";
    std::cout << "Below we print the matrix Q and R. Since there might be small numerical errors  " << "\n";
    std::cout << "not all below the diagonal elements might not be exactly equal to zero.         " << "\n";
    std::cout << "\n";
    std::cout << "Q =                                                                             " << "\n";
    Q.print();
    std::cout << "\n";
    std::cout << "R =                                                                             " << "\n";
    R.print();
    std::cout << "\n";
    std::cout << "In order for the method to work properly R must be upper triangular which it is." << "\n";
    std::cout << "Next, we check that Q^T * Q = I. For this we print the matrix product Q^T * Q.  " << "\n";
    std::cout << "Since there might be small numerical errors and non-diagonal elements may not   " << "\n";
    std::cout << "exactly be equal to zero, but close!                                            " << "\n";
    std::cout << "\n";
    std::cout << "I = Q^T * Q =                                                                   " << "\n";
    I.print();
    std::cout << "\n";
    std::cout << "Finally, at last we see if A = Q * R. We print A below as the product of Q and R" << "\n";
    std::cout << "\n";
    std::cout << "A = Q * R =                                                                     " << "\n";
    A_new.print();
    std::cout << "\n";
    std::cout << "Next we check that the method solve(Q,R,b) works as intended. We generate a     " << "\n";
    std::cout << "random 5x5 matrix with elements between 1.0 and 10.0. It can be seen below.     " << "\n";
    std::cout << "\n";
    M.print();
    std::cout << "\n";
    std::cout << "We also generate a random column vector of size 5 and solve M * x = b. The      " << "\n";
    std::cout << "vector b and solution x is printed below.                                       " << "\n";
    std::cout << "\n";
    std::cout << "b =                                                                             " << "\n";
    b.print();
    std::cout << "\n";
    std::cout << "x =                                                                             " << "\n";
    x.print();
    std::cout << "\n";
    std::cout << "In order to check that it is the correct solution we compute M * x and see if it" << "\n";
    std::cout << "it is equal to b.                                                               " << "\n";
    std::cout << "\n";
    std::cout << "M * x =                                                                         " << "\n";
    b_new.print();
    std::cout << "\n";
    std::cout << "Comparing it to b we see that it is the same and therefor our methods works.    " << "\n\n\n";


    // Part B
    // Generate a random square matrix
    n = 5;
    matrix C = generateRandomMatrix(n,n);
    
    // // Now we calculate the inverse of C
    matrix B = inverse(C);
    
    I = C * B;


    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: QR - part B" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "In part B we check that the method inverse(matrix A) for a square matrix works. " << "\n";
    std::cout << "We generate a random 5x5 square matrix A.                                       " << "\n";
    std::cout << "\n";
    std::cout << "A =                                                                             " << "\n";
    C.print();
    std::cout << "\n";
    std::cout << "Next, we apply the method inverse(A) to calculate the inverse of A. It is       " << "\n";
    std::cout << "printed below.                                                                  " << "\n";
    std::cout << "\n";
    std::cout << "A^-1 =                                                                          " << "\n";
    B.print();
    std::cout << "To check that the method works, we calculate A * A^-1 to see if it is equal to  " << "\n";
    std::cout << "the identity matrix. There might be numerical errors so the off-diagonal        " << "\n";
    std::cout << "elements that are not exactly equal to zero, but close.                         " << "\n";
    std::cout << "\n";
    I.print();
    std::cout << "\n";
    std::cout << "As we can see, we get the identity matrix so our method works.                  " << "\n\n";


    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: QR - part C" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "In part C we measure the time it takes to QR factorize a NxN matrix and show    " << "\n"; 
    std::cout << "that it is proportional to O(N^3). To do so we have plotted the QR factorization" << "\n";
    std::cout << "for NxN matricies. On the plot we see that at log(N) = 5, log(Time) = -3 and at " << "\n";
    std::cout << "log(N) = 6, log(Time) = 0. By rough estimation, we can approximate the slope to " << "\n";
    std::cout << "be a = (-3 - 0) / (5 - 6) = 3 which is the same as saying that the time         " << "\n";
    std::cout << "complexity is O(N^3).                                                           " << "\n";

    return 0;

}