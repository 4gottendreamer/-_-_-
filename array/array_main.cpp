#include <iostream>
#include "array.h"

int main()
{
	const int SIZE = 5;
	array<double, SIZE> Ar7;
	for ( size_t i = 0; i < Ar7.size(); i++ ) {
		Ar7[i] = sin( rand() );
		std::cout << Ar7[i] << std::endl;
	}
	return 0;
}