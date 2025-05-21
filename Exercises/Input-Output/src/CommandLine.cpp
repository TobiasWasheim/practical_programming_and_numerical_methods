#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

int main (int argc, char* argv[]) {
	std::vector<double> numbers;
	for(int i=0;i<argc;++i){
		std::string arg=argv[i];
		if(arg=="-n" && i+1<argc)
			numbers.push_back(std::stod(argv[i+1]));
	}
	std::cout << "x" << " |  " << "sin(x)" << "       " << "cos(x)" << "\n";
    std::cout << "----------------------------" << "\n";
    for(auto n: numbers)
        std::cout << n <<" | " << std::setw(10) << std::right << std::sin(n) <<"   "<< std::setw(10) << std::right << std::cos(n) << "\n";
}  