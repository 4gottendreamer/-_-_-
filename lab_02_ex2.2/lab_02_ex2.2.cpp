﻿// lab_02_ex2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>


using namespace std;

int main()
{
    cout << "Practics #02\nExercise 2.2" << endl;

    char A = _getch(); // Чтение символа из потока в переменную A
    system("cls"); // Очистка экрана
    // Вывод шаблона 3х3 из символов A
    cout << A << A << A << '\n'
        << A << A << A << '\n'
        << A << A << A;

    _getch(); // Ожидание нажатия клавиши
    system("cls"); // Очистка экрана
    // Вывод шаблона 3х3 из символов A со смещением на пять символов
    cout << "     " << A << A << A << '\n'
        << "     " << A << A << A << '\n'
        << "     " << A << A << A;

    _getch();
    system("cls"); // Очистка экрана
    cout << "\n\n\n\n\n"; // Отступ пяти строк
    // Вывод шаблона 3х3 из символов A
    cout << A << A << A << '\n'
        << A << A << A << '\n'
        << A << A << A;
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
