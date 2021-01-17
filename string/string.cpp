#include "string.h"
using namespace str;

string::string()
{
	//std::cout << "string()\n";
	str = nullptr;
	length = 0;
}

string::string( char _Ch )
{
	//std::cout << "string( char )\n";
	this->str = new char[2];
	this->str[0] = _Ch;
	this->str[1] = '\0';
	this->length = 1;
}

string::string( char* _String )
{
	//std::cout << "string( char* )\n";
	this->length = str::lenghthof( _String );
	this->str = new char[(size_t)this->length + 1];
	for ( int i = 0; i < this->length; i++ ) {
		this->str[i] = _String[i];
	}
	this->str[this->length] = '\0';
}

string::string( const char* _String )
{
	//std::cout << "string( const char* )\n";
	this->length = str::lenghthof( _String );
	this->str = new char[(size_t)this->length + 1];
	for ( int i = 0; i < this->length; i++ ) {
		this->str[i] = _String[i];
	}
	this->str[this->length] = '\0';
}

string::string( string&& _String ) noexcept
{
	//std::cout << "string( string&& )\n";
	this->length = _String.length;
	this->str = _String.str;
	_String.str = nullptr;
}

string::string( const string& _String )
{
	//std::cout << "string( const string& )\n";
	length = str::lenghthof( _String.str );
	this->str = new char[(size_t)length + 1];
	for ( int i = 0; i < length; i++ ) {
		this->str[i] = _String.str[i];
	}
	this->str[length] = '\0';
}

string::~string()
{
	//std::cout << "~string()\n";
	delete[]( this->str );
}

string& string::operator=( const string& _String )
{
	if ( this->str != nullptr ) {
		delete[] str;
	}
	this->length = _String.length;
	this->str = new char[(size_t)this->length + 1];
	for ( int i = 0; i < length; i++ ) {
		this->str[i] = _String.str[i];
	}
	this->str[this->length] = '\0';
	return *this;
}

string& string::operator=( const char _Ch )
{
	if ( this->str != nullptr ) {
		delete[] this->str;
	}
	this->length = 1;
	this->str = new char[2];
	this->str[0] = _Ch;
	this->str[1] = '\0';
	return *this;
}

string& string::operator=( const char* _ChArr )
{
	if ( this->str != nullptr ) {
		delete[] this->str;
	}
	size_t thisLength = str::lenghthof( _ChArr );
	this->str = new char[thisLength + 1];
	for ( int i = 0; i < thisLength; i++ ) {
		this->str[i] = _ChArr[i];
	}
	this->length = (int)thisLength;
	this->str[thisLength] = '\0';
	return *this;
}

string string::operator+( const string& _String )
{
	string newString;
	size_t thisLength = this->length;
	size_t stringLength = _String.length;
	newString.length = thisLength + stringLength;
	newString.str = new char[thisLength + stringLength + 1];
	int i = 0;
	for ( ; i < thisLength; i++ ) {
		newString.str[i] = this->str[i];
	}
	for ( int j = 0; j < stringLength; j++, i++ ) {
		newString.str[i] = _String.str[j];
	}
	newString.str[thisLength + stringLength] = '\0';
	return newString;
}

string string::operator+( const char _Ch )
{
	string newString;
	newString.length = this->length + 1;
	newString.str = new char[(size_t)newString.length + 1];
	for ( int i = 0; i < this->length; i++ ) {
		newString.str[i] = this->str[i];
	}
	newString.str[(size_t)newString.length - 1] = _Ch;
	newString.str[(size_t)newString.length] = '\0';
	return newString;
}

string string::operator+( const char* _ChArr )
{
	string newString;
	size_t thisLength = this->length;
	size_t stringLength = str::lenghthof( _ChArr );
	newString.length = thisLength + stringLength;
	newString.str = new char[thisLength + stringLength + 1];
	int i = 0;
	for ( ; i < thisLength; i++ ) {
		newString.str[i] = this->str[i];
	}
	for ( int j = 0; j < stringLength; j++, i++ ) {
		newString.str[i] = _ChArr[j];
	}
	newString.str[thisLength + stringLength] = '\0';
	return newString;
}

