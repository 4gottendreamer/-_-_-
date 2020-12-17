// lab_09.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант №6.
// Дано: прямоугольная матрица А[N, M]. Отсортировать столбцы матрицы
// в порядке неубывания сумм положительных элементов столбцов.
// Нахождение суммы положительных элементов столбцов оформить как функцию.
// Перестановку столбцов оформить как функцию

#include <iostream>

#define RESIDUE 10 // Макроподстановка с переменной для изменения остатков от деления

template <typename T>
void swap(T* _A, int _N, int _i_from, int _j_to)
{
    T tmp = _A[_i_from];
    _A[_i_from] = _A[_j_to];
    _A[_j_to] = tmp;
}

// Меняет местами столбцы с индексами _i_from и _j_to в матрице _a[_M][*]
template <typename T>
void SwapColumns(T** _a, const int _M, int _i_from, int _j_to)
{
    for (int i = 0; i < _M; i++) {
        T tmp = _a[i][_i_from];
        _a[i][_i_from] = _a[i][_j_to];
        _a[i][_j_to] = tmp;
    }
}

// Сортировка вставками
template <typename T>
void SortInsert(T* _A, const int _N)
{
    T tmp;
    for (int i = 1, j; i < _N; i++) {
        tmp = _A[i];
        j = i;
        while (j > 0 and tmp < _A[j - 1]) {
            _A[j] = _A[j - 1];
            j--;
        }
        _A[j] = tmp;
    }
}

// Вывод матрицы на экран
template <typename T>
void PrintMatrix(T** _a, const int _M, const int _N)
{
    //std::cout.width(20);
    for (int i = 0; i < _M; i++) {
        for (int j = 0; j < _N; j++) {
            std::cout << _a[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Возвращает сумму положительных элементов столбца матрицы
int SumColumnPositive(int** _a, const int _M, int _jCol)
{
    int sum = 0;
    for (int i = 0; i < _M; i++) {
        if(_a[i][_jCol] > 0)
            sum+=_a[i][_jCol];
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Russian"); // Установка корректного вывода кириллицы
    srand(time(NULL)); // Установка генератора случайных чисел
    int M, N;
    int** a;
    int** PatternSorted;
    int** ArrCheck;

    std::cout << "Введите размерность матрицы:" << std::endl;
    std::cin >> M >> N;

    // Шаблон для перестановки отсортированной матрицы
    PatternSorted = new int* [2];
    PatternSorted[0] = new int[N];
    PatternSorted[1] = new int[N];
    ArrCheck = new int* [2];
    ArrCheck[0] = new int[N];
    ArrCheck[1] = new int[N];

    // Выделение памяти под массив
    a = new int* [M];
    for (int i = 0; i < M; i++) {
        a[i] = new int[N];
    }

    // Заполнение массива псевдослучайными числами
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % RESIDUE - RESIDUE / 2;
        }
    }
    std::cout << "Исходная матрица:\n";
    PrintMatrix(a, M, N);
    
    // Заполнение обеих строк массива PatternSorted
    // суммами положительных элементов столбцов матрицы a[M][N]
    for (int j = 0; j < N; j++) {
        PatternSorted[0][j] = SumColumnPositive(a, M, j);
        PatternSorted[1][j] = PatternSorted[0][j];
        /*ArrCheck[0][j] = SumColumnPositive(a, M, j);
        ArrCheck[1][j] = ArrCheck[0][j];*/
    }

    std::cout << std::endl << "Суммы положительных элементов столбцов матрицы:\n\n";
    for (int j = 0; j < N; j++) {
        std::cout << PatternSorted[0][j] << '\t';
    }
    
    // Сортировка строки 0 массива PatternSorted порядке неубывания элементов
    SortInsert(PatternSorted[0], N);
    //std::cout << std::endl << "\nОтсортированный массив Pattern\n";
    //PrintMatrix(PatternSorted, 2, N);
    
    std::cout << std::endl << std::endl;
    
    // Поиск вхождений элементов строки 0 (отсортированной) в строку 1 (изначальную)
    // и перестановка столбцов с соответствующими индексами в матрице a[M][N]
    std::cout << "Перестановка матрицы...\n";
    for (int j0 = 0; j0 < N - 1; j0++) {
        for (int j1 = j0 + 1; j1 < N; j1++) {
            if (PatternSorted[0][j0] == PatternSorted[1][j1]) {

                SwapColumns(a, M, j0, j1);  // Смена столбцов соответствующих индексов
                                            // в исходной матрице
                swap(PatternSorted[1], N, j0, j1);
                /*std::cout << j0 << '\t' << j1 << std::endl;
                std::cout << PatternSorted[0][j0] << '\t' << PatternSorted[0][j1] << std::endl;
                std::cout << PatternSorted[1][j0] << '\t' << PatternSorted[1][j1] << std::endl;
                PrintMatrix(ArrCheck, 2, N);
                PrintMatrix(PatternSorted, 2, N);*/
            }
        }
    }

    std::cout << "\nОтсортированная матрица:\n";
    PrintMatrix(a, M, N);

    std::cout << "\nКонтрольная проверка сумм:\n";
    for (int j = 0; j < N; j++) {
        PatternSorted[0][j] = SumColumnPositive(a, M, j);
        PatternSorted[1][j] = PatternSorted[0][j];
    }
    // Вывод на экран сумм столбцов преобразованной матрицы
    for (int j = 0; j < N; j++) {
        std::cout << PatternSorted[0][j] << '\t';
    }
    std::cout << std::endl;

    // Освобождение динамически выделенной памяти
    for (int i = 0; i < M; i++) {
        delete a[i];
    }
 
    delete PatternSorted[0];
    delete PatternSorted[1];
    delete[]a;
    delete[]PatternSorted;
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
