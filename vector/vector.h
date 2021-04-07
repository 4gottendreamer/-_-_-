#pragma once
#include <iostream>

#define _ALLOCATION_ 0

/*
* TODO:
*	1.	Teach realloc() to reduce allocated memory
*	2.	Check on pop_back() if reductive reallocation is needed
*	3.	vector( const std::initializer_list<T>& _List )
*		vector<int> A = { 1, 2, 3, ... }
*	4.	T& at( size_t _Index ) // operator[]() with range checking
*	5.	T& begin()
*	6.	T& end()
*	7.	void swap( size_t _From, size_t _To );
*/

template <typename vector>
class vector_iterator
{
public:
	using ValueType = typename vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	vector_iterator( PointerType _Ptr )
		: m_Ptr( _Ptr )
	{}

	vector_iterator& operator++() // Prefix increment
	{
		m_Ptr++;
		return *this;
	}

	vector_iterator operator++( int ) // Postfix increment
	{
		vector_iterator curIter = *this;
		++( *this );
		return curIter;
	}

	vector_iterator& operator--() // Prefix decrement
	{
		m_Ptr--;
		return *this;
	}

	vector_iterator operator--( int ) // Postfix decrement
	{
		vector_iterator curIter = *this;
		--( *this );
		return curIter;
	}

	ReferenceType operator[]( size_t _Index )
	{
		return *( m_Ptr + _Index );
	}

	PointerType operator->()
	{
		return m_Ptr;
	}

	ReferenceType operator*()
	{
		return *m_Ptr;
	}

	bool operator==( const vector_iterator& _Rhs ) const
	{
		return m_Ptr == _Rhs.m_Ptr;
	}

	bool operator!=( const vector_iterator& _Rhs ) const
	{
		return !( *this == _Rhs );
	}

private:
	PointerType m_Ptr;
};

template <typename T>
class vector
{
public:
	using ValueType = T;
	using iterator = vector_iterator<vector<T>>;

public:
	vector<T>();
	//vector<T>( const vector& _Vec );
	//vector<T>( vector&& _Vec ) noexcept;
	~vector();

	void push_back( const T& _Elem );
	void push_back( T&& _Elem );

	template<typename... Targs>
	T& emplace_back( Targs&&... _Args );

	void push_head( const T& _Elem );
	void pop_back();
	T& pop_head(); // Deletes and nullifies element m_Arr[0]; returns ref. to new m_Arr[0]

	void swap( size_t _From, size_t _To ); // Swaps element m_Arr[_From] with element m_Arr[_To]

	void clear(); // Destroys evey element of vector
	void reserve( size_t _newCapacity ); // Allocates _newCapacity elements of space in advance

	T& operator[]( size_t _i );
	const T& operator[]( size_t _i ) const;

	size_t size();
	size_t capacity();

	iterator begin()
	{
		return iterator( m_Arr );
	}

	iterator end()
	{
		return iterator( m_Arr + m_Size );
	}

private:
	T* m_Arr = nullptr;

	size_t m_Size = 0;
	size_t m_Capacity = 0;

private:
	void realloc( size_t _newCapacity );
};

template <typename T>
vector<T>::vector()
{
	realloc( 2 );
}

//template <typename T>
//vector<T>::vector( const vector& _Arr )
//{
//	this->m_Size = _Arr.m_Size;
//	this->m_Arr = new T[this->m_Capacity];
//	for ( int i = 0; i < this->m_Size; i++ ) {
//		this->m_Arr[i] = _Arr[i];
//	}
//}

//template <typename T>
//vector<T>::vector( vector&& _Arr ) noexcept
//{
//	this->m_Size = _Arr.m_Size;
//	this->m_Arr = _Arr.m_Arr;
//	_Arr.m_Arr = nullptr;
//}

#if _ALLOCATION_
template <typename T>
vector<T>::~vector()
{
	//clear();
	delete[] this->m_Arr;
	//::operator delete( m_Arr, m_Capacity * sizeof( T ) );
}

#else
template <typename T>
vector<T>::~vector()
{
	clear();
	//delete[] this->m_Arr;
	::operator delete( m_Arr, m_Capacity * sizeof( T ) );
}

#endif // 0

template <typename T>
void vector<T>::push_back( const T& _Elem )
{
#if _ALLOCATION_
	if( m_Size >= m_Capacity ) {
		realloc( m_Capacity + m_Capacity / 2 );
	}
	m_Arr[m_Size++] = _Elem;
#else
	emplace_back( _Elem );
#endif // 0

	/*T* tmp = new T[this->m_Size + 1];
	for ( size_t i = 0; i < this->m_Size; i++ ) {
		tmp[i] = this->m_Arr[i];
	}
	tmp[this->m_Size++] = _Elem;
	delete[] this->m_Arr;
	this->m_Arr = tmp;
	tmp = nullptr;*/
}

