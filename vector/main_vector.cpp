#include <iostream>
#include "vector.h"
//#include <vector>
#include "..\string\string.h"

using TYPE = str::string;

void PrintVector( vector<TYPE>& _Vec )
{
	for ( size_t i = 0; i < _Vec.size(); i++ ) {
		std::cout << _Vec[i] << std::endl;
	}
	std::cout << "===============================\n";
}

int main()
{
	//TYPE S;
	//std::cout << "S.capacity() == " << S.capacity() << std::endl;
	
	TYPE S = "std::String___O.N.E.__";
	
	vector<TYPE> sV;
	sV.push_back( S );
	sV.emplace_back( "emplaced_one" );
	sV.emplace_back( "two" );
	sV.push_back( "three" );
	sV.push_back( "four" );
	sV.pop_back();

	std::cout << "sizeof( std::string ) == " << sizeof( TYPE ) << '\n';
	std::cout << "iS.size() == " << sV.size() << "\tsV.capacity() == " << sV.capacity() << std::endl;
	
	PrintVector( sV );
	
	/*for ( size_t i = 0; i < sV.size(); i++ ) {
		std::cout << sV[i] << '\n';
	}*/

	//std::cin.get();
	std::cout << std::endl;
}