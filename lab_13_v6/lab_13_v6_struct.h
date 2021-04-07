#pragma once
#include "..\string\string.h"

struct location
{
	short apartment = 0;
	short building = 0;
	str::string street;
	str::string city;

	location& operator=( const location& _Loc )
	{
		apartment = _Loc.apartment;
		building = _Loc.building;
		street = _Loc.street;
		city = _Loc.city;
		return *this;
	}

	void inputf()
	{
		std::cout << "Город: "; city.cingetline();
		std::cout << "Улица: "; street.cingetline();
		std::cout << "Дом "; std::cin >> building;
		std::cout << "Квартира: "; std::cin >> apartment;
	}

	friend std::ostream& operator<<( std::ostream& _outStream, const location& _Loc );
	friend std::istream& operator>>( std::istream& _inStream, location& _Loc );
};

inline std::ostream& operator<<( std::ostream& _outStream, const location& _Loc )
{
	std::cout << _Loc.city << ", ";
	std::cout << _Loc.street << ", ";
	std::cout << _Loc.building << ", ";
	std::cout << _Loc.apartment;
	return _outStream;
}

inline std::istream& operator>>( std::istream& _inStream, location& _Loc )
{
	_inStream >> _Loc.city;
	_inStream >> _Loc.street;
	_inStream >> _Loc.building;
	_inStream >> _Loc.apartment;
	return _inStream;
}
