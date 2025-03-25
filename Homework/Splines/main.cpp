#include<cmath>
#include<iostream>
#include<vector>
#include <stdexcept>
#include "LinearSpline.h"

/* 

Generate points for a cos function evenly spaced and print then

*/

int main() {
    int size = 10;
    double x[size];
    double y[size];
 
    // We make an array with values for (x, y=cos(x)). 
    for (int i = 0; i < size; i++) {
        double xpoint = i / (1.0 * size - 1.0) * 7.0;
        double ypoint = std::cos(xpoint);

        x[i] = xpoint;
        y[i] = ypoint;
    }

    // Next, we make an array with values from the linterp
    int sizeL = 634;
    double xL[sizeL];
    double yL[sizeL];

    std::cout << "x " << "linterp " << "linterpInteg" << "\n";
    int count = 0;
    for (double i = 0; i < 6.33; i += 0.01) {
        xL[count] = i;
        yL[count] = linterp(x,y,i,size);
        count++;
    }   
    int index = 0;
    while (index < sizeL) {
        std::cout << xL[index] << " " << yL[index] << " " << linterpInteg(xL,yL,xL[index],sizeL) << "\n";

        index++;
    }
}
