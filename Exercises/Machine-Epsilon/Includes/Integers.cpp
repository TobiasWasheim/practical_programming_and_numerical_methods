#include <iostream>
#include "Integers.h"
int largestInteger() {
    int num {1};
    int previous {0}; 
    while (num > 0)
    {   
        previous = num;
        num++;
    }
    return previous;
}

int smallestInteger() {
    int num {-1};
    int previous {0};

    while (num < 0) {
        previous = num;
        num--;
    }
    return previous;
}

void printPart1() {
    int largestInt = largestInteger();
    int smallestInt = smallestInteger();
    
    std::cout << "Part 1: Maximum/Minimum representable Integers" << "\n";
    std::cout << "Largest Integer = " << largestInt << "\n";
    std::cout << "Smallest Integer = " << smallestInt << "\n\n";

    bool compareMaxInt = INT32_MAX == largestInt;
    bool compareMinInt = INT32_MIN == smallestInt;

    std::cout << "largestInteger == INT32_MAX  " << compareMaxInt << "\n";
    std::cout << "smallestInteger == INT32_MIN " << compareMinInt << "\n";
    std::cout << "\n"; 
}