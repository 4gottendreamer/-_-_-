#include <iostream>
#include "vector.h"
#include <vector>
int main()
{
	const int SIZE = 7;
	vector<std::string, SIZE> Str;
	vector<char> ChStr;
	Str.push_back( "alpha" ); std::cout << "Str.size() == " << Str.size()
										<< "\tStr[Str.size() - 1] == " << Str[Str.size() - 1] << std::endl;
	
	for ( size_t i = 0; i < Str.size(); i++ ) {
		Str[i] = i * i + 1;
		std::cout << Str[i] << '\t';
	}
	std::cout << std::endl;

	std::cout << "Str.size() == " << Str.size() << '\t' << "Str.capacity() == " << Str.capacity() << std::endl;
	//Str.reserve( 20 );
	Str.emplace_back( "SibFU" );
	std::cout << "Str.size() == " << Str.size() << '\t' << "Str.capacity() == " << Str.capacity() << std::endl;
	for ( size_t i = 0; i < Str.size(); i++ ) {
		std::cout << Str[i] << '\n';
	}
	std::cout << std::endl;
	std::vector<char> stdV;
	/*int* I = new int[15];
	for ( int i = 0; i < 15; i++ ) {
		I[i] = i * i;
	}
	int c_I[] = { 2,3,5,7,11,13,17,19 };
	for ( int& i : c_I ) {
		std::cout << i << '\n';
	}
	return 0;*/
}