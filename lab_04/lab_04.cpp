// lab_04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <limits>

#define MAGAZINE_PRICE 80.
#define NEWSPAPER_PRICE 5.

using namespace std;

int main()
{
    cout << "Practics #04\n";

    // Установка корректного вывода кириллицы в консоль Windows
    setlocale(LC_ALL, "Russian");

    cout << "Здравсвтуйте. Выберите приобретаемый товар\n1 - журнал\n2 - газета" << endl;
    int choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
A:
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Выбран журнал. Внесите деньги.\n";
        float PaymentMagazine;
        cin >> PaymentMagazine;
        if (PaymentMagazine < MAGAZINE_PRICE) { cout << "Не достаточная сумма" << endl; }
        else if (PaymentMagazine == MAGAZINE_PRICE) { cout << "Вы купили журнал" << endl; }
        else { cout << "Вы купили журнал. Ваша сдача " << PaymentMagazine - MAGAZINE_PRICE << endl; }
        break;
    case 2:
        cout << "Выбрана газета. Внесите деньги.";
        float PaymentNewspaper;
        cin >> PaymentNewspaper;
        if (PaymentNewspaper < NEWSPAPER_PRICE) { cout << "Не достаточная сумма" << endl; }
        else if (PaymentNewspaper == NEWSPAPER_PRICE) { cout << "Вы купили газету" << endl; }
        else { cout << "Вы купили газету. Ваша сдача " << PaymentNewspaper - NEWSPAPER_PRICE << endl; }
        break;
    default:
        cout << "Неверный выбор!\n";
        goto A;
        //break;
    }

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
