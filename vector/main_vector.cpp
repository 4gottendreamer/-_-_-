#include <iostream>
#include "vector.h"
#include <vector>
#include "..\string\string.h"

//using TYPE = std::string;
using TYPE = str::string;

void PrintVector( vector<TYPE>& _Vec )
{
	std::cout << "===============================\n";
	for ( size_t i = 0; i < _Vec.size(); i++ ) {
		std::cout << "["<< i << "]" << _Vec[i] << std::endl;
	}
	std::cout << "===============================\n";
}

int main()
{
	setlocale( LC_ALL, "ru" );
	//TYPE S;
	//std::cout << "S.capacity() == " << S.capacity() << std::endl;
	
	std::vector<std::string> strVec;
	
	/*strVec.push_back( "Один" );
	strVec.push_back( "Два" );
	strVec.emplace_back( "Три" );
	strVec.push_back( "Четыре" );*/
	
	TYPE S_ONE = "std::String___O.N.E.__";
	TYPE R("this was emplaced inTWO here");

	vector<TYPE> sV;
	sV.emplace_back( "emplaced_one" );
	sV.emplace_back( R );
	sV.push_back( "three" );
	sV.push_back( "four" );
	sV.push_back( S_ONE );
	
	PrintVector( sV );
	
	std::cout << "\n\tsV.pop_back();" << std::endl;
	sV.pop_back();

	std::cout << "\nsizeof( str::string ) == " << sizeof( TYPE ) << '\n';
	std::cout << "sV.size() == " << sV.size() << "\tsV.capacity() == " << sV.capacity() << std::endl;

	std::cout << "\tsV.emplace_back( \"последнее ЧИСЛО\" );" << std::endl;
	sV.emplace_back( "последнее ЧИСЛО" );
	
	str::string B( "самое последнее число" );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );
	sV.emplace_back( B );

	PrintVector( sV );

	sV.pop_back();
	sV.pop_back();
	sV.pop_back();
	sV.pop_back();
	sV.pop_back();
	sV.pop_back();

	PrintVector( sV );

	std::cout << "clear();\n";
	sV.clear();
	std::cout << "sV.size() == " << sV.size() << "\tsV.capacity() == " << sV.capacity() << std::endl;

	TYPE C( "самое единственное число" );
	sV.emplace_back( C );
	std::cout << "sV.size() == " << sV.size() << "\tsV.capacity() == " << sV.capacity() << std::endl;
	PrintVector( sV );
	
	/*for ( size_t i = 0; i < sV.size(); i++ ) {
		std::cout << sV[i] << '\n';
	}*/

	system( "pause" );
	std::cout << std::endl;
}