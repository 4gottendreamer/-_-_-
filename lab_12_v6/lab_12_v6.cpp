// lab_12_v6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Вариант №6.
/*
Информация о студентах размещается в двух двоичных файлах.
В первом файле:
фамилия,
имя,
отчество,
курс,
оценки
	по физике,
	математике,
	программированию.
Во втором файле для тех же студентов в том же порядке:
фамилия,
имя,
отчество,
пол,
год рождения.
Отсортировать записи в обоих файлах по возрастанию количества пятёрок по всем предметам.
Вывести на экран фамилии студентов первого курса,
у которых количество пятёрок больше указанного пользователем значения.
*/

#include <iostream>
#include <fstream>
#include "..\string\string.h"
#include "..\vector\vector.h"
#include "lab_12_v6_struct.h"


int main()
{
	std::ifstream inFile;
	//std::ofstream outFile( "IDbook.txt", std::ios::app );
	
	// Открытие файла
	inFile.open( "db_score.txt" );
	
	vector<ID_score> db_Score;
	vector<ID> db_Years;
	ID_score tmp_Score;

	// Ввод данных из файла
	while( !inFile.eof() ) {
		inFile >> tmp_Score;
		db_Score.push_back( tmp_Score );
		std::cout << tmp_Score << std::endl;
	}
	
	inFile.close();
	inFile.open( "db_years.txt" );
	ID tmp_Years;
	while( !inFile.eof() ) {
		inFile >> tmp_Years;
		db_Years.push_back( tmp_Years );
		std::cout << tmp_Years << std::endl;
	}

	std::cout << "****************************" << std::endl;

	for( auto& elem : db_Score ) {
		std::cout << elem << std::endl;
	}
	std::cout << std::endl;
	for( auto& elem : db_Years ) {
		std::cout << elem << std::endl;
	}

}

// TODO: look for std::tuple;
