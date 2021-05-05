// Вариант 6
/*
Программа должна включать переписанные с C++ на C# лабораторные № 3, 5, 6, 7, 10.
Постановку задач из лабораторных (вариант задания) надо выводить на экран в
соответствующем пункте меню. Решение каждой задачи должно быть оформлено в виде
метода, который принимает введенные с клавиатуры значения и возвращает то, что надо
вывести (ввод и вывод внутри метода запрещен). Использовать массивы с динамическим
выделением памяти или с использованием класса List. Для строк использовать тип string
или класс String.
Меню программы:
1.	Расчёт периметра прямоугольника (лабораторная 2)
2.	Расчёт формулы (лабораторная 3)
3.	Сочетание циклов и разветвлений (лабораторная 5)
4.	Обработка одномерных массивов (лабораторная 6)
5.	Обработка двумерных массивов (лабораторная 7)
6.	Работа со строками (лабораторная 10)
 */

using System;
using System.Globalization;

namespace lab_14_v6
{
	class Program
	{
		static void Main( string[] args )
		{
			Console.WriteLine("Вариант 6");
			Console.WriteLine("1. Lab 3");
			Console.WriteLine("2. Lab 5");
			Console.WriteLine("3. Lab 6");
			Console.WriteLine("4. Lab 7");
			Console.WriteLine("5. Lab 10");

			int key = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine(key);
			switch (key) {
			case 1:
				Console.WriteLine("1. Lab 3");
				Console.Write("Введите исходные значения.\nx = ");
				NumberFormatInfo numberFormatInfo = new NumberFormatInfo() {
					NumberDecimalSeparator = ".",
				};
				double x = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);

				Console.Write("z = ");
				double z = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);

