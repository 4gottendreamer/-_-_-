/*
 * Лаба 3
Вычислить значение переменной y по заданной расчётной формуле и набору исходных
данных. Значения исходных данных вводить с клавиатуры. На печать вывести значения
вводимых исходных данных и результат вычислений, сопровождая вывод наименованием
выводимых переменных.
y = fabs(pow(x, 3) - 10) * (atan(z + 0.2) + exp(-(x / 2 + 3)));
*/

/*
 * Лаб 5
Даны натуральное число n, действительные числа а1,..., an.
Вычислить обратную величину произведения тех членов последовательности a1,..., an,
для которых выполняется условие i + 1 < a_i < i!
 */

/*
 * Лаб 6
Дан целочисленный массив А[N]. Определить индекс последнего элемента,
числовое значение которого состоит из наибольшего количества цифр.
 */

/*
 * Лаб 7
Дан целочисленный массив А[N][М].Определить индекс столбца,
в котором находится максимальное количество нулей.
Переставить элементы данного столбца в обратном порядке.
 */

/*
 * Лаб 10
В произвольном тексте, содержащем не более 10 строк, в каждой строке не более
80 символов, попарно переставить местами слова, стоящие на нечётных и чётных
местах в строке. Вывести полученный текст на экран.
 */

using System;
using System.Globalization;
using System.Linq;

namespace lab_15_v6
{
    class lab_15_v6
    {
        private static int randomizerMultiplier = 20; // Переменная смещения дисперсии
                                                      // псевдослучайных чисел

        private static double[] doubleArr1;
        private static int[] intArr1;
        private static int[,] intArr2;

        private static int[,] intArr2Test = new int[,] {
                { 1, 2, 3, 3, 0 },
                { 1, 2, 3, 1, 1 },
                { 1, 0, 3, 0, 2 },
                { 0, 5, 6, 4, 4 },
                { 7, 0, 0, 2, 5 },
                { 5, 8, 3, 3, 7 },
                { 3, 0, 0, 2, 8 },
                { 7, 8, 2, 2, 0 }
        };

        static void Main()
        {
            bool showMenu = true;
            while (showMenu) {
                showMenu = MainMenu();
            }
        }
        static void PrintMatrix(int[,] _Arr, char _Ch)
        {
            for (int i = 0; i < _Arr.GetLength(0); i++) {
                for (int j = 0; j < _Arr.GetLength(1); j++) {
                    Console.Write(_Arr[i, j] + _Ch);
                }
                Console.WriteLine();
            }
        }

        static double[] GetDoubleArray(int _dimension, int _randomizerMultiplier = 1)
        {
            double[] doubleArr1 = new double[_dimension];
            Random random = new Random();
            for (int i = 0; i < doubleArr1.GetLength(0); i++) {
                doubleArr1[i] = _randomizerMultiplier *
                    random.NextDouble();
                //(random.NextDouble() - random.NextDouble());
                Console.Write($"{doubleArr1[i]}\t");
            }
            return doubleArr1;
        }

        static int[] GetIntArray(int _dimension, int _minValue = 0, int _maxValue = 2147483647)
        {
            Random random = new Random();

            int[] intArr1 = new int[_dimension];
            for (int i = 0; i < intArr1.GetLength(0); i++) {
                intArr1[i] = random.Next();
            }
            return intArr1;
        }

        static int[,] GetIntArray2(
            int _dimensionY, int _dimensionX,
            int _minValue = 0, int _maxValue = 2147483647
            )
        {
            int[,] intArr2 =
                new int[_dimensionY, _dimensionX];
            Random random = new Random();
            for (int y = 0; y < intArr2.GetLength(0); y++) {
                for (int x = 0; x < intArr2.GetLength(1); x++) {
                    intArr2[y, x] = random.Next(_minValue, _maxValue);
                }
            }
            return intArr2;
        }

