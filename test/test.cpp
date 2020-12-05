// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma warning ( disable : 4996 )

#include <iostream>
#include <ctime>


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

template <typename T> inline constexpr
int signum(T x, std::false_type is_signed) {
    return T(0) < x;
}

template <typename T> inline constexpr
int signum(T x, std::true_type is_signed) {
    return (T(0) < x) - (x < T(0));
}

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); // Установка корректного вывода кириллицы
    srand(time(NULL)); // Установка генератора случайных чисел
 
    // с помощью константы
    const int N = 10;
    int A[N];
    
    // динамически в C++
    int M;
    std::cin >> M;
    int* B = new int[M];
    /*...*/
    delete[]B;

    // динамически в C
    int* C = NULL;
    C = (int*)malloc(M*sizeof(int));
    /*...*/
    free(C);

    // явное задание размера
    int D[10];
    
    // задание размера типом, приводящимуся к целочисленному положительному
    int E['t'];

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 10;
        std::cout << A[i] << "  ";
    }
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    std::cout << endl;

    std::cout << "A[3] = " << A[3] << endl;
    std::cout << "size(A) = " << size(A) << endl;
    std::cout << "sizeof(A) = " << sizeof(A) << endl;
    std::cout << "sizeof(*A) = " << sizeof(*A) << endl;
    std::cout << "A = " << A << endl;
    std::cout << "*(A + 3) = "<< *(A + 3) << endl;

    for (int i = 0; i < N; i++) {
        std::cout << *(A + i) << "  ";
    }
    // Подсчет нулевых элементов в заданном одномерном массиве
    int zeroes = 0;
    bool bThereIsZero = false;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            zeroes++;
            bThereIsZero = true; // Есть ли вообще нули?
        }
    }

    // Вычисление суммы положительных элементов
    // в заданном одномерном массиве
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > 0) {
            sum += A[i];
        }
    }
    
    // Поиск первого максимального элемента
    // и его индекса в заданном одномерном массиве
    int FirstMaxElement = *A,
        FirstMaxIndex;
    for (int i = 0; i < N; i++) {
        if (FirstMaxElement < A[i]) {
            FirstMaxElement = A[i];
            FirstMaxIndex = i;
        }
    }

    // Поиск последнего минимального элемента
    // и его индекса в заданном одномерном массиве
    int LastMinElement = *A,
        LastMinIndex;
    for (int i = 0; i < N; i++) {
        if (LastMinElement >= A[i]) {
            LastMinElement = A[i];
            LastMinIndex = i;
        }
    }

#if 0
    // Алгоритм сортировки массива
    int N; // количество элементов массива
    cin >> N;
    int a[N];
    int j = N - 1;
    bool FLAG;
    do {
        FLAG = 0;
        for (int i = 0; i < j; i++) {
            if (a[i] > a[i + 1]) {
                // перестановка элементов массива
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                FLAG = 1;
            }
        }
        j = j - 1;
    } while (FLAG); // сортировка заканчивается, если на предыдушем шаге
                    // не было выполнено ни одной перестановки в массиве
#endif

 #if 0
    std::std::cout << "Hello World!\n";
    
    int iINT = 1;               std::cout << "sizeof(iINT)\t\t" << sizeof(iINT) << endl;

    unsigned int uiINT = 1;     std::cout << "sizeof(unsigned int)\t" << sizeof(uiINT) << endl;
    long int liINT = 1;         std::cout << "sizeof(long int)\t" << sizeof(liINT) << endl;
    long long llINT = 1;        std::cout << "sizeof(long long)\t" << sizeof(llINT) << endl;
    float fFLOAT = 1;           std::cout << "sizeof(float)\t\t" << sizeof(fFLOAT) << endl;
    double dFLOAT = 1;          std::cout << "sizeof(double)\t\t" << sizeof(dFLOAT) << endl;
    long double ldFLOAT = 1;    std::cout << "sizeof(long double)\t" << sizeof(ldFLOAT) << endl;
    char cChar = 'a';           std::cout << "sizeof(char)\t\t" << sizeof(cChar) << endl;
    char32_t wcChar32 = 'A';    std::cout << "sizeof(char32_t)\t" << sizeof(wcChar32) << endl;
    float* Arr;                std::cout << "sizeof(double*)\t" << sizeof(Arr) << endl;

    int X = 1;
    std::cout << X << endl;
    X <<= 1;
    std::cout << X << endl;
    X <<= 1;
    std::cout << X << endl;
    X <<= 1;
    std::cout << X << endl;
    X <<= 1;
    std::cout << X << endl;
    X <<= 1;
    std::cout << X << endl;
    X <<= 1;
    std::cout << X << endl;

    X >>= 1;
    std::cout << X << endl;
    X >>= 1;
    std::cout << X << endl;
    X >>= 1;
    std::cout << X << endl;
    X >>= 1;
    std::cout << X << endl;
    X >>= 1;
    std::cout << X << endl;
    X >>= 1;
    std::cout << X << endl;
    X >>= 1;
    std::cout << X << endl;
    X >>= 1;
    std::cout << X << endl;
    X >>= 1;
    std::cout << X << endl;
    X >>= 1;
    std::cout << X << endl;

    X <<= 1;
    std::cout << X << endl;
    X <<= 1;
    std::cout << X << endl;
    X <<= 1;
    std::cout << X << endl;
    int Y = 0b00000001;
    X = 0b00000011;
    int C = X | Y;
    std::cout.binary;
    std::cout << C << endl;
    
    X = Y = 1;
    C = ++X; // C = X + 1; X = X + 1;
    std::cout << "C = ++X : " <<  C << endl;
    
    C = Y++; // C = Y; Y = Y + 1;
    std::cout << "C = Y++ : " << C << endl;

    //scanf_s("%d", &C);
    //printf("%d", C);

    char    ch = 'h',
            string[] = "computer";

    int     count = -1234;
    double  fp = 123.456;

    printf("%c\n", ch);
    printf("%s\n", string);
    printf("%d\n", count);
    printf("%f\n", fp);
#endif
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
