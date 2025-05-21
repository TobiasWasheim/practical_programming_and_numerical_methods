#include <iostream>
#include "../headers/Integers.h"
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