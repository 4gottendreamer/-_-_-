// algorithms_main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "algorithms.h"

int main()
{
    std::cout << "Hello World!\n";
    for( size_t i = 1; i <= 1000; i++ ) {
        double std_math_invsqrt = 1. / sqrt( i );
        double Q3_invsqrt = Q_rsqrt( i );
        std::cout << i << ": " << std_math_invsqrt << '\t' << Q3_invsqrt
            << " | " << dQ_rsqrt( i )
            << '\t' << std_math_invsqrt - Q3_invsqrt << std::endl;
    }
}
