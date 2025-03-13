#include "../Matrix/vector.h"
#include "../Matrix/matrix.h"
#include <tuple>
#include <iostream>
#include <stdexcept>

class QR
{
    public:
    std::vector<Matrix> decomp(Matrix A)
    {
        int n = A.getCols();
        Matrix Q(A.getRows(), n);
        Matrix R(n, n);

        for (int i = 0; i < n; i++) {
            Vector v = A.getColumn(i);
            
            for (int j = 0; j < i; j++) {
                R[j][i] = Q.getColumn(j).dot(A.getColumn(i));
                v -= Q.getColumn(j) * R[j][i];
            }
            R[i][i] = v.norm();
            Vector q = v * (1.0 / R[i][i]); 

            for (int k = 0; k < Q.getRows(); k++) {
                Q[k][i] = q[k];
            }
        }
        std::vector<Matrix> result({Q,R});
        return result;
    }
    Vector solve(Matrix Q, Matrix R, Vector b)
    {
        /*
         Given a system of linear equations Q R x = b
         we can rewrite it R x = Q^T b and back-
         substitution to solve for x
        */

        // We start by calculating Q^T b

        Vector c = Q.transpose() * b;

        // Next, we implement the back-substitution algorithm

        for (int i = c.getSize()-1; i >= 0; i--)
        {
            double sum = 0.0;
            for (int k = i+1; k < c.getSize(); k++)
            {
                sum += R[i][k] * c[k];
            }
            c[i] = (c[i] - sum)/R[i][i];
        }

        return c;

    }
    double det(Matrix R)
    {
        /*
            The determinant can be calculated from the upper right triangle as the
            product of the diagonal of R
        */
        double det = 1;
        for (int i = 0; i < R.getCols(); i++)
        {
            det *= R[i][i];
        }
        return det;
    }
    Matrix inverse(Matrix A)
    {
        int n = A.getCols();
        int m = A.getRows();
        // Check if matrix A is square. else: exception.
        if (n != m) throw std::invalid_argument("Matrix is not a square");
        
        // We start by doing QR-decomposition of A
        std::vector<Matrix> qr_decomp = decomp(A);

        Matrix Q = qr_decomp[0];
        Matrix R = qr_decomp[1];
        
        Matrix result(n,n);
        // We can solve for the inverse by
        for (int i = 0; i < n; i++)
        {
            // we create the unit matrix
            std::vector<double> v(n, 0.0);
            v[i] = 1.0;
                

            // Next, we solve for the ith column of inverse A
            Vector x = solve(Q,R,v);


            // attach the values to the inverse matrix
            for (int j = 0; j < n; j++)
            {
                result[j][i] = x[j];
            }
        }
        return result;
    }
};

int main()
{
    QR qr;
    std::vector<std::vector<double>> matrixValues = 
    {{7.87, 8.52, 9.49, 1.42}, {8.86, 0.93, 4.85, 9.17}, 
    {4.22, 6.56, 8.00, 9.71}, {9.57, 9.16, 6.55, 9.16}}
;

    Matrix A(matrixValues);
    Vector b({8.82, 0.44, 9.68, 6.78});

    std::vector<Matrix> qr_result = qr.decomp(A);
    Matrix Q = qr_result[0];
    Matrix R = qr_result[1];

    Vector x = qr.solve(Q, R, b);

    std::cout << "Q Matrix:" << std::endl;
    Q.printMatrix();

    std::cout << "R Matrix:" << std::endl;
    qr_result[1].printMatrix();
    std::cout << "Q^TQ matrix" << "\n";
    Matrix Q2 = Q.transpose() * Q;
    Q2.printMatrix();
    std::cout << "x" <<"\n";
    x.printVector();
    
    Vector c = Q * R * x;
    c.printVector();
    std::cout << "The determinant" << "\n";
    std::cout << qr.det(R) << "\n";

    Matrix B({{1.0,2.0},{3.0,4.0}});
    Matrix inverse = qr.inverse(B);
    inverse.printMatrix();
}