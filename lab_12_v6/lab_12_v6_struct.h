#pragma once
#include <iostream>
#include <fstream>

#include "..\string\string.h"
#include "..\vector\vector.h"

struct ID_score
{
	str::string LastName;
	str::string Patronym;
	str::string Name;
	short Course;
	short Phys;
	short Math;
	short Prog;

	friend std::ifstream& operator>>( std::ifstream& _inStream, ID_score& _Id );
	friend std::ostream& operator<<( std::ostream& _inStream, ID_score& _Id );
};

inline std::ifstream& operator>>( std::ifstream& _inStream, ID_score& _Id )
{
	_inStream >> _Id.LastName >> _Id.Patronym >> _Id.Name >> _Id.Course >>
		_Id.Phys >> _Id.Math >> _Id.Prog;
	return _inStream;
}

inline std::ostream& operator<<( std::ostream& _outStream, ID_score& _Id )
{
	_outStream << _Id.LastName << ' ' << _Id.Patronym << ' ' << _Id.Name <<
		' ' << _Id.Course << ' ' << _Id.Phys << ' ' << _Id.Math << ' ' << _Id.Prog;
	return _outStream;
}

struct ID
{
	str::string LastName;
	str::string Patronym;
	str::string Name;
	char Sex;
	short BirthYear;

	friend std::ifstream& operator>>( std::ifstream& _inStream, ID& _Id );
	friend std::ostream& operator<<( std::ostream& _outStream, ID& _Id );
};

inline std::ifstream& operator>>( std::ifstream& _inStream, ID& _Id )
{
	_inStream >> _Id.LastName >> _Id.Patronym >> _Id.Name >> _Id.Sex >> _Id.BirthYear;
	return _inStream;
}

inline std::ostream& operator<<( std::ostream& _outStream, ID& _Id )
{
	_outStream << ' ' << _Id.LastName << ' ' << _Id.Patronym << ' ' <<
		_Id.Name << ' ' << _Id.Sex << ' ' << _Id.BirthYear;
	return _outStream;
}
