#include"../Matrix/matrix.h"
#include "EVD.h"
#include<cmath>
#include<vector>
#include<cstdlib>
#include<iostream>
int main() {
    
    int size = 9;
    
    Matrix M(size,size);


    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            double random = (rand() % 101)/100.0;
            
            M[i][j] = random;
            M[j][i] = random;
        }
    }
                                            
    //Matrix A(std::vector<std::vector<double>> {{10,5,5,5,10},{5,2,2,2,5},{5,2,2,2,5},{5,2,2,2,5},{10,5,5,5,10}});

    M.printMatrix();

    cyclic(M);

    M.printMatrix();    
    

    
}