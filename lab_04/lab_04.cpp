﻿// lab_04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <limits>

// Определение идентификаторов для цен журнала и газеты
#define MAGAZINE_PRICE 80.
#define NEWSPAPER_PRICE 5.

using namespace std;

int main()
{
    cout << "Practics #04\n";

    // Установка корректного вывода кириллицы в консоль Windows
    setlocale(LC_ALL, "Russian");

    cout << "Здравсвтуйте.\nВыберите приобретаемый товар\n"
            "1 - журнал\n2 - газета" << endl;
    
    int choice; // Переменная выбора товара
    bool bIsOK; // Флаг проверки корректности операции покупки
    float payment; // Переменная для хранения оплаты

    do
    {
        bIsOK = false;
        cin >> choice; // Ввод выбора товара
        switch (choice)
        {
        case 1: // Случай 1 - журнал
            cout << "Выбран журнал. Внесите деньги.\n";
            do {
                cin >> payment; // "Внесение" оплаты
                // Внесённая сумма меньше цены
                if (payment < MAGAZINE_PRICE) {
                    cout << "Не достаточная сумма. Доплатите." << endl;
                    bIsOK = false; // Покупка не удалась
                }
                // Внесённая сумма равна цене
                else if (payment == MAGAZINE_PRICE) {
                    cout << "Вы купили журнал" << endl;
                    bIsOK = true; // Покупка ОК
                }
                // Внесённая сумма больше цены
                else {
                    cout << "Вы купили журнал. Ваша сдача "
                         // Рассчитываем сдачу
                         << payment - MAGAZINE_PRICE << endl;
                    bIsOK = true; // Покупка ОК
                }
            } while (!bIsOK); // Проверка корректности покупки
            break;
        case 2: // Случай 2 - газета
            cout << "Выбрана газета. Внесите деньги. ";
            do {
                cin >> payment; // "Внесение" оплаты
                // Внесённая сумма меньше цены
                if (payment < NEWSPAPER_PRICE) {
                    cout << "Не достаточная сумма. Доплатите." << endl;
                    bIsOK = false; // Покупка не удалась
                }
                // Внесённая сумма равна цене
                else if (payment == NEWSPAPER_PRICE) {
                    cout << "Вы купили газету" << endl;
                    bIsOK = true; // Покупка ОК
                }
                // Внесённая сумма больше цены
                else {
                    cout << "Вы купили газету. Ваша сдача "
                            << payment - NEWSPAPER_PRICE << endl;
                    bIsOK = true; // Покупка ОК
                }
            } while (!bIsOK); // Проверка корректности покупки
            break;
        default: // Случаи неверного выбора товара
            cout << "Неверный выбор!\n";
            bIsOK = false; // Покупка не удалась
        }
    } while (!bIsOK); // Проверка корректности покупки
    
    // Игнорирование символа '\n' в потоке ввода
    // для корректной работы cin.get()
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get(); // Ожидание нажатия Enter
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
