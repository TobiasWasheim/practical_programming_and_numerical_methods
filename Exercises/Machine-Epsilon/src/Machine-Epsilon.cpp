#include <iostream>
#include <cmath>
#include <limits>
#include "../headers/Machine-Epsilon.h"

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


