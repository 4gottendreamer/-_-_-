#pragma once

#include "..\vector\vector.h"
#include "..\string\string.h"

struct date
{
	short day = 1;
	short month = 1;
	short year = 1900;

	friend std::ostream& operator<<( std::ostream& _outStream, const date& _Date );
};

std::ostream& operator<<( std::ostream& _outStream, const date& _Date )
{
	if( _Date.day < 10 ) {
		std::cout << '0';
	}
	std::cout << _Date.day << '.';
	if( _Date.month < 10 ) {
		std::cout << '0';
	}
	std::cout << _Date.month << '.' << _Date.year;
	return _outStream;
}


struct location
{
	short apartment = 0;
	short building = 0;
	str::string street;
	str::string city;

	friend std::ostream& operator<<( std::ostream& _outStream, const location& _Loc );
};

std::ostream& operator<<( std::ostream& _outStream, const location& _Loc )
{
	std::cout << _Loc.city << ", ";
	std::cout << _Loc.street << ", ";
	std::cout << _Loc.building << ", ";
	std::cout << _Loc.apartment;
	return _outStream;
}


struct ID
{
	str::string nameLast;
	date birthDay;
	location address;
	str::string occupation;

	friend std::ostream& operator<<( std::ostream& _outStream, const ID& _Elem );
	friend std::istream& operator>>( std::istream& _inStream, const ID& _Elem );
};

std::istream& operator>>( std::istream& _inStream, ID& _Elem )
{
	if( !_inStream.eof() ) {

		//_inStream >> _Elem.nameLast;
		_Elem.nameLast.fgetline( _inStream );
		//std::cout << _Elem.nameLast << std::endl;

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
	_outStream << _Elem.nameLast << std::endl;
	_outStream << _Elem.birthDay << std::endl;
	/*_outStream << _Elem.birthDay.day; _outStream << '.';
	_outStream << _Elem.birthDay.month; _outStream << '.';
	_outStream << _Elem.birthDay.year; _outStream << '\n';*/

	_outStream << _Elem.address << std::endl;
	/*_outStream << _Elem.address.city; _outStream << '\n';
	_outStream << _Elem.address.street; _outStream << '\n';
	_outStream << _Elem.address.building; _outStream << '\n';
	_outStream << _Elem.address.apartment; _outStream << '\n';*/

	_outStream << _Elem.occupation; _outStream << '\n';

	return _outStream;
}
