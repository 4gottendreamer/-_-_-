#pragma once
#include <iostream>

template <typename T, size_t Tsize = 2>
class vector
{
public:
	vector<T, Tsize>();
	vector<T, Tsize>( const vector& _Arr );
	vector<T, Tsize>( vector&& _Arr );
	~vector();

	size_t size();
	size_t capacity();

	void push_back( const T& _Elem );
	void push_back( const T&& _Elem );

	template<typename... Targs>
	T& emplace_back( Targs... _Args );

	void push_head( const T& _Elem );
	void pop_back();
	T& pop_head(); // Deletes and nullifies element m_Arr[0]; returns ref. to new m_Arr[0]

	void clear(); // Destroys evey element of vector

	void reserve( size_t _newCapacity );

	T& operator[]( size_t _i );
	const T& operator[]( size_t _i ) const;

private:
	T* m_Arr = nullptr;
	size_t m_Size = 0;
	size_t m_Capacity = 0;

	void realloc( size_t _newCapacity );
};

template <typename T, size_t Tsize>
vector<T, Tsize>::vector()
{
	this->m_Size = Tsize;
	//this->m_Arr = new T[Tsize];
	realloc( Tsize );
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
	clear();
	//delete[] this->m_Arr;
	::operator delete( m_Arr, m_Capacity * sizeof( T ) );
}

template<typename T, size_t Tsize>
inline size_t vector<T, Tsize>::size()
{
	return m_Size;
}

template<typename T, size_t Tsize>
inline size_t vector<T, Tsize>::capacity()
{
	return m_Capacity;
}

template <typename T, size_t Tsize>
void vector<T, Tsize>::push_back( const T& _Elem )
{
#if 1
	if ( m_Size >= m_Capacity ) {
		realloc( m_Capacity + m_Capacity / 2 );
	}
	m_Arr[m_Size++] = _Elem;
#else
	T* tmp = new T[this->m_Size + 1];
	for ( size_t i = 0; i < this->m_Size; i++ ) {
		tmp[i] = this->m_Arr[i];
	}
	tmp[this->m_Size++] = _Elem;
	delete[] this->m_Arr;
	this->m_Arr = tmp;
	tmp = nullptr;
#endif // 0
}

template<typename T, size_t Tsize>
inline void vector<T, Tsize>::push_back( const T&& _Elem )
{
	if ( m_Size >= m_Capacity ) {
		realloc( m_Capacity + m_Capacity / 2 );
	}
	m_Arr[m_Size++] = std::move( _Elem );
}

template<typename T, size_t Tsize>
template<typename ...Targs>
inline T& vector<T, Tsize>::emplace_back( Targs ..._Args )
{
	if ( m_Size >= m_Capacity ) {
		realloc( m_Capacity + m_Capacity / 2 );
	}
	//m_Arr[m_Size] = T( std::forward<Targs>( _Args )... );
	new( &m_Arr[m_Size] ) T( std::forward<Targs>( _Args )... );
	return m_Arr[m_Size++];
}

template <typename T, size_t Tsize>
void vector<T, Tsize>::push_head( const T& _Elem )
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
void vector<T, Tsize>::pop_back()
{
#if 1
	if ( m_Size > 0 ) {
		m_Arr[--m_Size].~T();
	}
#else
	T* tmp = new T[this->m_Size - 1];
	for ( size_t i = 0; i < this->m_Size - 1; i++ ) {
		tmp[i] = this->m_Arr[i];
	}
	delete[] this->m_Arr;
	this->m_Arr = tmp;
	tmp = nullptr;
#endif // 0
}

template<typename T, size_t Tsize>
inline void vector<T, Tsize>::clear()
{
	for ( size_t i = 0; i < m_Size; i++ ) {
		m_Arr[i].~T();
	}
	m_Size = 0;
}

template<typename T, size_t Tsize>
inline void vector<T, Tsize>::reserve( size_t _newCapacity )
{
	realloc( _newCapacity );
}

template<typename T, size_t Tsize>
inline const T& vector<T, Tsize>::operator[]( size_t _i ) const
{
	// TODO: Out of range subscripting check
	return this->m_Arr[_i];
}

template <typename T, size_t Tsize>
T& vector<T, Tsize>::operator[]( size_t _i )
{
	// TODO: Out of range subscripting check
	return this->m_Arr[_i];
}

/*//////////////////////////////////////////
*
* PRIVATE METHODS
*
*///////////////////////////////////////////

// Gets vector m_Capacity grown or shrinked to _newCapacity size
template<typename T, size_t Tsize>
inline void vector<T, Tsize>::realloc( size_t _newCapacity )
{
	if ( _newCapacity < m_Size ) { // Downsizing capacity case
		m_Size = _newCapacity;
	} // TODO(*): Check for memory re-allocations in shrinking case

	//T* newArr = new T[_newCapacity];
	T* newArr = ( T* )::operator new( _newCapacity * sizeof( T ) );

	if ( m_Arr != nullptr ) { // If (this) is un-initialized instance no move and destroys are needed

		for ( size_t i = 0; i < m_Size; i++ ) {
			newArr[i] = std::move( m_Arr[i] );
		}

		// TODO(*): Use original m_Size in case of shrinking
		// TODO(*): Использовать изначальный размер в случае сжатия ёмкости
		for ( size_t i = 0; i < m_Size; i++ ) {
			m_Arr[i].~T();
		}

		//delete[] m_Arr;
		::operator delete( m_Arr, m_Capacity * sizeof( T ) );
	}

	m_Arr = newArr;
	m_Capacity = _newCapacity;
}
