#pragma once
#include <iostream>
#include <Windows.h>

namespace str
{
	class string
	{
	public:
		string(); // ����������� ��� ����������
		string( char ); // ����������� � �����������
		string( char* ); // ����������� � �����������
		string( const char* ); // ����������� � �����������
		string( const string& ); // ����������� �����������
		string( string&& ) noexcept; // ����������� �������� �� ������
		~string(); // ����������

		string& operator=( const string& ); // ������������ r-value str::string
		string& operator=( const char ); // ������������ r-value const char
		string& operator=( const char* ); // ������������ r-value const char[]

		string operator+( const string& ); // ������������ ����� r-value str::string
		string operator+( const char ); // ������������ ����� r-value const char
		string operator+( const char* ); // ������������ ����� r-value const char[]

		void operator+=( const string& ); // ������������ � �������������
		void operator+=( const char ); // ������������ � �������������
		void operator+=( const char* ); // ������������ � �������������

		bool operator==( const string& ); // ��������� �����
		bool operator==( const char* ); // ��������� �����

		bool operator!=( const string& ); // ��������� �����
		bool operator!=( const char* ); // ��������� �����

		char& operator[]( int ); // �������������� ����� ������

		void cin();
		void getline();
		void cout(); // ����� � �������

		string pull_word() const; // ���������� ������ ����� (������ �������� �� �������) �� ������� ������
		string pull_word( const int _Index ) const; // ���������� ����� �� ������� ������, ������� � ������� _Index
		string pull_word_iter( int& _Index ) const; // ���������� ����� �� ������� ������, ������� � ������� _Index
													// ������ _Index �� ������ ������� ���������� �� �������� ������
		string& pull_word_iter( const string& _String, int& _Index ); // ������ ������� ������ �� ������ ����� �� _String, ������� � ������� _Index
																	  // ������ _Index �� ������ ������� ���������� �� �������� ������
		string& pull_word( const string& _String, const int _Index ); // ������ ������ �� ������ ����� �� _String, ������� � ������� _Index
		//string& pull_word( const char* ); // ���������� ������ ����� �� ������� char[]
		//string& pull_word( const char*, int ); // TODO // ���������� ����� �� ������� char[], ������� �� ���������� �������

		void push( const char _Ch, const int _Index );
		void push( const char* _ChArr, const int _Index );
		void push( const string& _String, const int _Index );

		void push_back( const char _Ch ); // ���������� ������ � ����� ������
		void push_back( const string& _String ); // ���������� ������ � ����� ������

		void pop_back(); // ������� ��������� ������ ������

		void push_head( char _Ch ); // ���������� ������ _Ch � ������ ������
		void push_head( const string& _String ); // ���������� ������ _String � ������ ������

		void pop_head(); // ������� ������ ������ ������

		int size(); // ���������� ����� ������
		void clear(); // �������� ������
		
		char* find( const char* _ChArr ); // ���������� ��������� �� ������ ������ ������� ��������� _ChArr � ������
		char* find( const string& _String ); // ���������� ��������� �� ������ ������ ������� ��������� _String � ������

	private:
		int length;
		char* str;

		friend std::ostream& operator<<( std::ostream& _outStream, const string& _String );
		friend std::istream& operator>>( std::istream& _outStream, string& _String );
	};

	std::ostream& operator<<( std::ostream& _outStream, const string& _String );
	std::istream& operator>>( std::istream& _outStream, string& _String );

	int lenghthof( const char* _ChArr );
}