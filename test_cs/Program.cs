/*
 * Лаба 3
Вычислить значение переменной y по заданной расчётной формуле и набору исходных
данных. Значения исходных данных вводить с клавиатуры. На печать вывести значения
вводимых исходных данных и результат вычислений, сопровождая вывод наименованием
выводимых переменных.
y = fabs(pow(x, 3) - 10) * (atan(z + 0.2) + exp(-(x / 2 + 3)));
*/

/*
 * Лаб 4
В киоске продается газета стоимостью 5 руб. и журнал стоимостью 80 руб. Составить
программу, которая спрашивает о желании покупателя (журнал или газета) и принимает
деньги (сумма вводится с клавиатуры). В том случае, если указанная сумма больше, чем
стоимость покупки, на экран выводится сумма сдачи. Если уплаченных денег недостаточно, то
выдается соответствующее сообщение.
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

namespace test_cs
{
	class Program
	{

		static void Main()
		{
			Lab06();
			//int N = Convert.ToInt32(Console.ReadLine());
			Console.ReadLine();
			/*int[] myArray = new int[N];
			for (int i = 0; i < myArray.Length; i++) {
				myArray[i] = Convert.ToInt32(Console.ReadLine());
			}

			Random numberGenerator = new Random();
			for (int i = 0; i < myArray.Length; i++) {
				myArray[i] = Convert.ToInt32(numberGenerator.Next());
			}

			myArray.Where(i => i % 2 == 0).Min();
			int[] restult = myArray.Distinct().ToArray();*/
		}
		static void Lab03( string[] args )
		{
			double Y_xz( double _x, double _z )
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
			ulong factorial( long _N )
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
			const int DIVISOR = 10000000;
			// Возвращает количество цифр числа _A
			int DigitsNumber( long _A )
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

			int MaxDigitsIndex = 0,		// Индекс элемента массива с наибольшим количеством цифр
				MaxDigitsNumber = 0;    // Максимальное число цифр элемента массива

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
	}
}
