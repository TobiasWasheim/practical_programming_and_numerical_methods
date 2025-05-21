#include<iostream>
#include"EVD.h"

std::tuple<matrix,colVector,int> BuildHamiltonianMatrix(double rmax, double dr) {
    int npoints = (int)(rmax/dr)-1;
    colVector r(npoints);
    for(int i=0;i<npoints;i++) {
        r[i]=dr*(i+1);
    }
    
    matrix H(npoints,npoints);

    for(int i=0;i<npoints-1;i++){
        H(i,i)  =-2*(-0.5/dr/dr);
        H(i,i+1)= 1*(-0.5/dr/dr);
        H(i+1,i)= 1*(-0.5/dr/dr);
    }
    H(npoints-1,npoints-1) = -2*(-0.5/dr/dr);
    
    for(int i=0;i<npoints;i++) {
        H(i,i)+=-1/r[i];
    }
    return std::make_tuple(H,r,npoints);
}

int main() {

    
    

    // part B (1) - convergence of dr -> 0. What happens to the ground state energy?
    for (double dr = 1/16.0; dr < 1; dr += 1.0/32.0) {
        std::tuple<matrix,colVector,double> buildHamiltonian = BuildHamiltonianMatrix(10.0,dr);
        matrix Hamiltonian = std::get<0>(buildHamiltonian);
        // Diagonalize the Hamiltonian to obtain eigenvalues and eigenvectors
        std::tuple<matrix,matrix> diagonalizeH = ComputeDiagonalAndOrthogonalMatrix(Hamiltonian);

        matrix diagonalMatrix = std::get<0>(diagonalizeH);
        matrix orthogonalMatrix = std::get<1>(diagonalizeH);

        std::cout << dr << " " <<diagonalMatrix(0,0) << "\n";
        }
    std::cout << "\n";

    // part B (2) - change of rmax from 1 (0.1 Bohr radii) to 10 (1 Bohr radii)
    for (double r = 2.0; r < 10; r += 0.5) {
        std::tuple<matrix,colVector,double> buildHamiltonian = BuildHamiltonianMatrix(r,0.1);
        matrix Hamiltonian = std::get<0>(buildHamiltonian);
        // Diagonalize the Hamiltonian to obtain eigenvalues and eigenvectors
        std::tuple<matrix,matrix> diagonalizeH = ComputeDiagonalAndOrthogonalMatrix(Hamiltonian);

        matrix diagonalMatrix = std::get<0>(diagonalizeH);
        matrix orthogonalMatrix = std::get<1>(diagonalizeH);

        std::cout << r   << " " <<diagonalMatrix(0,0) <<"\n";
        
        }
    std::cout << "\n";
    
    // part B (3) - plotting the wave function and Bohr radius 
    std::tuple<matrix,colVector,double> buildHamiltonian = BuildHamiltonianMatrix(10.0,0.1);
    matrix Hamiltonian = std::get<0>(buildHamiltonian);
    colVector r = std::get<1>(buildHamiltonian);
    int npoints = std::get<2>(buildHamiltonian);

    std::tuple<matrix,matrix> diagonalizeH = ComputeDiagonalAndOrthogonalMatrix(Hamiltonian);

    
    matrix orthogonalMatrix = std::get<1>(diagonalizeH);
    for (int i = 0; i < npoints; i++) {
        std::cout << r[i] << " " << orthogonalMatrix(i,0) << "\n";
    }


}