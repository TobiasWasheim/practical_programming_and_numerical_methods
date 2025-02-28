#include <iostream>
#include <fstream>
#include "sfuns.h"


int main()
{
    // Output into data/erf_data.txt
    std::ofstream erf_data("data/erf_data.txt");
    if (erf_data.is_open())
    {
        for (double x = -3.5; x <= 3.5; x += 1/32.0)
        {
            erf_data << x << " " << sfuns::error_function(x) << "\n";
        }
        erf_data.close();
        
    }
    // Output into data/sgamma_data.txt
    std::ofstream sgamma_data("data/sgamma_data.txt");
    if (sgamma_data.is_open())
    {
        for (double x = -5; x <= 5; x += 1/128.0)
        {
            sgamma_data << x << " " << sfuns::sgamma(x) << "\n";
        }
        sgamma_data.close();
    }

    // Output into data/lngamma_data.txt
    std::ofstream lngamma_data("data/lngamma_data.txt");
    if (lngamma_data.is_open())
    {
        for (double x = 1/32.0; x <= 2; x += 1/32.0)
        {
            lngamma_data << x << " " << sfuns::lngamma(x) << "\n";
        }
        lngamma_data.close();
    }
    
    
}