        static bool MainMenu()
        {
            // Вывести менюшку
            Console.Clear();
            Console.WriteLine("1. Лабораторная №03. Вычисление по заданной формуле.");
            Console.WriteLine("2. Лабораторная №05. Работа с линейными массивами.");
            Console.WriteLine("3. Лабораторная №06. Работа с линейными массивами.");
            Console.WriteLine("4. Лабораторная №07. Работа с двумерными массивами.");
            Console.WriteLine("5. Лабораторная №10. Работа со строками.");
            Console.WriteLine("0. Выход");
            Console.Write("Выберите пункт:> ");

            switch (Console.ReadLine()) {
            // lab 03
            case "1": {
                /*
                 * Лаба 3
                Вычислить значение переменной y по заданной расчётной формуле
                и набору исходных данных.
                Значения исходных данных вводить с клавиатуры.
                На печать вывести значения вводимых исходных данных и результат вычислений,
                сопровождая вывод наименованием выводимых переменных.
                y = fabs(pow(x, 3) - 10) * (atan(z + 0.2) + exp(-(x / 2 + 3)));
                */
                Console.WriteLine();
                Console.WriteLine("Лабораторная №03");
                Console.WriteLine();
                Console.WriteLine("Вычислить значение переменной y по заданной расчётной формуле");
                Console.WriteLine("и набору исходных данных.");
                Console.WriteLine("Значения исходных данных вводить с клавиатуры.");
                Console.WriteLine("На печать вывести значения вводимых исходных данных и результат вычислений,");
                Console.WriteLine("сопровождая вывод наименованием выводимых переменных.");
                Console.WriteLine("y(x; z; t) = | x^3 - 10 | * (arctg(z + 0.2) + e^(-(x / 2 + 3)))");
                Console.WriteLine();
                Console.WriteLine("Введите x, z, t:");
                NumberFormatInfo numberFormatInfo = new NumberFormatInfo() {
                    NumberDecimalSeparator = ".",
                };
                Console.Write("x = ");
                double x = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);
                Console.Write("z = ");
                double z = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);
                Console.Write("t = ");
                double t = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);
                Console.WriteLine($"Вы ввели:\nx = {x}\nz = {z}\nt = {t}");
                Console.WriteLine("y(x; z; t) = | x^3 - 10 | * (arctg(z + 0.2) + e^(-(x / 2 + 3)))");
                Console.WriteLine($"y({x}; {z}; {t}) = {Lab03(x, z)}");
                Console.WriteLine();
                Console.WriteLine("Конец Лабораторной №03");
                Console.WriteLine("Нажмите Enter");
                Console.ReadLine();
                return true;
            }
            // lab 05
            case "2": {
                /*
                 * Лаб 5
                Даны натуральное число n, действительные числа а1,..., an.
                Вычислить обратную величину произведения тех членов последовательности a1,..., an,
                для которых выполняется условие i + 1 < a_i < i!
                 */
                Console.WriteLine();
                Console.WriteLine("Лабораторная №05");
                Console.WriteLine();
                Console.WriteLine("Даны натуральное число n, действительные числа а1,..., an.");
                Console.WriteLine("Вычислить обратную величину произведения тех членов последовательности");
                Console.WriteLine("для которых выполняется условие i + 1 < a_i < i!");
                Console.WriteLine();

                bool ChoiceMenu()
                {
                    Console.WriteLine("1. Ввод с клавиатуры");
                    Console.WriteLine("2. Автоматическое генерирование");
                    Console.Write("Выбор:> ");

                    switch (Console.ReadLine()) {
                    case "1": {
                        Console.WriteLine("Введите количество элементов массива.\n" +
                            "Внимание! При значениях больше 20 вычисление факториала вызывает " +
                            "переполнение типа UInt64.");
                        Console.WriteLine("Введите размерность n: ");
                        int n = int.Parse(Console.ReadLine());
                        double[] Arr = new double[n];
                        Console.WriteLine("Введите значения:");
                        for (int i = 0; i < Arr.Length; i++) {
                            Console.Write($"a[{i + 1}] = ");
                            NumberFormatInfo numberFormatInfo = new NumberFormatInfo() {
                                NumberDecimalSeparator = ".",
                            };
                            Arr[i] = Convert.ToDouble(Console.ReadLine());
                        }
                        doubleArr1 = Arr;
                        return true;
                    }
                    case "2": {
                        Console.WriteLine("Введите количество элементов массива.\n" +
                            "Внимание! При значениях больше 20 вычисление факториала вызывает " +
                            "переполнение типа UInt64.");
                        int n = int.Parse(Console.ReadLine());
                        double[] Arr = GetDoubleArray(n, randomizerMultiplier);
                        doubleArr1 = Arr;
                        Console.WriteLine("Автоматическое заполнение массива");
                        return true;
                    }
                    default:
                        Console.WriteLine("Неверный выбор");
                        return false;
                    }
                }
                bool menu = ChoiceMenu();
                while (!menu) {
                    menu = ChoiceMenu();
                }

                double reciprocal = 1;
                Console.WriteLine();
                Console.WriteLine("\nПроверка условия\ni + 1\t<\ta_i\t\t<\t\ti!");
                ulong Factorial(int _arg) // Подсчёт факториала итерационным методом
                {
                    ulong fact = 1;
                    for (int i = 1; i <= _arg; i++) {
                        fact *= (ulong)i;
                    }
                    return fact;
                }
                // Вывод массива и условий
                for (int i = 0; i < doubleArr1.Length; i++) {
                    Console.WriteLine($"{i + 2}\t{doubleArr1[i]}\t{Factorial(i + 1)}");
                }

                if (Lab05(doubleArr1, out reciprocal)) {
                    Console.WriteLine($"Обратное значение произведений элементов, " +
                        $"удовлетворяющих условию:\n{reciprocal}");
                }
                else {
                    Console.WriteLine("Нет чисел, удовлетворяющих условию");
                }
                Console.WriteLine();
                Console.WriteLine("Конец Лабораторной №05");
                Console.WriteLine("Нажмите Enter");
                Console.ReadLine();
                return true;
            }
            case "3": { // lab 06
                /*
                 * Лаб 6
                Дан целочисленный массив А[N]. Определить индекс последнего элемента,
                числовое значение которого состоит из наибольшего количества цифр.
                 */
                Console.WriteLine();
                Console.WriteLine("Лабораторная №06");
                Console.WriteLine();
                Console.WriteLine("Дан целочисленный массив А[N]. Определить индекс последнего элемента,");
                Console.WriteLine("числовое значение которого состоит из наибольшего количества цифр.");
                Console.WriteLine();

                bool ChoiceMenu()
                {
                    Console.WriteLine("1. Ввод с клавиатуры");
                    Console.WriteLine("2. Автоматическое генерирование");
                    Console.Write("Выбор:> ");

                    switch (Console.ReadLine()) {
                    case "1": {
                        Console.WriteLine("Введите размерность N: ");
                        int n = int.Parse(Console.ReadLine());
                        int[] Arr = new int[n];
                        Console.WriteLine("Введите значения:");
                        for (int i = 0; i < Arr.Length; i++) {
                            Console.Write($"a[{i + 1}] = ");
                            NumberFormatInfo numberFormatInfo = new NumberFormatInfo() {
                                NumberDecimalSeparator = ".",
                            };
                            Arr[i] = Convert.ToInt32(Console.ReadLine());
                        }
                        intArr1 = Arr;
                        return true;
                    }
                    case "2": {
                        Console.WriteLine("Введите размерность N: ");
                        int n = int.Parse(Console.ReadLine());
                        int[] Arr = GetIntArray(n);
                        intArr1 = Arr;
                        Console.WriteLine("Автоматическое заполнение массива");
                        return true;
                    }
                    default:
                        Console.WriteLine("Неверный выбор");
                        return false;
                    }
                }
                bool menu = ChoiceMenu();
                while (!menu) {
                    menu = ChoiceMenu();
                }

                Console.WriteLine("Полученный массив:");
                {
                    int i = 0;
                    foreach (var item in intArr1) {
                        Console.WriteLine($"a[{i++}]\t==\t{item}");
                    }
                }
                int lab06Result = Lab06(intArr1);
                Console.WriteLine(
                    $"Максимальный индекс элемента массива с наибольшим количеством цифр: {lab06Result}");
                Console.WriteLine($"Элемент массива a[{lab06Result}]\t=\t{intArr1[lab06Result]}");

                Console.WriteLine();
                Console.WriteLine("Конец Лабораторной №06");
                Console.WriteLine("Нажмите Enter");
                Console.ReadLine();
                return true;
            }
            case "4": { // lab 07
                /*
                 * Лаб 7
                Дан целочисленный массив А[N][М].Определить индекс столбца,
                в котором находится максимальное количество нулей.
                Переставить элементы данного столбца в обратном порядке.
                 */
                Console.WriteLine();
                Console.WriteLine("Лабораторная №07");
                Console.WriteLine();
                Console.WriteLine("Дан целочисленный массив А[N][М].Определить индекс столбца,");
                Console.WriteLine("в котором находится максимальное количество нулей.");
                Console.WriteLine("Переставить элементы данного столбца в обратном порядке.");
                Console.WriteLine();
                bool ChoiceMenu()
                {
                    Console.WriteLine("1. Ввод с клавиатуры");
                    Console.WriteLine("2. Автоматическое генерирование");
                    Console.Write("Выбор:> ");

                    switch (Console.ReadLine()) {
                    case "1": {
                        Console.WriteLine("Введите количество строк: ");
                        int y = int.Parse(Console.ReadLine());
                        Console.WriteLine("Введите количество столбцов: ");
                        int x = int.Parse(Console.ReadLine());
                        int[,] Arr2 = new int[y,x];
                        Console.WriteLine("Введите значения элементов:");
                        for (int j = 0; j < Arr2.GetLength(0); j++) {
                            Console.WriteLine($"Строка {j + 1}");
                            for (int i = 0; i < Arr2.GetLength(1); i++) {
                                Console.Write($"A_{j + 1}{i + 1} = ");
                                Arr2[j, i] = Convert.ToInt32(Console.ReadLine());
                            }
                        }
                        intArr2 = Arr2;
                        return true;
                    }
                    case "2": {
                        Console.WriteLine("Введите количество строк: ");
                        int y = int.Parse(Console.ReadLine());
                        Console.WriteLine("Введите количество столбцов: ");
                        int x = int.Parse(Console.ReadLine());
                        int[,] Arr2 = new int[y,x];
                        Arr2 = GetIntArray2(y, x, 0, 10);
                        intArr2 = Arr2;
                        Console.WriteLine("Автоматическое заполнение массива");
                        return true;
                    }
                    default:
                        Console.WriteLine("Неверный выбор");
                        return false;
                    }
                }
                bool menu = ChoiceMenu();
                while (!menu) {
                    menu = ChoiceMenu();
                }
                for (int i = 0; i < intArr2.GetLength(0); i++) {
                    for (int j = 0; j < intArr2.GetLength(1); j++) {
                        Console.Write(intArr2[i, j] + "  ");
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
                int index = Lab07(intArr2);
                if (index > -1) {
                    Console.WriteLine(
                        $"Индекс столбца с максимальным количеством нулей: {index}");
                }
                else {
                    Console.WriteLine("Нули в массиве отсутствуют.");
                }
                Console.WriteLine();
                Console.WriteLine("Конец Лабораторной №07");
                Console.WriteLine("Нажмите Enter");
                Console.ReadLine();
                return true;
            }
            case "5": {  // lab 10
                /*
                 * Лаб 10
                В произвольном тексте, содержащем не более 10 строк,
                в каждой строке не более 80 символов,
                попарно переставить местами слова,
                стоящие на нечётных и чётных местах в строке.
                Вывести полученный текст на экран.
                 */

                Console.WriteLine("Лабораторная №10");
                Console.WriteLine();
                Console.WriteLine("В произвольном тексте, содержащем не более 10 строк,");
                Console.WriteLine("в каждой строке не более 80 символов,");
                Console.WriteLine("попарно переставить местами слова,");
                Console.WriteLine("стоящие на нечётных и чётных местах в строке.");
                Console.WriteLine("Вывести полученный текст на экран.");
                Console.WriteLine();
                string[] Text = new string[0];
                string line;
                do {
                    line = Console.ReadLine();
                    if (line.Length > 0) {
                        Array.Resize<string>(ref Text, Text.Length + 1);
                        Text[^1] = line;
                    }
                }
                while (line.Length != 0);

                // Выполнение задания и вывод полученного текста
                Console.WriteLine("Полученный текст");
                string [] swappedText = Lab10(Text);
                foreach (var item in swappedText) {
                    Console.WriteLine(item);
                }

                Console.WriteLine();
                Console.WriteLine("Конец Лабораторной №10");
                Console.ReadLine();
                return true;
            }
            case "0": { // Выход
                Console.WriteLine("Выход");
                return false;
            }
            default: {
                Console.WriteLine("Неверный выбор");
                Console.ReadLine();
                return true;
            }
            }
        }

