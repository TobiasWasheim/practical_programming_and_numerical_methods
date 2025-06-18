#include"../../Min/hdr/gradient.h"
#include"../hdr/qnewton.h"

#include<iostream>

colVector qnewton(std::function<double(colVector)> f, colVector x, double acc, int maxsteps) {
    colVector gx = gradient(f,x);
    matrix B = id(x.size());
    int nsteps = 0;
    while (nsteps < maxsteps) {
        if (norm(gx) < acc) break;
        nsteps++;
        
        colVector Dx = -1 * B * gx;
        double lambda = 1.0;

        do { // Linear search
            colVector s = lambda * Dx;
            colVector z = x + s;

            colVector gz = gradient(f,z);
            colVector y = gz - gx;
            colVector u = s - B * y;

            double STY = dot(s,y);

            if (f(z) < f(x)) {
                if (STY > 1e-6) {
                    // update B... using Broyden's method
                    double gamma = dot(u,y) / STY / 2;
                    colVector a = (u-gamma *s) / STY;

                    B.update(a,s);
                    B.update(s,a);
            
                }
            x = z; 
            gx = gz;
            }

            if (lambda < 1.0 / 1024.0) {
                B = id(x.size());

            if (STY > 1e-6) {
            // update B... using Broyden's method
                double gamma = dot(u,y) / STY / 2;
                colVector a = (u-gamma *s) / STY;

                B.update(a,s);
                B.update(s,a);  
            }
            x = z; 
            gx = gz;
                break;
            }
            lambda /= 2.0;
        } while(true);
        
    
        

    }
    return x;
}
