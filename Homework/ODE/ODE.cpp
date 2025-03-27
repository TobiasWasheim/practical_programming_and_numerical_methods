#include<functional>
#include<vector>
#include<cmath>
#include<tuple>
#include"ODE.h"
#include"../Matrix/vector.h"


std::tuple<Vector,Vector> rkstep12(
                            std::function<Vector(double, Vector)> f, 
                            double x, 
                            Vector y, 
                            double h
                        ) {

    Vector k0 = f(x,y);
    Vector k1 = f((x + h) * 0.5,y + k0 * h * 0.5);
    Vector yh = y + k1 * h;
    Vector dy = (k1 - k0) * h;
        
    return std::make_tuple(yh,dy);
}


std::tuple<Vector,std::vector<Vector>> driver(
                                    std::function<Vector(double, Vector)> f, 
                                    double a, 
                                    Vector ya, 
                                    double b, 
                                    double h, 
                                    double acc, 
                                    double eps
                                ) {
    double x = a;
    Vector y = ya;
    std::vector<double> xlist({x});
    std::vector<Vector> ylist({y});

    while (true) {
        if (x >= b) {
            return std::make_pair(xlist,ylist);
        }

        if (x + h > b) {
            x = b - h;
        }

        std::tuple<Vector,Vector> ys = rkstep12(f,x,y,h);
        Vector yh = std::get<0>(ys);
        Vector dy = std::get<1>(ys);
            
        double tolerance = (acc + yh.norm() * eps) * std::sqrt(h/(b-a));
        double error = dy.norm();

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
