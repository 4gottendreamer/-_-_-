// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma warning ( disable : 4996 )

#include <iostream>

using namespace std;
/*
    Определение функции Main
    Выводит на консоль строку Hello World!
*/
int main()
{
    std::cout << "Hello World!\n";
    int iINT = 1;
    unsigned int uiINT = 1;
    long int liINT = 1;
    long long llINT = 1;
    float fFLOAT = 1;
    double dFLOAT = 1;
    long double ldFLOAT = 1;
    char cChar = 'a';
    char32_t wcChar32 = 'A';
    cout << "sizeof(iINT)\t\t" << sizeof(iINT) << endl;
    cout << "sizeof(unsigned int)\t" << sizeof(uiINT) << endl;
    cout << "sizeof(long int)\t" << sizeof(liINT) << endl;
    cout << "sizeof(long long)\t" << sizeof(llINT) << endl;
    cout << "sizeof(float)\t\t" << sizeof(fFLOAT) << endl;
    cout << "sizeof(double)\t\t" << sizeof(dFLOAT) << endl;
    cout << "sizeof(long double)\t" << sizeof(ldFLOAT) << endl;
    cout << "sizeof(char)\t\t" << sizeof(cChar) << endl;
    cout << "sizeof(char32_t)\t" << sizeof(wcChar32) << endl;

    int X = 1;
    cout << X << endl;
    X <<= 1;
    cout << X << endl;
    X <<= 1;
    cout << X << endl;
    X <<= 1;
    cout << X << endl;
    X <<= 1;
    cout << X << endl;
    X <<= 1;
    cout << X << endl;
    X <<= 1;
    cout << X << endl;

    X >>= 1;
    cout << X << endl;
    X >>= 1;
    cout << X << endl;
    X >>= 1;
    cout << X << endl;
    X >>= 1;
    cout << X << endl;
    X >>= 1;
    cout << X << endl;
    X >>= 1;
    cout << X << endl;
    X >>= 1;
    cout << X << endl;
    X >>= 1;
    cout << X << endl;
    X >>= 1;
    cout << X << endl;
    X >>= 1;
    cout << X << endl;

    X <<= 1;
    cout << X << endl;
    X <<= 1;
    cout << X << endl;
    X <<= 1;
    cout << X << endl;
    int Y = 0b00000001;
    X = 0b00000011;
    int C = X | Y;
    cout.binary;
    cout << C << endl;
    
    X = Y = 1;
    C = ++X; // C = X + 1; X = X + 1;
    cout << "C = ++X : " <<  C << endl;
    
    C = Y++; // C = Y; Y = Y + 1;
    cout << "C = Y++ : " << C << endl;

    scanf_s("%d", &C);
    //printf("%d", C);

    char    ch = 'h',
            string[] = "computer";

    int     count = -1234;
    double  fp = 123.456;

    printf("%c\n", ch);
    printf("%s\n", string);
    printf("%d\n", count);
    printf("%f\n", fp);
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
