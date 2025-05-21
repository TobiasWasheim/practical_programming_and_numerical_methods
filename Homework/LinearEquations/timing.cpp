#include <iostream>
#include <tuple>
#include "QR.h"
#include "../../Matrix/matrix.h"
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " -size:N" << std::endl;
        return 1;
    }

    int N;
    if (sscanf(argv[1], "-size:%d", &N) != 1) {
        std::cerr << "Invalid argument: " << argv[1] << std::endl;
        return 1;
    }

    std::cout << "Timing with N = " << N << std::endl; // Debugging output

    matrix M(N, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            M(i,j) = std::rand() % 50;
        }
    }

    std::tuple<matrix, matrix> qr = decomp(M);
    std::cout << "Q(0,0) = " << std::get<0>(qr)(0, 0) << std::endl; // Access an element to force usage
    return 0;
}