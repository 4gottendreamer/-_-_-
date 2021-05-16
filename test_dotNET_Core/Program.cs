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

namespace test_dotNET_Core
{
	class Program
	{
		static void PrintMatrix(int[,] _Arr)
		{
			for (int i = 0; i < _Arr.GetLength(0); i++) {
				for (int j = 0; j < _Arr.GetLength(1); j++) {
					Console.Write(_Arr[i, j] + "  ");
				}
				Console.WriteLine();
			}
		}
		static void Main()
		{
			Lab10();
		}

		static void Lab10()
		{
			Console.WriteLine("Hello, World!");
			/*bool showMenu = true;
			while (showMenu) {
				showMenu = MainMenu();
			}*/
			char[] delimiterChars =
			{
				'!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
				',', '+', '-', '=', ';', '{', '}', '[', ']', '.',
				'<', '>', ',', '/', '\\', '|', '?', '"', '`', '~',
				'\t', ' '
			};

			char whiteSpace = ' ';
			string S = Console.ReadLine();
			S = S.Trim();
			string[] words = S.Split(whiteSpace);
			S[^1].Equals(delimiterChars);
			for (int i = 1; i < words.Length; i += 2) {
				/*
				 * 1. Если оба слова оканчиваются не-буквой, то swap
				 * 2. Если только в одном слове последний символ -- не-буква, то Concat
				 */
				if (IsDelimChar(words[i - 1][^1])) { // Если первое слоло оканчивается не-буквой
					if (IsDelimChar(words[i][^1])) { // Если второе слово оканчивается не-буквой
													 // меняем последние символы местами
						SwapLastChars(ref words[i - 1], ref words[i]);
					}
					else { // первое не-буква, второе буква
						char tmpChar = words[i - 1][^1]; // Берем из первого не-букву

						words[i - 1] = // сокращаем первое слово на один (последний) символ
							words[i - 1][0..^1];
						// и переносим во второе слово не-букву последним символом
						words[i] += tmpChar;
					}
				}
				else if(IsDelimChar(words[i][^1])) { // Первое буква, второе не-буква
					char tmpChar = words[i][^1];
					words[i] = words[i][0..^1];
					words[i - 1] += tmpChar;
				}

				SwapWords(ref words[i - 1], ref words[i]);
			}

			foreach (var item in words) {
				Console.Write(item + ' ');
			}

			static void SwapLastChars(ref string str1, ref string str2)
			{
				char c1 = str1[^1];
				char c2 = str2[^1];
				str1 = str1[0..^1];
				str1 += c2;
				str2 = str2[0..^1];
				str2 += c1;
			}

			static void SwapWords(ref string str1, ref string str2)
			{
				string tmp = str1;
				str1 = str2;
				str2 = tmp;
			}

			static bool IsDelimChar(char c)
			{
				char[] delimChars =
			{
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

			Console.ReadLine();
		}


		static void Main0()
		{
			int[,] A = new int[,] {
				{ 1, 2, 3, 3, 0 },
				{ 1, 2, 3, 1, 1 },
				{ 1, 0, 3, 0, 2 },
				{ 0, 5, 6, 4, 4 },
				{ 7, 0, 0, 2, 5 },
				{ 5, 8, 3, 3, 7 },
				{ 3, 0, 0, 2, 8 },
				{ 7, 8, 2, 2, 0 }
			};

			Console.WriteLine($"Номер столбца с максимальным количеством нулей: {Lab07(A) + 1}");
			//int N = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine("Нажмите Enter");
			Console.ReadLine();

			/*myArray.Where(i => i % 2 == 0).Min();
			int[] restult = myArray.Distinct().ToArray();*/
		}
		static void Lab03(string[] args)
		{
			/*
			 * Лаба 3
			Вычислить значение переменной y по заданной расчётной формуле и набору исходных
			данных. Значения исходных данных вводить с клавиатуры. На печать вывести значения
			вводимых исходных данных и результат вычислений, сопровождая вывод наименованием
			выводимых переменных.
			y = fabs(pow(x, 3) - 10) * (atan(z + 0.2) + exp(-(x / 2 + 3)));
			*/

			double Y_xz(double _x, double _z)
			{
				return Math.Abs(Math.Pow(_x, 3) - 10) *
					(Math.Atan(_z + 0.2) + Math.Exp(-(_x / 2 + 3)));
			}

			uint key = Convert.ToUInt32(Console.ReadLine());
			for (int i = 0; i < key; i++) {
				Console.WriteLine(key - i);
				Console.Write($"{key - 1} and {key}");
				Console.Beep();
				System.Threading.Thread.Sleep(5);
			}

			Console.WriteLine("Lab #03");
			Console.Write("Введите исходные значения.\nx = ");
			double x = Convert.ToDouble(Console.ReadLine());

			Console.Write("z = ");
			double z = Convert.ToDouble(Console.ReadLine());

			NumberFormatInfo numberFormatInfo = new NumberFormatInfo()
			{
				NumberDecimalSeparator = ".",
			};
			Console.Write("t = ");
			double t = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);

			Console.WriteLine(
						$"Вы ввели:\nx = " + x +
						"\nz = " + z +
						"\nt = " + t);

			Console.WriteLine("y(x; z; t) = | x^3 - 10 | * (arctg(z + 0.2) + e^(-(x / 2 + 3)))");
			Console.WriteLine($"y({x};{z}; {t}) = {Y_xz(x, z)}");

			Console.ReadLine();
		}

		static void Lab05()
		{
			/*
			 * Лаб 5
			Даны натуральное число n, действительные числа а1,..., an.
			Вычислить обратную величину произведения тех членов последовательности a1,..., an,
			для которых выполняется условие i + 1 < a_i < i!
			 */

			const int DIVISOR = 1000;
			int N;

			Console.WriteLine("Введите количество элементов массива" +
				"Внимание! При значениях больше 20 вычисление факториала вызывает" +
				"переполнение типа unsigned __int64.");

			N = Convert.ToInt32(Console.ReadLine());
			double[] a = new double[N]; // Выделение памяти под массив

			// Заполнение массива последовательностю псевдослучайных чисел
			// и вывод значений элементов в консоль
			Console.WriteLine("Последовательность псевдослучайных чисел:");
			Random random1 = new Random();
			for (int i = 0; i < N; i++) {
				double random2;
				random2 = Math.Pow(-1, i) * Math.PI;
				a[i] = (random1.Next() % DIVISOR) / random2;
				Console.WriteLine($"{i + 1}\t{a[i]}");
			}
			Console.WriteLine("\nПроверка условия\ni + 1\t<\ta_i\t\t<\t\ti!");

			bool bDoesAnyFit = false; // Флаг проверки выполнения условия
			double reciprocal = 1;
			// Проверка условий задачи
			for (int i = 0; i < N; i++) {
				ulong F = factorial(i + 1);
				if (i + 2 < a[i] && a[i] < F) {
					bDoesAnyFit = true; // Если выполняется хотя бы раз, "поднимаем" флаг
					Console.WriteLine($"{i + 2}\t< {a[i]}\t< {F}\n");
					reciprocal /= a[i];
				}
				// Если условие не выполнилось ни разу, сообщить об этом
				if (bDoesAnyFit) {
					Console.WriteLine($"Обратное значение произведений элементов, удовлетворяющих условию:\n{reciprocal}");
				}
				else {
					Console.WriteLine("Нет чисел, удовлетворяющих условию");
					Console.ReadLine();
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
		}

		static void Lab06()
		{
			/*
			 * Лаб 6
			Дан целочисленный массив А[N]. Определить индекс последнего элемента,
			числовое значение которого состоит из наибольшего количества цифр.
			 */

			const int DIVISOR = 10000000;
			// Возвращает количество цифр числа _A
			int DigitsNumber(long _A)
			{
				if (_A == 0)
					return 1;
				int count = 0;
				while (_A != 0) {
					count++;
					_A /= 10;
				}
				return count;
			}

			Console.WriteLine("Введите количество элементов массива: ");
			int N = Convert.ToInt32( Console.ReadLine());
			long[] a = new long[N];

			Console.WriteLine("Последовательность псевдослучаных чисел:");

			int MaxDigitsIndex = 0;  // Индекс элемента массива с наибольшим количеством цифр
			int MaxDigitsNumber = 0; // Максимальное число цифр элемента массива

			Random random = new Random();
			// Заполнение массива псевдослучайной последовательностью чисел
			// и вывод значений элементов в консоль
			for (int i = 0; i < N; i++) {
				int RandomizeMe = random.Next();
				//Console.WriteLine(RandomizeMe);
				//Console.WriteLine(RandomizeMe % DIVISOR);
				//Console.WriteLine(Math.Sin(RandomizeMe));
				a[i] = (long)(RandomizeMe % DIVISOR * Math.Sin(RandomizeMe));
				Console.WriteLine($"a[{i}] = {a[i]}\tЦифр: {DigitsNumber(a[i])}");
				if (MaxDigitsNumber <= DigitsNumber(a[i])) { // Если текущее максимальное число цифр
															 // меньше числа цифр
															 // текущего элемента массива,
					MaxDigitsNumber = DigitsNumber(a[i]);    // то присваиваем переменным
					MaxDigitsIndex = i;                      // текущие значения
				}
			}

			Console.WriteLine($"Максимальный индекс {MaxDigitsIndex}");
			Console.WriteLine($"Элемент массива a[{MaxDigitsIndex}] = {a[MaxDigitsIndex]}");

			Console.WriteLine("Нажмите Enter");
			Console.ReadLine();
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

			for (int i = 0; i < _Arr.GetLength(0); i++) {
				for (int j = 0; j < _Arr.GetLength(1); j++) {
					//Console.Write(_Arr[i, j] + "  ");
				}
				//Console.WriteLine();
			}
			//Console.WriteLine("=====================");

			/*
			 * Поиски нулей по столбцам
			 */
			int idxRowMaxZeros = -1;
			int  zeroCountPrev = 0;
			for (int j = 0, i = 0; j < _Arr.GetLength(1); j++) {
				bool thereIs0 = false;
				int zeroCountCurr = 0;
				for (i = 0; i < _Arr.GetLength(0); i++) {
					//Console.Write(_Arr[i, j] + "  ");
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

			/*
			 * Перестановка элементов нужного столбца в обратном порядке
			 */
			void swapTwo(ref int _a, ref int _b)
			{
				int tmp = _a;
				_a = _b;
				_b = tmp;
			}
			if (idxRowMaxZeros > -1) {
				int height = _Arr.GetLength(0);
				//Console.WriteLine($"height : {height}");
				for (int j = 0; j < height / 2; j++) {
					swapTwo(
						ref _Arr[j, idxRowMaxZeros],
						ref _Arr[height - j - 1, idxRowMaxZeros]
						);
				}
			}

			for (int i = 0; i < _Arr.GetLength(0); i++) {
				for (int j = 0; j < _Arr.GetLength(1); j++) {
					//Console.Write(_Arr[i, j] + "  ");
				}
				//Console.WriteLine();
			}

			//Console.WriteLine();
			return idxRowMaxZeros;
		}
	}
}
