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
		static void PrintMatrix(int[,] _Arr, char _Ch)
		{
			for (int i = 0; i < _Arr.GetLength(0); i++) {
				for (int j = 0; j < _Arr.GetLength(1); j++) {
					Console.Write(_Arr[i, j] + _Ch);
				}
				Console.WriteLine();
			}
		}

		static void Main()
		{
			int dimensionXForIntArray = 5;
			int dimensionXForDoubleArray = 5;
			int dimensionYForDoubleArray = 4;

			double[] doubleArr1 = new double[dimensionXForDoubleArray];
			Random random = new Random();
			for (int i = 0; i < doubleArr1.GetLength(0); i++) {
				doubleArr1[i] = random.NextDouble();
				Console.Write($"{doubleArr1[i]}\t");
			}

			double[,] doubleArr2 = new double[dimensionXForDoubleArray, dimensionYForDoubleArray];
			for (int i = 0; i < doubleArr2.GetLength(0); i++) {
				for (int j = 0; j < doubleArr2.GetLength(1); j++) {
					doubleArr2[i, j] = random.NextDouble();
					Console.Write($"{doubleArr2[i, j]}\t");
				}
				Console.WriteLine();
			}

			int[] intArr1 = new int[dimensionXForIntArray];
			for (int i = 0; i < intArr1.GetLength(0); i++) {
				intArr1[i] = random.Next();
			}

			int[,] intArr2Test = new int[,] {
				{ 1, 2, 3, 3, 0 },
				{ 1, 2, 3, 1, 1 },
				{ 1, 0, 3, 0, 2 },
				{ 0, 5, 6, 4, 4 },
				{ 7, 0, 0, 2, 5 },
				{ 5, 8, 3, 3, 7 },
				{ 3, 0, 0, 2, 8 },
				{ 7, 8, 2, 2, 0 }
			};
			int choice;
			do {

				// TODO: Вывести менюшку

				choice = Convert.ToInt32(Console.Read());
				Console.WriteLine("Выберите пункт");
				switch (choice) {
				case 1: // lab 03
				{
					//////////////////////////////
					/// LAB 03
					//////////////////////////////
					Console.WriteLine("Лаба 03");
					Console.WriteLine("y(x; z; t) = | x^3 - 10 | * (arctg(z + 0.2) + e^(-(x / 2 + 3)))");
					Console.WriteLine("Введите x, z, t:");
					NumberFormatInfo numberFormatInfo = new NumberFormatInfo()
					{
						NumberDecimalSeparator = ".",
					};
					Console.Write("x = ");
					double x = Convert.ToDouble(Console.ReadLine());
					Console.Write("z = ");
					double z = Convert.ToDouble(Console.ReadLine());
					Console.Write("t = ");
					double t = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);
					Console.WriteLine($"Вы ввели:\nx = {x}\nz = {z}\nt = {t}");
					Console.WriteLine("y(x; z; t) = | x^3 - 10 | * (arctg(z + 0.2) + e^(-(x / 2 + 3)))");
					Console.WriteLine($"y({x};{z}; {t}) = {Lab03(x, z)}");
					Console.WriteLine();
					Console.WriteLine("Конец Лабы 06");
					Console.WriteLine("Нажмите Enter");
					Console.ReadLine();
					break;
				}
				case 2: // lab 05
				{

					Console.WriteLine("Лаба 05");
					double reciprocal = 1;
					Console.WriteLine("Введите количество элементов массива.\n" +
						"Внимание! При значениях больше 20 вычисление факториала вызывает " +
						"переполнение типа unsigned __int64.");
					Console.WriteLine("\nПроверка условия\ni + 1\t<\ta_i\t\t<\t\ti!");
					if (Lab05(doubleArr1, ref reciprocal)) {
						Console.WriteLine($"Обратное значение произведений элементов, " +
							"удовлетворяющих условию:\n{reciprocal}");
					}
					else {
						Console.WriteLine("Нет чисел, удовлетворяющих условию");
						Console.ReadLine();
					}
					break;
				}
				case 3: // lab 06
				{

					Console.WriteLine("Лаба 06");
					Console.WriteLine("Последовательность псевдослучаных чисел:");
					foreach (var item in intArr1) {
						Console.WriteLine(item);
					}
					int lab06Result = Lab06(intArr1);
					Console.WriteLine(
						$"Максимальный индекс числа массива с наибольшим количеством цифр: {lab06Result}");
					Console.WriteLine($"Элемент массива a[{lab06Result}] = {intArr1[lab06Result]}");

					Console.WriteLine();
					Console.WriteLine("Конец Лабы 06");
					Console.WriteLine("Нажмите Enter");
					Console.ReadLine();
					break;
				}
				case 4: // lab 07
				{
					Console.WriteLine("Лаба 07");
					for (int i = 0; i < intArr2Test.GetLength(0); i++) {
						for (int j = 0; j < intArr2Test.GetLength(1); j++) {
							Console.Write(intArr2Test[i, j] + "  ");
						}
						Console.WriteLine();
					}
					Console.WriteLine();
					Console.WriteLine(
						$"Номер столбца с максимальным количеством нулей: {Lab07(intArr2Test) + 1}");
					Console.WriteLine("Нажмите Enter");
					Console.ReadLine();
					break;
				}
				case 5: // lab 10
				{
					Console.WriteLine("Лаба 07");
					break;
				}
				case 0: // Выход
				{
					break;
				}
				default: {
					Console.WriteLine("Неверный выбор");
					Console.Read();
					break;
				}
				}
			}
			while (choice != 0);
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

			/*double Y_xz(double _x, double _z)
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

			Console.WriteLine($"Вы ввели:\nx = {x}\nz = {z}\nt = {t}");

			Console.WriteLine("y(x; z; t) = | x^3 - 10 | * (arctg(z + 0.2) + e^(-(x / 2 + 3)))");
			Console.WriteLine($"y({x};{z}; {t}) = {Y_xz(x, z)}");

			Console.ReadLine();*/
			return
				Math.Abs(Math.Pow(_x, 3) - 10) *
				(Math.Atan(_z + 0.2) + Math.Exp(-(_x / 2 + 3)));
		}

		static bool Lab05(double[] _Arr, ref double __reciprocal)
		{
			/*
			 * Лаб 5
			Даны натуральное число n, действительные числа а1,..., an.
			Вычислить обратную величину произведения тех членов последовательности a1,..., an,
			для которых выполняется условие i + 1 < a_i < i!
			 */

			//Console.WriteLine("\nПроверка условия\ni + 1\t<\ta_i\t\t<\t\ti!");

			bool bDoesAnyFit = false; // Флаг проверки выполнения условия
			double _reciprocal = 1;
			// Проверка условий задачи
			for (int i = 0; i < _Arr.Length; i++) {
				ulong F = factorial(i + 1);
				if (i + 2 < _Arr[i] && _Arr[i] < F) {
					bDoesAnyFit = true; // Если выполняется хотя бы раз, "поднимаем" флаг
					Console.WriteLine($"{i + 2}\t< {_Arr[i]}\t< {F}\n");
					_reciprocal /= _Arr[i];
				}
				// Если условие не выполнилось ни разу, сообщить об этом
				/*if (bDoesAnyFit) {
					Console.WriteLine($"Обратное значение произведений элементов, удовлетворяющих условию:\n{_reciprocal}");
				}
				else {
					Console.WriteLine("Нет чисел, удовлетворяющих условию");
					Console.ReadLine();
				}*/

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

			const int DIVISOR = 10000000;
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
			// Вынести наружу
			/*Console.WriteLine("Введите количество элементов массива: ");
			int N = Convert.ToInt32( Console.ReadLine());
			long[] a = new long[N];*/
			// Вынести наружу

			//Console.WriteLine("Последовательность псевдослучаных чисел:");

			int MaxDigitsIndex = 0;  // Индекс элемента массива с наибольшим количеством цифр
			int MaxDigitsNumber = 0; // Максимальное число цифр элемента массива

			//Random random = new Random();
			// Заполнение массива псевдослучайной последовательностью чисел
			// и вывод значений элементов в консоль
			/*for (int i = 0; i < N; i++) {
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
			}*/

			for (int i = 0; i < _Arr.GetLength(0); i++) {
				// Если текущее максимальное число цифр
				// меньше числа цифр текущего элемента массива,
				if (MaxDigitsNumber <= DigitsNumber(_Arr[i])) {
					MaxDigitsNumber = DigitsNumber(_Arr[i]);    // то присваиваем переменным
					MaxDigitsIndex = i;                         // текущие значения
				}
			}

			//Console.WriteLine($"Максимальный индекс {MaxDigitsIndex}");
			//Console.WriteLine($"Элемент массива a[{MaxDigitsIndex}] = {a[MaxDigitsIndex]}");

			/*Console.WriteLine("Нажмите Enter");
			Console.ReadLine();*/
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

		static int Lab10()
		{
			/*
			 * Лаб 10
			В произвольном тексте, содержащем не более 10 строк, в каждой строке не более
			80 символов, попарно переставить местами слова, стоящие на нечётных и чётных
			местах в строке. Вывести полученный текст на экран.
			 */

			string Text;
			IntPtr intPtr;
			int[] A = new int[5];

			return 0;
		}
	}
}
