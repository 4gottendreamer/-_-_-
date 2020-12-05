// lab_07.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант №6.
// Дан целочисленный массив А[N][М].Определить индекс столбца,
// в котором находится максимальное количество нулей.
// Переставить элементы данного столбца в обратном порядке.

#include <iostream>
//#include <cstdlib>

#define RESIDUE 10 // Макро-переменная для изменения модуля остатков от деления в коде

// Поиск индекса первого максимального элемента в массиве _Array[_M]
int MaxElementIndexFirst(int* _Array, int _M)
{
    int MaxIndex = 0;
    for (int i = 0; i < _M; i++) {
        if (_Array[MaxIndex] < _Array[i]) {
            MaxIndex = i;
        }
    }
    return MaxIndex;
}

// Поиск индекса последнего максимального элемента в массиве _Array[_M]
int MaxElementIndexLast(int* _Array, int _M)
{
    int MaxIndex = 0;
    for (int i = 0; i < _M; i++) {
        if (_Array[MaxIndex] <= _Array[i]) {
            MaxIndex = i;
        }
    }
    return MaxIndex;
}

// Переставляет в обратном порядке элементы столбца с индексом _SwapColumn
// в массиве _Array[_M][_N]
void BackwardsSwapColumn(int** _Array, int _M, int _N, int _SwapColumn)
{
    int tmp;
    for (int i = 0; i < _M / 2; i++) {
        tmp = _Array[i][_SwapColumn];
        _Array[i][_SwapColumn] = _Array[_M - 1 - i][_SwapColumn];
        _Array[_M - 1 - i][_SwapColumn] = tmp;
    }
}

// Выводит массив в виде прямоугольной матрицы из M строк, N столбцов
void PrintMatrix(int** _Array, int _M, int _N)
{
    for (int i = 0; i < _M; i++) {
        for (int j = 0; j < _N; j++) {
            std::cout << _Array[i][j] << "    ";
        }
        std::cout << std::endl << std::endl;
    }
}

int main()
{
    using namespace std;

    setlocale(LC_ALL, "Russian"); // Установка корректного вывода кириллицы
    srand(time(NULL)); // Установка генератора случайных чисел

    int M, N;
    int** a;
    int* ColumnIndices;
    bool bIsThereAnyZero = false; // Флаг отметки наличия хотя бы одного нуля в массиве

    cout << "Введите размерность массива" << endl;
    cin >> M >> N;

    ColumnIndices = new int[N] {0};

#if 0 // Test output
    for (int i = 0; i < N; i++) {
        cout << ColumnIndices[i] << "  ";
    }
    cout << endl;
#endif // 0 //


    a = new int* [M];
    for (int i = 0; i < M; i++) {
        a[i] = new int[N];
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % RESIDUE; // Заполнение массива псевдослучайными числами
            if (a[i][j] == 0) {      // Если текущий элемент == 0,
                ColumnIndices[j]++;  // то увеличиваем на 1 соотвествующий элемент 
                bIsThereAnyZero = true; // Если есть нули, поднимаем флажок
            }
        }
    }
    
    cout << "Полученный массив:" << endl;
    PrintMatrix(a, M, N);
    cout << endl << endl;

#if 1 // Test output
    cout << "Количество нулей по столбцам" << endl;
    for (int i = 0; i < N; i++) {
        cout << i << "    ";
    }
    cout << "// Индексы столбцов" << endl;
    for (int i = 0; i < N; i++) {
        cout << ColumnIndices[i] << "    ";
    }
    cout << "// Количества нулей" << endl << endl;
#endif // 0 //

    // Вывод результатов
    if (bIsThereAnyZero) { // Если есть нули в массиве
        int MaxFirst = MaxElementIndexFirst(ColumnIndices, N);
        int MaxLast = MaxElementIndexLast(ColumnIndices, N);
        if (MaxFirst != MaxLast) { // Если одинаковое число нулей в двух разных столбцах
            // Вывести оба значения индексов
            cout << "Индекс первого столбца с максимальным количеством нулей\t\t"
                 << MaxFirst << endl;
            cout << "Количество нулей в этом столбце\t\t\t\t\t"
                 << ColumnIndices[MaxFirst] << endl;
            cout << "Индекс последнего столбца с максимальным количеством нулей\t"
                 << MaxLast << endl;
            cout << "Количество нулей в этом столбце\t\t\t\t\t"
                 << ColumnIndices[MaxLast] << endl;
            // Смена порядка следования элементов столбцов в массиве
            BackwardsSwapColumn(a, M, N, MaxFirst);
            BackwardsSwapColumn(a, M, N, MaxLast);
            cout << endl << "Массив с обратным порядком элементов в столбцах:" << endl;
        }
        else { // Иначе вывести одно значение индекса
            cout << "Индекс столбца с максимальным количеством нулей\t"
                 << MaxFirst << endl;
            cout << "Количество нулей в этом столбце\t\t\t"
                 << ColumnIndices[MaxFirst] << endl;
            // Смена порядка элементов в столбце
            BackwardsSwapColumn(a, M, N, MaxFirst);
            cout << endl << "Массив с обратным порядком элементов в столбце:" << endl;
        }
        // Вывод маркеров для изменённых столбцов
        for (int i = 0; i < N; i++) {
            if (i == MaxFirst or i == MaxLast) {
                cout << "*    "; // Если столбец изменён, выводим '*' и четыре пробела
            }
            else {
                cout << "     "; // Иначе выводим пять пробелов
            }
        }
        cout << endl;
        PrintMatrix(a, M, N); // Вывод изменённого массива на печать
    }
    else { // Иначе вывод сообщения об отсутствии нулей
        cout << "Нули в массиве отсутствуют" << endl;
    }

    // Освобождение динамически выделенной памяти
    for (int i = 0; i < M; i++) {
        delete a[i];
    }
    delete[]a;
    delete[]ColumnIndices;
 
    cout << "Нажмите Enter";
    cin.get(); cin.get();
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
