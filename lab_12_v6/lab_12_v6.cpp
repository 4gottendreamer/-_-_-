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
//#include <utility>
#include "..\string\string.h"
#include "..\vector\vector.h"
#include "lab_12_v6_struct.h"


int main()
{
	/*
	* 1.	Ввод файла 1 (оценки) в вектор
	* 2.	Ввод файла 2 (годы рождения) в вектор
	* 3.	Сортировка параллельная двух векторов по оценкам
	* 4.	Вывод векторов в файлы
	* 5.	Вывод в консоль фамилий в отсортированном порядке с фильром по курсу
	*/

	setlocale( LC_ALL, "ru" ); // Установка корректного вывода кириллицы
	std::ifstream inFile;
	//std::ofstream outFile( "IDbook.txt", std::ios::app );

	// Открытие файла
	inFile.open( "db_score.txt" );

	vector<ID_score> db_Score;
	vector<ID> db_Years;

	// Ввод данных из файла оценок
	while( !inFile.eof() ) {
		ID_score tmp_Score;
		if( inFile >> tmp_Score ) {
			db_Score.push_back( tmp_Score );
		}
		std::cout << tmp_Score << std::endl;
	}

	inFile.close();
	inFile.open( "db_years.txt" );
	// Ввод данных из файла годов рождения
	while( !inFile.eof() ) {
		ID tmp_Years;
		if( inFile >> tmp_Years ) {
			db_Years.push_back( tmp_Years );
		}
		std::cout << tmp_Years << std::endl;
	}

	int* Trace[2];
	Trace[0] = new int[db_Years.size()];
	Trace[1] = new int[db_Years.size()];
	std::cout << "\nTraces\n";
	for( size_t i = 0; i < db_Years.size(); i++ ) {
		auto Fives = [&db_Score](int _i)->int {
			short fiveCount = 0;
			db_Score[_i].Math == 5 ? fiveCount++ : fiveCount;
			db_Score[_i].Phys == 5 ? fiveCount++ : fiveCount;
			db_Score[_i].Prog == 5 ? fiveCount++ : fiveCount;
			return fiveCount;
		};
		Trace[0][i] = (int)i;
		Trace[1][i] = Fives(i);
		//Trace[1][i] = 5;
		std::cout << db_Score[i] << "\t[ " << Trace[1][i] << " ]" << std::endl;
	}

	std::cout << "****************************" << std::endl;

	std::ofstream outFile( "output.txt" );

	for( auto& elem : db_Score ) {
		std::cout << elem << std::endl;
	}
	std::cout << std::endl;
	for( auto& elem : db_Years ) {
		std::cout << elem << std::endl;
	}

	for( auto& elem : db_Years ) {
		outFile << elem << std::endl;
	}

	std::cout << "Первокуры" << std::endl;
	for( auto& elem : db_Score ) {
		if( elem.Course == 1 ) {
			outFile << elem << std::endl;
			std::cout << elem << std::endl;
		}
	}
}

// TODO: look for std::tuple;
