#include "matrix.h"
#include "vector.h"
#include <cmath>
#include <iostream>
#include <stdexcept>


// Constructor
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    elements = std::vector<std::vector<double>>(rows, std::vector<double>(cols, 0.0));
}
// Constructor
Matrix::Matrix(const std::vector<std::vector<double>>& values) 
{
    rows = values.size();
    cols = values.empty() ? 0.0 : values[0].size();
    elements = values;
}
// Get number of rows
int Matrix::getRows()
{
    return rows;
}
// Get number of columns
int Matrix::getCols()
{
    return cols;
}
// Get the i'th vector column
Vector Matrix::getColumn(int colIndex)
{
    Vector result(this->cols);
    for (int i = 0; i < result.getSize(); i++)
    {
        result[i] = this->elements[i][colIndex];
    }
    return result;
}
// Print matrix
void Matrix::printMatrix()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            printElement(i,j);
            std::cout << " ";
        }
    }
        std::cout << "\n";
}
// Print element of Matrix
void Matrix::printElement(int row, int col)
{
    std::cout << this->elements[row][col];
}
// Matrix addition
Matrix Matrix::operator+(Matrix& other) 
{
    // Check if dimensions are the same
    if (rows != other.rows && cols != other.cols)
    {
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    // Add each element and store it in new matrix "result"
    Matrix result(rows,cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            result.elements[i][j] = elements[i][j] + other.elements[i][j];
        }
    }
    return result;
}
// Matrix subtraction
Matrix Matrix::operator-(Matrix& other)
{
    // Check if dimensions are the same
    if (rows != other.rows && cols != other.cols)
    {
        throw std::invalid_argument("Matrix dimensions do not match");
    }
    // Add each element and store it in new matrix "result"
    Matrix result(rows,cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            result.elements[i][j] = elements[i][j] - other.elements[i][j];
        }
    }
    return result;
}
// Scalar multiplication
Matrix Matrix::operator*(double scalar)
{
    // Multiplies each element with the scalar and store it in new matrix "result"
    Matrix result(rows,cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
        {
            result.elements[i][j] = scalar*elements[i][j];
        }
    }
    return result;
}
// Matrix multiplication
Matrix Matrix::operator*(Matrix& other)
    {
        // Check if dimensions of matricies are correct
        if (this->cols != other.rows)
        {
            throw std::invalid_argument("Matrix dimensions do not match to do matrix multiplication");
        }
        Matrix result(rows,other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int k = 0; k < other.cols; k++) 
            {
                double sum = 0;
                for (int j = 0; j < cols; j++)
                {
                    sum += elements[i][j] * other.elements[j][k];
                }
                
                result.elements[i][k] = sum; // Sum of  rows * cols
            }
        }
        return result;
    }
// Matrix multiplication with a vector
Vector Matrix::operator*(Vector& other)
{
    if (this->cols != other.getSize())
    {
        throw std::invalid_argument("Matrix dimensions do not match to do matrix multiplication");
    }

    Vector result(this->cols);
    for (int i = 0; i < this->cols; i++)
    {
        double sum = 0;
        // ...
    }
}
// Matrix addition
Matrix Matrix::operator+=(Matrix& other)
{
    *this = *this + other;
    return *this;
}
// Matrix subtraction
Matrix Matrix::operator-=(Matrix& other)
{
    *this = *this - other;
    return *this;
}
// Matrix Multiplication
Matrix Matrix::operator*=(Matrix& other)
{
    *this = *this * other;
    return *this;
}
    // Scalar multiplication
Matrix Matrix::operator*=(double scalar) 
{
    *this = *this * scalar;
    return *this;
}
// Transpose
Matrix Matrix::transpose() 
{
    Matrix result(cols,rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) 
        {
            result.elements[j][i] = elements[i][j];
        }
    }
    return result;
}


int main() {
    Matrix A({{1,2},{3,4}});
    A.printMatrix();
    std::cout << A[1][1] << "\n";
}