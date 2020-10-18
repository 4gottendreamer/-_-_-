﻿// lab_02_ex2.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <consoleapi2.h>

using namespace std;

int main()
{
    cout << "Practics #02.\nExercise 2.3\n";

    // Установка корректного ввода-вывода кириллицы в консоли
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char cStr[80]; // Объявление массива типа <char>

    cout << "Введите фимилию, имя и отчество:" << endl;
    
    // Чтение строки символов из потока ввода в массив cStr[]
    cin.getline(cStr, sizeof(cStr));

    cout << "Введите сумму заказа:" << endl;
    float Price;
    cin >> Price;

    float Shipping = Price / 10.; // Расчёт стоимости транспортировки (10%)
    float Tax = Price * 0.06; // Расчёт налога (6%)
    float TotalCost = Tax + Shipping + Price; // Итого

    // Вывод накладной
    cout << "\t\t\t\t\tНАКЛАДНАЯ\n"
        << "__________________________________________________________________________________________\n"
        << "ПОКУПАТЕЛЬ\t\t\t\t" << cStr << '\n'
        << "Сумма заказа\t\t\t\t" << Price << '\n'
        << "Налог\t\t\t\t\t" << Tax << '\n'
        << "Транспортировка\t\t\t\t" << Shipping << '\n'
        << "__________________________________________________________________________________________\n"
        << "Стоимость всего\t\t\t\t" << TotalCost << '\n'
        << "__________________________________________________________________________________________\n" << endl;
    
    _getch();
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
