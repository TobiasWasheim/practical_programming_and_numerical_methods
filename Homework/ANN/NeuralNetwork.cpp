#include<functional>
#include<cmath>
#include<vector>

class ann {
    
public:
    
    /* number of hidden neurons */
    int n;

    /* activation function for hidden neurons */
    std::function<double(double)> f = [&](double x) {return x * std::exp(- x * x);};
    
    /* network parameters */
    std::vector<double> p;

    ann(int n) {
        this->n = n;
    }

    double response(double x) {
        /* return the response of the network to the input signal x */
        return 0;
    }

    void train(std::vector<double> y, std::vector<double> x) {
        /* train the network to interpolate the given table {x,y} */
    }

};