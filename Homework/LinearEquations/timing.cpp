#include <iostream>
#include <tuple>
#include "QR.h"
#include "../Matrix/matrix.h"
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " -size:N" << std::endl;
        return 1;
    }

    int N = 0;
    if (sscanf(argv[1], "-size:%d", &N) != 1) {
        std::cerr << "Invalid argument: " << argv[1] << std::endl;
        return 1;
    }

    std::cout << "Timing with N = " << N << std::endl; // Debugging output

    Matrix M(N, N);
    std::tuple<Matrix, Matrix> qr = decomp(M);

    return 0;
}