void string::operator+=( const string& _String )
{
	this->operator=( this->operator+( _String ) );
	/*size_t thisLength = this->length;
	size_t stringLength = _String.length;
	this->length = thisLength + stringLength;
	char* tmpstr = new char[thisLength + stringLength + 1];
	int i = 0;
	for ( ; i < thisLength; i++ ) {
		tmpstr[i] = this->str[i];
	}
	for ( int j = 0; j < stringLength; j++, i++ ) {
		tmpstr[i] = _String.str[j];
	}
	tmpstr[thisLength + stringLength] = '\0';
	delete[]( this->str );
	this->str = tmpstr;*/
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
	if ( this->length != _String.length ) {
		return false;
	}
	for ( int i = 0; i < this->length; i++ ) {
		if ( this->str[i] != _String.str[i] ) {
			return false;
		}
	}
	return true;
}

bool string::operator==( const char* _ChArr )
{
	//return ( this->operator==( (string&)_ChArr ) );

	if ( this->length != str::lenghthof( _ChArr ) ) {
		return false;
	}
	for ( int i = 0; i < this->length; i++ ) {
		if ( this->str[i] != _ChArr[i] ) {
			return false;
		}
	}
	return true;
}

bool string::operator!=( const string& _String )
{
	return !( this->operator==( _String ) );
}

bool string::operator!=( const char* _ChArr )
{
	return ( this->operator==( _ChArr ) );
}

char& string::operator[]( size_t _Index )
{
	if ( _Index >= this->length ) {
		throw( "Overlength indexing" );
	}
	else {
		return this->str[_Index];
	}
}

void string::cin()
{
	if ( this->str != nullptr ) {
		this->clear();
	}
	char c;
	SetConsoleCP( 1251 );
	std::cin.get( c );
	while ( c == ' ' ) {
		std::cin.get( c );
		if ( c == '\n' ) {
			return;
		}
	}
	this->operator+=( c );
	while ( std::cin.get( c ) and c != ' ' and c != '\n' ) {
		this->operator+=( c );
	}
	SetConsoleCP( 866 );

	/*
	delete[] this->str;
	this->str = new char;
	this->length = 0;
	//char* tmp = new char[1024];
	setconsolecp( 1251 );
	std::cin >> this->str;
	setconsolecp( 866 );
	*/

	this->length = str::lenghthof( this->str );

	/*
	delete[] this->str;
	this->str = new char[(size_t)this->length + 1];
	for ( int i = 0; i < this->length; i++ ) {
		this->str[i] = tmp[i];
	}
	this->str[this->length] = '\0';
	delete[] tmp;
	*/
}

