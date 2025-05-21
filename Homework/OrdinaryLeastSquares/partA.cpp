#include<iostream>
#include"OLSFit.h"



double func1(double x) {
    return 1.0;
}

double func2(double x) {
    return -x;
}


double fit(double x, colVector c) {
    return c[0] - c[1] * x;
}

int main () {
    
}