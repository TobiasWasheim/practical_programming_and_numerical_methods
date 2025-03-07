#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include<stdexcept>

class Matrix
{
protected:
    int rows;
    int cols;
    std::vector<std::vector<double>> elements;

public:
    // Constructors
    Matrix(int rows, int cols);
    Matrix(const std::vector<std::vector<double>>& values);

    // Getters
    double get(int rows, int cols);
    int getRows();
    int getCols();
    Matrix getColumn(int columnIndex);
    double getNorm(int columnIndex);

    // Setters
    void set(double value, int rows, int cols);

    // print
    void print();

    // Operators
    Matrix operator+(const Matrix& other);   // Matrix addition
    Matrix operator-(const Matrix& other);   // Matrix subtraction
    Matrix operator*(double scalar);         // Scalar multiplication
    Matrix operator*(const Matrix& other);   // Matrix multiplication
    Matrix operator*=(double scalar);
    Matrix transpose();                            // Transpose
};

#endif