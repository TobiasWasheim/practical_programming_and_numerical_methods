#include<tuple>
#include<functional>
#include<random>
#include<cmath>
#include"../Matrix/vector.h"

double nextDouble() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

std::tuple<double, double> plainMC(std::function<double(Vector)> f, Vector a, Vector b, int N) {
    
    double V = 1;
    int dim = a.getSize();
    
    for (int i = 0; i < dim; i++) {
        V *= b[i] - a[i];
    }

    double sumf = 0;
    double sumfsquared = 0;
    Vector x(dim);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < dim; j++) {
            x[j] = a[j] + nextDouble() * (b[j] - a[j]);
        }
        double fx = f(x);
        sumf += fx;
        sumfsquared += fx*fx;
    }
    double mean = sumf/N;
    double sigma = sqrt(sumfsquared/N-mean*mean);
    
    return std::make_tuple(mean*V,sigma*V/sqrt(N));
}