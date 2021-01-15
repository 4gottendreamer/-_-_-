#pragma once
#include <iostream>
#include <Windows.h>

namespace str
{
	class string
	{
	public:
		string(); // Конструктор без параметров
		string( char ); // Конструктор с параметрами
		string( char* ); // Конструктор с параметрами
		string( const char* ); // Конструктор с параметрами
		string( const string& ); // Конструктор копирования
		string( string&& ) noexcept; // Конструктор переноса по ссылке
		~string(); // Деструктор

		string& operator=( const string& ); // Присваивание r-value str::string
		string& operator=( const char ); // Присваивание r-value const char
		string& operator=( const char* ); // Присваивание r-value const char[]
		
		string operator+( const string& ); // Конкатенация строк r-value str::string
		string operator+( const char ); // Конкатенация строк r-value const char
		string operator+( const char* ); // Конкатенация строк r-value const char[]
		
		void operator+=( const string& ); // Конкатенация с присваиванием
		void operator+=( const char ); // Конкатенация с присваиванием
		void operator+=( const char* ); // Конкатенация с присваиванием

		bool operator==( const string& ); // Сравнение строк
		bool operator==( const char* ); // Сравнение строк
		
		bool operator!=( const string& ); // Сравнение строк
		bool operator!=( const char* ); // Сравнение строк

		char& operator[]( int ); // Индексирование буквы строки

		void cin();
		void getline(); // TODO ПОПРАВИТЬ
		void cout(); // Вывод в консоль

		string getword() const; // Возвращает первое слово (строку символов до пробела) из текущей строки
		string getword( int ) const; // Возвращает слово из текущей стоки, начиная от указанного индекса
		string& getword( const string&, int ); // Меняет текущую строку на слово из str::string, начиная от указанного индекса
		string& getword( const char* ); // Возвращает первое слово из массива char[]
		string& getword( const char*, int ); // TODO // Возвращает слово из массива char[], начиная от указанного индекса
		
		void push_back( const char ); // Дописывает символ в конец строки
		void push_back( const string& ); // Дописывает строку в конец строки
		
		void pop_back(); // Удаляет последний символ строки

		void push_head( char ); // Дописывает символ в начало строки
		void push_head( const string& ); // Дописывает символ в начало строки
		
		void pop_head(); // Удаляет первый символ строки

		int getlength(); // Возвращает длину строки

	private:
		int length;
		char* str;

		friend std::ostream& operator<<( std::ostream&, const string& );
		friend std::istream& operator>>( std::istream&, string& );
	};

	std::ostream& operator<<( std::ostream&, const string& );
	std::istream& operator>>( std::istream&, string& );
	std::istream& operator>>( const string&, string& );

	int lenghthof( const char* );
}
