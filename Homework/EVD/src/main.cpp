#include"../hdr/EVD.h"
#include<vector>
#include<iostream>
#include<random>

matrix generateRandomSymmetricMatrix() {
    int min = 1;
    int max = 100;
    int range = max - min + 1;
    int n = 5;

     matrix A(n,n);
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j++) {
            double matrixEntry = (rand() % range + min)/10.0;
            A(i,j) = matrixEntry;
            A(j,i) = matrixEntry;
        }
    }
    return A;
}


int main() {
    
    // Generate a random 5x5 symmetrix matrix
    matrix A = generateRandomSymmetricMatrix();

    // Apply the Jacobi diagonalization routine
    std::tuple<matrix,matrix> diagonalAndOrthogonalMatrix = ComputeDiagonalAndOrthogonalMatrix(A);
    
    // Get the diagonal and orthogonal matrix
    matrix diagonalMatrix = std::get<0>(diagonalAndOrthogonalMatrix);
    matrix orthogonalMatrix = std::get<1>(diagonalAndOrthogonalMatrix);
    

    // Compute the matrix product A = V * D * V^T
    matrix VTAV = transpose(orthogonalMatrix) * A * orthogonalMatrix;
    matrix VDVT = orthogonalMatrix * diagonalMatrix * transpose(orthogonalMatrix);
    matrix VTV = transpose(orthogonalMatrix) * orthogonalMatrix;
    matrix VVT = orthogonalMatrix * transpose(orthogonalMatrix);



 std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: EVD - part A" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "In part A we test the implementation of Jacobi diagonalization with cyclic      " << "\n";
    std::cout << "sweeps. We generate a random 5x5 symmetric matrix A which is printed below.     " << "\n";
    std::cout << "\n";
    A.print();
    std::cout << "\n";
    std::cout << "We apply the Jacobi diagonalization routine and generate a diagonal matrix with " << "\n";
    std::cout << "eigenvalues of A and the orthogonal matrix V. These matricies can be seen below."<< "\n";
    std::cout << "\n";
    std::cout << "D =                                                                             " << "\n";
    diagonalMatrix.print();
    std::cout << "\n";
    std::cout << "V =                                                                             " << "\n";
    orthogonalMatrix.print();
    std::cout << "\n";
    std::cout << "To test that we get the correct diagonal and orthogonal matrix, we compute the  " << "\n";
    std::cout << "matrix product V^T * A * V which must be equal to the diagonal matrix D.        " << "\n";
    std::cout << "\n";
    std::cout << "V^T * A * V =                                                                   " << "\n";
    VTAV.print();
    std::cout << "\n";
    std::cout << "We see that his matrix is equal to D. We also test that V * D * V^T = A.        " << "\n";
    std::cout << "\n";
    std::cout << "V * D * V^T =                                                                   " << "\n";
    VDVT.print();
    std::cout << "We can see that this product is exactly equal to A.                             " << "\n";
    std::cout << "To test that the orthogonal matricies are orthogonal we compute V^T * V = I.    " << "\n";
    std::cout << "\n";
    VTV.print();
    std::cout << "\n";
    std::cout << "Which we see is equal to the identity matrix. There might be some numerical     " << "\n";
    std::cout << "errors such that the off-diagonal elements are very small, but not exactly equal" << "\n";
    std::cout << "to zero. Finally, we test that V * V^T = I.                                     " << "\n";
    std::cout << "\n";
    VVT.print();
    std::cout << "\n";
    std::cout << "Here we get the identity matrix. There might also occur some numerical errors   " << "\n";
    std::cout << "like the test above. But we get the correct result by ignoring these errors.    " << "\n\n\n";


    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: EVD - part B" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";
    
    std::cout << "In part B we use our EVD routine on the Hamiltonian obtained from the           " << "\n";
    std::cout << "schrodinger equation for the hydrogen atom. In the plots folder you can see the " << "\n";
    std::cout << "the investigation of convergence for energies w.r.t r_max and Δr. We see that   " << "\n";
    std::cout << "for plots/dr.svg/ that when Δr -> 0 our numerical result converges with our     " << "\n";
    std::cout << "analytical result (that E = 0.5). For plots/rmax.svg/ we see the energy as a    " << "\n";
    std::cout << "function of distance from the nuclei which agrees with our analytical result. We" << "\n";
    std::cout << "have only showcased the analytical result for r = 10. On plots/psi.svg the wave-" << "\n";
    std::cout << "function has been plotted as a function of radius.                              " << "\n";

    return 0;
}