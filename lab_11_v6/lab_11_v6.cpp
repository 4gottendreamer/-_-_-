// lab_11_v6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант №6.
/*
 На основе записной книжки, содержащей сведения о людях (
 фамилия,
 год рождения,
 адрес  - город,
		- улица,
		- номер дома,
		- квартиры,
 место работы или учебы),
 вывести на печать фамилии и адреса лиц,
 живущих в Красноярске по улице Киренского, и расположить список в алфавитном порядке.
*/

#include <iostream>
#include <fstream>

#include "..\string\string.h"
#include "..\vector\vector.h"
#include "..\lab_11_v6\lab_11_v6_struct.h"

void sort_name_az( vector<ID>& _Container );
void sort_name_za( vector<ID>& _Container );

int main()
{
	vector<ID> DataBase;

	std::ifstream inFile;
	//std::ofstream outFile( "IDbook.txt", std::ios::app );

	inFile.open( "IDbook.txt" );
	if( !inFile.is_open() ) {
		std::cerr << "Error opening file.";
		exit( 1 );
	}
	else std::cout << "File opened\n" << std::endl;

	ID tmp;

	// Data input from file
	// Ввод данных из файла
	while( !inFile.eof() ) {
		inFile >> tmp;
		DataBase.push_back( tmp );
	}

	// Data output to console
	// Вывод данных в консколь
	for( size_t i = 0; i < DataBase.size(); i++ ) {
		std::cout << DataBase[i];
		std::cout << "-------------\n";
	}

	// Database filtering
	vector<ID> db_fetched;
	for( size_t i = 0; i < DataBase.size(); i++ ) {
		if( DataBase[i].nameLast == "Krasnoyarsk" ) {
			db_fetched.push_back( DataBase[i] );
		}
	}

	std::cout << "\n----------- Sorting -------------\n";
	// Sorting by name in accending order
	// Сортировка по имени в порядке возрастания
	sort_name_az( db_fetched );

	// Output
	// Вывод
	for( size_t i = 0; i < db_fetched.size(); i++ ) {
		std::cout << db_fetched[i];
		std::cout << "------------\n";
	}

	inFile.close();

	/*
	1.+	Ввод данных (файл или консоль) в вектор
	2.+	Выборка по ключу в вектор (копия)
	3.	Сортировка выборки
	4.	Вывод
	*/
}

void sort_name_az( vector<ID>& _Container )
{
	bool isSwapped;
	do {
		isSwapped = false;
		for( size_t i = 0; i < _Container.size() - 1; i++ ) {
			if( _Container[i].nameLast > _Container[i + 1].nameLast ) {
				_Container.swap( i, i + 1 );
				isSwapped = true;
			}
		}
	}
	while( isSwapped );
}

void sort_name_za( vector<ID>& _Container )
{
	bool isSwapped;
	do {
		isSwapped = false;
		for( size_t i = 0; i < _Container.size() - 1; i++ ) {
			if( _Container[i].nameLast < _Container[i + 1].nameLast ) {
				_Container.swap( i, i + 1 );
				isSwapped = true;
			}
		}
	}
	while( isSwapped );
}
