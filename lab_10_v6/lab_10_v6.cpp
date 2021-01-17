// lab_10_v6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант №6.
// В произвольном тексте, содержащем не более 10 строк, в каждой строке не более
// 80 символов, попарно переставить местами слова, стоящие на нечётных и чётных
// местах в строке. Вывести полученный текст на экран.
//

#include <iostream>
#include "..\string\string.h"
#include "..\vector\vector.h"

#if 0
template <typename Tarr, typename Tsize, typename Tsize_add>
void push_back( Tarr*& _Arr, Tsize _size, Tarr*& const _Arr_add, const Tsize_add _size_add )
{
	Tarr* newArray = new Tarr[( _size + (size_t)_size_add )];
	for ( int i = 0; i < _size; i++ ) {
		newArray[i] = _Arr[i];
	}
	for ( int i = _size; i < _size + _size_add; i++ ) {
		newArray[i] = _Arr_add[i - _size];
	}
	delete[] _Arr;
	_size += _size_add;
	_Arr = newArray;
}

template <typename Tarr, typename Tsize, typename Tsize_add>
void push_back( Tarr*& _Arr, Tsize _size, const Tarr* _Arr_add, const Tsize_add _size_add )
{
	Tarr* newArray = new Tarr[( _size + (size_t)_size_add )];
	for ( int i = 0; i < _size; i++ ) {
		newArray[i] = _Arr[i];
	}
	for ( int i = _size; i < _size + _size_add; i++ ) {
		newArray[i] = _Arr_add[i - _size];
	}
	delete[] _Arr;
	_size += _size_add;
	_Arr = newArray;
}

// Конкатенация символьных массивов (строк) _Arr и _Arr_add
// _Arr = _Arr + _Arr_add
void push_back( char*& _Arr, char* const& _Arr_add )
{
	size_t size = strlen( _Arr );
	size_t size_add = strlen( _Arr_add );
	char* newArray = new char[size + size_add + 1];
	for ( int i = 0; i < size; i++ ) {
		newArray[i] = _Arr[i];
	}
	for ( int i = size; i < size + size_add; i++ ) {
		newArray[i] = _Arr_add[i - size];
	}
	newArray[size + size_add] = '\0';
	delete[] _Arr;
	_Arr = newArray;
}

// Перегрузка push_back( char*, const char*& )
void push_back( char*& _Arr, const char*& _Arr_add )
{
	size_t size = strlen( _Arr );
	size_t size_add = strlen( _Arr_add );
	char* newArray = new char[size + size_add + 1];
	for ( int i = 0; i < size; i++ ) {
		newArray[i] = _Arr[i];
	}
	for ( int i = size; i < size + size_add; i++ ) {
		newArray[i] = _Arr_add[i - size];
	}
	newArray[size + size_add] = '\0';
	delete[] _Arr;
	_Arr = newArray;
}

// Проверяет, является ли символ <char>_symbol
// заглавной или строчной буквой английского или русского алфавита
bool IsSymbol( const char& _symbol )
{
	if ( ( _symbol >= 65 and _symbol <= 90 ) or	// English CAPITALS
		 ( _symbol >= 97 and _symbol <= 122 ) ) { // English lowercases
		return true;
	}
	if ( _symbol >= -128 and _symbol <= -15 ) { // Русские буквы
		return true;
	}
	return false;
}

// Возвращает указатель на строку с очередным словом из строки _Line
// Менает значение переменной _StartPos
// на индекс первого пробела после текущего слова в строке _Line
char* GetWord( char* _Line, int& _StartPos )
{
	// Если текущий символ не буква, сдвигаем каретку до первой буквы
	while ( !IsSymbol( _Line[_StartPos] ) ) {
		_StartPos++;
	}
	int CurPos = _StartPos; // Текущее начало слова == текущему концу слова

	// Подсчёт количества непрерывной цепочки букв
	while ( IsSymbol( _Line[CurPos] ) and _Line[CurPos] != '\0' and _Line[CurPos] != '\n' ) {
		CurPos++;
	}

	char* Word = new char[1];
	Word[0] = '\0';
	push_back( Word, 0, _Line + _StartPos, CurPos - _StartPos );
	push_back( Word, CurPos - _StartPos, "\0", strlen( Word ) );
	_StartPos = CurPos;
	return Word;
}
#endif // 0

const int MAX_LINES = 3; // максимальное количество строк

