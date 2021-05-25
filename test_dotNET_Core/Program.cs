using System;
using System.Linq;

namespace test_dotNET_Core
{
    class Program
    {
        // Возвращает массив значений, переданных в параметры
        static int[] PlaceParametersIntoArray(params int[] vs)
        {
            int[] intArr = new int[vs.Length];
            for (int i = 0; i < vs.Length; i++) {
                intArr[i] = vs[i];
            }
            return intArr;
        }

        // Возвращает отсортированный массив из значений параметров,
        // поступивших в качестве аргументов,
        // а также присваивает среднее значение элементов массива
        // первому аргументу, переданном по ссылке
        static int[] GetAverage(out float average, params int[] vs)
        {
            int[] intArr = new int[vs.Length];
            average = 0;
            foreach (var item in vs) {
                average += item;
            }
            average /= vs.Length;
            Array.Sort(intArr);
            return intArr;
        }

        /*
         * 
         * 
         * 
         * 
         * 
         * 
         */
        // Передача параметров по значению
        static int PassByValue(int value)
        {
            return ++value;
        }

        // Передача параметров по ссылке
        // (Аналог int& в C++)
        static void PassByReference(ref int value)
        {
            value++;
        }

        // Передача параметров по ссылке
        // с обязательным присваиванием значения в теле метода
        static void PassByReferenceToAssign(out int value)
        {
            value = 3;
        }

        // Передача параметров по ссылке
        // с запретом изменения значений
        // переменной в теле метода
        static int PassByReferenceReadonly(in int value)
        {
            return value * 2;
        }

        // Передача переменного числа аргументов
        // одного типа в качестве параметров
        static int SumOfParameters(params int[] parameters)
        {
            int result = 0;
            foreach (var item in parameters) {
                result += item;
            }
            return result;
        }

        // Передача переменного числа аргументов
        // различных типов в качестве параметров
        static void GetTypeOfParameters(params object[] vs)
        {
            foreach (var item in vs) {
                Console.WriteLine($"{item.GetType()}\t{item}");
            }
        }

        static void Main()
        {
            // Индексируемый массив с динамическим выделением памяти
            // некоторый аналог std::vector<T> в C++
            var list = new System.Collections.Generic.List<string>() {
                "One", "Two", "Three"
            };
            list.Add("Four");
            list.Add("Five");
            string four = list[3];
            foreach (var item in list) {
                Console.Write($"{item}  ");
            }
            Console.WriteLine();

            // Двусвязный список
            var linkedList = new System.Collections.Generic.LinkedList<int>();
            linkedList.AddLast(11);
            linkedList.AddLast(-2);
            linkedList.AddLast(7);
            linkedList.AddLast(5);
            linkedList.AddLast(-2);
            linkedList.AddLast(linkedList.Max());
            foreach (var item in linkedList) {
                Console.Write($"{item}  ");
            }
            Console.WriteLine();

            // Битовый массив
            var bitArray1 = new System.Collections.BitArray(8);
            var bitArray2 = new System.Collections.BitArray(8);
            bitArray1.SetAll(false);
            bitArray2.Set(3, true);
            var bitArray3 = bitArray1.Or(bitArray2);
            foreach (var bit in bitArray3) {
                Console.Write($"{Convert.ToUInt16(bit)} ");
            }
            Console.WriteLine();

            // Упорядоченная коллекция объектов
            // Элементы в коллекции отсортированы в порядке возрастания значений
            var sortedSet = new System.Collections.Generic.SortedSet<int>();
            sortedSet.Add(5);
            sortedSet.Add(2);
            sortedSet.Add(-2);
            sortedSet.Add(19);
            sortedSet.Add(7);
            foreach (var item in sortedSet) {
                Console.Write($"{item}  ");
            }
            Console.WriteLine();


            /*
             * 
             * 
             * 
             */
            int a = 1;
            int b = PassByValue(a); // b = a; ++b; (b == 2) == true;

            PassByReference(ref a); // (a == 2) == true
            PassByReferenceToAssign(out b); // b = 3
            var c = PassByReferenceReadonly(in b); // c = 2 * b;
            var d = SumOfParameters(a, b, c); // d = a + b + c;
            string s = "2 is the oddest number";
            decimal Pi = 3.14159265m;
            float g = 9.81f;
            int n = 2;
            GetTypeOfParameters(n, g, Pi, s);
        }

    }
}
