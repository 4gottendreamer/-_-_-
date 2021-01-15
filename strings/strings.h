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
		void getline(); // TODO ���������
		void cout(); // ����� � �������

		string getword() const; // ���������� ������ ����� (������ �������� �� �������) �� ������� ������
		string getword( int ) const; // ���������� ����� �� ������� �����, ������� �� ���������� �������
		string& getword( const string&, int ); // ������ ������� ������ �� ����� �� str::string, ������� �� ���������� �������
		string& getword( const char* ); // ���������� ������ ����� �� ������� char[]
		string& getword( const char*, int ); // TODO // ���������� ����� �� ������� char[], ������� �� ���������� �������
		
		void push_back( const char ); // ���������� ������ � ����� ������
		void push_back( const string& ); // ���������� ������ � ����� ������
		
		void pop_back(); // ������� ��������� ������ ������

		void push_head( char ); // ���������� ������ � ������ ������
		void push_head( const string& ); // ���������� ������ � ������ ������
		
		void pop_head(); // ������� ������ ������ ������

		int getlength(); // ���������� ����� ������

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
