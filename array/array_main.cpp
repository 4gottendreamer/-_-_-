#include <iostream>
#include "array.h"

int main()
{
	int tmp;
	std::cin >> tmp;
	const int SIZE = 5;
	array<float, SIZE> Ar7;
	for ( size_t i = 0; i < Ar7.size(); i++ ) {
		Ar7[i] = sin( rand() );
		std::cout << Ar7[i] << std::endl;
	}
	return 0;
}