        static double Lab03(double _x, double _z)
        {
            /*
             * Лаба 3
            Вычислить значение переменной y по заданной расчётной формуле и набору исходных
            данных. Значения исходных данных вводить с клавиатуры. На печать вывести значения
            вводимых исходных данных и результат вычислений, сопровождая вывод наименованием
            выводимых переменных.
            y = fabs(pow(x, 3) - 10) * (atan(z + 0.2) + exp(-(x / 2 + 3)));
            */

            return
                Math.Abs(Math.Pow(_x, 3) - 10d) *
                (Math.Atan(_z + 0.2) + Math.Exp(-(_x / 2 + 3)));
        }

        static bool Lab05(double[] _Arr, out double _reciprocal)
        {
            /*
             * Лаб 5
            Даны натуральное число n, действительные числа а1,..., an.
            Вычислить обратную величину произведения тех членов последовательности a1,..., an,
            для которых выполняется условие i + 1 < a_i < i!
             */

            bool bDoesAnyFit = false; // Флаг проверки выполнения условия
            _reciprocal = 1;
            // Проверка условий задачи
            for (int i = 0; i < _Arr.Length; i++) {
                ulong F = factorial(i + 1);
                if (i + 2 < _Arr[i] && _Arr[i] < F) {
                    bDoesAnyFit = true; // Если выполняется хотя бы раз, "поднимаем" флаг
                                        //Console.WriteLine($"{i + 2}\t< {_Arr[i]}\t< {F}\n");
                    _reciprocal /= _Arr[i];
                }
            }
            ulong factorial(long _N)
            {
                ulong fact = 1;
                for (int i = 1; i <= _N; i++) {
                    fact *= (ulong)i;
                }
                return fact;
            }
            return bDoesAnyFit;
        }

