#include <stdafx.h>
#include <iostream>

//Потехина Вера Фт-170008 - Калькулятор 

using namespace std;

int main()
{
	int a, b;
	float d, e;
	char c;
	cout << "Welcome to the calculator program!" << endl;
	cout << "Enter a and b: ";
	cin >> a >> b;
	cout << "Enter operation (+, -, /, * or %): ";
	cin >> c;
	if (c == '*')
		cout << "a * b = " << a * b << endl;
	else if (c == '/')
	{
		if (b == 0)
		{
			cout << "Error: b = 0" << endl;
		}
		else
		{
			d = a;
			e = b;
			cout << "a / b = " << d / e << endl;
		};
	}
	else if (c == '+')
		cout << "a + b = " << a + b << endl;
	else if (c == '-')
		cout << "a - b = " << a - b << endl;
	else if (c == '%')
	{
		if (b == 0)
		{
			cout << "Error: b = 0" << endl;
		}
		else
		{
			cout << "a % b = " << a % b << endl;
		};
	}
	else cout << "Error: Wrong input" << endl;
	return 0;
}

