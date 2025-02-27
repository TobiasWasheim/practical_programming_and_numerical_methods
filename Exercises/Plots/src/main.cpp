#include <iostream>
#include <fstream>
#include "sfuns.h"


int main()
{
    // Output into data/erf_data.txt
    std::ofstream erf_data("data/erf_data.txt");
    if (erf_data.is_open())
    {
        erf_data << "This is a line in the file.\n";
        erf_data.close();
    }
    // Output into data/sgamma_data.txt
    std::ofstream sgamma_data("data/sgamma_data.txt");
    if (sgamma_data.is_open())
    {
        sgamma_data << "This is a line in the file.\n";
        sgamma_data.close();
    }

    // Output into data/lngamma_data.txt
    std::ofstream lngamma_data("data/lngamma_data.txt");
    if (lngamma_data.is_open())
    {
        lngamma_data << "This is a line in the file.\n";
        lngamma_data.close();
    }
    
    
}