#include <iostream>
#include <cmath>
#include <limits>
#include "Machine-Epsilon.h"

double machineEpsilonDouble() {
    
    double epsilon = 1.0;
    while(true){
	    double onepe = 1.0+epsilon;
	    if(onepe == 1.0) break;
	    // std::cout << epsilon << " " << 1+epsilon << "\n";
        	epsilon /= 2.0;
    }
    return epsilon*2;
}

float machineEpsilonFloat() {
    
    float epsilon = 1.0f;
    float previous = 1.0f;
    while ((1.0f+epsilon) != 1.0f) {
        previous = epsilon;
        epsilon /= 2.0f;
    }

    return epsilon*2.0f;
}

bool approx(double a, double b, double acc, double eps) {
    if (std::abs(a-b) <= acc) return 1;
    if (std::abs(a-b) <= std::max(std::abs(a),std::abs(b)*eps)) return 1;
    return 0;
}

void printPart2() {
    double epsilonDouble = machineEpsilonDouble();
    float epsilonfloat = machineEpsilonFloat();

    std::cout << "Part 2: The Machine Epsilon" << "\n";
    std::cout << "Machine epsilon for double-precision: " << epsilonDouble << "\n";
    std::cout << "Machine epsilon for double-precision (correct): " << std::numeric_limits<double>::epsilon() << "\n";
    std::cout << "Machine epsilon for float-precision:  " << epsilonfloat << "\n" ;
    std::cout << "Machine epsilon for float-precision (correct): " << std::numeric_limits<float>::epsilon() << "\n\n";
    // Comparisons
    double tiny = epsilonDouble/2.0;
    double a = 1.0 + tiny + tiny;
    double b = tiny + tiny + 1.0;

    bool equal = a == b;
    bool aGreaterThan1 = a > 1.0;
    bool bGreaterThan1 = b > 1.0;

    std::cout << "Part 3:" << "\n";
    std::cout << "a == b ? " << equal << "\n";
    std::cout << "a > 1 ?  " << aGreaterThan1 << "\n";
    std::cout << "b > 1 ?  " << bGreaterThan1 << "\n" << "\n";

    std::cout << "Explanation:" << "\n";
    std::cout << "Since epsilon is the smallest representation of the value between 1.0 and the next. So" << "\n";
    std::cout << "when we define tiny as epsilon/2, the program sees tiny as equal to zero." << "\n" << "\n";
}

void printPart3() {
    double tiny = machineEpsilonDouble()/2.0;
    double a = 1 + tiny + tiny;
    double b = tiny + tiny + 1.0;

    bool equal = a == b;
    bool aGreaterThan1 = a > 1.0;
    bool bGreaterThan1 = b > 1.0;

    std::cout << "Part 3:Tiny Epsilon" << "\n";
    std::cout << "a == b ? " << equal << "\n";
    std::cout << "a > 1 ?  " << aGreaterThan1 << "\n";
    std::cout << "b > 1 ?  " << bGreaterThan1 << "\n" << "\n";

    std::cout << "Explanation:" << "\n";
    std::cout << "Since epsilon is the smallest representation of the value between 1.0 and the next. So" << "\n";
    std::cout << "when we define tiny as epsilon/2, the program sees tiny as equal to zero." << "\n" << "\n";
}

void printPart4() {
    std::cout << "Part 4: Comparing Doubles" << "\n";
    double d1 = 0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1;
    double d2 = 8*0.1; 

    std::cout << "Compare d1 and d2: " << approx(d1,d2) << "\n";
}
