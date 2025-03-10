#include "vector.h"
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
};


int main() {
    testVector test;
    test.ShouldHaveSize3();
    test.shouldBeAbleToAccessElement();
    test.shouldHaveDotProduct();
    test.shouldHaveNorm();
}