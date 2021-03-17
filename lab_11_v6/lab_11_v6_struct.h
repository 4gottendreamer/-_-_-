#pragma once

#include "..\vector\vector.h"
#include "..\string\string.h"

struct date
{
	short day = 1;
	short month = 1;
	short year = 1900;

	void Init( short _d, short _m, short _y )
	{
		day = _d;
		month = _m;
		year = _y;
	}
};

struct location
{
	short apartment = 0;
	short building = 0;
	str::string street;
	str::string city;

	void Init( short _Apt, short _Bld, char* _St, char* _City )
	{
		apartment = _Apt;
		building = _Bld;
		street = _St;
		city = _City;
	}
};

struct ID
{
	/* TODO:
	*	1. Input form file with initialization
	*	2. Output to file
	*/
	str::string nameLast;
	date birthDay;
	location address;
	str::string occupation;

	//ID(
	//	char* _Name,
	//	short _Day,
	//	short _Month,
	//	short _Year,
	//	char* _Occupation,
	//	// Address part
	//	char* _City,
	//	char* _St,
	//	short _Bld,
	//	short _Apt
	//)
	//	: nameLast( _Name )
	//	, occupation( _Occupation )
	//{
	//	birthDay.Init( _Day, _Month, _Year );
	//	address.Init( _Apt, _Bld, _City, _St );
	//}

	//ID& finput( const char* _Path )
	//{
	//	std::ifstream infile;
	//	infile.open( _Path );
	//	if( infile.fill() ) {
	//		std::cerr << "Error opening file.";
	//		exit( 1 );
	//	}

	//	while( !infile.eof() ) {
	//		infile >> nameLast;
	//		std::cout << nameLast << std::endl;

	//		infile >> birthDay.day;
	//		std::cout << birthDay.day << ".";
	//		infile >> birthDay.month;
	//		std::cout << birthDay.month << ".";
	//		infile >> birthDay.year;
	//		std::cout << birthDay.year << std::endl;;

	//		infile >> address.city;
	//		std::cout << address.city << std::endl;
	//		infile >> address.street;
	//		std::cout << address.street << std::endl;
	//		infile >> address.building;
	//		std::cout << address.apartment << std::endl;

	//		infile >> occupation;
	//		std::cout << occupation << std::endl;
	//	}

	//	infile.close();
	//}

	//ID& foutput( const char* _Path )
	//{
	//	std::ofstream fout;
	//	fout.open( _Path, std::ofstream::app );
	//	if( !fout.is_open() ) {
	//		std::cout << "Opening file error\n";
	//	}
	//	else {

	//		fout << '\n';
	//	}
	//	fout.close();
	//}

	friend std::ostream& operator<<( std::ostream& _outStream, const ID& _Elem );
	friend std::istream& operator>>( std::istream& _inStream, const ID& _Elem );
};

std::istream& operator>>( std::istream& _inStream, ID& _Elem )
{
	if( !_inStream.eof() ) {

		//_inStream >> _Elem.nameLast;
		_Elem.nameLast.fgetline( _inStream );
		std::cout << _Elem.nameLast << std::endl;

		_inStream >> _Elem.birthDay.day;
		_inStream.get();
		//std::cout << _Elem.birthDay.day << ".";
		_inStream >> _Elem.birthDay.month;
		_inStream.get();
		//std::cout << _Elem.birthDay.month << ".";
		_inStream >> _Elem.birthDay.year;
		_inStream.get();
		//std::cout << _Elem.birthDay.year << std::endl;

		_Elem.address.city.fgetline( _inStream );
		//std::cout << _Elem.address.city << std::endl;
		_Elem.address.street.fgetline( _inStream );
		//std::cout << _Elem.address.street << std::endl;
		_inStream >> _Elem.address.building;
		//std::cout << _Elem.address.building << std::endl;
		_inStream >> _Elem.address.apartment;
		_inStream.get();
		//std::cout << _Elem.address.apartment << std::endl;

		_Elem.occupation.fgetline( _inStream );
		//std::cout << _Elem.occupation << std::endl;
	}

	return _inStream;
}

std::ostream& operator<<( std::ostream& _outStream, const ID& _Elem )
{
	_outStream << _Elem.nameLast; _outStream << '\n';

	_outStream << _Elem.birthDay.day; _outStream << '.';
	_outStream << _Elem.birthDay.month; _outStream << '.';
	_outStream << _Elem.birthDay.year; _outStream << '\n';

	_outStream << _Elem.address.city; _outStream << '\n';
	_outStream << _Elem.address.street; _outStream << '\n';
	_outStream << _Elem.address.building; _outStream << '\n';
	_outStream << _Elem.address.apartment; _outStream << '\n';

	_outStream << _Elem.occupation; _outStream << '\n';

	return _outStream;
}
