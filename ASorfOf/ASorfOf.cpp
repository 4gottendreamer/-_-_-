// ASorfOf.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

// Swaps _A[_i_from] with _A[_j_to] elements
template <typename T>
void swap(T* _A, int _N, int _i_from, int _j_to)
{
    T tmp = _A[_i_from];
    _A[_i_from] = _A[_j_to];
    _A[_j_to] = tmp;
}

// Сортировка вставками
template <typename T>
void SortInsert(T* A, const int n)
{
    T tmp;
    for (int i = 1, j; i < n; i++) {
        tmp = A[i];
        j = i;
        while (j > 0 and tmp < A[j - 1]) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tmp;
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
