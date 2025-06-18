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

class cspline {

    public:
        std::vector<double> x,y; // data points
        std::vector<double> b, c, d; // coefficients
        std::vector<double> p, dx, dy; // helpful variables

        std::vector<double> B, D, B_tilde, D_tilde, Q;


        cspline(std::vector<double> xs,std::vector<double> ys) {
            assert(xs.size() == ys.size());

            size_t n = xs.size();
            
            x = xs;
            y = ys;

            b.resize(n);        // We have introduced a auxilary coefficient b[n]
            c.resize(n-1);
            d.resize(n-1);

            p.resize(n-1);
            dx.resize(n-1);
            dy.resize(n-1);

            D.resize(n);
            B.resize(n);
            D_tilde.resize(n);
            B_tilde.resize(n);
            Q.resize(n-1);


            // Compute the helpful variables
            for (int i = 0; i < n-1; i++) {
                dx[i] = x[i+1] - x[i];
                assert(dx[i] > 0);

                dy[i] = y[i+1] - y[i];
                p[i] = dy[i]/dx[i];
        }

        // Compute the B's, D's and Q's
        B[0] = 3 * p[0];
        B[n-1] = 3 * p[n-1];
        D[0] = 2;
        D[n-1] = 2;
        Q[0] = 1;
        for (int i = 0; i < n-2; i++) {
            B[i+1] = 3 * (p[i] + p[i+1] * dx[i]/dx[i+1]);
            D[i+1] = 2 * dx[i]/dx[i+1]+2;
            Q[i+1] = dx[i]/dx[i+1];
        }

        // Compute the D_tilde's and 
        D_tilde[0] = D[0];
        B_tilde[0] = B[1];
        for (int i = 1; i < n; i++) {
            D_tilde[i] = D[i] - Q[i-1]/D_tilde[i-1];
            B_tilde[i] = B[i] - B[i-1]/D_tilde[i-1];
        }

        // Compute the b's 
        b[n-1] = B_tilde[n-1]/D_tilde[n-1];
        for (int i = n-1; i >= 0 - 1; i--) {
            b[i] = (B_tilde[i] - Q[i] * b[i+1]) / D_tilde[i];
        }


        // Compute c's and d's (note that c[0] = 0)
        for (int i = 1; i < n-1; i++) {
            c[i] = (-2 * b[i] - b[i+1] + 3 * p[i]) / dx[i];
            d[i] = (b[i] + b[i+1] - 2 * p[i]) / dx[i] / dx[i];
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