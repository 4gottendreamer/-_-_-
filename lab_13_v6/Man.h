#pragma once
#include "..\string\string.h"
#include "lab_13_v6_struct.h"

#define DEFAULT "default"

class Man
{
public:
	Man();							// Конструктор без параметров
	Man( const char* _ChArr );		// Конструктор с парамтерами
	Man( const char* _LastName,		// Конструктов с параметрами
		 const char* _Name,
		 const char* _Patronymic,
		 short _Age,
		 const char* _City,
		 const char* _Street,
		 short _Bld,
		 short _Apt);
	Man( const Man& _Man );			// Конструктор копирования
	Man( Man&& _Man ) noexcept;		// Конструктор перемещения
	~Man();

public:
	str::string getname();			// Возращает имя
	str::string getltname();		// Возращает фамилию
	str::string getpatr();			// Возращает отчество

	const char* getname_cstr();		// Возращает имя в виде C-строки
	const char* getltname_cstr();	// Возращает фамилию в виде C-строки
	const char* getpatr_cstr();		// Возращает отчество в виде C-строки

	void setname(const char* _ChName);		// Присваивает имя
	void setlname( const char* _ChLName );	// Присваивает фамилию
	void setpatr( const char* _ChPatr );	// Присваивает отчество

public:
	bool is_voter();	// Проверка избирательных прав
	bool match_lastname( const char* _LastName );	// Сравнение фамилий

	// Input/Output
	Man& inputf();	// Форматированный ввод
	void printf();	// Форматированный вывод

public:
	Man& operator=( const Man& _Man );
	Man operator+( short _Age );			// Увеличение возраста на _Age лет
	void operator+=( short _Age );			// Увеличение возраста на _Age лет
	bool operator==( const char* _ChLName );		// Сравнение фамилии
	bool operator==( const str::string& _StrName );	// Сравнение фамилии
	bool operator==( const Man& _Man );				// Сравнение фамилии

public:
	friend std::ostream& operator<<( std::ostream& _outStream, Man& _Man );
	friend std::istream& operator>>( std::istream& _inStream, Man& _Man );

private:
	short m_Age = 0;
	str::string m_LastName;
	str::string m_Name;
	str::string m_Patronymic;
	location m_address;

private:
	void init_default();
};