template <typename T>
void vector<T>::push_back( T&& _Elem )
{
#if _ALLOCATION_
	if( m_Size >= m_Capacity ) {
		realloc( m_Capacity + m_Capacity / 2 );
	}
	m_Arr[m_Size++] = std::move( _Elem );
	//m_Arr[m_Size++] = _Elem;
#else
	emplace_back( std::move( _Elem ) );
#endif
}

template <typename T>
template<typename ...Targs>
T& vector<T>::emplace_back( Targs&& ..._Args )
{
	if( m_Size >= m_Capacity ) {
		realloc( m_Capacity + m_Capacity / 2 );
	}
	//m_Arr[m_Size] = T( std::forward<Targs>( _Args )... );
	new( &m_Arr[m_Size] ) T( std::forward<Targs>( _Args )... );
	return m_Arr[m_Size++];
}

template <typename T>
void vector<T>::push_head( const T& _Elem )
{
	T* tmp = new T[this->m_Size + 1];
	for( size_t i = 1; i < this->m_Size + 1; i++ ) {
		tmp[i] = this->m_Arr[i - 1];
	}
	tmp[0] = _Elem;
	delete[] this->m_Arr;
	this->m_Arr = tmp;
	tmp = nullptr;
}

template <typename T>
void vector<T>::pop_back()
{

	if( m_Size > 0 ) {
		m_Arr[--m_Size].~T();
	}

	//T* tmp = new T[this->m_Size - 1];
	//for ( size_t i = 0; i < this->m_Size - 1; i++ ) {
	//	tmp[i] = this->m_Arr[i];
	//}
	//delete[] this->m_Arr;
	//this->m_Arr = tmp;
	//tmp = nullptr;
}

template<typename T>
inline void vector<T>::swap( size_t _From, size_t _To )
{
	T tmp = m_Arr[_To];
	m_Arr[_To] = m_Arr[_From];
	m_Arr[_From] = tmp;
}

template <typename T>
void vector<T>::clear()
{
	for( size_t i = 0; i < m_Size; i++ ) {
		m_Arr[i].~T();
	}
	m_Size = 0;
}

template <typename T>
void vector<T>::reserve( size_t _newCapacity )
{
	realloc( _newCapacity );
}

template <typename T>
T& vector<T>::operator[]( size_t _i )
{
	// TODO: Out of range subscripting check
	return this->m_Arr[_i];
}

template <typename T>
const T& vector<T>::operator[]( size_t _i ) const
{
	// TODO: Out of range subscripting check
	return this->m_Arr[_i];
}

template <typename T>
size_t vector<T>::size()
{
	return m_Size;
}

template <typename T>
size_t vector<T>::capacity()
{
	return m_Capacity;
}

/*//////////////////////////////////////////
*
* PRIVATE METHODS
*
*///////////////////////////////////////////

// Gets vector m_Capacity grown or shrinked to _newCapacity size
#if _ALLOCATION_
template <typename T>
void vector<T>::realloc( size_t _newCapacity )
{
	T* newArr = new T[_newCapacity];
	//T* newArr = ( T* )::operator new( _newCapacity * sizeof( T ) );

	if( _newCapacity < m_Size ) { // Downsizing capacity case
		m_Size = _newCapacity;
	} // TODO(*): Check for memory re-allocations in shrinking case

	for( size_t i = 0; i < m_Size; i++ ) {
		//newArr[i] = m_Arr[i];
		newArr[i] = std::move( m_Arr[i] );
	}

	delete[] m_Arr;

	// TODO(*): Use initial m_Size in case of shrinking
	// TODO(*): Использовать изначальный m_Size в случае сокращения ёмкости
	//for ( size_t i = 0; i < m_Size; i++ ) {
	//	m_Arr[i].~T();
	//}

	//::operator delete( m_Arr, m_Capacity * sizeof( T ) );

	m_Arr = newArr;
	m_Capacity = _newCapacity;
}

#else
template <typename T>
void vector<T>::realloc( size_t _newCapacity )
{
	//T* newArr = new T[_newCapacity];
	T* newArr = (T*)( ::operator new( _newCapacity * sizeof( T ) ) );

	if( _newCapacity < m_Size ) { // Downsizing capacity case
		m_Size = _newCapacity;
	} // TODO(*): Check for memory re-allocations in shrinking case

	for( size_t i = 0; i < m_Size; i++ ) {
		//newArr[i] = m_Arr[i];
		//newArr[i] = std::move( m_Arr[i] );
		//new( &newArr[i] ) T( std::forward<T>( m_Arr[i] ) );
		new( &newArr[i] ) T( std::move( m_Arr[i] ) );
	}

	//delete[] m_Arr;

	// TODO(*): Use initial m_Size in case of shrinking
	// TODO(*): Использовать изначальный m_Size в случае сокращения ёмкости
	for( size_t i = 0; i < m_Size; i++ ) {
		m_Arr[i].~T();
	}

	::operator delete( m_Arr, m_Capacity * sizeof( T ) );

	m_Arr = newArr;
	m_Capacity = _newCapacity;
}
#endif // 0
