#include<cmath>
#include<iostream>
#include<vector>

#include"../hdr/OLS.h"

std::tuple<colVector,matrix> radioactivityFit()  {
    
    std::function<double(double)> f1 = [](double x) {return 1.0;};
    std::function<double(double)> f2 = [](double x) {return -x;};



    // Data
    std::vector<double> xs = {1,2,3,4,6,9,10,13,15};
    std::vector<double> ys = {117,100,88,72,53,29.5,25.2,15.2,11.1};
    std::vector<double> dys = {6,5,4,4,4,3,3,2,2};

    // Linearize the data
    std::vector<double> ln_ys(ys.size());
    std::vector<double> ln_dys(dys.size());

    for (int i = 0; i < ys.size(); i++) {
        ln_ys[i] = std::log(ys[i]);
        ln_dys[i]= dys[i]/ys[i];
    }

    // Define vectors
    colVector x(xs);
    colVector y(ln_ys);
    colVector dy(ln_dys);

    std::function<double(double)> fs[2];

    fs[0] = f1;
    fs[1] = f2;

    // define size of function set
    int size = 2;

    // do fitting
    return lsfit(fs,x,y,dy,size);
 }

int main() {

    std::tuple<colVector,matrix> fit = radioactivityFit();

    colVector c = std::get<0>(fit);
    matrix covariance = std::get<1>(fit);

    double logaUncertainty = covariance(0,0);
    double lambdaUncertainty = covariance(1,1);
    double halfLifeUncertainty = std::log(2)/c[1]/c[1] * lambdaUncertainty;

    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: OLS - part A" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "In part A we have implemented ordinary least squares fit using QR-decomposition." << "\n";
    std::cout << "To show that it works we have fitted the data from measurements of ThX activity." << "\n\n";

    std::cout << "The plot of the measurements can be seen in the folder 'plots/'. Using OLS the  " << "\n";
    std::cout << "fitting coefficients are printed below.                                         " << "\n\n";

    std::cout << "ln(a) = " << std::exp(c[0]) << "," << "\n";
    std::cout << "lambda: " << c[1] << "." << "\n";
    
    std::cout << "The half-life of ThX from the fitting is " << "\n\n";

    std::cout << "T_(1/2) = " << std::log(2)/c[1] << " days." << "\n\n";
    
    std::cout << "The modern value is 3.66 days.           " << "\n\n";


    std::cout << "--------------------------------------------------------------------------------" << "\n";
    std::cout << "Homework: OLS - part B" << "\n";
    std::cout << "--------------------------------------------------------------------------------" << "\n\n";

    std::cout << "In part B we have modified the ordinary least least squares method to calculate " << "\n";
    std::cout << "and return the covariance matrix. The uncertainty on the fitting coefficients   " << "\n";
    std::cout << "are                                                                             " << "\n\n";

    std::cout << "log(a) uncertainty = " << logaUncertainty << "\n";
    std::cout << "Lambda uncertainty = " <<  lambdaUncertainty << "\n\n";

    std::cout << "The uncertainty for the half-life is    " << "\n\n";
    
    std::cout << "T_(1/2) uncertainty = " << halfLifeUncertainty << "days." << "\n\n";

    std::cout << "are                                                                             " << "\n\n";
    std::cout << "The modern half-life uncertainty for ThX is 0.0014 days. Comparing the modern   " << "\n";
    std::cout << "value for the half-life from the fit and its uncertainty we see that the values " << "\n";
    std::cout << "does not agree within the estimated uncertainty.                                " << "\n\n"; 

    std::cout << "Source for ThX modern value and half life: NIST" << "\n";
    return 0;
}   