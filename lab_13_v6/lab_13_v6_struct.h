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

	//location& operator=( location&& _Loc ) noexcept
	//{
	//	apartment = _Loc.apartment;
	//	building = _Loc.building;
	//	street.operator=( (str::string&&)_Loc.street );
	//	city.operator=( (str::string&&)_Loc.city );
	//	return *this;
	//}

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

//struct date
//{
//	short day = 1;
//	short month = 1;
//	short year = 1900;
//
//	date& operator=( const date& _Date )
//	{
//		day = _Date.day;
//		month = _Date.month;
//		year = _Date.year;
//		return *this;
//	};
//
//	friend std::ostream& operator<<( std::ostream& _outStream, const date& _Date );
//};

//inline std::ostream& operator<<( std::ostream& _outStream, const date& _Date )
//{
//	if( _Date.day < 10 ) {
//		std::cout << '0';
//	}
//	std::cout << _Date.day << '.';
//	if( _Date.month < 10 ) {
//		std::cout << '0';
//	}
//	std::cout << _Date.month << '.' << _Date.year;
//	return _outStream;
//}