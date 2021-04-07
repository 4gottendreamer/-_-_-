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
	string( string&& _String ) noexcept; // Конструктор переноса по rvalue-ссылке
	~string(); // Деструктор

public:
	string& operator=( const string& _String ); // Присваивание str::string
	string& operator=( string&& _String ) noexcept; // Перемещение (move semantics)
	string& operator=( const char _Ch ); // Присваивание const char
	string& operator=( const char* _ChArr ); // Присваивание const char[]

	string operator+( const string& _String ); // Конкатенация rvalue str::string
	string operator+( const char _Ch ); // Конкатенация строк const char
	string operator+( const char* ); // Конкатенация строк const char[]

	void operator+=( const string& _String ); // Конкатенация с присваиванием
	void operator+=( const char _Ch ); // Конкатенация с присваиванием
	void operator+=( const char* _ChArr ); // Конкатенация с присваиванием

	bool operator==( const string& _String ); // Сравнение строк
	bool operator==( const char* _ChArr ); // Сравнение строк

	bool operator!=( const string& _String ); // Сравнение строк
	bool operator!=( const char* _ChArr ); // Сравнение строк

	bool operator<( const string& _String ); // Сравнение строк лексикографическое
	bool operator<=( const string& _String ); // Сравнение строк лексикографическое
	bool operator>( const string& _String ); // Сравнение строк лексикографическое
	bool operator>=( const string& _String ); // Сравнение строк лексикографическое

	char& operator[]( size_t _Index ); // Индексирование буквы строки

public:
	// Console input
	void cin();
	void cingetline();
	std::istream& fgetline( std::istream& _inStream );

	// Console output
	void cout(); // Вывод в консоль
	void coutnl(); // Вывод в консоль с переводом каретки на новую строку

	string pull_word() const; // Возвращает первое слово (строку символов до пробела) из текущей строки
	string pull_word( const size_t _Index ) const; // Возвращает слово из текущей строки, начиная с индекса _Index
	string pull_word_iter( size_t& _Index ) const; // Возвращает слово из текущей строки, начиная с индекса _Index
												   // меняет _Index на индекс символа, следующего за входящим словом
	string& pull_word_iter( const string& _String, size_t& _Index ); // Меняет текущую строку на первое слово из _String, начиная с индекса _Index
																	 // меняет _Index на индекс символа следующего за входящим словом
	string& pull_word( const string& _String, const size_t _Index ); // Меняет строку на первое слово из _String, начиная с индекса _Index
	//string& pull_word( const char* ); // Возвращает первое слово из массива char[]
	//string& pull_word( const char*, int ); // TODO // Возвращает слово из массива char[], начиная от указанного индекса

	size_t insert( size_t _Pos, const char _Ch );
	size_t insert( size_t _Pos, const char* _ChArr );
	size_t insert( size_t _Pos, const str::string& _String );

	size_t insert( size_t _Pos, size_t _Amount, const char _Ch );
	size_t insert( size_t _Pos, const str::string& _String, size_t _Index, size_t _Amount );

	void push_back( const char _Ch ); // Дописывает символ в конец строки
	void push_back( const string& _String ); // Дописывает строку в конец строки

	void pop_back(); // Удаляет последний символ строки

	void push_head( char _Ch ); // Дописывает символ _Ch в начало строки
	void push_head( const string& _String ); // Дописывает строку _String в начало строки

	void pop_head(); // Удаляет первый символ строки

	size_t size(); // Возвращает длину строки
	void clear(); // Обнуляет строку
	void erase( size_t _Index, size_t _Amount ); // Удаляет количество символов _Amount, начиная с позиции _Index
	bool empty(); // 1, если строка пустая (size() == 0), иначе 1

	const char* c_str(); // Возвращает указатель на строку в стиле C

	size_t begin();
	size_t end();

	size_t find( const char _Ch ); // Возвращает индекс первого вхождения _ChArr в строку
	size_t find( const char* _ChArr ); // Возвращает индекс первого символа первого вхождения _ChArr в строку
	size_t find( const string& _String ); // Возвращает индекс первого символа первого вхождения _String в строку

	friend std::ostream& operator<<( std::ostream& _outStream, const string& _String );
	friend std::istream& operator>>( std::istream& _outStream, string& _String );

private:
	size_t m_Length = 0;
	char* m_Str = nullptr;
private:
	int strcmp1( const char* str1, const char* str2 );
	int strcmp2( const char* str1, const char* str2 );
	int strcmp3( const char* str1, const char* str2 );
	int strcmp4( const char* str1, const char* str2 );
	int strcmp5( const char* str1, const char* str2 );
};

std::ostream& operator<<( std::ostream& _outStream, const string& _String );
std::istream& operator>>( std::istream& _outStream, string& _String );

size_t lenghthof( const char* _ChArr );
}
