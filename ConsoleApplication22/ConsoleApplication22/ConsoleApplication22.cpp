﻿#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <C:\Users\Костя\source\repos\ConsoleApplication22\UnitTest1\Header.h>
using namespace std;



int main()
{
	char s[30], condition[60];
	int i=1, b, e;

	setlocale(LC_ALL, "Russian_russia.1251");
	printf("Ñòðîêà:");
	while (i != 0)
	{
		b = 0;
		cin >> condition;
		for (e = 0; e <= strlen(condition); e++)
		{
			if (b<0)
			if (condition[e] == '(')
				b++;
			else
				if (condition[e] == ')')
					b--;
		}
		if (b == 0)
		{
			if (check(condition) == -1)
			{
				cout << calculator(condition) << endl;
				i = 0;
			}
			else
				cout << "не правельный ввод в символе под номером " << i + 1 << " повторите ввод" << endl;
		}
		else
		cout << "не хватает скобки, повторите ввод" << endl;
	}
	system("pause");
	return 0;
}
//cos, sin, tg, ctg, ln, log, sqrt
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.