#include "stdafx.h"
#include <iostream>

//Пoтехина Вера Фт-170008 - Приближенное значение экспоненты в точке X (Задача For22)

using namespace std;

float factorial(int m) // факториал j
{
	float s = 1;
	for (int i = 1; i <= m; i++)
	{
		s = s * i;
	};
	return s;
};

float power(float y, int m) // возведение х в степень j
{
	float s = 1;
	for (int i = 1; i <= m; i++)
	{
		s = s * y;
	}
	return s;
};


int main()
{
	float x, a, b, s = 1;
	int n;
	cout << "Enter X: ";
	cin >> x;
	cout << "Enter N: ";
	cin >> n;
	for (int j = 1; j <= n; j++)
	{
		a = factorial(j);
		b = power(x, j);
		s = s + b / a;
	}
	cout << "Result: " << s << endl;
	return 0;
}

