// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "strings.h"
//#include <string>

int main()
{
	setlocale( LC_ALL, "ru" );

	str::string strLine( "Слово другое" );
	str::string strW;
	std::cout << strLine << "\n";
	std::cout << strLine.getword() << ' ' << strLine.getword().getlength() << "\n";
	std::cout << strLine.getword( 3 ) << ' ' << strLine.getword( 3 ).getlength() << "\n\n";
	std::cout << strLine.getword( 6 ) << ' ' << strLine.getword( 6 ).getlength() << "\n\n";
	strW.getword( strLine, 3 ); std::cout << strW << ' ' << strW.getlength() << '\n';
	strLine.push_head( 'A' );
	strLine.cout(); std::cout << std::endl;
	strLine.push_head( "AБВ" );
	std::cout << strLine << std::endl;
	
	strLine.pop_head();
	std::cout << strLine << std::endl;

	strLine.pop_back();
	std::cout << strLine << std::endl;

	strLine.push_back( 'К' );
	std::cout << strLine << std::endl;
	strLine.push_back( "ОНЕЦ" );
	std::cout << strLine << std::endl;

	strLine.getline();
	strLine.cout(); std::cout << std::endl;

	//str::string str1( "Hello" );
	//std::cout << "str1 == " << str1 << std::endl;

	//str::string str2( "World" );
	//std::cout << "str2 == " << str2 << std::endl;

	//str::string result;
	//result = str1 + str2;

	//std::cout << "result = str1 + str2 == " << result << std::endl;
	//int i = 5;
	//std::cout << "result[" << i + 1 << "] == " << result[i] << std::endl;
	//std::cout << "str1.getlenght() == " << str1.getlength() << std::endl;

	//str::string result2 = str2;
	//result2 += str1; // result = result + str1;
	//std::cout << "result2 += str1 == " << result2 << std::endl;

	/*std::cin >> str1;
	str2.cin();
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	str1.getline();
	std::cout << "str1.getline();\n" << str1 << std::endl;*/

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
