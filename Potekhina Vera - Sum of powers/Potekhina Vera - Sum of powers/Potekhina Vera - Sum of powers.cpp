#include "stdafx.h"
#include <iostream>

//Пoтехина Вера Фт-170008 - Сумма степеней (Задача For17)
//Работает и для целых, и для дробных, всё хорошо 

using namespace std;

float func(float b, int n)
{
	float v = 1, s = 1;
	for (int i = 0; i < n; i++)
	{
		v = v * b;
		s = s + v;
	}
	return s;
}

int main()
{
	float a, s;
	int n;
	cout << "Enter A: ";
	cin >> a;
	cout << "Enter N: ";
	cin >> n;
	s = func(a, n);
	cout << "Result: " << s << endl;
	return 0;
}