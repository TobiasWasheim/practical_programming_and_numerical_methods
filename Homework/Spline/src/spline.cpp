#include"../hdr/spline.h"

double lspline::evaluate(double z) {
    int i = binsearch(x, z);
    return y[i] + dy[i]/dx[i] * (z-x[i]);
}

double lspline::integrate(double z) {
    int i = binsearch(x,z);
    double sum = 0;

    for (int j = 0; j < i; j++) {

        sum += y[j] * dx[j] + p[j] * dx[j] * dx[j]  / 2.0;
    }
    sum += y[i] * (z-x[i]) + p[i] * (z-x[i]) * (z-x[i]) / 2.0;
    return sum;
}

double qspline::evaluate(double z) {
    int i = binsearch(x, z);
    double b = p[i] - c[i] * dx[i];

    return y[i] + b * (z - x[i]) + c[i] * (z - x[i])* (z - x[i]);
}

double qspline::integrate(double z) {
    int i = binsearch(x,z);
    double sum = 0;

    for (int j = 0; j < i; j++) {
        double b = p[j] - c[j] * dx[j];

        sum += y[j] * dx[j] + b * dx[j] * dx[j] / 2.0 + c[j] * dx[j] * dx[j] * dx[j] / 3.0;
    }
    double b = p[i] - c[i] * dx[i];
    sum += y[i] * (z - x[i]) + b * (z-x[i]) * (z-x[i]) / 2.0 + c[i] * (z-x[i]) * (z-x[i]) * (z-x[i]) / 3.0;
    return sum;
}

double qspline::derivative(double z) {
    int i = binsearch(x,z);
    double b = p[i] - c[i] * dx[i];
    return b + 2 * c[i] * (z - x[i]);
}

double cspline::evaluate(double z) {
    int i = binsearch(x, z);

    return y[i] + b[i] * (z - x[i]) + c[i] * (z - x[i])* (z - x[i]) + d[i] * (z-x[i]) * (z-x[i]) * (z-x[i]);
}

double cspline::derivative(double z) {
    int i = binsearch(x,z);
    return b[i] + 2 * c[i] * (z - x[i]) + 3 * d[i] * (z - x[i]) * (z - x[i]);
}
 

int binsearch(const std::vector<double> x, double z) {

    assert(z > x[0]);
    assert(z < x[x.size() - 1]);

    int i = 0;
    int j = x.size() - 1;
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