void string::getline()
{
#if 1
	if ( this->str != nullptr ) {
		this->clear();
	}

	//if ( this->str != nullptr ) {
	//	//delete[] this->str;
	//	/*this->str = nullptr;
	//	this->length = 0;*/
	//	this->erase();
	//}

	char c;
	SetConsoleCP( 1251 );
	while ( std::cin.get( c ) and c != '\n' ) {
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
	this->length = str::lenghthof( tmp );
	this->str = new char[(size_t)this->length + 1];
	for ( int i = 0; i < this->length; i++ ) {
		this->str[i] = tmp[i];
	}
#endif // 0
}

void string::cout()
{
	std::cout << this->str;
}

string string::pull_word() const
{
	string strWord;
	if ( this->str[0] == '\0' ) {
		return strWord;
	}
	int i = 0;
	while ( this->str[i] == ' ' or this->str[i] == '\0' ) {
		i++;
	}
	while ( this->str[i] != ' ' and this->str[i] != '\0' ) {
		strWord += this->str[i];
		i++;
	}
	return strWord;
}

string str::string::pull_word( const int _Index ) const
{
	string strWord;
	int i = _Index;
	if ( this->str[i] == '\0' ) {
		return strWord;
	}
	while ( this->str[i] == ' ' or this->str[i] == '\0' ) {
		i++;
	}
	while ( this->str[i] != ' ' and this->str[i] != '\0' ) {
		strWord += this->str[i];
		i++;
	}
	return strWord;
}

string string::pull_word_iter( int& _Index ) const
{
	// TODO: Проверка на выход за длину строки
	string strWord;
#if 0
	int i = _Index;
	if ( this->str[i] == '\0' ) {
		return strWord;
	}
	while ( this->str[i] == ' ' or this->str[i] == '\0' ) {
		i++;
	}
	while ( this->str[i] != ' ' and this->str[i] != '\0' ) {
		strWord += this->str[i];
		i++;
	}
#else
	if ( this->str[_Index] == '\0' ) {
		return strWord;
	}
	while ( this->str[_Index] == ' ' or this->str[_Index] == '\0' ) {
		_Index++;
	}
	while ( this->str[_Index] != ' ' and this->str[_Index] != '\0' ) {
		strWord += this->str[_Index];
		_Index++;
	}
#endif // 0
	return strWord;
}

string& string::pull_word_iter( const string& _String, int& _Index )
{
	*this = _String.pull_word_iter( _Index );
	/*string strWord;
	if ( this->str[_Index] == '\0' ) {
		return strWord;
	}
	while ( this->str[_Index] == ' ' or this->str[_Index] == '\0' ) {
		_Index++;
	}
	while ( this->str[_Index] != ' ' and this->str[_Index] != '\0' ) {
		strWord += this->str[_Index];
		_Index++;
	}*/
	return *this;
}

string& str::string::pull_word( const string& _String, const int _Index )
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
	char* tmp = new char[(size_t)this->length];
	for ( int i = 0; i < this->length; i++ ) {
		tmp[i] = this->str[i];
		//std::cout << tmp[i - 1] << ' ' << this->str[i] << std::endl;
	}
	this->length = this->length - 1;
	tmp[this->length] = '\0';
	delete[] this->str;
	this->str = tmp;
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
	char* tmp = new char[(size_t)this->length];
	for ( int i = 1; i < this->length; i++ ) {
		tmp[i - 1] = this->str[i];
	}
	this->length = this->length - 1;
	tmp[this->length] = '\0';
	delete[] this->str;
	this->str = tmp;
}

size_t string::size()
{
	return this->length;
}

void string::clear()
{
	delete[] this->str;
	this->str = nullptr;
	this->length = 0;
}

size_t str::string::begin()
{
	return 0;
}

size_t str::string::end()
{
	return this->length;
}

char* str::string::find( const char* _ChArr )
{
	size_t ChArrLength = str::lenghthof( _ChArr );
	if ( ChArrLength > this->length ) {
		return nullptr;
	}
	else {
		for ( size_t i = 0; i < this->length - ChArrLength + 1; i++ ) {
			bool match = false;
			int count = 0;
			for ( size_t j = 0; j < ChArrLength; j++ ) {
				if ( this->str[i + j] == _ChArr[j] ) {
					count++;
				}
				else {
					break;
				}
				if ( count == ChArrLength ) {
					match = true;
				}
			}
			if ( match ) {
				return &( this->str[i] );
			}
		}
	}
	return nullptr;
}

char* str::string::find( const string& _String )
{
	size_t StringLength = _String.length;
	if ( StringLength > this->length ) {
		return nullptr;
	}
	else {
		for ( size_t i = 0; i < this->length - StringLength + 1; i++ ) {
			bool match = false;
			int count = 0;
			for ( size_t j = 0; j < StringLength; j++ ) {
				if ( this->str[i + j] == _String.str[j] ) {
					count++;
				}
				else {
					break;
				}
				if ( count == StringLength ) {
					match = true;
				}
			}
			if ( match ) {
				return &( this->str[i] );
			}
		}
	}
	return nullptr;
}

/*
*
* FRIENDS
*
*/

std::ostream& str::operator<<( std::ostream& _outStream, const str::string& _String )
{
	_outStream << _String.str;
	return _outStream;
}

std::istream& str::operator>>( std::istream& _inStream, str::string& _String )
{
	char* tmp = new char[1024];
	delete[] _String.str;
	SetConsoleCP( 1251 );
	_inStream >> tmp;
	SetConsoleCP( 866 );
	_String.length = str::lenghthof( tmp );
	_String.str = new char[_String.length + 1];
	for ( int i = 0; i < _String.length; i++ ) {
		_String.str[i] = tmp[i];
	}
	_String.str[_String.length] = '\0';
	delete[] tmp;
	return _inStream;
}

size_t str::lenghthof( const char* _String )
{
	int count = 0;
	while ( _String[count] != '\0' ) {
		count++;
	}
	return count;
}
