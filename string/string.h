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
		string( string&& _String ) noexcept; // ����������� �������� �� ������
		~string(); // ����������

		string& operator =( const string& _String ); // ������������ rvalue str::string
		string& operator=( string&& _String ) noexcept; // �����������-��������������
		string& operator=( const char _Ch ); // ������������ rvalue const char
		string& operator=( const char* _ChArr ); // ������������ rvalue const char[]

		string operator+( const string& _String ); // ������������ ����� rvalue str::string
		string operator+( const char _Ch ); // ������������ ����� rvalue const char
		string operator+( const char* ); // ������������ ����� rvalue const char[]

		void operator+=( const string& _String ); // ������������ � �������������
		void operator+=( const char _Ch ); // ������������ � �������������
		void operator+=( const char* _ChArr ); // ������������ � �������������

		bool operator==( const string& _String ); // ��������� �����
		bool operator==( const char* _ChArr ); // ��������� �����

		bool operator!=( const string& _String ); // ��������� �����
		bool operator!=( const char* _ChArr ); // ��������� �����

		char& operator[]( size_t ); // �������������� ����� ������

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

		void push_at( const char _Ch, const size_t _Index );
		void push_at( const char* _ChArr, const size_t _Index );
		void push_at( const string& _String, const size_t _Index );

		void push_back( const char _Ch ); // ���������� ������ � ����� ������
		void push_back( const string& _String ); // ���������� ������ � ����� ������

		void pop_back(); // ������� ��������� ������ ������

		void push_head( char _Ch ); // ���������� ������ _Ch � ������ ������
		void push_head( const string& _String ); // ���������� ������ _String � ������ ������

		void pop_head(); // ������� ������ ������ ������

		size_t size(); // ���������� ����� ������
		void clear(); // �������� ������

		size_t	 begin();
		size_t end();

		char* find( const char* _ChArr ); // ���������� ��������� �� ������ ������ ������� ��������� _ChArr � ������
		char* find( const string& _String ); // ���������� ��������� �� ������ ������ ������� ��������� _String � ������

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
