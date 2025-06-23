#include<iostream>

#include"InverseIteration.h"
#include"../Homework/EVD/hdr/EVD.h"

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

matrix randomMatrix(int size) {
    matrix A(size,size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double num = (rand() % 101) / 10.0;
            A(i,j) = num;
            A(j,i) = num;
        }
    }
    return A;
}

int main() {

    // Part A

    // We create a random 5x5 matrix and calculate eigenvalue and compare it to using our EVD routine


    matrix A = randomMatrix(5);
    
    std::tuple<double, colVector> iterationMethod = InverseAlgorithm(A,20);

    double eigenValue = std::get<0>(iterationMethod);

    std::cout << "Eigenvalue from iteration method = "<< eigenValue << "\n";

    std::cout << "Jacobian method routine: " << "\n";

    std::tuple<matrix,matrix> EVD = ComputeDiagonalAndOrthogonalMatrix(A);   

    matrix D = std::get<0>(EVD);
    D.print();

    std::cout << "Hamiltonian Energy eigenvalue" << "\n";

    // In part B we determine the energy-eigenvalue from the schrodinger equation

    std::tuple<matrix,colVector, int> BuildHamiltonian = BuildHamiltonianMatrix(10,0.1);

    matrix H = std::get<0>(BuildHamiltonian);

    std::tuple<double, colVector> partB = InverseAlgorithm(H,-1);

    double E = std::get<0>(partB);

    std::cout << E << "\n";


    // In part C we compare the complexity of the iterative method and the EVD method. 
    


    return 0;
}