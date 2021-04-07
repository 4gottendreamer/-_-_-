#include "string.h"
using namespace str;

string::string()
	: m_Length( 0 )
	, m_Str( nullptr )
{
	//std::cout << "string()\n";
	/*m_Str = nullptr;
	m_Str = nullptr;*/
}

string::string( char _Ch )
	: m_Length( 1 )
{
	//std::cout << "string( char )\n";
	//this->m_Length = 1;
	this->m_Str = new char[2];
	this->m_Str[0] = _Ch;
	this->m_Str[1] = '\0';
}

string::string( char* _String )
{
	//std::cout << "string( char* )\n";
	this->m_Length = str::lenghthof( _String );
	this->m_Str = new char[this->m_Length + 1];
	for (int i = 0; i < this->m_Length; i++) {
		this->m_Str[i] = _String[i];
	}
	this->m_Str[this->m_Length] = '\0';
}

string::string( const char* _String )
{
	//std::cout << "string( const char* )\n";
	this->m_Length = str::lenghthof( _String );
	this->m_Str = new char[this->m_Length + 1];
	for (int i = 0; i < this->m_Length; i++) {
		this->m_Str[i] = _String[i];
	}
	this->m_Str[this->m_Length] = '\0';
}

string::string( string&& _String ) noexcept
	: m_Length( _String.m_Length )
	, m_Str( _String.m_Str )
{
	//std::cout << "string( string&& )\n";
	//this->m_Length = _String.m_Length;
	//this->m_Str = _String.m_Str;
	_String.m_Length = 0;
	_String.m_Str = nullptr;
}

string::string( const string& _String )
	: m_Length( str::lenghthof( _String.m_Str ) )
{
	//std::cout << "string( const string& )\n";
	//m_Length = str::lenghthof( _String.m_Str );
	this->m_Str = new char[m_Length + 1];
	for (int i = 0; i < m_Length; i++) {
		this->m_Str[i] = _String.m_Str[i];
	}
	this->m_Str[m_Length] = '\0';
}

string::~string()
{
	//std::cout << "~string()\n";
	m_Length = 0;
	delete[]( this->m_Str );
	//::operator delete( m_Str, ( str::lenghthof( m_Str ) + 1 ) * sizeof( char ) );
}

string& string::operator=( const string& _String )
{
	if (this->m_Str != nullptr) {
		delete[] this->m_Str;
	}
	this->m_Length = _String.m_Length;
	this->m_Str = new char[this->m_Length + 1];
	for (int i = 0; i < m_Length; i++) {
		this->m_Str[i] = _String.m_Str[i];
	}
	this->m_Str[this->m_Length] = '\0';
	return *this;
}

string& string::operator=( string&& _String ) noexcept
{
	if (this != &_String) {
		delete[] this->m_Str;

		this->m_Length = _String.m_Length;
		this->m_Str = _String.m_Str;

		_String.m_Length = 0;
		_String.m_Str = nullptr;
	}

	return *this;
}

string& string::operator=( const char _Ch )
{
	if (this->m_Str != nullptr) {
		delete[] this->m_Str;
	}
	this->m_Length = 1;
	this->m_Str = new char[2];
	this->m_Str[0] = _Ch;
	this->m_Str[1] = '\0';
	return *this;
}

string& string::operator=( const char* _ChArr )
{
	if (this->m_Str != nullptr) {
		delete[] this->m_Str;
	}
	size_t thisLength = str::lenghthof( _ChArr );
	this->m_Str = new char[thisLength + 1];
	for (int i = 0; i < thisLength; i++) {
		this->m_Str[i] = _ChArr[i];
	}
	this->m_Length = (int)thisLength;
	this->m_Str[thisLength] = '\0';
	return *this;
}

string string::operator+( const string& _String )
{
	string newString;
	size_t thisLength = this->m_Length;
	size_t stringLength = _String.m_Length;
	newString.m_Length = thisLength + stringLength;
	newString.m_Str = new char[thisLength + stringLength + 1];
	int i = 0;
	for (; i < thisLength; i++) {
		newString.m_Str[i] = this->m_Str[i];
	}
	for (int j = 0; j < stringLength; j++, i++) {
		newString.m_Str[i] = _String.m_Str[j];
	}
	newString.m_Str[thisLength + stringLength] = '\0';
	return newString;
}

