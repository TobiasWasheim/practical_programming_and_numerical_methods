#include"../headers/GenList.h"
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>

int main(){

	genlist<std::vector<double>> list;
	std::string line;
	double x;

	while(std::getline(std::cin,line)){
		std::istringstream iss(line);
		std::vector<double> numbers;
		while(iss >> x) numbers.push_back(x);
		list.add(numbers);
		}

	for(int i=0;i<list.size;i++){
		std::cout << "list[" << std::setw(2) << i << "]=";
		for(double x: list[i])
			std::cout << " " << std::scientific << std::setprecision(4) << x;
		std::cout << "\n";
	}
}