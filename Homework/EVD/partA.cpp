#include"EVD.h"
#include<vector>
#include<iostream>
#include<random>

matrix generateRandomSymmetricMatrix() {
    int min = 5;
    int max = 20;
    int range = max - min + 1;
    int n = rand() % range + min;

     matrix A(n,n);
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            min = 1;
            max = 100;
            range = max - min + 1;
            double matrixEntry = (rand() % range + min)/10.0;
            A(i,j) = matrixEntry;
            A(j,i) = matrixEntry;
        }
    }
    return A;
}


int main() {
    
    // Generate a random integer between 5 and 20.
    matrix A = generateRandomSymmetricMatrix();

    // Apply the Jacobi diagonalization routine
    std::tuple<matrix,matrix> diagonalAndOrthogonalMatrix = ComputeDiagonalAndOrthogonalMatrix(A);
    
    // Get the diagonal and orthogonal matrix
    matrix diagonalMatrix = std::get<0>(diagonalAndOrthogonalMatrix);
    matrix orthogonalMatrix = std::get<1>(diagonalAndOrthogonalMatrix);
    

    // Compute the matrix product A = V * D * V^T
    matrix matrixDDecomp = transpose(orthogonalMatrix) * A * orthogonalMatrix;
    matrix matrixADecomp = orthogonalMatrix * diagonalMatrix * transpose(orthogonalMatrix);
    matrix VTV = transpose(orthogonalMatrix) * orthogonalMatrix;
    matrix VVT = orthogonalMatrix * transpose(orthogonalMatrix);



    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: Eigenvalue Decomposition - part A" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part A we test the implementation of Jacobi diagonalization with cyclic sweeps." << "\n\n";

    std::cout << "We generate a random nxn symmetric matrix A which is printed below." << "\n";
    A.print();
    std::cout << "\n\n";


    std::cout << "Next, we apply the Jacobi diagonalization routine and generate a diagonal matrix with eigenvalues of A and the orthogonal matrix V." << "\n";
    std::cout << "Test: D == V^T * A * V: ";

    if (compare(diagonalMatrix,matrixDDecomp)) {
        std::cout << "true" << "\n";
    } else {
        std::cout << "false" << "\n";
    }

    std::cout << "Test: A == V * D * V^T: ";

    if (compare(A,matrixADecomp)) {
        std::cout << "true" << "\n";
    } else {
        std::cout << "false" << "\n";
    }

    std::cout << "Test: I == V^T * V:     ";
    
    if (compare(VTV,id(VTV.cols()))) {
        std::cout << "true" << "\n";
    } else {
        std::cout << "false" << "\n";
    }

    std::cout << "Test: I == V * V^T:     ";

    if (compare(VVT,id(VVT.cols()))) {
        std::cout << "true" << "\n";
    } else {
        std::cout << "false" << "\n";
    }
    // std::cout << "\n";
    // std::cout << "For reference, the diagonal matrix is" << "\n";
    // diagonalMatrix.print();

    // std::cout << "\n\n";
    // std::cout << "The orthogonal matrix is" << "\n";
    // orthogonalMatrix.print();

    return 0;
}