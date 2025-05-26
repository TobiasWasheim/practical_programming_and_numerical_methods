#include<functional>
#include<vector>
#include<cmath>
#include<tuple>
#include"ODE.h"
#include"../../Matrix/matrix.h"


std::tuple<colVector,colVector> rkstep12(
                            std::function<colVector(double, colVector)> f, 
                            double x, 
                            colVector y, 
                            double h
                        ) {

    colVector k0 = f(x,y);
    colVector k1 = f((x + h) * 0.5,y + k0 * h * 0.5);
    colVector yh = y + k1 * h;
    colVector dy = (k1 - k0) * h;
        
    return std::make_tuple(yh,dy);
}


std::tuple<colVector,std::vector<colVector>> driver(
                                    std::function<colVector(double, colVector)> f, 
                                    double a, 
                                    colVector ya, 
                                    double b, 
                                    double h, 
                                    double acc, 
                                    double eps
                                ) {
    double x = a;
    colVector y = ya;
    std::vector<double> xlist({x});
    std::vector<colVector> ylist({y});

    while (true) {
        if (x >= b) {
            return std::make_pair(xlist,ylist);
        }

        if (x + h > b) {
            x = b - h;
        }

        std::tuple<colVector,colVector> ys = rkstep12(f,x,y,h);
        colVector yh = std::get<0>(ys);
        colVector dy = std::get<1>(ys);
            
        double tolerance = (acc + norm(yh) * eps) * std::sqrt(h/(b-a));
        double error = norm(dy);

        if (error < tolerance) {
            x += h;
            y = yh;
            xlist.push_back(x);
            ylist.push_back(y);
        }
        
        if (error > 0) {
            h *= std::min(pow(tolerance/error,2)*0.95,2.0);
        } else {
             h *= 2;
        }
    }
} 