        // Возвращает индекс последнего элемента, числовое значение которого
        // состоит из наибольшего количества цифр.
        static int Lab06(int[] _Arr) // Передавать заполненный массив
        {
            /*
             * Лаб 6
            Дан целочисленный массив А[N]. Определить индекс последнего элемента,
            числовое значение которого состоит из наибольшего количества цифр.
            */

            // Возвращает количество цифр числа _Number
            int DigitsNumber(long _Number)
            {
                if (_Number == 0)
                    return 1;
                int count = 0;
                while (_Number != 0) {
                    count++;
                    _Number /= 10;
                }
                return count;
            }

            int MaxDigitsIndex = 0;  // Индекс элемента массива с наибольшим количеством цифр
            int MaxDigitsNumber = 0; // Максимальное число цифр элемента массива

            for (int i = 0; i < _Arr.GetLength(0); i++) {
                // Если текущее максимальное число цифр
                // меньше числа цифр текущего элемента массива,
                if (MaxDigitsNumber <= DigitsNumber(_Arr[i])) {
                    MaxDigitsNumber = DigitsNumber(_Arr[i]); // то присваиваем переменным
                    MaxDigitsIndex = i;                  // текущие значения
                }
            }

            return MaxDigitsIndex;
        }

        // Возращает индекс столбца с максимальным количеством нулей
        // Переставляет элемены этого столбца в обратном порядке
        // Returns index of a row with the greatest number of zeroes
        // Inverses the order of this row
        static int Lab07(int[,] _Arr)
        {
            /*
             * Лаб 7
            Дан целочисленный массив А[N][М].Определить индекс столбца,
            в котором находится максимальное количество нулей.
            Переставить элементы данного столбца в обратном порядке.
             */

            /*
             * Поиски нулей по столбцам
             */
            int idxRowMaxZeros = -1;
            int  zeroCountPrev = 0;
            for (int j = 0, i = 0; j < _Arr.GetLength(1); j++) {
                bool thereIs0 = false;
                int zeroCountCurr = 0;
                for (i = 0; i < _Arr.GetLength(0); i++) {
                    if (_Arr[i, j] == 0) { // Поиск и подсчёт элементов,
                        zeroCountCurr++;   // удовлетворяющих условию
                        thereIs0 = true;
                    }
                }
                if (zeroCountCurr > zeroCountPrev && thereIs0) {
                    idxRowMaxZeros = j;
                    zeroCountPrev = zeroCountCurr;
                }
            }

            void swapTwo(ref int _a, ref int _b)
            {
                int tmp = _a;
                _a = _b;
                _b = tmp;
            }

            // Перестановка элементов нужного столбца в обратном порядке
            if (idxRowMaxZeros > -1) {
                int height = _Arr.GetLength(0);
                for (int j = 0; j < height / 2; j++) {
                    swapTwo(
                        ref _Arr[j, idxRowMaxZeros],
                        ref _Arr[height - j - 1, idxRowMaxZeros]
                        );
                }
            }

            return idxRowMaxZeros;
        }

