// lab_14_v6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Вариант 6
/*
Разработать шаблон класса «Двусвязный список»,
включающий в себя необходимый минимум методов,
обеспечивающий полноценное функционирование объектов указанного класса
при их использовании в программе, а именно:
++	1) конструкторы(по умолчанию, с параметрами, копирования);
++	2) деструктор;
+++	3) добавление элемента в начало, конец, заданную(по номеру) позицию списка;
+++	4) удаление элемента из начала, конца, заданной(по номеру) позиции списка;
++	5) поиск элемента – по значению и по номеру; // поиск по итератору
+	6) вывод списка на экран. // Вывод через итераторы методом аналогичным std::list
Разработать программу, содержащую меню, которое позволяет протестировать функции
добавления, удаления, поиска и вывода на экран элементов списка.
В качестве отдельного пункта меню добавить решение задачи в соответствии со своим вариантом.
При необходимости в разработанный шаблон класса добавить дополнительные методы,
если того требует решение задачи.
	7) MENU
		- Добавить элемент	// push_back();
		- Удалить элемент	// pop_back();
		- Поиск по значению	// find();
		- Вывод				// for(auto& iter : List) { std::cout << iter; }
	8)	- Решение задачи



Вариант №6.
Построить список из входной последовательности вещественных чисел.
Вывести список на экран.
Перестроить список, расположив узлы списка в порядке убывания числовых значений.
Вывести список на экран.
*/

#include <iostream>
#include <vector>
#include "..\list\list.h"

class Menu
{
public:
	Menu(std::vector<std::string> _Lines)
	{
		m_Lines = _Lines;
		m_LinesCount = _Lines.size();
	}

	~Menu() {}

	void PrintCls()
	{
		system("cls");
		for (auto& line : m_Lines) {
			std::cout << line << std::endl;
		}
	}

	void Print()
	{
		for (auto& line : m_Lines) {
			std::cout << line << std::endl;
		}
	}

private:
	std::vector<std::string> m_Lines;
	size_t m_LinesCount;
};

using TYPE = typename double;

int lab_14_v6()
{
	srand(time(NULL));		 // Установка генератора псевдослучайной последовательности чисел
	setlocale(LC_ALL, "ru"); // Установка корректного вывода кириллицы

	/*
	 std::cout
		<< "Вариант №6."
		<< "Построить список из входной последовательности вещественных чисел." << std::endl
		<< "Вывести список на экран." << std::endl
		<< "Перестроить список, расположив узлы списка в порядке убывания числовых значений." << std::endl
		<< "Вывести список на экран." << std::endl;
		*/

	my::list<TYPE> List;	// Объявление списка

	uint16_t choice0;
	do {
		system("cls");
		std::cout << "5 Задача варианта №6" << std::endl;

		std::cout
			<< "Построить список из входной последовательности вещественных чисел." << std::endl
			<< "Вывести список на экран." << std::endl
			<< "Перестроить список, расположив узлы списка в порядке убывания числовых значений." << std::endl
			<< "Вывести список на экран." << std::endl;

		std::cout << "1. Автозаполнение" << std::endl;
		std::cout << "2. Ручное заполнение" << std::endl;
		std::cout << "0. Выход" << std::endl;
		std::cout << "Выберите пункт:> ";
		std::cin >> choice0;
		switch (choice0) {

		case 1: // 1. Автозаполнение
		{
			std::cout << "Введите необходимое количество узлов:> ";
			int size;
			std::cin >> size;
			for (size_t i = 0; i < size; ++i) {
				List.push_back((rand() % 123) / 7.f);
			}
			std::cout << "Полученный список:" << std::endl;
			List.print('\n');
			std::cout << std::endl;
			std::cout
				<< "\nСортировка списка в порядке"
				<< "возрастания числовых значений..." << std::endl;
			List.sort_az();
			List.print('\n');
			std::cout
				<< "\nСортировка списка в порядке"
				<< "убывания числовых значений..." << std::endl;
			List.sort_za();
			List.print('\n');
			std::cout << "Нажмите Enter" << std::endl;
			std::cin.get();
			std::cin.get();

			break;
		}

		case 2: // 2. Ручное заполнение
		{
			std::cout << "Введите необходимое количество узлов:> ";
			int size;
			std::cin >> size;
			std::cout << "Введите значения узлов:> ";
			for (size_t i = 0; i < size; ++i) {
				std::cout << "Узел " << size + 1 << " : ";
				double data;
				std::cin >> data;
				List.push_back(data);
			}
			std::cout << "Введённый список:" << std::endl;
			List.print('\n');
			std::cout << std::endl;
			std::cout
				<< "\nСортировка списка в порядке"
				<< "возрастания числовых значений..." << std::endl;
			List.sort_az();
			List.print('\n');
			std::cout
				<< "\nСортировка списка в порядке"
				<< "убывания числовых значений..." << std::endl;
			List.sort_za();
			List.print('\n');
			std::cout << "Нажмите Enter" << std::endl;
			std::cin.get();
			std::cin.get();

			break;
		}

		case 0:
			break;
		default:
		{
			std::cout
				<< "Неверный пункт" << std::endl
				<< "Нажмите Enter" << std::endl;
			std::cin.get();
			std::cin.get();
			break;
		}
		}

	}
	while (choice0 != 0);
	return 0;
}

int main()
{
	return 0;
}