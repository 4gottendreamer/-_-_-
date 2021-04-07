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
//#include "..\string\string.h"
#include "..\vector\vector.h"
#include "..\algorithms\algorithms.h"
#include "lab_12_v6_struct.h"

int main( int argc, char* argv[] )
{
	/*
	* 1.+	Ввод файла 1 (оценки) в вектор
	* 2.+	Ввод файла 2 (годы рождения) в вектор
	* 3.+	Создание массива-шаблона вектора оценок
	* 4.+	Сортировка шаблона оценок
	* 5.+-	Перестановка элементов векторов согласно порядку в шаблоне
	* 6.+	Вывод векторов в файлы
	* 7.+	Вывод в консоль фамилий в отсортированном порядке с фильром по курсу
	*/

	setlocale( LC_ALL, "ru" ); // Установка корректного вывода кириллицы

	std::ifstream inFile;

	vector<ID_score> db_Score;	// Контейнер для данных студентов, курсов и оценок
	vector<ID> db_Years;		// Контейнер для данных студентов и годов рождения

	std::cout << "Program begin" << std::endl;
	// Открытие файла оценок
	//inFile.open( "db_score.txt" );
	std::cout << argv[1] << std::endl;
	inFile.open( argv[1] );

	// Ввод данных из файла оценок
	while (!inFile.eof()) {
		ID_score tmp_Score;
		if (inFile >> tmp_Score) {
			db_Score.push_back( tmp_Score );
		}
	}
	inFile.close();
	
	// Открытие файла годов рождения
	//inFile.open( "db_years.txt" );
	std::cout << argv[2] << std::endl;
	inFile.open( argv[2] );

	// Ввод данных из файла годов рождения
	while (!inFile.eof()) {
		ID tmp_Years;
		if (inFile >> tmp_Years) {
			db_Years.push_back( tmp_Years );
		}
	}

	// Вывод списков в консоль
	std::cout << "Студенты, курс, оценки:\n" << std::endl;
	for (auto& elem : db_Score) {
		std::cout << elem << std::endl;
	}
	std::cout << std::endl << "Студенты, пол, год рождения:\n" << std::endl;
	for (auto& elem : db_Years) {
		std::cout << elem << std::endl;
	}
	std::cout << "\nКоличество студендов: " << db_Years.size() << std::endl;

	// Создание характеристического шаблона
	int** Trace;
	Trace = new int* [2];
	Trace[0] = new int[db_Score.size()];
	Trace[1] = new int[db_Score.size()];
	for (size_t i = 0; i < db_Score.size(); i++) {
		// Лямбда-функция вставлена для проверки функционала C++11
		auto Fives = [&db_Score]( int _i )->int {
			int fiveCount = 0;
			db_Score[_i].Math == 5 ? fiveCount++ : 0;
			db_Score[_i].Phys == 5 ? fiveCount++ : 0;
			db_Score[_i].Prog == 5 ? fiveCount++ : 0;
			return fiveCount;
		};
		Trace[0][i] = Fives( i );
		Trace[1][i] = (int)i;
	}

	// Сортировка шаблона по возрастанию количества оценок '5'
	alg::sort_bubble2_up( Trace, 2, db_Score.size() );

	std::ofstream outFile( "output.txt" );
	std::ofstream out_Years( "out_Years.txt" );
	std::ofstream out_Score( "out_Score.txt" );

	// Вывод результатов в файлы
	for (size_t j = 0; j < db_Score.size(); j++) {
		//std::cout << db_Years[Trace[1][j]] << std::endl;
		out_Years << db_Years[Trace[1][j]] << std::endl;
	}
	std::cout << "----------------" << std::endl;
	for (size_t j = 0; j < db_Score.size(); j++) {
		//std::cout << db_Score[Trace[1][j]] << std::endl;
		out_Score << db_Score[Trace[1][j]] << std::endl;
	}

	std::cout << std::endl << "Фильтр по первокурсникам" << std::endl;
	std::cout << std::endl << "Введите порог количества оценок '5': ";
	int threshold;
	std::cin >> threshold;
	for (size_t j = 0; j < db_Score.size(); j++) {
		// Проверка прохождения порога фильтрации среди первокурсников
		if (db_Score[Trace[1][j]].Course == 1 and Trace[0][j] > threshold) {
			std::cout << db_Score[Trace[1][j]].LastName << std::endl; // Вывод в консоль фамилии
			outFile << db_Score[Trace[1][j]] << std::endl; // Вывод в файл
		}
	}

	outFile.close();
	out_Years.close();
	out_Score.close();

	std::cout << "Нажмите Enter";
	std::cin.get(); std::cin.get();
}