string string::operator+( const char _Ch )
{
	string newString;
	newString.m_Length = this->m_Length + 1;
	newString.m_Str = new char[newString.m_Length + 1];
	for (int i = 0; i < this->m_Length; i++) {
		newString.m_Str[i] = this->m_Str[i];
	}
	newString.m_Str[newString.m_Length - 1] = _Ch;
	newString.m_Str[newString.m_Length] = '\0';
	return newString;
}

string string::operator+( const char* _ChArr )
{
	string newString;
	size_t thisLength = this->m_Length;
	size_t stringLength = str::lenghthof( _ChArr );
	newString.m_Length = thisLength + stringLength;
	newString.m_Str = new char[thisLength + stringLength + 1];
	int i = 0;
	for (; i < thisLength; i++) {
		newString.m_Str[i] = this->m_Str[i];
	}
	for (int j = 0; j < stringLength; j++, i++) {
		newString.m_Str[i] = _ChArr[j];
	}
	newString.m_Str[thisLength + stringLength] = '\0';
	return newString;
}

void string::operator+=( const string& _String )
{
	this->operator=( this->operator+( _String ) );
	/*size_t thisLength = this->m_Length;
	size_t stringLength = _String.m_Length;
	this->m_Length = thisLength + stringLength;
	char* tmpstr = new char[thisLength + stringLength + 1];
	int i = 0;
	for ( ; i < thisLength; i++ ) {
		tmpstr[i] = this->m_Str[i];
	}
	for ( int j = 0; j < stringLength; j++, i++ ) {
		tmpstr[i] = _String.m_Str[j];
	}
	tmpstr[thisLength + stringLength] = '\0';
	delete[]( this->m_Str );
	this->m_Str = tmpstr;*/
}

void string::operator+=( const char _Ch )
{
	this->operator=( this->operator+( _Ch ) );
}

void string::operator+=( const char* _ChArr )
{
	this->operator=( this->operator+( _ChArr ) );
}

bool string::operator==( const string& _String )
{
	if (this->m_Length != _String.m_Length) {
		return false;
	}
	for (int i = 0; i < this->m_Length; i++) {
		if (this->m_Str[i] != _String.m_Str[i]) {
			return false;
		}
	}
	return true;
}

bool string::operator==( const char* _ChArr )
{
	//return ( this->operator==( (string&)_ChArr ) );

	if (this->m_Length != str::lenghthof( _ChArr )) {
		return false;
	}
	for (int i = 0; i < this->m_Length; i++) {
		if (this->m_Str[i] != _ChArr[i]) {
			return false;
		}
	}
	return true;
}

bool string::operator!=( const string& _String )
{
	return !(this->operator==( _String ));
}

bool string::operator!=( const char* _ChArr )
{
	return !(this->operator==( _ChArr ));
}

//bool string::operator<( const string& _String )
//{
//	if( strcmp2( this->m_Str, _String.m_Str ) < 0 ) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}

bool string::operator<( const string& _String )
{
	if (this->m_Length and _String.m_Length) {
		size_t lesserLength = this->m_Length < _String.m_Length ? this->m_Length : _String.m_Length;
		for (size_t i = 0; i < lesserLength; i++) {
			//std::cout << lesserLength << std::endl;
			//std::cout << this->m_Str[i] << std::endl;
			//std::cout << _String.m_Str[i] << std::endl;
			if (this->m_Str[i] < _String.m_Str[i]) {
				return true;
			}
			else if (this->m_Str[i] == _String.m_Str[i]) {
				continue;
			}
			else {
				return false;
			}
		}
	}
	if (this->m_Length == 0 and _String.m_Length == 0) {
		return false;
	}
	if (this->m_Length == 0 and _String.m_Length != 0) {
		return true;
	}
	if (this->m_Length != 0 and _String.m_Length == 0) {
		return false;
	}
}

bool string::operator<=( const string& _String )
{
	if (this->m_Str != NULL and _String.m_Str != NULL) {
		size_t lesserLength = this->m_Length < _String.m_Length ? this->m_Length : _String.m_Length;
		for (size_t i = 0; i < lesserLength; i++) {
			if (this->m_Str[i] <= _String.m_Str[i]) {
				return true;
			}
			else if (this->m_Str[i] == _String.m_Str[i]) {
				continue;
			}
			else {
				return false;
			}
		}
	}
	if (this->m_Length == 0 and _String.m_Length == 0) {
		return true;
	}
	if (this->m_Length == 0 and _String.m_Length != 0) {
		return true;
	}
	if (this->m_Length != 0 and _String.m_Length == 0) {
		return false;
	}
}

