﻿// lab_03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath> // Подключение библиотеки с математическими функциями

using namespace std;

int main()
{
    cout << "Practics #03\n";

    // Установка корректного вывода кириллицы в консоль Windows
    setlocale(LC_ALL, "Russian");

    double t, x, y, z;

    cout << "Введите исходные значения.\nx = ";
    cin >> x;
    cout << "z = ";
    cin >> z;
    cout << "t = ";
    cin >> t;

    cout << "Вы ввели:\nx = ";
    cout << x << endl;
    cout << "z = ";
    cout << z << endl;
    cout << "t = ";
    cout << t << endl;

    y = fabs(pow(x, 3) - 10) * (atan(z + 0.2) + exp(-(x / 2 + 3)));

    cout << "y(x, z, t) = | x^3 - 10 | * (arctg(z + 0.2) + e^(-(x / 2 + 3)))" << endl;
    cout << "y(" << x << ", " << z << ", " << t << ") = " << y << endl;
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
