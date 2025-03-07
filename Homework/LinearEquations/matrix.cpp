#include "matrix.h"
#include <cmath>
#include <iostream>
#include <stdexcept>


// Constructors
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    elements = std::vector<std::vector<double>>(rows, std::vector<double>(cols, 0.0));
}
Matrix::Matrix(const std::vector<std::vector<double>>& values) 
{
    rows = values.size();
    cols = values.empty() ? 0 : values[0].size();
    elements = values;
}

// Getters
double Matrix::get(int rows, int cols)
{
    return elements[rows][cols];
}    
int Matrix::getRows()
{
    return rows;
}
int Matrix::getCols()
{
    return cols;
}
Matrix Matrix::getColumn(int colIndex)
{
    Matrix colVector(rows,1);
    for (int i = 0; i < rows; i++)
    {
        colVector.set(elements[i][colIndex],i,0);
    }
    return colVector;
}
double Matrix::getNorm(int colIndex)
{
    double result = 0.0;
    Matrix colVector = getColumn(colIndex);
    for (int i = 0; i < cols; i++)
    {
        result += colVector.get(i,0) * colVector.get(i,0);
    }
    return sqrt(result);
}
// Setters
void Matrix::set(double value, int rows, int cols)
{
    elements[rows][cols] = value;
}

// Print matrix
void Matrix::print()
{
    for (const auto& row : elements) 
    {
        for (double value : row) 
        {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

// Operations
Matrix Matrix::operator+(const Matrix& other) // Addition
{
    // Check if dimensions are the same
    if (rows != other.rows && cols != other.cols)
    {
        throw std::invalid_argument("Matrix dimensions must match for addition");
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
Matrix Matrix::operator-(const Matrix& other) // Subtraction
{
    // Check if dimensions are the same
    if (rows != other.rows && cols != other.cols)
    {
        throw std::invalid_argument("Matrix dimensions must match for subtraction");
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
Matrix Matrix::operator*(const double scalar) // Scalar multiplication
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
Matrix Matrix::operator*(const Matrix& other) // Matrix multiplication
    {
        // Check if dimensions of matricies are correct
        if (cols != other.rows)
        {
            throw std::invalid_argument("Matrix dimensions do not match to do matrix multiplication");
        }
        Matrix result(rows,other.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int k = 0; k < other.cols; k++) 
            {
                int sum = 0;
                for (int j = 0; j < cols; j++)
                {
                    sum += elements[i][j] * other.elements[j][k];
                }
                
                result.elements[i][k] = sum; // Sum of  rows * cols
            }
        }
        return result;
    }
Matrix Matrix::operator*=(double scalar) 
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; i++)
        {
            elements[i][j] *= scalar;
        }
    }
}
Matrix Matrix::transpose()                    // Transpose 
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

    std::vector<std::vector<double>> values = {{1,2,3},{2,5,6},{2,8,9}};

    Matrix B(values);

    std::cout <<B.getNorm(0) << "\n";

}