int main()
{
	setlocale( LC_ALL, "ru" ); // Установка корректного вывода кириллицы
	
	vector<str::string, MAX_LINES> arrTxt;
	for ( size_t i = 0; i < arrTxt.size(); i++ ) {
		str::string Tmp;
		Tmp.getline();
		arrTxt.push_back( Tmp );
	}

	for ( size_t i = 0; i < arrTxt.size(); i++ ) {
		arrTxt[i].cout();
		std::cout << '\n';
	}

	
	/*str::string* tmp = new str::string[MAX_LINES];
	for ( size_t i = 0; i < MAX_LINES; i++ ) {
		tmp[i].getline();
		std::cout << "[TEST:]\nline " << i << ":\n" << tmp[i] << std::endl;
	}
	str::string* Text = new str::string[MAX_LINES + 1];
	for ( size_t i = 0; i < MAX_LINES; i++ ) {
		Text[i] = tmp[i];
	}

	std::cout << "getline();\n";
	Text[MAX_LINES].getline();
	std::cout << "\nText[1..3].cout():\n";
	for ( size_t i = 0; i < MAX_LINES + 1; i++ ) {
		Text[i].cout();
		std::cout << std::endl;
	}*/

	/*str::string* Text = nullptr;
	for ( size_t i = 0; i < MAX_LINES; i++ ) {
		str::string* tmp = new str::string[i + 1];
		for ( int j = 0; j < i + 1; j++ ) {
			tmp[j].getline();
			std::cout << "line " << j << ":\t" << tmp[j] << std::endl;
		}
		delete[] Text;
		if ( tmp[i].size() ) {
			Text = new str::string[i + 1];
			for ( int j = 0; j < i + 1; j++ ) {
				Text[j] = tmp[j];
			}
		}
		else {
			Text = new str::string[i];
			for ( int j = 0; j < i; j++ ) {
				Text[j] = tmp[j];
				delete[] tmp;
				break;
			}
		}
		delete[] tmp;
	}

	std::cout << "\nText[1..n].cout():\n";
	for ( size_t i = 0; i < MAX_LINES; i++ ) {
		Text[i].cout();
		std::cout << std::endl;
	}*/

#if 0
	std::cout << "Hello World!\n";
	int LinesNumber = 0;
	char* cText[MAX_LINES];			// исходный текст
	char* cText_fixed[MAX_LINES];   // исправленный текст 
	char cLine[80];					// рабочая строка

	// Цикл ввода строк символов, пока не конец потока ввода (CTRL+Z) и кол-во строк не > 10
	//считываем очередную стоку в рабочую строку
	const char* Word = "";
	std::cout << "strlen( Word )\t" << strlen( Word ) << std::endl;
	/* while ( ( gets_s( cLine ) != NULL ) && ( i < MAX_LINES ) ) {
		size_t lineLenght = strlen( cLine );
		cText[i] = new char[lineLenght + 1];
		push_back( cText[i], 0, cLine, lineLenght );
		std::cout << lineLenght << std::endl;
	} */

	while ( std::cin.getline( cLine, 80 ) and ( LinesNumber < MAX_LINES ) ) {
		size_t lineLenght = strlen( cLine );
		cText[LinesNumber] = new char[lineLenght + 1];
		push_back( cText[LinesNumber], cLine );
		cText_fixed[LinesNumber] = new char[lineLenght];
		std::cout << lineLenght << std::endl;
		std::cout << cText[LinesNumber] << std::endl;
		LinesNumber++;
	}
	std::wcout << "step1" << std::endl;

	for ( int i = 0; i < LinesNumber; i++ ) {
		std::wcout << "line\t" << i << '\t' << cText[i];
		for ( int j = 0; j < strlen( cText_fixed[i] ); j++ ) {
			char* Word_odd = GetWord( cLine, j );
			char* Word_even = GetWord( cLine, j );
			push_back( cText_fixed[j], Word_even );
			push_back( cText_fixed[j], Word_odd );
			std::cout << cText_fixed[j];
			delete[]Word_odd;
			delete[]Word_even;
		}
	}

#endif // 0

#if 0
	const int m = 10;   // m - максимальное количество строк
	char* s[m],         // массив указателей на строки
		wstr[80];       // рабочая строка
	int i,              // текущий индекс строки
		j,              // текущий индекс символа в строке
		j1,
		dl_wstr,        // длина текущей вводимой строки
		kol_str,        // количество введенных строк
		inword = 0,     // местоположение: если находимся внутри слова, то inword=1, а если вне слова, то inword=0
		beg,            // индекс первой буквы слова
		dl_str,         // длина текущей строки
		dl_word;        // длина очередного выделенного слова
	system( "cls" );
	i = 0;
	setlocale( 0, "" );
	// Цикл ввода строк символов, пока не конец потока ввода (CTRL+Z) и кол-во строк не > 10
	while ( ( gets_s( wstr ) != NULL ) && ( i < 10 ) ) //считываем очередную стоку в рабочую строку
	{
		//выделяем динамически память для хранения введенной строки
		//адрес выделенной памяти сохраняем в массиве указателей на строки
		//размер выделенной памяти на 1 больше длины рабочей строки (для '\0')
		dl_wstr = strlen( wstr ) + 1;
		s[i] = new char[dl_wstr];
		//копируем содержимое рабочей строки в динамически выделенный участок памяти
		strcpy_s( s[i], dl_wstr, wstr );
		i++;
	}
	kol_str = i;
	for ( i = 0; i < kol_str; i++ ) // перебираем все введенные строки
	{
		dl_str = strlen( s[i] ); // определяем длину текущей строки
		for ( j = 0; j <= dl_str; j++ ) // движемся по строке
			if ( *( s[i] + j ) == ' ' || *( s[i] + j ) == '\0' || *( s[i] + j ) == ',' )
				// если встретили символ-разделитель
			{
				if ( inword == 1 ) // и этот символ первый после слова
				{
					dl_word = j - beg; // определяем длину текущего слова
					if ( dl_word % 2 ) // если длина нечетная, то
					// удаляем из слова средний символ, для чего сдвигаем все символы строки на одну позицию влево
					// после середины слова и до конца строки (включая '\0')
					{
						for ( j1 = beg + dl_word / 2; j1 < dl_str; j1++ )
							*( s[i] + j1 ) = *( s[i] + j1 + 1 );
						dl_str = dl_str - 1; // уменьшаем длину строки и
						j = j - 1; // индекс текущего символа в строке
					}
					inword = 0; // теперь находимся вне слова
				}
			}
			else // если не разделитель
				if ( inword == 0 ) // и находимся вне слова,
				{
					inword = 1; // то встретили новое слово
					beg = j; // запоминаем индекс первого символа в слове
				}
	}
	// Выводим на экран преобразованный текст
	printf( "\nРезультат\n" );
	for ( i = 0; i < kol_str; i++ )
		puts( s[i] );
	std::cin.get();
#endif // 0

	system( "pause" );
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
