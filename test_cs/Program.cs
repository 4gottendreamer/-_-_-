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

namespace test_cs
{
	class Program
	{

		static void Main()
		{
			Console.WriteLine("Hello, World!");
			/*bool showMenu = true;
			while (showMenu) {
				showMenu = MainMenu();
			}*/
			char[] delimiterChars = { ' ', ',', '.', ':', '\t' };
			char whiteSpace = ' ';
			string S = Console.ReadLine();
			S = S.Trim();
			string[] words = S.Split(whiteSpace);
			
			for (int i = 1; i < words.Length; i += 2) {
				/*
				 * 1. Если оба слова оканчиваются не-буквой, то дальше
				 * 2. Если только в одном слове последний символ -- не-буква, то swap
				 */
				words[^1];
				Swap(ref words[i - 1], ref words[i]);
			}

			foreach (var item in words) {
				Console.Write(item + ' ');
				
			}
			Console.ReadLine();
		}

		private static void Swap(ref string v1, ref string v2)
		{
			string tmp = v1;
			v1 = v2;
			v2 = tmp;
		}

		private static bool MainMenu()
		{
			Console.Clear();
			Console.WriteLine("Choose an option:");
			Console.WriteLine("1) Reverse String");
			Console.WriteLine("2) Remove Whitespace");
			Console.WriteLine("3) Exit");
			Console.Write("\r\nSelect an option: ");

			switch (Console.ReadLine()) {
			case "1":
				return true;
			case "2":
				return true;
			case "3":
				return false;
			default:
				return true;
			}
		}

		private static string CaptureInput()
		{
			Console.Write("Enter the string you want to modify: ");
			return Console.ReadLine();
		}

		private static void ReverseString()
		{
			Console.Clear();
			Console.WriteLine("Reverse String");

			char[] charArray = CaptureInput().ToCharArray();
			Array.Reverse(charArray);
			DisplayResult(String.Concat(charArray));
		}

		private static void RemoveWhitespace()
		{
			Console.Clear();
			Console.WriteLine("Remove Whitespace");

			DisplayResult(CaptureInput().Replace(" ", ""));
		}

		private static void DisplayResult(string message)
		{
			Console.WriteLine($"\r\nYour modified string is: {message}");
			Console.Write("\r\nPress Enter to return to Main Menu");
			Console.ReadLine();
		}
	}
}