				Console.Write("t = ");
				double t = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);
				Console.WriteLine($"Вы ввели:\nx = {x}\nz = {z}\nt = {t}");
				Console.Write("y(x; z; t) = | x^3 - 10 | * (arctg(z + 0.2) + e^(-(x / 2 + 3)))");
				Console.WriteLine($"{Lab03(x, z)}");
				break;
			case 2:
				Console.WriteLine("2. Lab 5");
				Lab05();
				break;
			case 3:
				Console.WriteLine("3. Lab 6");
				break;
			case 4:
				Console.WriteLine("4. Lab 7");
				break;
			case 5:
				Console.WriteLine("5. Lab 7");
				break;
			case 6:
				Console.WriteLine("5. Lab 10");
				break;
			default:
				Console.WriteLine("Неверный выбор.");
				key = Console.Read();
				break;
			}

			Program.MenuPrint(5, "Строка меню");
			bool isOK = false;
			do {
				int switchKey;
				//switchKey = Convert.ToInt32(Console.ReadLine());
				int.TryParse(Console.ReadLine(), out switchKey);
				switch (switchKey) {
				case 1:
					Console.WriteLine("Выбран пункт " + switchKey);
					isOK = true;
					break;
				case 2:
					Console.WriteLine("Выбран пункт " + switchKey);
					isOK = true;
					break;
				case 3:
					Console.WriteLine("Выбран пункт " + switchKey);
					isOK = true;
					break;
				case 4:
					Console.WriteLine("Выбран пункт " + switchKey);
					isOK = true;
					break;
				case 5:
					Console.WriteLine("Выбран пункт " + switchKey);
					isOK = true;
					break;
				case 0:
					Console.WriteLine("Выход");
					isOK = false;
					break;
				default:
					Console.WriteLine("Неверный выбор");
					isOK = true;
					break;
				}
			} while (isOK);

			Console.ReadLine();
		}

		static void MenuPrint( string[] _Lines )
		{
			Console.Clear();
			for (int i = 0; i < _Lines.Length; i++) {
				Console.WriteLine($"> {(i + 1)} . {_Lines[i]} ");
			}
		}
		static void MenuLineSelect( ConsoleKey consoleKey )
		{
			Console.Clear();
		}
		static void MenuPrint( int _LinesCount, string _Line )
		{
			Console.Clear();
			for (int i = 0; i < _LinesCount; i++) {
				Console.WriteLine($"{(i + 1)} . {_Line} ");
			}
		}
		static double Y_xz( double _x, double _z )
		{
			return Math.Abs(Math.Pow(_x, 3) - 10) *
				(Math.Atan(_z + 0.2) + Math.Exp(-(_x / 2 + 3)));
		}
		static double Lab03( double _x, double _z )
		{
			Console.Clear();
			NumberFormatInfo numberFormatInfo = new NumberFormatInfo()
			{
				NumberDecimalSeparator = ".",
			};
			Console.WriteLine("Lab #03");
			Console.Write("Введите исходные значения.\nx = ");
			double x = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);

			Console.Write("z = ");
			double z = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);

			Console.Write("t = ");
			double t = Convert.ToDouble(Console.ReadLine(), numberFormatInfo);

			Console.WriteLine($"Вы ввели:\nx = {x}\nz = {z}\nt = {t}");

			//Console.WriteLine("y(x; z; t) = | x^3 - 10 | * (arctg(z + 0.2) + e^(-(x / 2 + 3)))");
			//Console.WriteLine($"y({x};{z}; {t}) = {Y_xz(x, z)}");
			return Math.Abs(Math.Pow(_x, 3) - 10) *
				(Math.Atan(_z + 0.2) + Math.Exp(-(_x / 2 + 3)));
		}
		static void Lab04()
		{
			// Определение идентификаторов для цен журнала и газеты
			const float MAGAZINE_PRICE = 80f;
			const float NEWSPAPER_PRICE = 5f;
			Console.WriteLine("Lab #04");

			Console.WriteLine("Здравсвтуйте.\nВыберите приобретаемый товар");
			Console.WriteLine("1 - журнал\n2 - газета");

			int choice; // Переменная выбора товара
			bool isOK; // Флаг проверки корректности операции покупки
			float payment; // Переменная для хранения оплаты

			do {
				isOK = false;
				int.TryParse(Console.ReadLine(), out choice); // Ввод выбора товара
				switch (choice) {
				case 1: // Случай 1 - журнал
					Console.WriteLine("Выбран журнал. Внесите деньги.");
					do {
						NumberFormatInfo numberFormatInfo = new NumberFormatInfo() {
							NumberDecimalSeparator = ".",
						};
						// "Внесение" оплаты
						payment = float.Parse(Console.ReadLine(), numberFormatInfo);
						// Внесённая сумма меньше цены
						if (payment < MAGAZINE_PRICE) {
							Console.WriteLine("Не достаточная сумма. Доплатите.");
							isOK = false; // Покупка не удалась
						}
						// Внесённая сумма равна цене
						else if (payment == MAGAZINE_PRICE) {
							Console.WriteLine("Вы купили журнал");
							isOK = true; // Покупка ОК
						}
						// Внесённая сумма больше цены
						else {
							Console.WriteLine($"Вы купили журнал. Ваша сдача {payment - MAGAZINE_PRICE}");
							isOK = true; // Покупка ОК
						}
					} while (!isOK); // Проверка корректности покупки
					break;
				case 2: // Случай 2 - газета
					Console.Write("Выбрана газета. Внесите деньги. ");
					do {
						payment = float.Parse(Console.ReadLine()); // "Внесение" оплаты
																   // Внесённая сумма меньше цены
						if (payment < NEWSPAPER_PRICE) {
							Console.WriteLine("Не достаточная сумма. Доплатите.");
							isOK = false; // Покупка не удалась
						}
						// Внесённая сумма равна цене
						else if (payment == NEWSPAPER_PRICE) {
							Console.WriteLine("Вы купили газету");
							isOK = true; // Покупка ОК
						}
						// Внесённая сумма больше цены
						else {
							Console.WriteLine($"Вы купили газету. Ваша сдача {payment - NEWSPAPER_PRICE}");
							isOK = true; // Покупка ОК
						}
					} while (!isOK); // Проверка корректности покупки
					break;
				default: // Случаи неверного выбора товара
					Console.WriteLine("Неверный выбор!");
					isOK = false; // Покупка не удалась
					break;
				}
			} while (!isOK); // Проверка корректности покупки

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
			for (int i = 0; i < N; i++) {
				Random random1 = new Random();
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

	}
}
