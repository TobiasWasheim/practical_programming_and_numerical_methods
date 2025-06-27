#include <iostream>
#include <complex>

bool approx(double a, double b, double acc=1e-9, double eps=1e-9) {
    if (std::abs(a-b) <= acc) return 1;
    if (std::abs(a-b) <= std::max(std::abs(a),std::abs(b)*eps)) return 1;
    return 0;
}


int main() {
    std::cout << "If you comparisons are true we represent it as '1' and if false it is '0'." << "\n\n";
    
    // Calculating different complex numbers

    // Sqrt(-1): 
    std::complex<int> x(-1,0);


    std::cout << "Square root of  -1 = " << std::sqrt(x).real() << " + "
              << std::sqrt(x).imag() << "i" <<  "\n";

    std::cout << "Sqrt(-1) compared with our approx function: " << approx(sqrt(x).imag(),1) << "\n";
    
    
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
