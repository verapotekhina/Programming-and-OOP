#include "stdafx.h"
#include <iostream>

//Пoтехина Вера Фт-170008 - Двойной факториал (Задача While6)

using namespace std;

float dfactorial(int m) // двойной факториал n
{
	float s = 1;
	while (m > 0)
	{
		s = s * m;
		m = m - 2;
	};
	return s;
};


int main()
{
	int n;
	float a;
	cout << "Enter N: ";
	cin >> n;
	a = dfactorial(n);
	cout << "N!! = " << a << endl;
	return 0;
}

