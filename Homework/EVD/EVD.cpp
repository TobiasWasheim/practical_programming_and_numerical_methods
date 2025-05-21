#include<cmath>
#include"../../Matrix/matrix.h"
#include<stdexcept>
#include"EVD.h"




void timesJ(matrix& A, int p, int q, double theta) {
    double c = cos(theta);
    double s = sin(theta);

    for (int i = 0; i < A.rows(); i ++) {
        double aip = A(i,p);
        double aiq = A(i,q);

        A(i,p) = c * aip - s * aiq;
        A(i,q) = s * aip + c * aiq;
    }
}

void Jtimes(matrix& A, int p, int q, double theta) {
    double c = cos(theta);
    double s = sin(theta);

    for (int i = 0; i < A.rows(); i++) {
        double api = A(p,i);
        double aqi = A(q,i);

        A(p,i) = c * api + s * aqi;
        A(q,i) = -s* api + c * aqi;
    }
}

std::tuple<colVector,matrix> cyclic(matrix A) {

    int m = A.rows();
    int n = A.cols();

    colVector W(n);
    matrix V = id(n);

    try {
        if (n != m) {
            throw new std::invalid_argument("Matrix the same dimension");
        }
    } catch(int num) {

    }

    // Make a copy of matricies

    bool changed;
    do {
        changed=false;
        for(int p=0;p<n-1;p++) {
            for(int q=p+1;q<n;q++){
                double apq=A(p,q), app=A(p,p), aqq=A(q,q);
                double theta=0.5*std::atan2(2*apq,aqq-app);
                double c=std::cos(theta), s=std::sin(theta);
                double new_app=c*c*app-2*s*c*apq+s*s*aqq;
                double new_aqq=s*s*app+2*s*c*apq+c*c*aqq;
      
                if(new_app != app && new_aqq != aqq) {
                    changed=true;
                    timesJ(A,p,q, theta); // A←A*J 
                    Jtimes(A,p,q, -theta); // A←JT*A 
                    timesJ(V,p,q, theta);
                }
            }
        }
    }while(changed);

    

    for (int i = 0; i < n; i++) {
        W[i] = A(i,i);
    }
    return std::make_tuple(W,V);
}

std::tuple<matrix,matrix> ComputeDiagonalAndOrthogonalMatrix(matrix A) {
    
    std::tuple<colVector,matrix> cyclicM = cyclic(A);
    colVector eigenvalues = std::get<0>(cyclicM);
    matrix eigenvectors = std::get<1>(cyclicM);

    int eigenvaluesVectorSize = eigenvalues.size();
    matrix diagonalMatrix(eigenvaluesVectorSize,eigenvaluesVectorSize);
    for (int i = 0; i < eigenvaluesVectorSize; i++) {
        diagonalMatrix(i,i) = eigenvalues[i];
    }

    return std::make_tuple(diagonalMatrix,eigenvectors);

 }
