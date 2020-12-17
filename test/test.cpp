// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma warning ( disable : 4996 )
#pragma warning ( disable : 6368 )

#include <iostream>
#include <ctime>

#include <memory>

#if 0

<type> fuction_name(<type1> p1 = defaul_val1, ... <typeN> pN = defaul_valN)
{
    <type> R;
    /* Основные команды */
    return R;
}

int AddMe(int a, int b)
{
    return a + b;
}
#endif // 0


// Возвращает знак вещественного _X
// -1 при _X < 0
// 0 при _X == 0
// 1 при _X > 0
template <typename T>
int signum(T& _X)
{
    return (_X > 0) ? 1 : ((_X < 0) ? -1 : 0);
}

// Меняет знак _X на противоположный
template <typename T>
void Inverse(T& _X)
{
    _X *= T(-1.);
}

// Swaps _A[_i_from] with _A[_j_to] elements
template <typename T>
void swap(T* _A, int _N, int _i_from, int _j_to)
{
    T tmp = _A[_i_from];
    _A[_i_from] = _A[_j_to];
    _A[_j_to] = tmp;
}

// Меняет значения переменных _from и _to
template <typename T>
void swap(T* _from, T* _to)
{
    T tmp = *_from;
    *_from = *_to;
    *_to = tmp;
}

// Возвращает знак вещественного _X
// -1 при _X < 0
// 0 при _X == 0
// 1 при _X > 0
int fsignum(double _X)
{
    return (_X > 0) ? 1 : ((_X < 0) ? -1 : 0);
}

#if 0
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
#endif // 0

template <typename T>
void myOut(T* a = T(1))
{
    std::cout << a[0] << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian"); // Установка корректного вывода кириллицы
    srand(time(NULL)); // Установка генератора случайных чисел

    std::unique_ptr<int> uptrA;

    int A = -5;
    int B = 7;
    int* ptrA = &A;
    // В качестве параметров в функию передаются адреса переменных A и B
    std::cout << "myOut(ptrA) = "; myOut(ptrA);  std::cout << std::endl;
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;
    swap(&A, &B); std::cout << "Swapping...\n";
    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;

    B = signum(A);
    std::cout << "B = signum(A)" << std::endl;
    Inverse(B);
    std::cout << "Inverse(B) = " << B << std::endl;


#if 0   // ЛАБОРАТОРНАЯ 8. Вопрос 2. Синтаксис указателей //
    // Указатель symbol указывает на переменную типа char
    char* symbol;

    // Массив Arr содержит 10 элементов
    // каждый элемент имеет указатель на переменную с типом int
    int* Arr[10];

    // Переменная ptrArr указывает на массив с 10 элементами.
    // Каждый элемент в этом массиве имеет тип int
    long(*ptrArr)[10] = new long[5][10];
    
    // Имя массива также является указателем на его первый элемент
    double R[10];
    // ( R[0] == *(R) ) == true;

    /* Указатель prtX можно изменить, чтобы он указывал на другое значение int,
    но значение, на которое он указывает, изменить невозможно.*/
    int const* prtX;

    int FortyTwo = 42;
    int ZER0 = 0;

    int iCatch;
    int* ptrCatch = &iCatch; // Взятие адреса переменной iCatch
    *ptrCatch = 22;          // Присвоение значения с разыменованием адреса
    std::cout << iCatch << std::endl;

    /* Переменная ptrFixed0 объявляется как постоянный указатель на тип int.
    Значение, на которое он указывает, можно изменить,
    но указатель должен всегда указывать на одно и то же расположение — адрес ZER0. */
    int* const ptrFixed0 = &ZER0;

    /* Объявление prt42 указывает, что программа не может изменить значение,
     на которое указывает указатель, и что программа не может изменить сам указатель.*/
    int* const volatile ptr42 = &FortyTwo;

    // Также в С возможны сложные декларации указателей на указатели
    char* (*(*var)())[10];
    //^ ^  ^ ^ ^  ^   ^
    //7 6  4 2 1  3   5
/*  1 Идентификатор var объявлен как
    2 указатель на
    3 функцию, возвращающую
    4 указатель на
    5 массив из 10 элементов, которые являются
    6 указателями на
    7 значения типа char .*/

    int(*UDArr)[7] = new int[5][7];

#endif // ЛАБОРАТОРНАЯ 8. Вопрос 2. Синтаксис указателей //

#if 0
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
    C = (int*)malloc(M * sizeof(int));
    /*...*/
    free(C);

    // явное задание размера
    int D[10];

    // задание размера типом, приводящимуся к целочисленному положительному
    int E['t'];
#endif // 0

#if 0 // ЛАБОРАТОРНАЯ 7. Вопрос 2 //
    
    // ДВУМЕРНЫЕ МАССИВЫ. Объявление (declaring) //

    // с помощью констант
    const int K = 20, L = 10;
    int A[K][L];

    // динамически в C++
    int M, N;
    std::cin >> M >> N;
    int** B = new int* [M];
    for (int i = 0; i < M; i++) {
        B[i] = new int[N];
    }
    /*...*/
    for (int i = 0; i < M; i++) {
        delete B[i];
    }
    delete[]B;

    // динамически в C
    int** C = NULL;
    C = (int**)malloc(M * sizeof(int));
    for (int i = 0; i < N; i++) {
        C[i] = (int*)malloc(N * sizeof(int));
    }
    /*...*/
    for (int i = 0; i < M; i++) {
        free(C[i]);
    }
    free(C);

    // явное задание размера
    int D[20][10];

    // задание размера типом, приводящимуся к целочисленному положительному
    int E['M']['N'];
#endif // 0

#if 0 // ЛАБОРАТОРНАЯ 7. Вопрос 4 //
    
    // 1. Поиск произведения отрицательных элементов каждого столбца //

    const int M = 5, N = 3;
    int A[M][N];
    int negatives[N]; // Массив с постолбовыми произведениями
    std::fill_n(negatives, N, 1); // Заполнение массива единицами
    
    for (int i = 0; i < N; i++) {
        std::cout << negatives[i] << '\t';
    }
    std::cout << "\n\n";
    // Пример вывода массива в виде квадратной матрицы
    // Заполнение массива
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10 - 5; // Примерно половина отрицательных
            std::cout << A[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Проверка условия с выводом на экран
    for (int j = 0; j < N; j++) { // Внешний цикл делает обход по строкам
        int product = 1;
        bool ThereIsNegative = false;
        for (int i = 0; i < M; i++) { // Внутренний цикл делает обход по столбцам
            if (A[i][j] < 0) {
               product *= A[i][j];
               negatives[j] *= A[i][j]; // Если данные понадобятся в дальнейшем
               ThereIsNegative = true;
            }
        }
        // Если нет отрицательных, выводится прочерк
        if (!ThereIsNegative) {
            std::cout << "-\t";
            negatives[j] = 0; // Заполнение элемента массива нулём,
                               // если не было отрицательных
        }
        // Иначе выводим значение
        else
            std::cout << product << '\t';

        }
    std::cout << std::endl;

    // Вывод результатов
    for (int i = 0; i < N; i++) {
        if (negatives[i] != 0) {
            std::cout << negatives[i] << '\t';
        }
        else
            std::cout << "-\t";
    }
#endif // 0

#if 0 // ЛАБОРАТОРНАЯ 7. Вопрос 4 //
    
    // 2. Вычисление суммы положительных элементов каждой строки //
    const int M = 5, N = 3;
    int A[M][N];
    int positives[M] = { 0 }; // Массив с построчными суммами
                            // (на случай, если нужно запоминать результат)
    std::fill_n(positives, M, NULL);

    // Ввод элементов массива
    for (int i = 0; i < M; i++) {
        int sum = 0;
        bool ThereIsPositive = false;
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10 - 5;
            if (A[i][j] > 0) {
                sum += A[i][j];
                positives[i] += A[i][j];
                ThereIsPositive = true;
            }
        }
        // Вывод результата
        if (ThereIsPositive) {
            std::cout << sum << '\t';
        }
        // Если в строке не было положительных чисел, выводится прочерк
        else
            std::cout << "-\t";
    }
    std::cout << std::endl;

    // Вывод результатов
    // Если в строке не было положительных чисел, выводится прочерк
    for (int i = 0; i < M; i++) {
        if (positives[i] != NULL) {
            std::cout << positives[i] << '\t';
        }
        else
            std::cout << "-\t";
    }
    std::cout << std::endl;

    // Вывод массива
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << A[i][j] << '\t';
        }
        std::cout << std::endl;
    }

