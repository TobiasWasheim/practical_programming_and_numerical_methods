#include "../vector.h"
#include "../matrix.h"
#include <cassert>
#include <iostream>

class testMatrix
{
    void shouldGet3Rows()
    {
        // Given a 3x5 matrix
        Matrix M(3,5);
        // Then it should have 3 rows
        assert(M.getRows() == 3);
        std::cout << "Test: shouldGet3Rows passed" << "\n";
    }
    void shouldGet5Cols()
    {
        // Given a 3x5 matrix
        Matrix M(3,5);
        // Then it should have 5 columns
        assert(M.getCols() == 5);
        std::cout << "Test: shouldGet5Cols passed" << "\n";
    }
    void shouldGetAVectorForAColumn()
    {
        // Given a matrix
        Matrix M({{1,2},{3,4}});
        // When taking the 0th column
        Vector V = M.getColumn(0);
        // Then the vector should be V({1,2})
        assert(V[0] == 1);
        assert(V[1] == 2);
        std::cout << "Test: shouldGetAVectorForAColumn passed" << "\n";
    }
    void shouldBeAbleToGetASpecificElement()
    {

    }
    void shouldBeAbleToAddTwoMatricies()
    {

    }
    void shouldBeAbleToSubtractTwoMatricies()
    {

    }
    void shouldBeAbleToDoScalarMultiplication()
    {

    }
    void shouldBeAbleToDoMatrixMultiplication()
    {

    }
    void shouldBeAbleToDoMatrixMultiplicationWithVector()
    {

    }
    void shouldBeAbleTotranspose()
    {

    }
};