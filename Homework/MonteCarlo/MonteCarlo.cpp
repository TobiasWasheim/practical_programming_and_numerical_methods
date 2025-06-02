#include<tuple>
#include<functional>
#include<random>
#include<iostream>
#include<cmath>
#include"../../Matrix/matrix.h"
#include"MonteCarlo.h"

double nextDouble() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

std::vector<int> prime_numbers(int n) {
    std::vector<int> primes;
    int candidate = 2; 
    while (primes.size() < n) {
        if (isPrime(candidate)) {
            primes.push_back(candidate);
        }
        candidate++;
    }
    return primes;
}


double corput(int n, int b) {
    double output = 0.0;
    double output_increment = 1.0/b;
    while (n > 0) {
        int least_significant_digit = n % b;
        output += least_significant_digit*output_increment;
        
        n = n/b;
        output_increment /= b;
    }
    return output;
}

std::tuple<double, double> plainMC(std::function<double(colVector)> f, colVector a, colVector b, int N) {
    
    double V = 1;
    int dim = a.size();

    for (int i = 0; i < dim; i++) {
        V *= b[i] - a[i];
    }

    double sumf = 0.0;
    double sumfsquared = 0.0;
    colVector x(dim);

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


std::tuple<double,double> quasiMC(std::function<double(colVector)> f, colVector a, colVector b, int N) {
    double V = 1;
    int dim = a.size();
    std::vector<int> primes = prime_numbers(dim*2);
    
    for (int i = 0; i < dim; i++) {
        V *= b[i] - a[i];
    }

    double sumfx = 0;
    double sumfy = 0;

    colVector x(dim);
    colVector y(dim);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < dim; j++) {
            x[j] = a[j] + corput(i+1,primes[j]) * (b[j] - a[j]);
            y[j] = a[j] + corput(i+1,primes[j+dim]) * (b[j] - a[j]);
        }
        double fx = f(x);
        double fy = f(y);
        sumfx += fx;
        sumfy += fy;
    }
    double meanX = sumfx / N;
    double meanY = sumfy / N;
    double mean = (meanX + meanY) * V / 2.0;
    double sigma = std::abs(meanX - meanY) * V/std::sqrt(2.0);
    
    return std::make_tuple(mean,sigma);
}