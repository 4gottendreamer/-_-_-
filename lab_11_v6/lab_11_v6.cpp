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
#include "lab_11_v6_struct.h"
#include <variant>

void sort_name_az(vector<ID>& _Container);
void sort_name_za(vector<ID>& _Container);

int main()
{
	vector<ID> DataBase;
	std::ifstream inFile;
	//std::ofstream outFile( "IDbook.txt", std::ios::app );

	// Открытие файла
	inFile.open("IDbook.txt");
	if ( !inFile.is_open() ) {
		std::cerr << "Error opening file.";
		exit(1);
	}
	else std::cout << "File opened\n" << std::endl;

	ID tmp;

	// Ввод данных из файла
	while ( !inFile.eof() ) {
		inFile >> tmp;
		DataBase.push_back(tmp);
	}

	// Вывод данных в консколь
	for ( size_t i = 0; i < DataBase.size(); i++ ) {
		std::cout << i << "\t-------------\n";
		std::cout << DataBase[i];
		std::cout << "\t-------------\n\n";
	}

	// Выборка и копирование по ключам
	vector<ID> db_fetched;
	str::string QueryCity("Krasnoyarsk");			// Город
	str::string QueryStreet("Kirenskogo st.");	// Улица
	for ( size_t i = 0; i < DataBase.size(); i++ ) {
		if ( DataBase[i].address.city == QueryCity and
			DataBase[i].address.street == QueryStreet ) {
			db_fetched.push_back(DataBase[i]);
		}
	}

	std::cout << "\n----------- Sorting -------------\n";
	std::cout << "Key\tValue\n";
	std::cout << "City:\t" << QueryCity << std::endl;
	std::cout << "Street:\t" << QueryStreet << std::endl << std::endl;

	// Сортировка по имени в порядке возрастания
	sort_name_az(db_fetched);

	// Вывод
	for ( size_t i = 0; i < db_fetched.size(); i++ ) {
		//std::cout << db_fetched[i];
		/*std::cout << db_fetched[i].nameLast << std::endl;
		std::cout << db_fetched[i].address.street << ", "
				  << db_fetched[i].address.building << ", "
				  << db_fetched[i].address.apartment << std::endl;*/
		std::cout << db_fetched[i].nameLast << " | " << db_fetched[i].address << std::endl;
		std::cout << "------------\n";
	}

	inFile.close();
	std::cout << "Press Enter";
	std::cin.get();
}

void sort_name_az(vector<ID>& _Container)
{
	bool isSwapped;
	do {
		isSwapped = false;
		for ( size_t i = 0; i < _Container.size() - 1; i++ ) {
			if ( _Container[i].nameLast > _Container[i + 1].nameLast ) {
				_Container.swap(i, i + 1);
				isSwapped = true;
			}
		}
	}
	while ( isSwapped );
}

void sort_name_za(vector<ID>& _Container)
{
	bool isSwapped;
	do {
		isSwapped = false;
		for ( size_t i = 0; i < _Container.size() - 1; i++ ) {
			if ( _Container[i].nameLast < _Container[i + 1].nameLast ) {
				_Container.swap(i, i + 1);
				isSwapped = true;
			}
		}
	}
	while ( isSwapped );
}
