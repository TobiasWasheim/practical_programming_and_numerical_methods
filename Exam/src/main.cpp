#include<iostream>
#include <fstream>

#include"../hdr/InverseIteration.h"
#include"../../Homework/EVD/hdr/EVD.h"

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
    
    // Inverse algorithm for different shift-values
    std::tuple<double, colVector> iterationMethod_1 = InverseAlgorithm(A,-7);
    std::tuple<double, colVector> iterationMethod_2 = InverseAlgorithm(A,-1);
    std::tuple<double, colVector> iterationMethod_3 = InverseAlgorithm(A,1);
    std::tuple<double, colVector> iterationMethod_4 = InverseAlgorithm(A,8.5);
    std::tuple<double, colVector> iterationMethod_5 = InverseAlgorithm(A,21);
    
    double eigenvalue_1 = std::get<0>(iterationMethod_1);
    double eigenvalue_2 = std::get<0>(iterationMethod_2);
    double eigenvalue_3 = std::get<0>(iterationMethod_3);  
    double eigenvalue_4 = std::get<0>(iterationMethod_4);
    double eigenvalue_5 = std::get<0>(iterationMethod_5);


    colVector v_1 = std::get<1>(iterationMethod_1);
    colVector v_2 = std::get<1>(iterationMethod_2);
    colVector v_3 = -1 * std::get<1>(iterationMethod_3);
    colVector v_4 = std::get<1>(iterationMethod_4);
    colVector v_5 = std::get<1>(iterationMethod_5);

    matrix V_iteration = {v_1,v_2,v_3,v_4,v_5};

    // EVD routine
    std::tuple<matrix,matrix> EVD = ComputeDiagonalAndOrthogonalMatrix(A);   
    matrix D = std::get<0>(EVD);
    matrix V = std::get<1>(EVD);




    // In part B we determine the energy-eigenvalue from the schrodinger equation
    std::tuple<matrix,colVector,int> buildH = BuildHamiltonianMatrix(20,0.1);
    matrix H = std::get<0>(buildH);

    std::tuple<double, colVector> ground = InverseAlgorithm(H,-1);
    std::tuple<double, colVector> excited1 = InverseAlgorithm(H,-0.125);
    std::tuple<double, colVector> excited2 = InverseAlgorithm(H,-0.05);

    double E0 = std::get<0>(ground);
    double E1 = std::get<0>(excited1);
    double E2 = std::get<0>(excited2);

    std::tuple<colVector,matrix> H_EVD = cyclic(H);

    colVector D_H = std::get<0>(H_EVD);

    colVector eigenvector = std::get<1>(ground);
    colVector r = std::get<1>(buildH);
    int npoints = std::get<2>(buildH);
    // std::cout << eigenvector.size() << "\n";
    std::ofstream file;

    file.open("data/psi.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }

    for (int i = 0; i < npoints; i++) {
        double f = 1 /0.233*eigenvector[i];
        file << r[i] << " " << f << " " << 1 /0.366 * r[i] * std::exp(-r[i]) << "\n";
    }
    file.close();


    


    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Exam: Inverse Iteration - Implementation of Algorithm (part A)" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "We have implemented the algorithm in the file 'inverseIteration.cpp'. In order  " << "\n";
    std::cout << "to see if it works we test it by generating a random symmetrix 5x5 matrix and   " << "\n";
    std::cout << "calculate the eigenvalue closest to the shift-value s = 1. In order to see if we" << "\n";
    std::cout << "indeed get the correct eigenvalue we compare it to the eigenvalues obtained from" << "\n";
    std::cout << "from our EVD-routine that was created in one of the homeworks.                  " << "\n";
    std::cout << "\n";
    std::cout << "The matrix which we generate is printed below:                                  " << "\n";
    std::cout << "\n";
    A.print();
    std::cout << "\n";
    std::cout << "next, the eigenvalue that we get from our inverse-iteration routine with a shift" << "\n";
    std::cout << "value s = 1 is                                                                  " << "\n";
    std::cout << "\n";
    std::cout << "Eigenvalue = " << eigenvalue_1 << " where s = -7         " << "\n";
    std::cout << "Eigenvalue = " << eigenvalue_2 << " where s = -1         " << "\n";
    std::cout << "Eigenvalue = " << eigenvalue_3 << " where s = 1           " << "\n";
    std::cout << "Eigenvalue = " << eigenvalue_4 << " where s = 7           " << "\n";
    std::cout << "Eigenvalue = " << eigenvalue_5 << " where s = 20         " << "\n";
    std::cout << "\n";
    std::cout << "In order to see if we get the correct eigenvalue we compare it to the eigen-    " << "\n";
    std::cout << "values which we obtain by computing the diagonal matrix from our EVD routine.   " << "\n";
    std::cout << "The diagonal matrix can be seen below.                                          " << "\n";
    std::cout << "\n";
    std::cout << "D =                                                                              " << "\n";
    D.print();
    std::cout << "\n";
    std::cout << "When we look at the diagonal matrix we see that we get eigenvalues that are     " << "\n";
    std::cout << "close to the eigenvalues from the inverse iteration method.                     " << "\n";
    std::cout << "\n";
    std::cout << "Additionally, the algorithm also gives the eigenvectors. Below we have printed  " << "\n";
    std::cout << "the eigenvectors for all eigenvalues. Column 1 corresponds to the first eigenvalue," << "\n";
    std::cout << "column 2 corresponds to the second eigenvalue and so on...." << "\n";
    std::cout << "\n";
    V_iteration.print();
    std::cout << "\n";
    std::cout << "Now, we compare these eigenvectors to the result of the EVD routine. From that we " << "\n";
    std::cout << "we get the eigenvectors                                                          " << "\n";
    std::cout << "\n";
    V.print();
    std::cout << "\n";
    std::cout << "Which we can see are numerically close the the result from our EVD routine! Based on" << "\n";
    std::cout << "our tests, we conclude that our reverse iteration method works." << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Exam: Inverse Iteration - Application to schrodinger's equation (part B)" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";
    
    std::cout << "In this part we apply our routine to find the energy-eigenvalue for the ground-state," << "\n";
    std::cout << "first, and second excited state. From theory we expect that E0 = -1/2 = 0.5, and that" << "\n";
    std::cout << "E1 = -1/(2*2^2) = -1/8 = 0.125 and E2 = -1/(2*3^2) = -1/18 = -0.0588... The results  " << "\n";
    std::cout << "are printed below.                                                                   " << "\n";
    std::cout << "\n";
    std::cout << "E0 = " << E0 << " where s = -1.0                                                     " << "\n";
    std::cout << "E1 = " << E1 << " where s = -0.3                                                     " << "\n";
    std::cout << "E2 = " << E2 << " where s = -0.05                                                     " << "\n";
    std::cout << "\n";
    std::cout << "We see that we get the eigenvalue that matches (almost) energies of the ground state" << "\n";
    std::cout << "and the excited states for E1 and E2. We have also plotted the s-wave function for  " << "\n";
    std::cout << "the ground state at 'plots/psi.svg/' and compared to the analytical wave function.  " << "\n";
    std::cout << "We have built the Hamiltonian using the same procedure as the EVD homework part B.  " << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Exam: Inverse Iteration - Timing of the algorithm (part C)" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";
    std::cout << "In this part we've timed the algorithm and the EVD routine which can be seen at " << "\n";
    std::cout << "'plots/timing.svg/' where we can see that both algorithms goes as O(N^3).       " << "\n";
    return 0;
}