#ifndef HAVE_QSPLINE_H
#define HAVE_QSPLINE_H

#include<cassert>
#include<vector>
#include<iostream>

class lspline {
public:
    std::vector<double> x,y;
    std::vector<double> p, dx, dy;

public:
    lspline(std::vector<double> xs, std::vector<double> ys) {
        assert(xs.size() == ys.size());

        size_t n = xs.size() - 1;

        x = xs;
        y = ys;

        p.resize(n);
        dx.resize(n);
        dy.resize(n);

        // We calculate the dx's, dy's and p's
        for (int i = 0; i < n; i++) {
            dx[i] = x[i+1] - x[i];
            assert(dx[i] > 0);

            dy[i] = y[i+1] - y[i];
            p[i] = dy[i]/dx[i];
        }
    }

    double evaluate(double z);
    double integrate(double z);
};

class qspline {

public:
    std::vector<double> x, y;
    std::vector<double> p, c, dx, dy;

public:
    qspline(std::vector<double> xs,std::vector<double> ys) {
        assert(xs.size() == ys.size());

        size_t n = xs.size() - 1; 

        x = xs;
        y = ys;

        p.resize(n);
        c.resize(n-1);
        dx.resize(n);
        dy.resize(n);

        // We calculate the dx's, dy's and p's
        for (int i = 0; i < n - 1; i++) {
            dx[i] = x[i+1] - x[i];
            assert(dx[i] > 0);

            dy[i] = y[i+1] - y[i];
            p[i] = dy[i]/dx[i];
        }

        // calculate the c's
        c[0] = 0;
        for (int i = 0; i < n - 2; i++) {
            c[i+1] = 1/dx[i+1] * (p[i+1] - p[i] - c[i] * dx[i+1]);
            
        }
    }
    // Evaluate the function at point z
    double evaluate(double z);

    // Evaluate the derivative at point z
    double derivative(double z);

    // integrate from 0 to z
    double integrate(double z);
};
int binsearch(const std::vector<double> x, double z);

#endif