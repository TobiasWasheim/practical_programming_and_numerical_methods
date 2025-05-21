#include"matrix.h"
#include<vector>
#include<cassert>
#include<cmath>
#include<stdio.h>
#include<iostream>
int testCounter()
{
    static int count = -1;
    count++;
    return count;
}
int testCounterSuccess() {

    static int countSucess = -1;
    countSucess++;
    return countSucess;
}
void printTestMessage() {
    printf("\n");
    printf("%d/%d tests ran successfully.\n",testCounterSuccess(), testCounter());
}



/*          Vector class        */

void testCreationOfVector() {
    
    testCounter();

    vector v({1,2,3});
    vector u = {4,5,6};
    vector w(2);

    assert(v[0] == 1);
    assert(v[1] == 2);
    assert(v[2] == 3);
    assert(u[0] == 4);
    assert(u[1] == 5);
    assert(u[2] == 6);

    assert(w[0] == 0);
    assert(w[1] == 0);

    printf("Test: Creation of vector - success.\n");
    testCounterSuccess();
}

/*      rowVector class         */

void testAdditionOfRowVector() {
    testCounter();

    rowVector v = {1,2};
    rowVector u = {4,6};

    rowVector w = v + u;

    assert(w[0] == 1 + 4);
    assert(w[1] == 2 + 6);

    printf("Test: Addition of row vectors - success.\n");
    testCounterSuccess();
}

void testSubtractionOfRowVectors() {
    testCounter();

    rowVector v = {1,2};
    rowVector u = {4,6};

    rowVector w = v - u;

    assert(w[0] == 1 - 4);
    assert(w[1] == 2 - 6);

    printf("Test: Addition of row vectors - success.\n");
    testCounterSuccess();
}

void testDivisionOfRowVectors() {
    testCounter();
    
    rowVector v = {2,4};
    double num = 2;

    rowVector w = v/num;

    assert(w[0] == 1);
    assert(w[1] == 2);

    printf("Test: Addition of row vectors - success.\n");
    testCounterSuccess();
}


/*      colVector class         */
void testAdditionOfColVector() {
    testCounter();

    colVector v = {1,2};
    colVector u = {4,6};

    colVector w = v + u;

    assert(w[0] == 1 + 4);
    assert(w[1] == 2 + 6);

    printf("Test: Addition of col vectors - success.\n");
    testCounterSuccess();
}

void testSubtractionOfColVectors() {
    testCounter();

    colVector v = {1,2};
    colVector u = {4,6};

    colVector w = v - u;

    assert(w[0] == 1 - 4);
    assert(w[1] == 2 - 6);

    printf("Test: Addition of col vectors - success.\n");
    testCounterSuccess();
}

void testDivisionOfColVectors() {
    testCounter();
    
    colVector v = {2,4};
    double num = 2;

    colVector w = v/num;

    assert(w[0] == 1);
    assert(w[1] == 2);

    printf("Test: Addition of col vectors - success.\n");
    testCounterSuccess();
}

/*      matrix class      */

void testCreationOfMatrix() {
    testCounter();
    matrix A(2,2);
    matrix B({colVector{1,2},colVector({3,4})});

    assert(A.cols() == 2);
    assert(A.rows() == 2);

    assert(B.cols() == 2);
    assert(B.rows() == 2);

    assert(A(0,0) == 0);
    assert(A(0,1) == 0);
    
    assert(A(1,0) == 0);
    assert(A(1,1) == 0);

    assert(B(0,0) == 1);
    assert(B(1,0) == 2);
    assert(B(0,1) == 3);
    assert(B(1,1) == 4);

    printf("Test: Creation of matrix with values and as default- success.\n");
    testCounterSuccess();
}

void testAdditionOfMatricies() {
    testCounter();

    matrix A = {colVector{1,2},colVector{3,4}};
    matrix B = {colVector{6,6}, colVector{-10,0}};

    matrix C = A + B;

    assert(C(0,0) == 7);
    assert(C(0,1) == -7);
    assert(C(1,0) == 8);
    assert(C(1,1) == 4);

    printf("Test: Addition of matricies - success.\n");
    testCounterSuccess();

}

void testSubtractionOfMatricies() {
    testCounter();

    matrix A = {colVector{1,2},colVector{3,4}};
    matrix B = {colVector{6,6}, colVector{-10,0}};

    matrix C = A - B;

    assert(C(0,0) == 1 - 6);
    assert(C(0,1) == 3 - (-10));
    assert(C(1,0) == 2 - 6);
    assert(C(1,1) == 4 - 0);

    printf("Test: Subtraction of matricies - success.\n");
    testCounterSuccess();
}

void testMatrixProduct() {
    testCounter();

    matrix A = {colVector{1,3},colVector{2,4}};

    matrix B = {colVector{1,2},colVector{3,1}};

    matrix product = A * B;
    
    assert(product(0,0) == 1*1 + 2 * 2);
    assert(product(0,1) == 1 * 3 + 2 * 1);
    assert(product(1,0) == 3 * 1 + 4 * 2);
    assert(product(1,1) == 3 * 3 + 4 * 1);

    printf("Test: Matrix product - sucess.\n");
    testCounterSuccess();
}

void testMatrixDivision() {
    testCounter();

    matrix A = {colVector{2,6},colVector{4,12}};

    matrix B = A/2;
    
    assert(B(0,0) == 1);
    assert(B(0,1) == 2);
    assert(B(1,0) == 3);
    assert(B(1,1) == 6);

    printf("Test: Division of a matrix and a number - sucess.\n");
    testCounterSuccess();
}

/*      other matrix and vector method tests        */

