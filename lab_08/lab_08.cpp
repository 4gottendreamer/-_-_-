// lab_08.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант №6.
// Задача 24.
// Дан вещественный массив А[N][М]. Будем называть «соседями» элемента А[i][j] такие элементы массива А,
// соответствующие индексы которых отличаются от i и j не более чем на единицу.
// Для массива А сформировать массив В, значения элементов которого вычисляются по следующему правилу:
// если среди соседей а[i][j] есть хотя бы один элемент, совпадающий с а[i][j], то b[i][j] = 1;
// в противном случае b[i][j] = 0.

#include <iostream>

#define RESIDUE 10 // Макроподстановка с переменной для изменения остатков от деления

// Рядом ли "соседи"?
// { 1 -- да; 0 -- нет }
// !!! ДОПИЛИТЬ !!!
bool IsNeighbourAround(int** _A, const int _M, const int _N, const int _i, const int _j)
{
    for (int i = (_i > 0 ? _i - 1 : _i); i < _i + 1 or i < _M; i++) {
        for (int j = (_j > 0 ? _j - 1 : _j); j < _j + 1 or j < _N; j++) {
            if (_A[i][j] == _A[_i][_j] and (i != _i) and (j != _j)) {
                    return true;
            }
        }
    }
    return false;
}

// Проверка на "соседство" элемента _A[_i[_j]
// 1 если "сосед" рядом, иначе 0
// (реализация на костылях)
bool IsNeighbourAround4fools(int** _A, const int _M, const int _N, const int _i, const int _j)
{
    if (_i == 0) { // ВЕРХ
        if (_j == 0) {  // верх-лево угол
            if (_A[_i][_j + 1] == _A[_i][_j]) { return true; }
            if (_A[_i + 1][_j] == _A[_i][_j]) { return true; }
            if (_A[_i + 1][_j + 1] == _A[_i][_j]) { return true; }
        }
        else if (_j == _N - 1) {
            // верх-право угол
            if (_A[_i][_j - 1] == _A[_i][_j]) { return true; }
            if (_A[_i + 1][_j - 1] == _A[_i][_j]) { return true; }
            if (_A[_i + 1][_j] == _A[_i][_j]) { return true; }
        }
        else {
            // верх-середина строки
            if (_A[_i][_j - 1] == _A[_i][_j]) { return true; }
            if (_A[_i][_j + 1] == _A[_i][_j]) { return true; }
            if (_A[_i + 1][_j - 1] == _A[_i][_j]) { return true; }
            if (_A[_i + 1][_j] == _A[_i][_j]) { return true; }
            if (_A[_i + 1][_j + 1] == _A[_i][_j]) { return true; }
        }
    }
    else if (_i == _M - 1) { // НИЗ
        if (_j == 0) {  // низ-лево угол
            if (_A[_i][_j + 1] == _A[_i][_j]) { return true; }
            if (_A[_i - 1][_j] == _A[_i][_j]) { return true; }
            if (_A[_i - 1][_j + 1] == _A[_i][_j]) { return true; }
        }
        else if (_j == _N - 1) { // низ-право угол
            if (_A[_i - 1][_j - 1] == _A[_i][_j]) { return true; }
            if (_A[_i - 1][_j] == _A[_i][_j]) { return true; }
            if (_A[_i][_j - 1] == _A[_i][_j]) { return true; }
        }
        else { // низ-середина
            if (_A[_i - 1][_j - 1] == _A[_i][_j]) { return true; }
            if (_A[_i - 1][_j] == _A[_i][_j]) { return true; }
            if (_A[_i - 1][_j + 1] == _A[_i][_j]) { return true; }
            if (_A[_i][_j - 1] == _A[_i][_j]) { return true; }
            if (_A[_i][_j + 1] == _A[_i][_j]) { return true; }
        }
    }
    else { // СЕРЕДИНА
            if (_A[_i - 1][_j - 1] == _A[_i][_j]) { return true; }
            if (_A[_i - 1][_j] == _A[_i][_j]) { return true; }
            if (_A[_i - 1][_j + 1] == _A[_i][_j]) { return true; }
            
            if (_A[_i][_j - 1] == _A[_i][_j]) { return true; }
            if (_A[_i][_j + 1] == _A[_i][_j]) { return true; }
            
            if (_A[_i + 1][_j - 1] == _A[_i][_j]) { return true; }
            if (_A[_i + 1][_j] == _A[_i][_j]) { return true; }
            if (_A[_i + 1][_j + 1] == _A[_i][_j]) { return true; }
    }
    return false;
}

// Вывод матрицы на экран
void PrintMatrix(int** _A, const int _M, const int _N)
{
    for (int i = 0; i < _M; i++) {
        for (int j = 0; j < _N; j++) {
            std::cout << _A[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian"); // Установка корректного вывода кириллицы
    srand(time(NULL)); // Установка генератора случайных чисел
    int M, N;
    int** a;
    int** b;

    std::cout << "Введите размерность массива:" << std::endl;
    std::cin >> M >> N;

    a = new int* [M];
    b = new int* [M];
    for (int i = 0; i < M; i++) {
        a[i] = new int[N];
        b[i] = new int[N];
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % RESIDUE; // Заполнение массива псевдослучайными числами
        }
    }
    
    std::cout << "Исходная матрица:" << std::endl;
    PrintMatrix(a, M, N);

    // Проверка условий
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (IsNeighbourAround4fools(a, M, N, i, j)) { // Если "соседи" поблизости,
                b[i][j] = 1;                              // ставим 1,
            }
            else {                                        // иначе 0
                b[i][j] = 0;
            }
        }
    }

    // Вывод матрицы
    std::cout << "Матрица \"соседства\":" << std::endl;
    PrintMatrix(b, M, N);

    // Освобождение динамически выделенной памяти
    for (int i = 0; i < M; i++) {
        delete a[i];
        delete b[i];
    }
    delete[]a;
    delete[]b;

    std::cout << "Нажмите Enter";
    std::cin.get(); std::cin.get();
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
