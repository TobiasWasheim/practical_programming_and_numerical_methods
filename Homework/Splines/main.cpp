#include<cmath>
#include<iostream>
#include <stdexcept>
#include "LinearSpline.h"

/* 

Generate points for a cos function evenly spaced and print then

*/

int main() {
    int size = 11;
    double x[size];
    double y[size];
 
    for (int i = 0; i < size; i++) {
        double xpoint = i / (1.0 * size - 1) * 2.0 * M_PI;
        double ypoint = std::cos(xpoint);

        x[i] = xpoint;
        y[i] = ypoint;
    }

    for (double i = 0; i < 2.0*M_PI; i += 0.01) {
        std::cout << i << " " << linterp(x,y,i,size) << "\n";
    }
    
}