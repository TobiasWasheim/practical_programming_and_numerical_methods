#include <iostream>
#include <complex>


int main() {
    // Calculating different complex numbers
    std::complex<int> x(-1,0);
    std::cout << "Square root of  -1 = " << std::sqrt(x).real() << " + "
              << std::sqrt(x).imag() << "i" <<  "\n";
    
    
    std::cout << "Square root of   i = " << std::sqrt(std::complex<double>(0,1)).real() 
              << " + "<< std::sqrt(std::complex<double>(0,1)).imag() << "i" <<  "\n";
    
    
    std::cout << "               e^i = " << std::exp(std::complex<double>(0,1)).real() 
              << " + "<< std::exp(std::complex<double>(0,1)).imag() << "i" <<  "\n";


    std::cout << "             e^ipi = " << std::exp(std::complex<double>(0,1)*M_PI).real() 
              << " + " << std::exp(std::complex<double>(0,1)*M_PI).imag() << "i\n";

    std::cout << "               i^i = " 
              << std::pow(std::complex<double>(0,1),std::complex<double>(0,1)).real() << " + " 
              << std::pow(std::complex<double>(0,1),std::complex<double>(0,1)).imag() 
              << "i\n";

    std::cout << "             ln(i) = " << std::log(std::complex<double>(0,1)).real() << " + "
              << std::log(std::complex<double>(0,1)).imag() << "i" << "\n";
    
    std::cout << "          sin(ipi) = " << std::sin(std::complex<double>(0,1)*M_PI).real() << " + "
              << std::sin(std::complex<double>(0,1)*M_PI).imag() << "i" << "\n";
}  
