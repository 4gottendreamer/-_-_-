#pragma once

template<typename T, size_t TSize>
class array
{
public:
	constexpr size_t size() const { return TSize; }

	T& operator[]( size_t _index ) { return this->m_Arr[_index]; }
	const T& operator[]( size_t _index ) const { return this->m_Arr[_index]; }
	
	T* data() { return this->m_Arr; } // For  memset( this->data(), 0, this->size() * sizeof( T ) );
	const T* data() const { return this->m_Arr; }
private:
	T m_Arr[TSize];
};

template<typename T, size_t TSize>
inline constexpr size_t array<T, TSize>::size() const
{
	return TSize;
}

template<typename T, size_t TSize>
T& array<T, TSize>::operator[]( size_t _index )
{
	return this->m_Arr[_index];
}
