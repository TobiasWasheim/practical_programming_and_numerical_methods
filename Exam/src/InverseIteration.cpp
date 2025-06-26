#include"../hdr/InverseIteration.h"
#include"../../Homework/QR/hdr/QR.h"

colVector randomVector(int size) {
    colVector x(size);

    for (int i = 0; i < size; i++) {
        double num = (std::rand() % 101) / 10.0;
        x[i] = num;
    }
    return x;
}

double rayLeighQuotient(colVector x0, colVector x1) {
    
    assert(x0.size() == x1.size());

    double eigenValue = dot(x1,x0) / (dot(x1,x1));

    return eigenValue;
}

std::tuple<double,colVector> InverseAlgorithm(matrix A, double s, colVector x0, double acc) {

    if (x0.isNull()) x0 = randomVector(A.cols());

    double lambda0, lambda1;

    matrix sI = s * id(A.cols());
    std::tuple<matrix, matrix> QR = decomp(A - sI);

    matrix Q = std::get<0>(QR);
    matrix R = std::get<1>(QR);
    colVector x1 = solve(Q,R,x0);

    lambda1 = s + rayLeighQuotient(x0,x1);

    while(true) {
        x0 = x1;
        x1 = solve(Q,R,x0);
        lambda0 = lambda1;
        lambda1 = s + rayLeighQuotient(x0,x1);
        if (std::abs(lambda1 - lambda0) < acc) break;
    }

    // Normalize x1 before returning
    x1 = x1 / norm(x1);

    return std::make_tuple(lambda1, x1);
}