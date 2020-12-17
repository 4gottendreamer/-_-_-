// lab_09.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант №6.
// Дано: прямоугольная матрица А[N, M]. Отсортировать столбцы матрицы
// в порядке неубывания сумм положительных элементов столбцов.
// Нахождение суммы положительных элементов столбцов оформить как функцию.
// Перестановку столбцов оформить как функцию
//

#include <iostream>

#define RESIDUE 10 // Макроподстановка с переменной для изменения остатков от деления

// Меняет значения переменных _from и _to
template <typename T>
void swap(T& _from, T& _to)
{
    T tmp = _from;
    _from = _to;
    _to = tmp;
}

// Меняет значения элементов _A[_from] и _A[_to]
template <typename T>
void Swap2InRow(T* const _A, const int _j_from, const int _j_to)
{
    swap(*(_A + _j_from), *(_A + _j_to));
}

// Меняет местами столбцы с индексами _i_from и _j_to в матрице _A[_M][*]
template <typename T>
void SwapColumns(T** const _A, const int _M, const int _j_from, const int _j_to)
{
    for (int i = 0; i < _M; i++) {
        swap(_A[i][_j_from], _A[i][_j_to]);
    }
}

// Сортировка вставками
template <typename T>
void SortInsert(T* const _A, const int _N)
{
    for (int i = 1; i < _N; i++) {
        int j = i;
        while (j > 0 and _A[j] < _A[j - 1]) {
            swap(_A[j], _A[j-1]);
            j--;
        }
    }
}

// Вывод матрицы на экран
template <typename T>
void PrintMatrix(T** const _A, const int _M, const int _N)
{
    for (int i = 0; i < _M; i++) {
        for (int j = 0; j < _N; j++) {
            std::cout << _A[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Возвращает сумму положительных элементов столбца матрицы
template <typename T>
T SumColumnPositive(T** const _A, const int _M, int _jCol)
{
    T sum = 0;
    for (int i = 0; i < _M; i++) {
        if(_A[i][_jCol] > 0)
            sum+=_A[i][_jCol];
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

    std::cout << "Введите размерность матрицы:" << std::endl;
    std::cin >> M >> N;

    // Шаблон для перестановки отсортированной матрицы
    PatternSorted = new int* [2];
    PatternSorted[0] = new int[N];
    PatternSorted[1] = new int[N];

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
    }

    std::cout << std::endl << "Суммы положительных элементов столбцов матрицы:\n\n";
    for (int j = 0; j < N; j++) {
        std::cout << PatternSorted[0][j] << '\t';
    }
    
    // Сортировка строки 0 массива PatternSorted порядке неубывания элементов
    SortInsert(PatternSorted[0], N);
    std::cout << std::endl << std::endl;
    
    // Поиск вхождений элементов строки 0 (отсортированной) в строку 1 (изначальную)
    // и перестановка столбцов с соответствующими индексами в матрице a[M][N]
    std::cout << "Перестановка матрицы...\n";
    for (int j0 = 0; j0 < N - 1; j0++) {
        for (int j1 = j0 + 1; j1 < N; j1++) {
            if (PatternSorted[0][j0] == PatternSorted[1][j1]) {
                SwapColumns(a, M, j0, j1);  // Смена столбцов соответствующих индексов
                                            // в исходной матрице
                // Смена элементов второй строки
                swap(PatternSorted[1][j0], PatternSorted[1][j1]);
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