#endif // 0

#if 0 // ЛАБОРАТОРНАЯ 7. Вопрос 5. Изменение индексов матрицы//

    /*...*/
    const int M = 5, N = 7;
    int A[M][N];

    // Заполнение массива числами, цифры десятичных разрядов которых
    // соответствуют индексам по M (количеству строк),
    // а единичных разрядов соответствуют индексам по N (количеству столбцов),
    // при M < 10; N < 10 (для удобства отладки)
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 10 * (i + 1) + (j + 1);
            std::cout << A[i][j] << "  ";
        }
        std::cout << std::endl;
    }
#if 1   // 1. На главной диагонали
    std::cout << "Главная диагональ\n";
    for (int i = 0; i < M and i < N; i++) {
        std::cout << A[i][i] << "  ";
    }
    std::cout << std::endl;
#endif
 

#if 1   // 2. На побочной диагонали //
    std::cout << "Побочная диагональ\n";
    for (int i = 0; i < M and i < N; i++) {
        std::cout << A[i][N - i - 1] << "  ";
    }
#endif
    std::cout << std::endl;

#if 0   // 3. Выше главной диагонали //
    std::cout << "Выше главной диагонали\n";
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j > i and j < N; j++) {
            std::cout << A[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
#endif

#if 0   // 4. Ниже главной диагонали //
    std::cout << "Ниже главной диагонали\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < i and j < N; j++) {
            std::cout << A[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
#endif 

#if 1   // 5. Выше побочной диагонали //
    std::cout << "Выше побочной диагонали\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            std::cout << A[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
#endif

#if 1   // 6. Ниже побочной диагонали //
    // Элементы индексируются от начала к концу
    std::cout << "Ниже побочной диагонали\n";
    for (int i = 0; i < M; i++) {
        for (int j = (M > N ? M : N) - i; j < N; j++) {
            std::cout << A[i][j] << "  ";
        }
        std::cout << std::endl;
    }

  /*  std::cout << "Ниже побочной диагонали\n";
    for (int i = M - 1; i > 0; i--) {
        for (int j = i-1; j < N; j++) {
            std::cout << A[i][j] << "  ";
        }
        std::cout << std::endl;
    }*/
#endif
    /*...*/

#endif  // ЛАБОРАТОРНАЯ 7. Вопрос 5. Изменение индексов матрицы//

#if 0


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
#endif // 0

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
