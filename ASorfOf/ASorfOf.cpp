// ASorfOf.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Разные методы сортировки
//

#include <iostream>

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
void Swap2InRow(T* _A, const int _j_from, const int _j_to)
{
    swap(*(_A + _j_from), *(_A + _j_to));
}

// Меняет местами столбцы с индексами _i_from и _j_to в матрице _A[_M][*]
template <typename T>
void SwapColumns(T** _A, const int _M, const int _j_from, const int _j_to)
{
    for (int i = 0; i < _M; i++) {
        swap(_A[i][_j_from], _A[i][_j_to]);
    }
}

// Сортировка вставками
template <typename T>
void SortInsert(T* _A, const int _N)
{
    for (int i = 1; i < _N; i++) {
        int j = i;
        while (j > 0 and _A[j] < _A[j - 1]) {
            swap(_A[j], _A[j - 1]);
            j--;
        }
    }
}

// Вывод матрицы на экран
template <typename T>
void PrintMatrix(T** _A, const int _M, const int _N)
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
T SumColumnPositive(T** _a, const int _M, int _jCol)
{
    T sum = 0;
    for (int i = 0; i < _M; i++) {
        if (_a[i][_jCol] > 0)
            sum += _a[i][_jCol];
    }
    return sum;
}

// Swaps _A[_i_from] with _A[_j_to] elements
template <typename T>
void swap(T* _A, int _N, int _i_from, int _j_to)
{
    T tmp = _A[_i_from];
    _A[_i_from] = _A[_j_to];
    _A[_j_to] = tmp;
}

/*
* 
* !!! ДОПИЛИТЬ !!!
* 
*/
template <typename T>
void SortBubble(T* _A, const int _N)
{
    for (int i = 0; i < _N - 1; i++) {
        //bool ThereIsASwap = false;
        int min = i;
        int j;
        for (j = i; j < _N - 1 - i; j++) {
            if (_A[j] > _A[j + 1]) {
                swap(_A, _N, j, j + 1);
                //ThereIsASwap = true;
            }
            /*if (_A[j] < _A[min]) {
                min = i;
            }*/
        }
        //if (!ThereIsASwap) break;
        /*if (min != i) {
            swap(_A, _N, i, min);
        }*/
    }
}
// Сортировка обменами (пузырьковая)
// устойчивый алгоритм
//FOR J = 0 TO N - 1 STEP 1
//    F = 0
//    MIN = J
//    FOR I = J TO N - 1 - J STEP 1
//        IF Y[I] > Y[I + 1] THEN SWAP Y[I], Y[I + 1]:F = 1
//        IF Y[I] < Y[MIN] THEN MIN = I
//    NEXT I
//    IF F = 0 THEN EXIT FOR
//    IF MIN<>J THEN SWAP Y[J], Y[MIN]
//NEXT J

//for (int i = 0; i < size - 1; i++) {
//    for (int j = 0; j < size - i - 1; j++) {
//        if (arr[j] > arr[j + 1]) {
//            // меняем элементы местами
//            temp = arr[j];
//            arr[j] = arr[j + 1];
//            arr[j + 1] = temp;
//        }
//    }
//}

int main()
{
    const int N = 10;

    int A[N];
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 10;
        std::cout << A[i] << "   ";
    }
    std::cout << std::endl;

    SortBubble(A, N);
    for (int i = 0; i < N; i++) {
        std::cout << A[i] << "   ";
    }
    std::cout << std::endl;

    SortInsert(A, N);
    for (int i = 0; i < N; i++) {
        std::cout << A[i] << "   ";
    }
    std::cout << std::endl;
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
