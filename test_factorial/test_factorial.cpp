﻿// test_factorial.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<string>

using namespace std;

string mult(string n, int x)
{
	int add = 0, num;
	string str = "";
	for (int i = n.size() - 1; i >= 0; i--) {
		num = ((int)n[i] - 48) * x + add;
		str = char(num % 10 + 48) + str;
		add = num / 10;
	}
	string tostr = "";
	int d = 1;
	while (add >= d) {
		tostr = char((add % (d * 10)) / d + 48) + tostr;
		d *= 10;
	}
	return tostr + str;
}

#include <list>
int main()
{
	std::list<int> iL{ 1,2,3,4,5 };
	auto iter = iL.begin();
	iL.insert(iter, -7);
	std::advance(iter, 1);
	iL.insert(iter, -2);
	for (auto it : iL) {
		std::cout << it << std::endl;
	}

	return 0;

	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	string str = "1";
	for (int i = 1; i <= n; i++)
		str = mult(str, i);
	cout << str;
	return 0;*/
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
