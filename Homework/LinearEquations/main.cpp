#include <tuple>
#include <iostream>
#include <stdexcept>
#include "../Matrix/vector.h"
#include "../Matrix/matrix.h"
#include "QR.h"


int main()
{
    std::vector<std::vector<double>> matrixValues = {   {1,2,3},
                                                        {4,5,6},
                                                        {7,8,9},
                                                        {1,2,3},
                                                        {4,5,6},
                                                        {7,8,9},
                                                        {1,2,3},
                                                        {4,5,6},
                                                        {7,8,9}};

    Matrix A(matrixValues);
    Vector b({8.82, 0.44, 9.68, 6.78});

    std::tuple<Matrix,Matrix> qr_result = decomp(A);
    Matrix Q = std::get<0>(qr_result);
    Matrix R = std::get<1>(qr_result);

    Q.printMatrix();
    std::cout << "\n\n";
    R.printMatrix();
}