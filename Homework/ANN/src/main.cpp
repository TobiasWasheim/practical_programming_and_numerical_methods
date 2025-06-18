#include"../hdr/ANN.h"
#include"../hdr/qnewton.h"

#include<fstream>
#include<iostream>

int main() {
    
    // We have our function
    std::function<double(double)> f = [](double x) {
        
        
        return std::cos(5*x-1)*std::exp(-x*x);};
    
    
    // train the function
    
    int n = 25;

    // data tables 
    colVector xs(n);
    colVector ys(n);

    for (int i = 0; i < n; i += 1) {
        double num = - 1 + i/(n-1.0)* 2.0 ;
        xs[i] = num;
        ys[i] = f(num);
    }
    ann NN(10);

    NN.train(xs,ys);
    std::ofstream file;

    file.open("data/data.txt");
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }

    for (double x = -1; x <= 1; x += 0.1) {
        file << x << " " << NN.response(x) << "\n";
    }
    file << "\n";

    std::function<double(double)> g = [](double x) {
        return std::cos(2*x);
    };

    colVector xs_b(n);
    colVector ys_b(n);

    for (int i = 0; i < n; i++) {
        double num = -5 + i/(n-1.0) * 10.0;
        xs_b[i] = num;
        ys_b[i] = g(num);
    }
    ann NN_partB(10);

    NN_partB.train(xs_b,ys_b);
    for (double x = -5; x <= 5; x += 0.5) {
        file << x << " " << NN_partB.derivative(x) << " " << NN_partB.double_derivative(x) << " " << NN_partB.integrate(x) << "\n";
    }
    

    file.close();




    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: ANN - part A" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part A, the artifical neural network (ANN) has been" << "\n";
    std::cout << "implemented. To test it, we try to interpolate the function" << "\n\n";
    
    std::cout << "f(x) = cos(5x - 1) exp(-x^2)," << "\n\n";

    std::cout << "We have plotted the interpolation and the function on the plot at" << "\n";
    std::cout << "plots/partA.svg where we see that the neural network fits quite well." << "\n\n";
    std::cout << "Since the minimization function from the homework 'Min' is unstable," << "\n";
    std::cout << "there has been implemented the quasi-Newton method using symmetic Broyden's update." << "\n\n\n";

    std::cout << "-------------------------------------------" << "\n";
    std::cout << "Homework: ANN - part B" << "\n";
    std::cout << "-------------------------------------------" << "\n\n";

    std::cout << "In part b, we have implemented the first, second, and anti-derivative of " <<"\n";
    std::cout << "a function fitted in the neural network. Since the function in part A" << "\n";
    std::cout << "does not have an anti-derivative that is easy to find analytically, we" << "\n";
    std::cout << "resort to a much simpler function to showcase that the derivatives work" << "\n";
    std::cout << "that are estimated from the neural network. This should however, not be an" << "\n";
    std::cout << "issue, since we would expect that if the derivatives fit for a simpler function" << "\n";
    std::cout << "it should also fit for more interesting functions. We use the function" << "\n\n";
    std::cout << "f(x) = cos(2x)" << "\n\n";
    std::cout << "We can see that the first derivative fits quite well in the plot at plots/first_derivative.svg/." << "\n";
    std::cout << "Also, the second derivative also fits nicely compared to the analytical solution. This can" << "\n";
    std::cout << "be seen on the plot at plots/second_derivative.svg/. At last, we have also plotted the anti-derivative" << "\n";
    std::cout << "for the cosine-function at plots/anti_derivative.svg/. We see here compared to the analytical result it" << "\n";
    std::cout << "it is similar. To clarify the integral: The integral we have plotted is the integral of cos(2x') from 0 to x." << "\n";
    std::cout << "This integral has the analytical solution 0.5 * sin(2x)." << "\n";
    return 0;
}