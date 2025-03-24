#include<stdexcept>
#include "LinearSpline.h"

double linterp(double x[], double y[], double z, int size) {
    int i = binsearch(x, z, size);
    double dx = x[i+1] - x[i];
    if (!(dx > 0)) {
        throw new std::invalid_argument("dx <= 0");
    }
    double dy = y[i+1] - y[i];
    return y[i] + dy/dx * (z-x[i]);
}

int binsearch(double x[], double z, int size) {

    if (z < x[0] || z > x[size-1]) {
        throw new std::invalid_argument("z is less than zero");
    }
    int i = 0;
    int j = size - 1;
    while (j - i > 1) {
        int mid =(i+j)/2;
        if (z > x[mid]) {
            i = mid; 
        } else {
            j = mid;
        }
    }
    return i;
}

double linterpInteg(double x[], double y[], double z, int size) {
    int i = binsearch(x,z, size);
    double sum = 0;

    for (int j = 0; j < i; j++) {
        double dx = x[j+1] - x[j];
        sum += dx * y[j+1];
    }
    return sum;
}
