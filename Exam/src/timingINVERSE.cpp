#include <iostream>
#include <tuple>
#include <cstdlib>

#include "../hdr/InverseIteration.h"


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

    std::cout << "Timing with N = " << N << "\n"; // Debugging output

    matrix M(N, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double num = (std::rand() % 101) / 10.0;
            M(i,j) = num;
            M(j,i) = num;
        }
    }

    std::tuple<double,colVector> qr = InverseAlgorithm(M,1,colVector(), 1e-3);
    std::cout << "V[0] = " << std::get<1>(qr)[0] << std::endl; // Access an element to force usage
    return 0;
}