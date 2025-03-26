#include<vector>
#include<iostream>
#include<tuple>
#include<cmath>
#include"MonteCarlo.h"


// Define some function
double f(Vector z) {
    double x = z[0];
    double y =z[1];

    return x*x + y*y;
}

double g(Vector v) {

    double x = v[0];
    double y = v[1];
    double z = v[2];

    return 1/(M_PI*M_PI*M_PI) * std::pow(1-cos(x)*cos(y)*cos(z),-1);
}

int main() {
    
    std::vector<double> bound_a = {0,0,0};
    std::vector<double> bound_b = {M_PI,M_PI,M_PI};
    
    std::function<double(Vector)> func_g = g;

    std::tuple<double,double> res = plainMC(func_g,bound_a,bound_b,1000000);
    
    std::cout << "integral = " << std::get<0>(res) << ", ";
    std::cout << "error    = " << std::get<1>(res) << "\n";
    

    
    
    std::vector<double> a_values = {0,0};
    std::vector<double> b_values = {1,1};
    Vector a(a_values);
    Vector b(b_values);



    std::function<double(Vector)> func = f;
    

    for (int N = 1000; N < 1e5; N+= 1000) {
        std::tuple<double,double> result = plainMC(f,a,b,N);
        double sqrtN = 1/sqrt(N);

        std::cout << N <<" "<< std::get<1>(result) <<" "<< sqrtN << "\n";
    }

}