using System;
using System.Collections.Generic;
using System.Text;

namespace lab_16_v6
{
	public class LabMethods
	{
		public static ulong Factorial(long _N)
		{
			ulong fact = 1;
			for (int i = 1; i <= _N; i++) {
				fact *= (ulong)i;
			}
			return fact;
		}

		public static int DigitsCount(long _N)
		{
			int count = 0;
			if (_N == 0) {
				return 1;
			}
			while (_N != 0) {
				_N /= 10;
				count++;
			}
			return count;
		}

		public static double[] GetDoubleArray(int _dimension, int _randomizerMultiplier = 1)
		{
			double[] doubleArr1 = new double[_dimension];
			System.Random random = new Random();
			for (int i = 0; i < doubleArr1.GetLength(0); i++) {
				doubleArr1[i] = _randomizerMultiplier *
					random.NextDouble();
				//(random.NextDouble() - random.NextDouble());
				//Console.Write($"{doubleArr1[i]}\t");
			}
			return doubleArr1;
		}

		public static double[,] GetDoubleArray2(
			int _rows,
			int _columns,
			int _randomizerMultiplier = 1
			)
		{
			double[,] doubleArr2 = new double[_rows, _columns];
			System.Random random = new Random();
			for (int i = 0; i < _rows; i++) {
				for (int j = 0; j < _columns; j++) {
					doubleArr2[i,j] = _randomizerMultiplier *
						random.NextDouble();
					//(random.NextDouble() - random.NextDouble());
					//Console.Write($"{doubleArr1[i]}\t");
				}
			}
			return doubleArr2;
		}

		public static int[] GetIntArray(int _dimension, int _minValue = 0, int _maxValue = 2147483647)
		{
			Random random = new Random();

			int[] intArr1 = new int[_dimension];
			for (int i = 0; i < intArr1.GetLength(0); i++) {
				intArr1[i] = random.Next(_minValue, _maxValue);
			}
			return intArr1;
		}

		public static int[,] GetIntArray2(
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

		public static double Lab03(double _x, double _z)
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

		public static bool Lab05(double[] _Arr, out double _reciprocal)
		{
			/*
			 * Лаб 5
			Даны натуральное число n, действительные числа а1,..., an.
			Вычислить обратную величину произведения тех членов последовательности a1,..., an,
			для которых выполняется условие i + 1 < a_i < i!
			 */
			bool[] checkedIndices = new bool[_Arr.Length];
			bool bDoesAnyFit = false; // Флаг проверки выполнения условия
			_reciprocal = 1;
			// Проверка условий задачи
			for (int i = 0; i < _Arr.Length; i++) {
				ulong F = factorial(i + 1);
				if (i + 2 < _Arr[i] && _Arr[i] < F) {
					bDoesAnyFit = true; // Если выполняется хотя бы раз, "поднимаем" флаг
										//Console.WriteLine($"{i + 2}\t< {_Arr[i]}\t< {F}\n");
					_reciprocal /= _Arr[i];
					checkedIndices[i] = true;
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
			Lab05CheckedIndices = checkedIndices;
			return bDoesAnyFit;
		}

		public static bool[] Lab05CheckedIndices = new bool[0];

		// Возвращает индекс последнего элемента, числовое значение которого
		// состоит из наибольшего количества цифр.
		public static int Lab06(long[] _Arr) // Передавать заполненный массив
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
		public static int Lab07(int[,] _Arr)
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

		public static int[,] array2d;

		public static string[] Lab10(string[] _Text)
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
					item.Trim(); // Удаляет лишние пробелы в начале и конце
								 // (по факту только один пробел в конце)
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
