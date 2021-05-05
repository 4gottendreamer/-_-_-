#pragma once
#include "..\string\string.h"
#include "lab_13_v6_struct.h"

#define DEFAULT "default"

class Man
{
public:
	Man();							// ����������� ��� ����������
	Man( const char* _ChArr );		// ����������� � �����������
	Man( const char* _LastName,		// ����������� � �����������
		 const char* _Name,
		 const char* _Patronymic,
		 short _Age,
		 const char* _City,
		 const char* _Street,
		 short _Bld,
		 short _Apt);
	Man( const Man& _Man );			// ����������� �����������
	Man( Man&& _Man ) noexcept;		// ����������� �����������
	~Man();

public:
	str::string getname();			// ��������� ���
	str::string getltname();		// ��������� �������
	str::string getpatr();			// ��������� ��������

	const char* getname_cstr();		// ��������� ��� � ���� C-������
	const char* getltname_cstr();	// ��������� ������� � ���� C-������
	const char* getpatr_cstr();		// ��������� �������� � ���� C-������

	void setname(const char* _ChName);		// ����������� ���
	void setlname( const char* _ChLName );	// ����������� �������
	void setpatr( const char* _ChPatr );	// ����������� ��������

public:
	bool is_voter();	// �������� ������������� ����
	bool match_lastname( const char* _LastName );	// ��������� �������

	// Input/Output
	Man& inputf();	// ��������������� ����
	void printf();	// ��������������� �����

public:
	Man& operator=( const Man& _Man );
	Man operator+( short _Age );			// ���������� �������� �� _Age ���
	void operator+=( short _Age );			// ���������� �������� �� _Age ���
	bool operator==( const char* _ChLName );		// ��������� �������
	bool operator==( const str::string& _StrName );	// ��������� �������
	bool operator==( const Man& _Man );				// ��������� �������

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
