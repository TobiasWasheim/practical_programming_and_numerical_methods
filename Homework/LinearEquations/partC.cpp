#include<iostream>

int main() {

    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: Linear Equations - part C" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part C we measure the time it takes to QR factorize a NxN matrix and show that it is proportional to O(N^3)." << "\n";
    std::cout << "To do so we have plotted the QR factorization for NxN matricies. Here we can see that at log(N) = 5, log(Time) = -3" << "\n";
    std::cout << "and at log(N) = 6, log(Time) = 0. So we can estimate that the slope of log(Time) = a * log(N) is a = 3. Therefor it" << "\n";
    std::cout << "goes as O(N^3)." << "\n";
}