        static string[] Lab10(string[] _Text)
        {
            /*
             * Лаб 10
            В произвольном тексте, содержащем не более 10 строк, в каждой строке не более
            80 символов, попарно переставить местами слова, стоящие на нечётных и чётных
            местах в строке. Вывести полученный текст на экран.
             */

            string[] result = _Text;

            // Массив "не-букв"
            char[] delimiterChars = {
                '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                ',', '+', '-', '=', ';', '{', '}', '[', ']', '.',
                '<', '>', ',', '/', '|', '?', '"', '`', '~', ':',
                '\t', '\\', ' '
            };
            char whiteSpace = ' ';

            // Построчный перебор текста
            for (int j = 0; j < result.Length; j++) {
                string[] words = result[j].Split(whiteSpace); // Разбивание строки в массив слов
                                                              // Переставление слов в заданном порядке
                if (words.Length > 1) { // Если в строке больше одного слова, то переставлять
                                        // (иначе ничего переставлять не нужно)
                    for (int i = 1; i < words.Length; i += 2) { // Итерирование по чётным словам
                        if (IsDelimChar(words[i - 1][^1])) { // Если первое слоло оканчивается не-буквой
                            if (IsDelimChar(words[i][^1])) { // Если второе слово оканчивается не-буквой
                                                             // меняем последние символы местами
                                SwapLastChars(ref words[i - 1], ref words[i]);
                            }
                            else {                           // Первое не-буква, второе буква
                                char tmpChar = words[i - 1][^1]; // Берем из первого не-букву

                                words[i - 1] = // сокращаем первое слово на один (последний) символ
                                    words[i - 1][0..^1];
                                // и переносим во второе слово не-букву последним символом
                                words[i] += tmpChar;
                            }
                        }
                        else if (IsDelimChar(words[i][^1])) { // Первое буква, второе не-буква
                            char tmpChar = words[i][^1];      // Последний символ второго слова,
                            words[i] = words[i][0..^1];       // сокращая второе слово на этот символ,
                            words[i - 1] += tmpChar;          // дописываем в конец первого слова
                        }
                        SwapWords(ref words[i - 1], ref words[i]);
                        result[j] = words[0] + ' ';
                    }
                }
                for (int k = 1; k < words.Length; k++) {
                    result[j] += words[k];
                    result[j] += ' ';
                }
                foreach (var item in result) {
                    item.Trim();
                }
            }

            return result;

            // Меняет последние символы слов
            static void SwapLastChars(ref string str1, ref string str2)
            {
                char c1 = str1[^1];
                char c2 = str2[^1];
                str1 = str1[0..^1];
                str1 += c2;
                str2 = str2[0..^1];
                str2 += c1;
            }

            // Менает слова по ссылкам
            static void SwapWords(ref string str1, ref string str2)
            {
                string tmp = str1;
                str1 = str2;
                str2 = tmp;
            }

            // Возвращает true, если символ является "не-буквой"
            static bool IsDelimChar(char c)
            {
                char[] delimChars = {
                    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                    ',', '+', '-', '=', ';', '{', '}', '[', ']', '.',
                    '<', '>', ',', '/', '|', '?', '"', '`', '~', ':',
                    '\t', '\\', ' '
                };

                for (int i = 0; i < delimChars.Length; i++) {
                    if (c == delimChars[i]) {
                        return true;
                    }
                }
                return false;
            }
        }

    }
}
