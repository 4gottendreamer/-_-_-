// lab_13_v6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Вариант 6.
/*
	ЧАСТЬ 1
Разработайте определение класса Man, описывающего тип «Человек».
Элементы - данные класса:
+	фамилия
+	имя,
+	отчество,
+	возраст,
+	адрес человека.
Предусмотрите следующие конструкторы класса:
+	-по умолчанию;
+	-получающий параметры;
+	-копирования.
Включите в класс деструктор, который освобождает память,
динамически выделенную при создании объекта класса.
Напишите функции – методы класса для:
+	-ввода с клавиатуры данных о человеке;
+	-вывода на экран данных о человеке;
+	-определения, является ли человек избирателем, если учитывать только его возраст;
+	-определения совпадения фамилии человека с некоторой заданной.
В основной программе среди всех объектов типа Man выведите всех избирателей с заданной фамилией.

	ЧАСТЬ 2
Модифицируйте класс, разработанный вами при выполнении лабораторной работы №13 (часть 1),
выполнив перегрузку следующих стандартных операций для их использования по отношению
к объектам созданного класса:
++	- присваивание =;
++	- вставка в поток << и извлечение из потока >> для выполнения ввода-вывода объектов класса;
++	- операции, указанные в варианте задания.
В основной программе необходимо продемонстрировать работу перегруженных операций.
Вариант 6.
Для класса Man, описывающего тип «Человек», помимо операций, перечисленных в общей постановке задачи,
перегрузите следующие стандартные операции:
++	– операцию « + » для увеличения возраста человека на заданное целое число;
	// не теряя общности и семантики использования, также перегружен operator+=()
++	– операцию « == » для определения совпадения фамилии человека с некоторой заданной.
*/

#include <iostream>
#include "..\\string\string.h"
#include "..\\vector\vector.h"
#include "Man.h"

int main()
{
	setlocale( LC_ALL, "ru" );

	// Объявление с полной инициализацией
	Man PKorchagin( "Корчагин",
					"Павел",
					"Андреевич",
					24, "Бердянск", "Центральная", 29, 7 );
	// Объявление
	Man	man_1,					// Конструктор
		man_2,					// по
		man_3,					// умолчанию
		man_4,

		JohnDoe1( "default" ),	// Конструктор с параметрами
		JohnDoe2( DEFAULT );	// Конструктор с параметрами

	vector<Man> manyMen;

	// Сравнения
	// operator==()
	std::cout << "(JohnDoe1 == JohnDoe2) == " << ( JohnDoe1 == JohnDoe2 ) << std::endl;
	std::cout << "(JohnDoe1 == \"Doe\") == " << ( JohnDoe1 == "Doe" ) << std::endl;
	str::string strD( "Doe" );
	std::cout << "(JohnDoe1 == str::string Doe(\"Doe\")) == " << ( JohnDoe1 == strD ) << std::endl;

	// Сравнения
	// operator==()
	JohnDoe2.setlname( "Daw" );
	std::cout << "(JohnDoe1 == JohnDoe2) == " << ( JohnDoe1 == JohnDoe2 ) << std::endl;
	std::cout << "(JohnDoe1 == \"Daw\") == " << ( JohnDoe1 == "Daw" ) << std::endl;
	strD = "Daw";
	std::cout << "(JohnDoe1 == str::string Daw(\"Daw\")) == " << ( JohnDoe1 == strD ) << std::endl;

	manyMen.push_back( PKorchagin );
	manyMen.push_back( JohnDoe1 );
	manyMen.push_back( JohnDoe2 );

	man_1.inputf();				// Ввод данных с клавиатуры
	manyMen.push_back( man_1 );

	// Присваивание
	// operator=()
	std::cout << "Man man_2 = man_1;" << std::endl;
	man_2 = man_1;

	// Сложение с присваиванием
	// operator+=()
	std::cout << "man_2 += 20;" << std::endl;
	man_2 += 20;
	manyMen.push_back( man_2 );
	// operator+()
	man_3 = man_2 + 10;
	manyMen.push_back( man_3 );

	// Оператор ввода из потока
	// operator>>()
	std::cout << "std::cin >> man_4;" << std::endl;
	std::cin >> man_4;
	manyMen.push_back( man_4 );
	std::cout << std::endl << std::endl;

	// Вывод списка
	for( auto& oneof : manyMen ) {
		std::cout << std::endl;
		oneof.printf();						// Форматированный вывод
		std::cout << std::endl << std::endl;
		std::cout << oneof << std::endl;	// Вывод в поток
		std::cout << std::endl;
	}

	std::cout << "Введите фамилию для проверки: ";
	std::cin >> strD;
	bool match = false;
	std::cout << "Совпадения:" << std::endl;
	for( auto& oneof : manyMen ) {
		if( oneof == strD ) {
			std::cout << std::endl;
			oneof.printf();
			match = true;
		}
	}
	if( !match ) {
		std::cout << "Не найдены." << std::endl;
	}

	return 0;
}
