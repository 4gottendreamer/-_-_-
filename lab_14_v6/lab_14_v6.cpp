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
+++		- Добавить элемент	// push_back();
	+		- в начало
	+		- в конец
	+		- в указанную позицию
+++-	- Удалить
	+		- первый
	+		- последний
	+		- указанный
	-		- удалить все узлы
++		- Поиск				// find();
	+		- по значению
	+		- по номеру узла
+		- Вывод				// for(auto& iter : List) { std::cout << iter; }
*	8)	- Решение задачи	// sort_az(); sort_za();


Вариант №6.
Построить список из входной последовательности вещественных чисел.
Вывести список на экран.
Перестроить список, расположив узлы списка в порядке убывания числовых значений.
Вывести список на экран.
*/

#include <iostream>
#include <vector>
#include "..\list\list.h"
#include "lab_14_v6_classMenu.h"

using TYPE = typename double;
void lab_14_v6();

int main()
{
	srand(time(NULL));		 // Установка генератора псевдослучайной последовательности чисел
	setlocale(LC_ALL, "ru"); // Установка корректного вывода кириллицы
	my::list<TYPE> List;	// Объявление списка

/*
	List.push_back((rand() % 100) / 3.f);
	List.push_back((rand() % 100) / 5.f);
	List.push_back((rand() % 100) / 7.f);
	List.push_back((rand() % 100) / 11.f);
	List.push_back((rand() % 100) / 13.f);
	List.push_back((rand() % 100) / 17.f);
	List.push_back((rand() % 100) / 19.f); */

	std::vector<std::wstring> menuLines0 = {
		L"1 Добавить узел в список",
		L"2 Удалить узел из списка",
		L"3 Поиск узла в списке",
		L"4 Вывести список на экран",
		L"5 Задача варианта №6",
		L"0 Выход"
	};

	// "1 Добавить узел в список"
	std::vector<std::wstring> menuLines0_1 = {
		L"1 Добавить узел в список",
		L"  1 Добавить узел в конец списка",
		L"  2 Добавить узел в начало списка",
		L"  3 Добавить узел в указанную позицию списка",
		L"  4 Вывести список на экран",
		L"  5 Заполнить список автоматически",
		L"  0 Назад"
	};

	// "2 Удалить узел из списка"
	std::vector<std::wstring> menuLines0_2 = {
		L"2 Удалить узел из списка",
		L"  1 Удалить конечный узел списка",
		L"  2 Удалить начальный узел списка",
		L"  3 Удалить указанный узел списка",
		L"  4 Вывести список на экран",
		L"  5 Удалить все элементы списка",
		L"  0 Назад"
	};

	// "3 Поиск узла в списке"
	std::vector<std::wstring> menuLines0_3 = {
		L"3 Поиск узла в списке",
		L"  1 Поиск по значению",
		L"  2 Поиск по номеру",
		L"  3 Вывести список на экран",
		L"  0 Назад"
	};

	Menu Menu0(menuLines0);
	Menu Menu0_1(menuLines0_1);
	Menu Menu0_2(menuLines0_2);
	Menu Menu0_3(menuLines0_3);

	uint16_t choice0;
	do {
		system("cls");
		Menu0.Print();
		std::cout << "Выберите пункт:> ";
		std::cin >> choice0;
		switch (choice0) {
		case 1:				// "1 Добавить узел в список"
		{
			uint16_t choice1;
			do {
				system("cls");
				Menu0_1.Print();

				std::cout << "Выберите пункт:> ";
				std::cin >> choice1;
				switch (choice1) {
				case 1:			// 1 Добавить узел в конец списка
				{
					std::cout << "Введие значение:> ";
					double data;
					std::cin >> data;
					List.push_back(data);
					std::cout
						<< "Узел добавлен в конец списка" << std::endl
						<< "Нажмите Enter";
					std::cin.get();
					std::cin.get();
					break;
				}
				case 2:			// 2 Добавить узел в начало списка
				{
					std::cout << "Введие значение:> ";
					double data;
					std::cin >> data;
					List.push_front(data);
					std::cout
						<< "Узел добавлен в начало списка" << std::endl
						<< "Нажмите Enter";
					std::cin.get();
					std::cin.get();
					break;
				}
				case 3:			// 3 Добавить узел в указанную поизицию списка
				{
					std::cout << "Введие номер позиции:> ";
					int count;
					std::cin >> count;
					if (count > List.size() or count < 0) {
						std::cout
							<< "Номер превышает количество узлов в списке"
							<< " или не является натуральным числом" << std::endl;
						std::cin.get();
						std::cin.get();
					}
					else {
						auto iter = List.begin();
						my::advance<TYPE>(iter, --count);
						std::cout << "Введие значение:> ";
						double data;
						std::cin >> data;
						List.insert(iter, data);
						std::cout
							<< "Узел добавлен в указанную позицию списка" << std::endl
							<< "Нажмите Enter";
						std::cin.get();
						std::cin.get();
					}
					break;
				}
				case 4:			// 4 Вывести список на экран
				{
					if (List.size() > 0) {
						std::cout
							<< "\nВ списке содержится " << List.size()
							<< " значений." << std::endl;
						std::cout << "\nЭлементы списка:" << std::endl;
						List.print('\n');
						std::cout << "\nНажмите Enter" << std::endl;
						std::cin.get();
						std::cin.get();
					}
					else {
						std::cout << "\nСписок пуск" << std::endl;
					}
					break;
				}
				case 5:			// 5 Заполнить список автоматически
				{
					List.clear();
					std::cout << "Введите необходимое количество узлов:> ";
					int size;
					std::cin >> size;
					srand(time(NULL));
					std::cout << "Заполнение списка..." << std::endl;
					for (size_t i = 0; i < size; ++i) {
						auto R = []()->double {
							int r = rand() % 10;
							if (r) {
								return (double)r;
							}
							else { return 3.f; }
						};
						List.push_back(
							((double)(rand() % 200) - (rand() % 100)) / R()
						);
					}
					std::cout << "Полученный список:" << std::endl;
					List.print('\n');
					std::cout << "Нажмите Enter";
					std::cin.get();
					std::cin.get();
					break;
				}
				case 0:			// 0 Назад
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
			while (choice1 != 0);
			break;
		}
		case 2:				// "2 Удалить узел из списка"
		{
			uint16_t choice1;
			do {
				system("cls");
				Menu0_2.Print();
				std::cout << "Выберите пункт:> ";
				std::cin >> choice1;
				switch (choice1) {
				case 1:				// 1 Удалить конечный узел списка
				{
					List.pop_back();
					std::cout
						<< "Конечный узел списка удалён" << std::endl
						<< "Нажмите Enter";
					std::cin.get();
					std::cin.get();
					break;
				}
				case 2:				// 2 Удалить начальный узел списка
				{
					List.pop_front();
					std::cout
						<< "Начальный узел списка удалён" << std::endl
						<< "Нажмите Enter";
					std::cin.get();
					std::cin.get();
					break;
				}
				case 3:				// 3 Удалить указанный узел списка
				{
					std::cout << "Введие номер позиции:> ";
					int count;
					std::cin >> count;
					if (count > List.size() or count < 0) {
						std::cout
							<< "Номер превышает количество узлов в списке"
							<< " или не является натуральным числом" << std::endl
							<< "Нажмите Enter" << std::endl;
						std::cin.get();
						std::cin.get();
					}
					else {
						auto iter = List.begin();
						my::advance<TYPE>(iter, --count);
						List.erase(iter);
						std::cout
							<< "Указанный узел списка удалён" << std::endl
							<< "Нажмите Enter";
						std::cin.get();
						std::cin.get();
					}
					break;
				}
				case 4:				// 4 Вывести список на экран
				{
					if (List.size() > 0) {

						std::cout
							<< "\nВ списке содержится " << List.size()
							<< " значений." << std::endl;
						std::cout << "\nЭлементы списка:" << std::endl;
						List.print('\n');
						std::cout << "\nНажмите Enter" << std::endl;
						std::cin.get();
						std::cin.get();
					}
					else {
						std::cout << "\nСписок пуск" << std::endl;
						std::cout << "Нажмите Enter";
						std::cin.get();
						std::cin.get();
					}

					break;
				}
				case 5:				// 5 Удалить все элементы списка
				{
					List.clear();
					std::cout << "Список очищен" << std::endl;
					std::cout << "Нажмите Enter";
					std::cin.get();
					std::cin.get();

					break;
				}

				case 0:				// 0 Назад
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
			while (choice1 != 0);
			break;
		}
		case 3:				// "3 Поиск узла в списке"
		{
			uint16_t choice1;
			do {
				system("cls");
				Menu0_3.Print();
				std::cout << "Выберите пункт:> ";
				std::cin >> choice1;
				switch (choice1) {
				case 1:				// 1 Поиск по значению
				{
					std::cout << "Введие значение:> ";
					double data;
					std::cin >> data;
					auto iter = List.begin();
					int count(1);
					bool found(0);
					while (iter != List.end()) {
						if (iter.getData() == data) {
							std::cout
								<< "Номер узла с найденным значением: "
								<< count++ << std::endl;
							++iter;
							found = true;
						}
						++count;
						++iter;
					}
					if (!found) {
						std::cout
							<< "Узел со значением " << data
							<< " отсутствует в списке" << std::endl
							<< "Нажмите Enter";
						std::cin.get();
						std::cin.get();
					}
					else {
						std::cin.get();
						std::cin.get();
					}

					break;
				}
				case 2:				// 2 Поиск по номеру
				{
					int count;
					std::cout << "Введите номер узла:>" << std::endl;
					std::cin >> count;
					if (count > List.size() or count < 0) {
						std::cout
							<< "Номер превышает количество узлов в списке"
							<< " или не является натуральным числом" << std::endl
							<< "Нажмите Enter" << std::endl;
						std::cin.get();
						std::cin.get();
					}
					else {
						auto iter = List.begin();
						my::advance<TYPE>(iter, --count);
						std::cout
							<< "Значение узла с номером " << ++count << ": "
							<< *iter << std::endl;
						std::cin.get();
						std::cin.get();
					}
					break;
				}
				case 3:				// 3 Вывести список на экран
				{
					if (List.size() > 0) {

						std::cout
							<< "\nВ списке содержится " << List.size()
							<< " значений." << std::endl;
						std::cout << "\nЭлементы списка:" << std::endl;
						List.print('\n');
						std::cout << "\nНажмите Enter" << std::endl;
						std::cin.get();
						std::cin.get();
					}
					else {
						std::cout << "\nСписок пуск" << std::endl;
						std::cout << "Нажмите Enter";
						std::cin.get();
						std::cin.get();
					}
					break;
				}
				case 0:			// 0 Назад
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
			while (choice1 != 0);
			break;
		}
		case 4:				// "4 Вывести список"
		{
			if (List.size() > 0) {

				std::cout
					<< "\nВ списке содержится " << List.size()
					<< " значений." << std::endl;
				std::cout << "\nЭлементы списка:" << std::endl;
				List.print('\n');
				std::cout << "\nНажмите Enter" << std::endl;
				std::cin.get();
				std::cin.get();
			}
			else {
				std::cout << "\nСписок пуск" << std::endl;
				std::cout << "Нажмите Enter" << std::endl;
				std::cin.get();
				std::cin.get();
			}
			break;
		}
		case 5:				// "5 Задача варианта №6"
		{
			system("cls");
			lab_14_v6();
			break;
		}
		case 0:				// 0 Выход
		{
			system("cls");
			break;
		}
		default:
			std::cout
				<< "Неверный пункт" << std::endl
				<< "Нажмите Enter" << std::endl;
			std::cin.get();
			std::cin.get();
			break;
		}
	}
	while (choice0 != 0);

	std::cout << "Выход из программы. Нажмите Enter" << std::endl;
	std::cin.get();
	std::cin.get();
	return 0;
}

void lab_14_v6()
{
	srand(time(NULL));		 // Установка генератора псевдослучайной последовательности чисел
	setlocale(LC_ALL, "ru"); // Установка корректного вывода кириллицы

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

		std::cout << "  1  Автозаполнение" << std::endl;
		std::cout << "  2  Ручное заполнение" << std::endl;
		std::cout << "  0  Назад" << std::endl;
		std::cout << "Выберите пункт:> ";
		std::cin >> choice0;
		switch (choice0) {

		case 1: // 1. Автозаполнение
		{
			std::cout << "Введите необходимое количество узлов:> ";
			int size;
			std::cin >> size;
			for (size_t i = 0; i < size; ++i) {
				auto R = []()->double {
					int r = rand() % 10;
					if (r) {
						return (double)r;
					}
					else { return 3.f; }
				};
				List.push_back(
					((double)(rand() % 200) - (rand() % 100)) / R()
					//(double)(rand() % 3)
				);
			}
			std::cout << "Полученный список:" << std::endl;
			List.print('\n');
			std::cout << std::endl;
			std::cout
				<< "\nСортировка списка в порядке "
				<< "возрастания числовых значений..." << std::endl;
			List.sort_az();
			List.print('\n');
			std::cout
				<< "\nСортировка списка в порядке "
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
				<< "\nСортировка списка в порядке "
				<< "возрастания числовых значений..." << std::endl;
			List.sort_az();
			List.print('\n');
			std::cout
				<< "\nСортировка списка в порядке "
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
}
