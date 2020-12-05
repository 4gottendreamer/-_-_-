// lab_06.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// Вариант №6.
// Дан целочисленный массив А[N]. Определить индекс последнего элемента,
// числовое значение которого состоит из наибольшего количества цифр.
//

#include <iostream>
#define DIVISOR 10000000


// Возвращает количество цифр числа _A
int DigitsNumber(__int64 _A)
{
    if (_A == 0) return 1;

    int count = 0;
    while (_A)
    {
        count++;
        _A /= 10;
    }

    return count;
}

// Возвращает знак вещественного _X
// -1 при _X < 0
// 0 при _X == 0
// 1 при _X > 0
int fsignum(double _X)
{
    return (_X > 0) ? 1 : ((_X < 0) ? -1 : 0);
}

// Возращает
// -1 при _X < 0
// 0 при _X == 0
// 1 при _X > 0
template <typename T>
int signum(T _X) {
    return (T(0) < _X) - (_X < T(0));
}

//template <typename T> inline constexpr
//int signum(T x, std::false_type is_signed) {
//    return T(0) < x;
//}

//template <typename T> inline constexpr
//int signum(T x, std::true_type is_signed) {
//    return (T(0) < x) - (x < T(0));
//}

//template <typename T> inline constexpr
//int signum(T x) {
//    return signum(x, std::is_signed<T>());
//}

int main()
{
    using namespace std;

    setlocale(LC_ALL, "Russian"); // Установка корректного вывода кириллицы
    srand(time(NULL)); // Установка генератора случайных чисел

    int N;
    __int64 *a;

    cout << "Введите количество элементов массива: ";
    cin >> N;
    
    a = new __int64[N]; // Выделение памяти под массив

    cout << "Последовательность псевдослучаных чисел:" << endl;

    int MaxDigitsIndex,         // Индекс элемента массива с наибольшем
        MaxDigitsNumber = 0;    // Максимальное число цифр элемента массива

    // Заполнение массива псевдослучайной последовательностю чисел
    // и вывод значений элементов в консоль
    for (int i = 0; i < N; i++)
    {
        int RandomizeMe = rand();
        //a[i] = (rand() % DIVISOR) * signum(sin(RandomizeMe)) * sin(RandomizeMe);
        a[i] = RandomizeMe % DIVISOR * sin(RandomizeMe); cout << sin(RandomizeMe) << '\n';
        printf("a[%2d] = %8lld\tЦифр: %d\n", i, a[i], DigitsNumber(a[i]));
        if (MaxDigitsNumber <= DigitsNumber(a[i])) { // Если текущее максимальное число цифр
                                                     // меньше числа цифр
                                                     // текущего элемента массива,
            MaxDigitsNumber = DigitsNumber(a[i]);    // то присваиваем переменным
            MaxDigitsIndex = i;                      // текущие значения
        }
    }

    cout << "Максимальный индекс (по спецификации C/C++) " << MaxDigitsIndex << endl;
    cout << "Элемент массива a[" << MaxDigitsIndex << "] = " << a[MaxDigitsIndex] << endl;
    delete[]a;

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
