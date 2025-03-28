#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
class Vector;


class Matrix
{
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> elements;

public:
    // Constructor
    Matrix(int rows, int cols);
    Matrix(const std::vector<std::vector<double>>& values);
    // Getters
    int getRows();
    int getCols();
    Vector getColumn(int columnIndex);


    // print
    void printMatrix();
    void printElement(int row, int col);

    // Operators
    Matrix operator+(Matrix& other);   // Matrix addition
    Matrix operator-(Matrix& other);   // Matrix subtraction

    Matrix operator*(double scalar);         // Scalar multiplication
    Matrix operator*(Matrix& other);   // Matrix multiplication
    Vector operator*(Vector& other);   // Matrix multiplication with a vector

    Matrix operator+=(Matrix& other);  // Matrix addition
    Matrix operator-=(Matrix& other);  // Matrix subtraction

    Matrix operator*=(double scalar);        // Scalar multiplication
    Matrix operator*=(Matrix& other);  // Matrix multiplication

    Matrix transpose();                      // Transpose

    
    class RowProxy {
        public:
            RowProxy(std::vector<double>& row);
            RowProxy(const std::vector<double>& row); // Added constructor for const vectors.
            double& operator[](int col);
            double operator[](int col) const;
        private:
            std::vector<double>& row_;
        };
        // Overloaded operator[] for row access
        RowProxy operator[](int row);

        const RowProxy operator[](int row) const;

        // Helper Function
    private:
        void checkMatrixSize(Matrix &other);

};
#endif