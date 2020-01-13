#include <stdafx.h>
#include <iostream>

//Потехина Вера Фт-170008 - Калькулятор с функциями

using namespace std;

int a, b;

void addition() //сложение
{
	cout << "a + b = " << a + b << endl;
};

void subtraction() //вычитание
{
	cout << "a - b = " << a - b << endl;
};

void multiplication() //умножение
{
	cout << "a * b = " << a * b << endl;
};

void division() //деление
{
	float d, e;
	d = a;
	e = b;
	cout << "a / b = " << d / e << endl;
};

void remainder() //остаток от деления
{
	cout << "a % b = " << a % b << endl;
};

int main()
{
	char c;
	cout << "Welcome to the calculator program!" << endl;
	cout << "Enter a and b: ";
	cin >> a >> b;
	cout << "Enter operation (+, -, /, * or %): ";
	cin >> c;
	if (c == '*')
		multiplication();
	else if (c == '+')
		addition();
	else if (c == '-')
		subtraction();
	else if (c == '/')
	{
		while (b == 0) //исключение нуля в знаменателе
		{
			cout << "Enter another b: ";
			cin >> b;
		};
		division();
	}
	else if (c == '%')
	{
		while (b == 0) //исключение нуля в знаменателе
		{
			cout << "Enter another b: ";
			cin >> b;
		};
		remainder();
	}
	else
		cout << "Error: Wrong input" << endl;
	return 0;
}

