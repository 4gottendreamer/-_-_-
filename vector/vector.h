#pragma once
#include <iostream>

template <typename T, size_t Tsize>
class vector
{
public:
	vector<T, Tsize>();
	vector<T, Tsize>( const vector& _Arr );
	vector<T, Tsize>( vector&& _Arr );
	~vector();

	int size();
	void push_back( T& _Elem );
	void push_head( T& _Elem );
	void pop_back( T& _Elem );
	void pop_head( T& _Elem );
	T& operator[]( int _i );

private:
	T* m_Arr;
	size_t m_Size;
};

template <typename T, size_t Tsize>
vector<T, Tsize>::vector()
{
	this->m_Size = Tsize;
	//T* m_Arr = (T*)alloca( Tsize * sizeof( T ) ); // Dynamic stack allocation. Dangerous way.
	this->m_Arr = new T[Tsize];
}

template <typename T, size_t Tsize>
vector<T, Tsize>::vector( const vector& _Arr )
{
	this->m_Size = _Arr.m_Size;
	this->m_Arr = new T[this->m_Size];
	for ( int i = 0; i < this->m_Size; i++ ) {
		this->m_Arr[i] = _Arr[i];
	}
}

template <typename T, size_t Tsize>
vector<T, Tsize>::vector( vector&& _Arr )
{
	this->m_Size = _Arr.m_Size;
	this->m_Arr = _Arr.m_Arr;
	_Arr.m_Arr = nullptr;
}

template <typename T, size_t Tsize>
vector<T, Tsize>::~vector()
{
	if ( this->m_Arr ) {
		delete[] this->m_Arr;
	}
	delete this->m_Arr;
}

template <typename T, size_t Tsize>
int vector<T, Tsize>::size()
{
	return this->m_Size;
}

template <typename T, size_t Tsize>
void vector<T, Tsize>::push_back( T& _Elem )
{
	T* tmp = new T[this->m_Size + 1];
	for ( size_t i = 0; i < this->m_Size; i++ ) {
		tmp[i] = this->m_Arr[i];
	}
	tmp[this->m_Size++] = _Elem;
	delete[] this->m_Arr;
	this->m_Arr = tmp;
	tmp = nullptr;
}

template <typename T, size_t Tsize>
void vector<T, Tsize>::push_head( T& _Elem )
{
	T* tmp = new T[this->m_Size + 1];
	for ( size_t i = 1; i < this->m_Size + 1; i++ ) {
		tmp[i] = this->m_Arr[i - 1];
	}
	tmp[0] = _Elem;
	delete[] this->m_Arr;
	this->m_Arr = tmp;
	tmp = nullptr;
}

template <typename T, size_t Tsize>
void vector<T, Tsize>::pop_back( T& _Elem )
{
	T* tmp = new T[this->m_Size - 1];
	for ( size_t i = 0; i < this->m_Size - 1; i++ ) {
		tmp[i] = this->m_Arr[i];
	}
	delete[] this->m_Arr;
	this->m_Arr = tmp;
	tmp = nullptr;
}

template <typename T, size_t Tsize>
T& vector<T, Tsize>::operator[]( int _i )
{
	return this->m_Arr[_i];
}
