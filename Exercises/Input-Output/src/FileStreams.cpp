#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

int main (int argc, char *argv[]) {
	
	std::string infile="", outfile="";
	for(int i=0;i<argc;i++){
		std::string arg=argv[i];
		if(arg=="--input" && i+1 < argc) infile=argv[i+1];
		if(arg=="--output" && i+1 < argc) outfile=argv[i+1];
	}


	std::ifstream myinput(infile);
	std::ofstream myoutput(outfile);
	double n;
	
	if( myinput.is_open() && myoutput.is_open() ){
		
		myoutput << "x" << " |  " << "sin(x)" << "       " << "cos(x)" << "\n";
		myoutput << "----------------------------" << "\n";
		while( myinput >> n ){
			myoutput << n <<" | " << std::setw(10) << std::right << std::sin(n) <<"   "<< std::setw(10) << std::right << std::cos(n) << "\n";
			}
		}
	else{
		std::cerr << "Error opening files: " << infile << outfile << std::endl;
		return EXIT_FAILURE;
		}
	myinput.close();
	myoutput.close();
	exit(EXIT_SUCCESS);
}