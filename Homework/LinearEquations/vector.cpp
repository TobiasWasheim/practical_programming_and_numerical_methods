#include "vector.h"
#include "matrix.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
// Constructor
Vector::Vector(int size) : size(size)
{
    this->elements = std::vector<double>(size, 0.0);
}
// Constructor
Vector::Vector(std::vector<double> elements)
{
    this->size = elements.size();
    this->elements = elements;
}
// print vector method
void Vector::printVector()
{
    for (int i = 0; i < this->size; i++)
    {
        printElement(i);
        std::cout << "\n";
    }
}
// print element of vector method
void Vector::printElement(int index)
{
    std::cout << this->elements[index];
}
// get size of vector
double Vector::getSize()
{
    return this->size;
}
// addition operator
Vector Vector::operator+(const Vector& other)
{
    checkVectorSize(other);

    Vector result(this->size);

    for (int i = 0; i < this->size; i++)
    {
        result.elements[i] += this->elements[i] + other.elements[i];
    }
    
    return result;
}
// Subtraction operator
Vector Vector::operator-(const Vector& other)
{
    checkVectorSize(other);

    Vector result(this->size);

    for (int i = 0; i < this->size; i++)
    {
        result.elements[i] += this->elements[i] - other.elements[i];
    }
    
    return result;
}
// Scalar multiplication
Vector Vector::operator*(double scalar)
{
    Vector result(this->size);

    for (int i = 0; i < this->size; i++)
    {
        result.elements[i] += this->elements[i] * scalar;
    }
    return result;
}
// Matrix multiplication with a vector
// Matrix Vector::operator*(Matrix& other)
// {
//     if (this->size != other.getRows()) throw std::invalid_argument("Vector and matrix do not match in size");

//     Matrix result(1,other.getCols());
//     for (int i = 0; i < other.getCols(); i++)
//     {
//         double sum = 0;
//         for (int j = 0; j < this->size; j++)
//         {
//             sum += other[i][j] * elements[j];  
//         }
//         result[0][i] = sum;
//     }
//     return result;
// } 
// Vector addition 
Vector Vector::operator+=(const Vector& other)
{
    *this = *this + other;
    return *this;
}
// Vector subtraction
Vector Vector::operator-=(const Vector& other)
{
    *this = *this - other;
    return *this;
}
// Vector scalar multiplication;
Vector Vector::operator*=(double scalar)
{
    *this = *this * scalar;
    return *this;
}
// Operator for vector[index]
double& Vector::operator[](double index){
    if (index >= size) {
        throw std::out_of_range("Vector index out of bounds");
    }
    return elements[index];
}
// Dot product
double Vector::dot(const Vector& other)
{
    checkVectorSize(other);
    double result = 0;
    for (int i = 0; i < this->size; i++)
    {
        result += this->elements[i] * other.elements[i];
    }
    return result;
}
// Norm
double Vector::norm()
{
    double result = dot(*this);
    return sqrt(result);
}


// Helper Function
void Vector::checkVectorSize(const Vector& other) 
{
    if (this->size != other.size) {
        throw std::invalid_argument("Vectors do not match in size");
    }
}


// Test 
// int main() {
//     std::cout << "Test initializing 0-vector and printing it" << "\n";
//     Vector V(3);
//     V.printVector();

//     std::cout << "Test initializing vector with values and printing it" << "\n";
//     std::vector<double> values = {1.0,4.0,3.0};
//     Vector W(values);
//     W.printVector();
//     std::cout << "Test that I can print the 2nd element (4)" << "\n";
//     W.printElement(1);
//     std::cout << "Test the + operator" << "\n";
//     Vector U = W * 2;
//     U.printVector();
//     std::cout << "----" << "\n";
//     U *= 5;
//     U.printVector();
//     double num = U[1];
//     std::cout << num << "\n";
//     double num2 = U.dot(W);
//     std::cout << num2 << "\n";
//     Vector A({3,4});
//     std::cout << A.norm() << "\n";
// }