#include "vector.h"
#include "matrix.h"
#include <cassert>
#include <iostream>

class testVector
{
public:
    void ShouldHaveSize3()
    {
        // Given a vector with dimension 3
        Vector V({1,2,3});
        // Then it is asserted that it should have dimension 3
        assert(V.getSize() == 3);
        std::cout << "Test: shouldHaveSize3 passed" << "\n";
    }
    void shouldBeAbleToAccessElement()
    {
        // Given a vector with dimension 3
        Vector V({1,2,3});
        // Then it is asserted that it should return 2 for it's 1st element
        assert(V[1] == 2);
        std::cout << "Test: shouldBeAbleToAccessElement passed" << "\n";
    }
    void shouldHaveDotProduct()
    {
        // Given two vectos
        Vector V({1,2,3});
        Vector W({4,5,6});
        // When taking the dot product between the two vectors
        double dotProduct = V.dot(W);
        // Then the dot product should be equal to 1*4+2*5+3*6 = 32s
        assert(dotProduct == 1*4+2*5+3*6);
        std::cout << "Test: shouldHaveDotProduct passed" << "\n";
    }
    void shouldHaveNorm()
    {
        // Given a vector
        Vector V({3,4});
        // When taking the norm of V
        double norm = V.norm();
        // Then the norm product should be sqrt(3^2+4^2) = 5
        assert(norm == 5);
        std::cout << "Test: shouldHaveNorm passed" << "\n";
    }
    void shouldBeAbleToAddTwoVectors()
    {  
        // Given two vectors
        Vector V({1,2});
        Vector U({4,8});
        // When adding V and U 
        Vector W = V + U;
        // Then the output should be V({5,10})
        assert(W[0] == 5);
        assert(W[1] == 10);
        std::cout << "Test: shouldBeAbleToAddTwoVectors passed" << "\n";
    }
    void shouldBeAbleToSubtractTwoVectors()
    {
        // Given two vectors
        Vector V({1,2});
        Vector U({4,8});
        // When adding V and U 
        Vector W = U - V;
        // Then the output should be T({3,6})
        assert(W[0] == 3);
        assert(W[1] == 6);
        std::cout << "Test: shouldBeAbleToSubtractTwoVectors passed" << "\n";
    }
    void shouldBeAbleToDoScalarMultiplicationForVector()
    {
        // Given a vector and scalar
        Vector V({1,2});
        double scalar = 5;
        // When doing scalar multiplication
        Vector U = V * scalar;
        // Then the output should be T({5,10})
        assert(U[0] == 5);
        assert(U[1] == 10);
        std::cout << "Test: shouldBeAbleToDoScalarMultiplicationForVector passed" << "\n";
    }
    void shouldBeAbleToDoMatrixMultiplication()
    {
        // Given a vector and matrix
        Vector V({2,5});
        Matrix M({{1,2},{3,4}});
        // When doing matrix multiplication
        Matrix N = V * M;
        // Then the result should be a row Matrix M({{12},{26}})
        assert(N[0][0] == 12);
        assert(N[0][1] == 26);
        std::cout << "Test: shouldBeAbleToDoMatrixMultiplication passed" << "\n";
    }
};


int main() {
    testVector test;
    test.ShouldHaveSize3();
    test.shouldBeAbleToAccessElement();
    test.shouldHaveDotProduct();
    test.shouldHaveNorm();
    test.shouldBeAbleToAddTwoVectors();
    test.shouldBeAbleToSubtractTwoVectors();
    test.shouldBeAbleToDoScalarMultiplicationForVector();
    test.shouldBeAbleToDoMatrixMultiplication();
}