void testVectorMatrixProduct() {
    testCounter();

    rowVector v = {1,2,3};
    colVector u = {4, 7, 8};

    double dotproduct = v * u;

    assert(dotproduct == 1 * 4 + 2 * 7 + 3 * 8);

    printf("Test: matrix product for vectors - success.\n");
    testCounterSuccess();
}

void testOuterProduct() {
    testCounter();

    rowVector v = {1,2};
    colVector u = {4,5};

    matrix outerProduct = u * v;
    
    assert(outerProduct(0,0) == 4);
    assert(outerProduct(0,1) == 5);
    assert(outerProduct(1,0) == 8);
    assert(outerProduct(1,1) == 10);

    printf("Test: Outer product - success.\n");
    testCounterSuccess();
}

void testDotProduct() {
    testCounter();
    colVector c1 = {1,2};
    colVector c2 = {4,8};

    rowVector r1 = {1,2};
    rowVector r2 = {4,8};

    double colDotProduct = dot(c1, c2);
    assert(colDotProduct == 20);

    double rowDotProduct = dot(r1, r2);
    assert(rowDotProduct == 20);

    printf("Test: Dot product - success.\n");
    testCounterSuccess();
}

void testColVectoscalarMultiplication() {
    testCounter();
    colVector v = {1,2};

    colVector u = 3 * v;
    colVector w = v * 4;

    assert(u[0] == 3);
    assert(u[1] == 6);

    assert(w[0] == 4);
    assert(w[1] == 8);

    printf("Test: colVector scalar multiplication - success.\n");
    testCounterSuccess();
}

void testrowVectoscalarMultiplication() {
    testCounter();
    rowVector v = {1,2};

    rowVector u = 3 * v;
    rowVector w = v * 4;

    assert(u[0] == 3);
    assert(u[1] == 6);

    assert(w[0] == 4);
    assert(w[1] == 8);

    printf("Test: colVector scalar multiplication - success.\n");
    testCounterSuccess();
}

void testTransposeVector() {
    testCounter();

    colVector v = {1,2};
    rowVector u = {3,4};

    rowVector v2 = transpose(v);
    colVector u2 = transpose(u);

    assert(typeid(v2) == typeid(u));
    assert(v2[0] == v[0]);
    assert(v2[1] == v[1]);

    assert(typeid(u2) == typeid(v));
    assert(u2[0] == u[0]);
    assert(u2[1] == u[1]);

    printf("Test: Transpose of vector - success.\n");
    testCounterSuccess();
}

void testNormOfVector() {
    testCounter();
    colVector v = {10,0};
    rowVector u = {3,4};

    double colNorm = norm(v);
    double rowNorm = norm(u);

    assert(colNorm == 10);
    assert(rowNorm == 5);

    printf("Test: norm of vector - success.\n");
    testCounterSuccess();
}

void testMatrixScalarMultiplication() {
    testCounter(); 

    matrix A = {colVector{1,2},colVector{3,4}};

    matrix A1 = A * 4;
    matrix A2 = 3 * A;

    assert(A1(0,0) == 4);
    assert(A1(1,0) == 8);
    assert(A1(0,1) == 12);
    assert(A1(1,1) == 16);

    assert(A2(0,0) == 3);
    assert(A2(1,0) == 6);
    assert(A2(0,1) == 9);
    assert(A2(1,1) == 12);

    printf("Test: Matrix scalar multiplication - success.\n");
    testCounterSuccess();
}

void testMatrixMultiplicationWithColVector() {
    testCounter();

    matrix A = {colVector{1,3}, colVector{2,4}};
    colVector x = {3,5};

    colVector b = A * x;

    assert(b[0] == 13);
    assert(b[1] == 9 + 4 * 5);

    printf("Test: Matrix multiplication with a col vector - success.\n");
    testCounterSuccess();
}

void testMatrixMultiplicationWithRowVector() {
    testCounter();

    matrix A = {colVector{1,3}, colVector{2,4}};
    rowVector x = {3,5};

    rowVector b = x * A;

    assert(b[0] == 3 + 5 * 3);
    assert(b[1] == 3 * 2 + 4 * 5);

    printf("Test: Matrix multiplication with a row vector - success.\n");
    testCounterSuccess();
}

void testMatrixComparison() {
    testCounter();
    matrix A =  {colVector{1,3},colVector{2,4}};
    matrix B =  {colVector{1,3},colVector{2,4}};
    matrix C = {colVector{1,3},colVector{2,5}};

    bool compareAtoB = compare(A,B);
    bool compareAtoC = compare(A,C);

    assert(compareAtoB == true);
    assert(compareAtoC == false);
    printf("Test: Matrix comparison - success.\n");
    testCounterSuccess();
}
int main() {

    


    /*      vector class tests      */
    testCreationOfVector();

    /*      rowVector class tests   */
    testAdditionOfRowVector();
    testSubtractionOfRowVectors();
    testDivisionOfRowVectors();

    /*      colVector class tests   */
    testAdditionOfColVector();
    testSubtractionOfColVectors();
    testDivisionOfColVectors();

    /*      matrix class tests      */
    testCreationOfMatrix();
    testAdditionOfMatricies();
    testSubtractionOfMatricies();
    testMatrixProduct();
    testMatrixDivision();

    /*      other matrix and vector method tests    */
    testVectorMatrixProduct();
    testOuterProduct();
    testDotProduct();
    testColVectoscalarMultiplication();
    testrowVectoscalarMultiplication();
    testTransposeVector();
    testNormOfVector();
    testMatrixScalarMultiplication();
    testMatrixMultiplicationWithColVector();
    testMatrixMultiplicationWithRowVector();
    testMatrixComparison();







    printTestMessage();

    
    
}