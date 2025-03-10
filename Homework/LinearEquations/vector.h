#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
class Matrix;

class Vector 
{
private:
    int size;
    std::vector<double> elements;

public:
    // Constructors
    Vector(int size);
    Vector(std::vector<double> elements);

    // Print 
    void printVector();
    void printElement(int index);

    // Get size of vector
    double getSize();

    // Operators
    Vector operator+(const Vector& other);   // Vector addition
    Vector operator-(const Vector& other);   // Vector subtraction

    Vector operator*(double scalar);         // Scalar multiplication
    //Matrix operator*(Matrix& other);   // Matrix multiplication with a vector

    Vector operator+=(const Vector& other);
    Vector operator-=(const Vector& other);

    Vector operator*=(double scalar);

    double& operator[](double index);

    // dot product
    double dot(const Vector& other);
    
    // Norm
    double norm();

private:
    void checkVectorSize(const Vector& other);

};
#endif