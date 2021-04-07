#include <iostream>
#include "Man.h"

Man::Man()
{}

Man::Man(const char* _ChArr)
{
	if (_ChArr == "default") {
		init_default();
	}
}

Man::Man(const char* _LastName, const char* _Name, const char* _Patronymic, short _Age,
	const char* _City, const char* _Street, short _Bld, short _Apt) :
	m_Age(_Age),
	m_LastName(_LastName),
	m_Name(_Name),
	m_Patronymic(_Patronymic)
{
	m_address.city = _City;
	m_address.street = _Street;
	m_address.building = _Bld;
	m_address.apartment = _Apt;
}

Man::Man(const Man& _Man)
{
	m_Age = _Man.m_Age;
	m_LastName = _Man.m_LastName;
	m_Name = _Man.m_Name;
	m_Patronymic = _Man.m_Patronymic;
	m_address = _Man.m_address;

}

Man::Man(Man&& _Man) noexcept
{
	m_Age = _Man.m_Age;
	//m_LastName = _Man.m_LastName;
	//m_Name = _Man.m_Name;
	//m_Patronymic = _Man.m_Patronymic;
	m_LastName.operator=((str::string&&)_Man.m_LastName);
	m_Name.operator = ((str::string&&)_Man.m_Name);
	m_Patronymic.operator=((str::string&&)_Man.m_Patronymic);
	m_address.operator=((location&&)_Man.m_address);
	/*m_address.city.operator=( (str::string&&)_Man.m_address.city );
	m_address.street.operator=( (str::string&&)_Man.m_address.street );*/
}

Man::~Man()
{
	//m_LastName.~string();
	//m_Name.~string();
	//m_Patronymic.~string();
	//m_address.city.~string();
	//m_address.street.~string();
}

str::string Man::getname()
{
	return m_Name;
}

str::string Man::getltname()
{
	return m_LastName;
}

str::string Man::getpatr()
{
	return m_Patronymic;
}

const char* Man::getname_cstr()
{
	return m_Name.c_str();
}

const char* Man::getltname_cstr()
{
	return m_LastName.c_str();
}

const char* Man::getpatr_cstr()
{
	return m_Patronymic.c_str();
}

void Man::setname(const char* _ChName)
{
	m_Name = _ChName;
}

void Man::setlname(const char* _ChLName)
{
	m_LastName = _ChLName;
}

void Man::setpatr(const char* _ChPatr)
{
	m_Patronymic = _ChPatr;
}

bool Man::is_voter()
{
	if (m_Age > 17) {
		return true;
	}
	else {
		return false;
	}
}

bool Man::match_lastname(const char* _LastName)
{
	if (m_LastName == _LastName) {
		return true;
	}
	else {
		return false;
	}
}

Man& Man::inputf()
{
	std::cout << "Фамилия: "; std::cin >> m_LastName;
	std::cout << "Имя: "; std::cin >> m_Name;
	std::cout << "Отчество: "; std::cin >> m_Patronymic;
	auto invalidAge = [](short _i)->bool {
		if (_i < 1) {
			std::cout << "Неверный возраст. Введите заново.\n";
			return true;
		}
		else {
			return false;
		}
	};
	do {
		std::cout << "Возраст: "; std::cin >> m_Age;
	} while (invalidAge(m_Age));
	std::cout << "Адрес:\n"; std::cin.get(); m_address.inputf();
	return *this;
}

void Man::printf()
{
	std::cout << "Фамилия:\t" << m_LastName << std::endl;
	std::cout << "Имя:\t\t" << m_Name << std::endl;
	std::cout << "Отчество:\t" << m_Patronymic << std::endl;
	std::cout << "Возраст:\t" << m_Age << std::endl;
	std::cout << "Адрес\n" << m_address;
}

Man& Man::operator=(const Man& _Man)
{
	m_Age = _Man.m_Age;
	m_LastName = _Man.m_LastName;
	m_Name = _Man.m_Name;
	m_Patronymic = _Man.m_Patronymic;
	m_address = _Man.m_address;
	return *this;
}

Man Man::operator+(short _Age)
{
	Man newMan(*this);
	newMan += _Age;
	return newMan;
}

void Man::operator+=(short _Age)
{
	m_Age += _Age;
}

bool Man::operator==(const char* _ChLName)
{
	return match_lastname(_ChLName);
}

bool Man::operator==(const str::string& _StrName)
{
	//( m_LastName == _StrName ) ? ( return true ) : ( return false );
	if (m_LastName == _StrName) {
		return true;
	}
	else {
		return false;
	}
}

bool Man::operator==(const Man& _Man)
{
	return (m_LastName == _Man.m_LastName);
}

std::ostream& operator<<(std::ostream& _outStream, Man& _Man)
{
	_outStream
		<< _Man.m_LastName << ' '
		<< _Man.m_Name << ' '
		<< _Man.m_Patronymic << "; "
		<< _Man.m_Age << "; ";
	_outStream << _Man.m_address;
	return _outStream;
}

std::istream& operator>>(std::istream& _inStream, Man& _Man)
{
	_inStream
		>> _Man.m_LastName
		>> _Man.m_Name
		>> _Man.m_Patronymic
		>> _Man.m_Age;
	//_inStream >> _Man.m_address;
	_inStream
		>> _Man.m_address.city
		>> _Man.m_address.street
		>> _Man.m_address.building
		>> _Man.m_address.apartment;
	return _inStream;
}

// Private method for testing
void Man::init_default()
{
	short m_Age = 0;
	m_LastName = "Doe";
	m_Name = "John";
	m_Patronymic = "William";
	m_address.street = "Elm st.";
	m_address.city = "Nowheranapolis";
}
