#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double n {};
    std::cout << "x" << " |  " << "sin(x)" << "       " << "cos(x)" << "\n";
    std::cout << "----------------------------" << "\n";
    
    while (std:: cin >> n) {
        std::cout << n <<" | " << std::setw(10) << std::right << std::sin(n) <<"   "<< std::setw(10) << std::right << std::cos(n) << "\n";
    }
}