bool string::operator>( const string& _String )
{
	if (this->m_Str != NULL and _String.m_Str != NULL) {
		if (strcmp( this->m_Str, _String.m_Str ) > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	if (this->m_Length == 0 and _String.m_Length == 0) {
		return false;
	}
	if (this->m_Length == 0 and _String.m_Length != 0) {
		return false;
	}
	if (this->m_Length != 0 and _String.m_Length == 0) {
		return true;
	}
}

bool string::operator>=( const string& _String )
{
	if (this->m_Str != NULL and _String.m_Str != NULL) {
		if (strcmp( this->m_Str, _String.m_Str ) >= 0) {
			return true;
		}
		else {
			return false;
		}
	}
	if (this->m_Length == 0 and _String.m_Length == 0) {
		return true;
	}
	if (this->m_Length == 0 and _String.m_Length != 0) {
		return false;
	}
	if (this->m_Length != 0 and _String.m_Length == 0) {
		return true;
	}
}

char& string::operator[]( size_t _Index )
{
	if (_Index > this->m_Length) {
		throw("Overlength indexing");
	}
	else {
		return this->m_Str[_Index];
	}
}

void string::cin()
{
	if (this->m_Str != nullptr) {
		this->clear();
	}
	char c;
	SetConsoleCP( 1251 );
	std::cin.get( c );
	while (c == ' ') {
		std::cin.get( c );
		if (c == '\n') {
			return;
		}
	}
	this->operator+=( c );
	while (std::cin.get( c ) and c != ' ' and c != '\n') {
		this->operator+=( c );
	}
	SetConsoleCP( 866 );

	/*
	delete[] this->m_Str;
	this->m_Str = new char;
	this->m_Length = 0;
	//char* tmp = new char[1024];
	setconsolecp( 1251 );
	std::cin >> this->m_Str;
	setconsolecp( 866 );
	*/

	this->m_Length = str::lenghthof( this->m_Str );

	/*
	delete[] this->m_Str;
	this->m_Str = new char[this->m_Length + 1];
	for ( int i = 0; i < this->m_Length; i++ ) {
		this->m_Str[i] = tmp[i];
	}
	this->m_Str[this->m_Length] = '\0';
	delete[] tmp;
	*/
}

void string::cingetline()
{
#if 1
	if (this->m_Str != nullptr) {
		this->clear();
	}

	//if ( this->m_Str != nullptr ) {
	//	//delete[] this->m_Str;
	//	/*this->m_Str = nullptr;
	//	this->m_Length = 0;*/
	//	this->erase();
	//}

	char c;
	SetConsoleCP( 1251 );
	while (std::cin.get( c ) and c != '\n') {
		this->operator+=( c );
	}
	SetConsoleCP( 866 );
#else
	char tmp[1024];
	{
		SetConsoleCP( 1251 );
		std::cin.getline( tmp, 1024 );
	}
	std::cout << "getline()\t" << tmp << std::endl;
	SetConsoleCP( 866 );
	this->m_Length = str::lenghthof( tmp );
	this->m_Str = new char[this->m_Length + 1];
	for (int i = 0; i < this->m_Length; i++) {
		this->m_Str[i] = tmp[i];
	}
#endif // 0
}

std::istream& str::string::fgetline( std::istream& _inStream )
{
	if (this->m_Str != nullptr) {
		this->clear();
	}

	//if ( this->m_Str != nullptr ) {
	//	//delete[] this->m_Str;
	//	/*this->m_Str = nullptr;
	//	this->m_Length = 0;*/
	//	this->erase();
	//}

	char c;
	//SetConsoleCP( 1251 );
	while (_inStream.get( c ) and c != '\n') {
		this->operator+=( c );
	}
	//SetConsoleCP( 866 );
	return _inStream;
}

void string::cout()
{
	std::cout << this->m_Str;
}

void string::coutnl()
{
	std::cout << this->m_Str << std::endl;
}

string string::pull_word() const
{
	string strWord;
	if (this->m_Str[0] == '\0') {
		return strWord;
	}
	int i = 0;
	while (this->m_Str[i] == ' ' or this->m_Str[i] == '\0') {
		i++;
	}
	while (this->m_Str[i] != ' ' and this->m_Str[i] != '\0') {
		strWord += this->m_Str[i];
		i++;
	}
	return strWord;
}

string string::pull_word( const size_t _Index ) const
{
	string strWord;
	size_t i = _Index;
	if (_Index == m_Length) {
		//if ( this->m_Str[i] == '\0' ) {
		return strWord;
	}
	while (this->m_Str[i] == ' ' /*or this->m_Str[i] == '\0'*/) {
		i++;
	}
	while (this->m_Str[i] != ' ' and this->m_Str[i] != '\0') {
		strWord += this->m_Str[i];
		i++;
	}
	return strWord;
}

string string::pull_word_iter( size_t& _Index ) const
{
	// TODO: Проверка на выход за длину строки
	string strWord;
#if 0
	int i = _Index;
	if (this->m_Str[i] == '\0') {
		return strWord;
	}
	while (this->m_Str[i] == ' ' or this->m_Str[i] == '\0') {
		i++;
	}
	while (this->m_Str[i] != ' ' and this->m_Str[i] != '\0') {
		strWord += this->m_Str[i];
		i++;
	}
#else
	if (_Index >= this->m_Length) {
		return strWord;
	}
	if (_Index == m_Length) {
		//if ( this->m_Str[_Index] == '\0' ) {
		return strWord;
	}
	while (this->m_Str[_Index] == ' ' /*or this->m_Str[_Index] == '\0'*/) {
		_Index++;
	}
	while (this->m_Str[_Index] != ' ' and this->m_Str[_Index] != '\0') {
		strWord += this->m_Str[_Index];
		_Index++;
	}
#endif // 0
	return strWord;
}

string& string::pull_word_iter( const string& _String, size_t& _Index )
{
	*this = _String.pull_word_iter( _Index );
	/*string strWord;
	if ( this->m_Str[_Index] == '\0' ) {
		return strWord;
	}
	while ( this->m_Str[_Index] == ' ' or this->m_Str[_Index] == '\0' ) {
		_Index++;
	}
	while ( this->m_Str[_Index] != ' ' and this->m_Str[_Index] != '\0' ) {
		strWord += this->m_Str[_Index];
		_Index++;
	}*/
	return *this;
}

string& string::pull_word( const string& _String, const size_t _Index )
{
	// TODO: вставьте здесь оператор return
	*this = _String.pull_word( _Index );
	return *this;
}

void string::push_back( const char _Ch )
{
	this->operator+=( _Ch );
}

void string::push_back( const string& _String )
{
	this->operator+=( _String );
}

void string::pop_back()
{
	char* tmp = new char[this->m_Length];
	for (int i = 0; i < this->m_Length; i++) {
		tmp[i] = this->m_Str[i];
		//std::cout << tmp[i - 1] << ' ' << this->m_Str[i] << std::endl;
	}
	this->m_Length = this->m_Length - 1;
	tmp[this->m_Length] = '\0';
	delete[] this->m_Str;
	this->m_Str = tmp;
}

void string::push_head( char _Ch )
{
	string newString( _Ch );
	newString += *this;
	*this = newString;
}

void string::push_head( const string& _String )
{
	string newString( _String );
	newString += *this;
	*this = newString;
}

void string::pop_head()
{
	char* tmp = new char[this->m_Length];
	for (int i = 1; i < this->m_Length; i++) {
		tmp[i - 1] = this->m_Str[i];
	}
	this->m_Length = this->m_Length - 1;
	tmp[this->m_Length] = '\0';
	delete[] this->m_Str;
	this->m_Str = tmp;
}

size_t string::size()
{
	return this->m_Length;
}

void string::clear()
{
	delete[] this->m_Str;
	this->m_Str = nullptr;
	this->m_Length = 0;
}

void str::string::erase( size_t _Index, size_t _Amount )
{
	// TODO: _Index out of rande checking
	char* tmp;
	if (_Amount < size() - _Index - 1) {

		m_Length -= _Amount;
		tmp = new char[m_Length + 1];
		for (size_t i = 0; i < _Index; i++) {
			tmp[i] = m_Str[i];
		}

		for (size_t i = _Index; i < m_Length; i++) {
			tmp[i] = m_Str[i + _Amount];
		}
	}
	else { // _Amount > size();
		m_Length = _Index;
		tmp = new char[m_Length + 1];
		for (size_t i = 0; i < m_Length; i++) {
			tmp[i] = m_Str[i];
		}
	}
	tmp[m_Length] = 0;
	delete[] m_Str;
	m_Str = tmp;
	tmp = nullptr;
}

bool str::string::empty()
{
	return size() == 0;
}

const char* str::string::c_str()
{
	return m_Str;
}

size_t string::begin()
{
	return 0;
}

size_t string::end()
{
	return this->m_Length;
}

size_t str::string::find( const char _Ch )
{
	for (size_t i = 0; i < this->m_Length + 1; i++) {
		if (this->m_Str[i] == _Ch) {
			return i;
		}
	}
	return -1;
}

size_t string::find( const char* _ChArr )
{
	size_t ChArrLength = str::lenghthof( _ChArr );
	if (ChArrLength > this->m_Length) {
		//return (size_t)nullptr;
		return -1;
	}
	else {
		for (size_t i = 0; i < this->m_Length - ChArrLength + 1; i++) {
			bool match = false;
			int count = 0;
			for (size_t j = 0; j < ChArrLength; j++) {
				if (this->m_Str[i + j] == _ChArr[j]) {
					count++;
				}
				else {
					break;
				}
				if (count == ChArrLength) {
					match = true;
				}
			}
			if (match) {
				return i;
			}
		}
	}
	//return nullptr;
	return -1;
}

size_t string::find( const string& _String )
{
	size_t StringLength = _String.m_Length;
	if (StringLength > this->m_Length) {
		//return nullptr;
		return -1;
	}
	else {
		for (size_t i = 0; i < this->m_Length - StringLength + 1; i++) {
			bool match = false;
			int count = 0;
			for (size_t j = 0; j < StringLength; j++) {
				if (this->m_Str[i + j] == _String.m_Str[j]) {
					count++;
				}
				else {
					break;
				}
				if (count == StringLength) {
					match = true;
				}
			}
			if (match) {
				return i;
			}
		}
	}
	//return nullptr;
	return -1;
}

/*
*
* FRIENDS
*
*/

std::ostream& str::operator<<( std::ostream& _outStream, const str::string& _String )
{
	_outStream << _String.m_Str;
	return _outStream;
}

std::istream& str::operator>>( std::istream& _inStream, str::string& _String )
{
	char* tmp = new char[1024];
	delete[] _String.m_Str;
	SetConsoleCP( 1251 );
	_inStream >> tmp;
	SetConsoleCP( 866 );
	_String.m_Length = str::lenghthof( tmp );
	_String.m_Str = new char[_String.m_Length + 1];
	for (int i = 0; i < _String.m_Length; i++) {
		_String.m_Str[i] = tmp[i];
	}
	_String.m_Str[_String.m_Length] = '\0';
	delete[] tmp;
	return _inStream;
}

size_t str::lenghthof( const char* _String )
{
	int count = 0;
	if (*_String != NULL) {
		while (_String[count] != '\0') {
			count++;
		}
	}
	return count;
}

//////////////////////////////////////////////////
int string::strcmp1( const char* str1, const char* str2 )
{
	std::cout << *str1 << std::endl;
	std::cout << *str2 << std::endl;
	if (str1 != NULL and str2 != NULL) {
		while (*str1 and *str2) {
			if (*str1 < *str2)
				return -1;
			if (*str1 > *str2)
				return 1;
			++str1;
			++str2;
		}
		return *str1 ? -1 : *str2 ? 1 : 0;
	}
	else
		return -1;
}

int string::strcmp2( const char* str1, const char* str2 )
{
	if (str1 != NULL and str2 != NULL) {
		while (*str1 and *str1 == *str2) {
			++str1, ++str2;
		}

		return
			((unsigned char)*str1 > (unsigned char)*str2) -
			((unsigned char)*str1 < (unsigned char)*str2);
	}
}

int string::strcmp3( const char* str1, const char* str2 )
{
	int i = 0;
	int flag = 0;
	while (flag == 0) {
		if (str1[i] > str2[i]) {
			flag = 1;
		}
		else if (str1[i] < str2[i]) {
			flag = -1;
		}
		if (str1[i] == '\0') {
			break;
		}
		i++;
	}
	return flag;
}

int string::strcmp4( const char* str1, const char* str2 )
{
	for (int i = 0; ; i++) {
		if (str1[i] != str2[i]) {
			return str1[i] < str2[i] ? -1 : 1;
		}
		if (str1[i] == '\0') {
			return 0;
		}
	}
}

int string::strcmp5( const char* str1, const char* str2 )
{
	while (*str1 and (*str1 == *str2)) {
		str1++;
		str2++;
	}
	return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

//////////////////////////////////////////////////