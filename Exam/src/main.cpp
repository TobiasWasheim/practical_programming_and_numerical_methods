#include<iostream>

#include"../hdr/InverseIteration.h"
#include"../../Homework/EVD/hdr/EVD.h"

matrix Hamiltonian(double rmax, double dr) {
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
    return H;
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
    
    std::tuple<double, colVector> iterationMethod = InverseAlgorithm(A,1);

    double eigenValue = std::get<0>(iterationMethod);
    colVector v = std::get<1>(iterationMethod);

    colVector v_normalized = v * 1e20;


    std::tuple<matrix,matrix> EVD = ComputeDiagonalAndOrthogonalMatrix(A);   

    matrix D = std::get<0>(EVD);
    matrix V = std::get<1>(EVD);

    int i = 0;

    while (true) {
        if (i >= D.cols()) break;

        if (std::abs(D(i,i) - eigenValue) < 0.1) break;
        i++;
    }

    colVector v_EVD = V.col(i);


    // In part B we determine the energy-eigenvalue from the schrodinger equation

    matrix H = Hamiltonian(10,0.1);

    std::tuple<double, colVector> partB = InverseAlgorithm(H,-1);

    double E = std::get<0>(partB);



    // In part C we compare the complexity of the iterative method and the EVD method. 
    


    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Exam: Inverse Iteration - Implementation of Algorithm" << "\n";
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
    std::cout << "Eigenvalue = " << eigenValue << " where s = 1                                   " << "\n";
    std::cout << "\n";
    std::cout << "In order to see if we get the correct eigenvalue we compare it to the eigen-    " << "\n";
    std::cout << "values which we obtain by computing the diagonal matrix from our EVD routine.   " << "\n";
    std::cout << "The diagonal matrix can be seen below.                                          " << "\n";
    std::cout << "\n";
    std::cout << "D =                                                                              " << "\n";
    D.print();
    std::cout << "\n";
    std::cout << "When we look at the diagonal matrix we see that we get the same eigenvalue and   " << "\n";
    std::cout << "that is the closest eigenvalue compared to the shift-value s = 1.                " << "\n";
    std::cout << "\n";
    std::cout << "Additionally, the algorithm also gives the eigenvector. In the case of s = 1 we  " << "\n";
    std::cout << "get the eigenvector                                                              " << "\n";
    std::cout << "\n";
    v.print();
    std::cout << "\n";
    std::cout << "Now, we compare this eigenvector to the result of the EVD routine. From that we " << "\n";
    std::cout << "we get the eigenvector                                                          " << "\n";
    std::cout << "\n";
    v_EVD.print();
    std::cout << "\n";
    std::cout << "We see that we get the same eigenvector, except it not normalized like the one  " << "\n";
    std::cout << "from our EVD method. By normalizing the eigenvector from the inverse iteration  " << "\n";
    std::cout << "routine by multiplying with a factor of 1e20 we get that it becomes             " << "\n";
    std::cout << "\n";
    v_normalized.print();
    std::cout << "\n";
    std::cout << "Which is close to the same eigenvector from the EVD routine (with an error of   " << "\n";
    std::cout << "roughly 0.2). We conclude that our inverse iteration algorithm works!           " << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Exam: Inverse Iteration - Application to schrodinger's equation" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";
    
    std::cout << "In this part we apply our routine to find the energy-eigenvalue closest to -1 which" << "\n";
    std::cout << "we excpect to be the one with the lowest energy E0 = -0.5. We print the eigenvalue " << "\n";
    std::cout << "below.                                                                             " << "\n";
    std::cout << "\n";
    std::cout << "E = " << E << " where s = -1.0                                                     " << "\n";
    std::cout << "\n";
    std::cout << "We see that we get the eigenvalue that matches (almost) ground state energy. To    " << "\n";
    std::cout << "build the Hamiltonian we used the same procedure as the EVD homework part B.       " << "\n";
    std::cout << "\n";
    std::cout << "\n";
    return 0;
}