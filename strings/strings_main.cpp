// strings_main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "strings.h"
//#include <string>

int main()
{
	setlocale( LC_ALL, "ru" );

	int I = 2;
	int c_I = I;
	str::string strLine( "Слово другое" );
	str::string strW;
	std::cout << strLine << "\n";
	std::cout << strLine.pull_word() << ' ' << strLine.pull_word().size() << "\n";
	std::cout << strLine.pull_word( 3 ) << ' ' << strLine.pull_word( 3 ).size() << "\n\n";
	
	std::cout << "I == " << I << std::endl;
	str::string Tmp = strLine.pull_word_iter( I );
	std::cout << Tmp << ' ' << Tmp.size() << " ; I == " << I << "\n\n";

	std::cout << "c_I == " << c_I << std::endl;
	Tmp = strLine.pull_word( c_I );
	std::cout << Tmp << ' ' << Tmp.size() << " ; I == " << c_I << "\n\n";
	
	strW.pull_word( strLine, 3 ); std::cout << strW << ' ' << strW.size() << '\n';
	strLine.push_head( 'A' );
	strLine.cout(); std::cout << std::endl;
	strLine.push_head( "AБВ" );
	std::cout << strLine << std::endl;

	strLine.pop_head();
	std::cout << strLine << std::endl;

	strLine.pop_back();
	std::cout << strLine << std::endl;

	strLine.push_back( 'К' );
	std::cout << strLine << '\t' << strLine.size() << std::endl;
	strLine.push_back( "ОНЕЦ" );
	std::cout << strLine << strLine.size() << std::endl;

	str::string str1( "Hello" );
	std::cout << "str1 == " << str1 << std::endl;

	str::string str2( "World" );
	std::cout << "str2 == " << str2 << std::endl;

	str::string result;
	result = str1 + str2;

	std::cout << "result = str1 + str2 == " << result << std::endl;
	int i = 5;
	std::cout << "result[" << i + 1 << "] == " << result[i] << std::endl;
	std::cout << "str1.getlenght() == " << str1.size() << std::endl;

	str::string result2 = str2;
	result2 += str1; // result = result + str1;
	std::cout << "result2 += str1 == " << result2 << std::endl;

	//char* c = new char[81];
	//std::cout << "char* c = new char[81]; cin >> c\n";
	////std::ws( std::cin );
	//std::cin >> c;
	//std::cout << c << '\t' << str::lenghthof( c ) << std::endl;
	//std::cin >> c;
	//std::cout << c << '\t' << str::lenghthof( c ) << std::endl;

	/*std::cin >> str1;
	str2.cin();
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	str1.getline();
	std::cout << "str1.getline();\n" << str1 << std::endl;*/

	/*std::cout << "strLine.getline();\n";
	strLine.getline();
	strLine.cout();
	std::cout << strLine.size() << std::endl;

	str::string S;
	std::cout << "S.getline();\n";
	S.getline();
	S.cout();
	std::cout << S.size() << std::endl;

	std::cout << "std::cin >> S;\n";
	std::cin >> S;
	std::cout << S << '\t' << S.size() << std::endl;

	std::cout << "S.cin();\n";
	S.cin();
	std::cout << S << '\t' << S.size() << std::endl;*/

	/*std::string s;
	std::cout << s << "\tsize: " << s.size() << "\tcapacity: " << s.capacity() << std::endl;
	s = "abcdef";
	std::cout << s << "\tsize: " << s.size() << "\tcapacity: " << s.capacity() << std::endl;
	s.clear();
	std::cout << s << "\tsize: " << s.size() << "\tcapacity: " << s.capacity() << std::endl;
	std::cout << "resize( 2 )\n";
	s = "абв";
	std::cout << s.capacity() << std::endl;*/

	char A[] = "abcdefgh";
	char B[] = "ef";
	std::cout << A << '\n' << B << '\n';
	char* BinA = nullptr;
	int ALength = str::lenghthof( A );
	int BLength = str::lenghthof( B );
	if ( ALength < BLength ) {
		BinA = nullptr;
	}
	else {
		for ( size_t i = 0; i < (size_t)ALength - BLength + 1; i++ ) {
			bool match = false;
			int count = 0;
			for ( size_t j = 0; j < BLength; j++ ) {
				if ( A[i + j] == B[j] ) {
					count++;
				}
				else {
					break;
				}
				std::cout << "Matching character: " << A[i + j] << " == "  << B[j] << " count == " << count << "; BLength == " << BLength << std::endl;
				if ( count == BLength ) {
					match = true;
					std::cout << count << " == " << BLength << "; match == true\n";
				}
			}
			if ( match ) {
				BinA = &A[i];
				std::cout << BinA << std::endl;
				break;
			}
		}
	}
	if ( BinA ) {
		std::cout << BinA << '\t' << *BinA << std::endl;
	}
	else { std::cout << "No match" << std::endl << std::endl; }

	str::string sA( A );
	sA.cout(); std::cout << std::endl;
	str::string sB( B );
	sB.cout(); std::cout << std::endl;
	
	BinA = sA.find( sB );
	if ( BinA ) {
		std::cout << BinA << '\t' << *BinA << std::endl;
	}
	else { std::cout << "No match" << std::endl << std::endl; }

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
