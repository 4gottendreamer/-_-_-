#pragma once
#include <iostream>
#include <Windows.h>

namespace str
{
	class string
	{
	public:
		string(); // Конструктор без параметров
		string( char _Ch ); // Конструктор с параметрами
		string( char* _ChArr ); // Конструктор с параметрами
		string( const char* _ChArr ); // Конструктор с параметрами
		string( const string& _String ); // Конструктор копирования
		string( string&& _String ) noexcept; // Конструктор переноса по ссылке
		~string(); // Деструктор

		string& operator =( const string& _String ); // Присваивание rvalue str::string
		string& operator=( string&& _String ) noexcept; // Перемещение-переназначение
		string& operator=( const char _Ch ); // Присваивание rvalue const char
		string& operator=( const char* _ChArr ); // Присваивание rvalue const char[]

		string operator+( const string& _String ); // Конкатенация строк rvalue str::string
		string operator+( const char _Ch ); // Конкатенация строк rvalue const char
		string operator+( const char* ); // Конкатенация строк rvalue const char[]

		void operator+=( const string& _String ); // Конкатенация с присваиванием
		void operator+=( const char _Ch ); // Конкатенация с присваиванием
		void operator+=( const char* _ChArr ); // Конкатенация с присваиванием

		bool operator==( const string& _String ); // Сравнение строк
		bool operator==( const char* _ChArr ); // Сравнение строк

		bool operator!=( const string& _String ); // Сравнение строк
		bool operator!=( const char* _ChArr ); // Сравнение строк

		char& operator[]( size_t ); // Индексирование буквы строки

		void cin();
		void getline();
		void cout(); // Вывод в консоль

		string pull_word() const; // Возвращает первое слово (строку символов до пробела) из текущей строки
		string pull_word( const int _Index ) const; // Возвращает слово из текущей строки, начиная с индекса _Index
		string pull_word_iter( int& _Index ) const; // Возвращает слово из текущей строки, начиная с индекса _Index
													// меняет _Index на индекс символа следующего за входящим словом
		string& pull_word_iter( const string& _String, int& _Index ); // Меняет текущую строку на первое слово из _String, начиная с индекса _Index
																	  // меняет _Index на индекс символа следующего за входящим словом
		string& pull_word( const string& _String, const int _Index ); // Меняет строку на первое слово из _String, начиная с индекса _Index
		//string& pull_word( const char* ); // Возвращает первое слово из массива char[]
		//string& pull_word( const char*, int ); // TODO // Возвращает слово из массива char[], начиная от указанного индекса

		void push_at( const char _Ch, const size_t _Index );
		void push_at( const char* _ChArr, const size_t _Index );
		void push_at( const string& _String, const size_t _Index );

		void push_back( const char _Ch ); // Дописывает символ в конец строки
		void push_back( const string& _String ); // Дописывает строку в конец строки

		void pop_back(); // Удаляет последний символ строки

		void push_head( char _Ch ); // Дописывает символ _Ch в начало строки
		void push_head( const string& _String ); // Дописывает строку _String в начало строки

		void pop_head(); // Удаляет первый символ строки

		size_t size(); // Возвращает длину строки
		void clear(); // Обнуляет строку

		size_t	 begin();
		size_t end();

		char* find( const char* _ChArr ); // Возвращает указатель на первый символ первого вхождения _ChArr в строку
		char* find( const string& _String ); // Возвращает указатель на первый символ первого вхождения _String в строку

	private:
		size_t m_Length = 0;
		char* m_Str = nullptr;

		friend std::ostream& operator<<( std::ostream& _outStream, const string& _String );
		friend std::istream& operator>>( std::istream& _outStream, string& _String );
	};

	std::ostream& operator<<( std::ostream& _outStream, const string& _String );
	std::istream& operator>>( std::istream& _outStream, string& _String );

	size_t lenghthof( const char* _ChArr );
}
