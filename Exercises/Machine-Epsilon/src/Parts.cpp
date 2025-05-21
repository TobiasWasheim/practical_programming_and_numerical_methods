#include "../headers/Integers.h"
#include "../headers/Machine-Epsilon.h"
#include <iostream>
#include <cmath>
#include <limits>



void printPart1() {
    int largestInt = largestInteger();
    int smallestInt = smallestInteger();
    
    std::cout << "Part 1: Maximum/Minimum representable Integers" << "\n";
    std::cout << "Largest Integer = " << largestInt << "\n";
    std::cout << "Smallest Integer = " << smallestInt << "\n\n";

    bool compareMaxInt = INT32_MAX == largestInt;
    bool compareMinInt = INT32_MIN == smallestInt;
    if (compareMaxInt) {
        std::cout << "The largest integer we have calculated is the largest 32-bit integer that is possible." << "\n";
    } else {
        std::cout << "The largest integer we have calculated is not the largest 32-bit integer that is possible." << "\n";
    }

    if (compareMinInt) {
        std::cout << "The smallest integer we have calculated is the smallest 32-bit integer that is possible." << "\n";
    } else {
        std::cout << "The smallest integer we have calculated is not the smallest 32-bit integer that is possible." << "\n";
    }
    std::cout <<"\n";
}
void printPart2() {
    double epsilonDouble = machineEpsilonDouble();
    float epsilonfloat = machineEpsilonFloat();

    std::cout << "Part 2: The Machine Epsilon" << "\n";
    std::cout << "Machine epsilon for double-precision: " << epsilonDouble << "  The correct value: " <<std::numeric_limits<double>::epsilon()<< "\n";

    std::cout << "Machine epsilon for float-precision:  " << epsilonfloat << "  The correct value: " <<std::numeric_limits<float>::epsilon()<< "\n\n" ;

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
    std::cout << "when   we define tiny as epsilon/2, the program sees tiny as equal to zero." << "\n" << "\n";
}

void printPart3() {
    double tiny = machineEpsilonDouble()/2.0;
    double a = 1.0 + tiny + tiny;
    double b = tiny + tiny + 1.0;

    bool equal = a == b;
    bool aGreaterThan1 = a > 1.0;
    bool bGreaterThan1 = b > 1.0;

    std::cout << "Part 3:Tiny Epsilon" << "\n";
    if (equal) {
        std::cout << "a == b is true" << "\n";
    } else {
        std::cout << "a == b is not true" << "\n";
    }
    
    if (aGreaterThan1) {
        std::cout << "a > 1 is true" << "\n";
    } else {
        std::cout << "a > 1 is not true" << "\n";
    }
   
    if (bGreaterThan1) {
        std::cout << "b > 1 is true" << "\n" << "\n";
    } else {
        std::cout << "b > 1 is not true" << "\n" << "\n";
    }


    std::cout << "Explanation:" << "\n";
    std::cout << "Since epsilon is the smallest representation of the value between 1.0 and the next. So" << "\n";
    std::cout << "when adding epsilon/2 to 1.0, the program considers that as equal to 1.0" << "\n" << "\n";
}

void printPart4() {
    std::cout << "Part 4: Comparing Doubles" << "\n";
    double d1 = 0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1;
    double d2 = 8*0.1; 

    if (approx(d1,d2)) {
        std::cout << "d1 and d2 are equal" << "\n";
    } else {
        std::cout << "d1 and d2 are not equal" << "\n";
    }
}