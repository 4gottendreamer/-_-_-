#include "strings.h"
using namespace str;

string::string()
{
	str = nullptr;
	length = 0;
}

string::string( char _Ch )
{
	this->str = new char[2];
	this->str[0] = _Ch;
	this->str[1] = '\0';
	this->length = 1;
}

string::string( char* _String )
{
	this->length = str::lenghthof( _String );
	this->str = new char[(size_t)this->length + 1];
	for ( int i = 0; i < this->length; i++ ) {
		this->str[i] = _String[i];
	}
	this->str[this->length] = '\0';
}

string::string( const char* _String )
{
	this->length = str::lenghthof( _String );
	this->str = new char[(size_t)this->length + 1];
	for ( int i = 0; i < this->length; i++ ) {
		this->str[i] = _String[i];
	}
	this->str[this->length] = '\0';
}

string::string( string&& _String ) noexcept
{
	this->length = _String.length;
	this->str = _String.str;
	_String.str = nullptr;
}

string::string( const string& _String )
{
	length = str::lenghthof( _String.str );
	this->str = new char[(size_t)length + 1];
	for ( int i = 0; i < length; i++ ) {
		this->str[i] = _String.str[i];
	}

	this->str[length] = '\0';
}

string::~string()
{
	delete[]( this->str );
}

string& string::operator=( const string& _String )
{
	if ( this->str != nullptr ) {
		delete[] str;
	}
	this->length = str::lenghthof( _String.str );
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
		delete[] str;
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
		delete[] str;
	}
	size_t thisLength = str::lenghthof( _ChArr );
	this->str = new char[thisLength + 1];
	for ( int i = 0; i < thisLength; i++ ) {
		this->str[i] = _ChArr[i];
	}
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
	size_t stringLength = (size_t)( str::lenghthof( _ChArr ) );
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
	return ( this->operator==( _ChArr ) );
}

bool string::operator!=( const string& _String )
{
	return !( this->operator==( _String ) );
}

bool string::operator!=( const char* _ChArr )
{
	return ( this->operator==( _ChArr ) );
}

char& string::operator[]( int _Index )
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
	char* tmp = new char[1024];
	SetConsoleCP( 1251 );
	std::cin >> tmp;
	SetConsoleCP( 866 );
	this->length = str::lenghthof( tmp );
	this->str = new char[(size_t)this->length + 1];
	for ( int i = 0; i < this->length; i++ ) {
		this->str[i] = tmp[i];
	}
	this->str[this->length] = '\0';
	delete[] tmp;
}

void string::getline()
{
	if ( this->str != nullptr ) {
		delete[] this->str;
	}
	char tmp[1024];
	SetConsoleCP( 1251 );
	std::cin.getline( tmp, 1024 );
	SetConsoleCP( 866 );
	this->length = str::lenghthof( tmp );
	this->str = new char[(size_t)this->length + 1];
	for ( int i = 0; i < this->length; i++ ) {
		this->str[i] = tmp[i];
	}
	this->str[this->length] = '\0';
	//delete[] tmp;
}

void string::cout()
{
	std::cout << this->str;
}

string string::getword() const
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

string string::getword( int _Index ) const
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

string& string::getword( const string& _String, int _Index )
{
	*this = _String.getword( _Index );
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

int string::getlength()
{
	return this->length;
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
	_String.str = new char[(size_t)_String.length + 1];
	for ( int i = 0; i < _String.length; i++ ) {
		_String.str[i] = tmp[i];
	}
	_String.str[_String.length] = '\0';
	delete[] tmp;
	return _inStream;
}

#if 0
std::istream& operator>> ( std::istream& _inStream, str::string& _str )
{
	std::istream::sentry s( _inStream, false ); // prepare the stream for input (flush output, skip leading whitespaces, error checking, etc)
	if ( s ) // is the stream ready?
	{
		// clear str as needed

		std::streamsize N = _inStream.width();
		if ( N == 0 ) N = ...; // set to max size of str, or numeric_limits<size_t>::max()

		char ch;
		while ( _inStream.get( ch ) ) // while not EOF or failure
		{
			// append ch to str, growing its capacity as needed

			if ( --N == 0 ) break; // max width reached?
			if ( !_inStream.peek( ch ) ) break; // EOF reached?
			if ( isspace( ch, _inStream.getloc() ) break; // trailing whitespace detected?
		}
	}

	_inStream.width( 0 ); // reset effect of std::setw()
		return _inStream;
}
#endif // 0

int str::lenghthof( const char* _String )
{
	int count = 0;
	while ( _String[count] != '\0' ) {
		count++;
	}
	return count;
}
