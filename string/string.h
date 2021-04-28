#pragma once
#include <iostream>
#include <Windows.h>

namespace str
{
class string
{
public:
	string(); // ����������� ��� ����������
	string( char _Ch ); // ����������� � �����������
	string( char* _ChArr ); // ����������� � �����������
	string( const char* _ChArr ); // ����������� � �����������
	string( const string& _String ); // ����������� �����������
	string( string&& _String ) noexcept; // ����������� �������� �� rvalue-������
	~string(); // ����������

public:
	string& operator=( const string& _String ); // ������������ str::string
	string& operator=( string&& _String ) noexcept; // ����������� (move semantics)
	string& operator=( const char _Ch ); // ������������ const char
	string& operator=( const char* _ChArr ); // ������������ const char[]

	string operator+( const string& _String ); // ������������ rvalue str::string
	string operator+( const char _Ch ); // ������������ ����� const char
	string operator+( const char* ); // ������������ ����� const char[]

	void operator+=( const string& _String ); // ������������ � �������������
	void operator+=( const char _Ch ); // ������������ � �������������
	void operator+=( const char* _ChArr ); // ������������ � �������������

	bool operator==( const string& _String ); // ��������� �����
	bool operator==( const char* _ChArr ); // ��������� �����

	bool operator!=( const string& _String ); // ��������� �����
	bool operator!=( const char* _ChArr ); // ��������� �����

	bool operator<( const string& _String ); // ��������� ����� ������������������
	bool operator<=( const string& _String ); // ��������� ����� ������������������
	bool operator>( const string& _String ); // ��������� ����� ������������������
	bool operator>=( const string& _String ); // ��������� ����� ������������������

	char& operator[]( size_t _Index ); // �������������� ����� ������

public:
	// Console input
	void cin();
	void cingetline();
	std::istream& fgetline( std::istream& _inStream );

	// Console output
	void cout(); // ����� � �������
	void coutnl(); // ����� � ������� � ��������� ������� �� ����� ������

	string pull_word() const; // ���������� ������ ����� (������ �������� �� �������) �� ������� ������
	string pull_word( const size_t _Index ) const; // ���������� ����� �� ������� ������, ������� � ������� _Index
	string pull_word_iter( size_t& _Index ) const; // ���������� ����� �� ������� ������, ������� � ������� _Index
												   // ������ _Index �� ������ �������, ���������� �� �������� ������
	string& pull_word_iter( const string& _String, size_t& _Index ); // ������ ������� ������ �� ������ ����� �� _String, ������� � ������� _Index
																	 // ������ _Index �� ������ ������� ���������� �� �������� ������
	string& pull_word( const string& _String, const size_t _Index ); // ������ ������ �� ������ ����� �� _String, ������� � ������� _Index
	//string& pull_word( const char* ); // ���������� ������ ����� �� ������� char[]
	//string& pull_word( const char*, int ); // TODO // ���������� ����� �� ������� char[], ������� �� ���������� �������

	size_t insert( size_t _Pos, const char _Ch );
	size_t insert( size_t _Pos, const char* _ChArr );
	size_t insert( size_t _Pos, const str::string& _String );

	size_t insert( size_t _Pos, size_t _Amount, const char _Ch );
	size_t insert( size_t _Pos, const str::string& _String, size_t _Index, size_t _Amount );

	void push_back( const char _Ch ); // ���������� ������ � ����� ������
	void push_back( const string& _String ); // ���������� ������ � ����� ������

	void pop_back(); // ������� ��������� ������ ������

	void push_head( char _Ch ); // ���������� ������ _Ch � ������ ������
	void push_head( const string& _String ); // ���������� ������ _String � ������ ������

	void pop_head(); // ������� ������ ������ ������

	size_t size(); // ���������� ����� ������
	void clear(); // �������� ������
	void erase( size_t _Index, size_t _Amount ); // ������� ���������� �������� _Amount, ������� � ������� _Index
	bool empty(); // 1, ���� ������ ������ (size() == 0), ����� 1

	const char* c_str(); // ���������� ��������� �� ������ � ����� C

	size_t begin();
	size_t end();

	size_t find( const char _Ch ); // ���������� ������ ������� ��������� _ChArr � ������
	size_t find( const char* _ChArr ); // ���������� ������ ������� ������� ������� ��������� _ChArr � ������
	size_t find( const string& _String ); // ���������� ������ ������� ������� ������� ��������� _String � ������

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
