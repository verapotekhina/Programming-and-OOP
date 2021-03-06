#include "stdafx.h"
#include <iostream>

//Потехина Вера Фт-170008 "Геометрические прогрессии"
//Вычисление n-ного элемента и суммы n элементов геометрической прогрессии

using namespace std;

int main()
{
	int v;
	cout << "Do you want to calculate the geometric progression element with number n? If Yes - enter 1, else - enter 0: ";
	cin >> v;
	if (v == 1)
	{
		cout << "Enter first element of a progration, number n and denominator: ";
		int n;
		float a, b, q, w = 1;
		cin >> a >> n >> q;
		for (int i = 0; i < n-1; i++)
			w = w * q;
		b = a * w;
		cout << "Progression element with number n = " << b << endl;
	};
	cout << "Do you want to calculate sum of the first n elements? If Yes - enter 1, else - enter 0: ";
	cin >> v;
	if (v == 1)
	{
		cout << "Enter first element of a progration, number n and denominator: ";
		int n;
		float a, b, q, w = 1;
		cin >> a >> n >> q;
		for (int i = 0; i < n; i++)
			w = w * q;
		b = a * (1 - w)/(1 - q);
		cout << "Sum of the first n elements = " << b << endl;
	}
	else
		cout << "You didn't want to calculate anything." << endl;

	return 0;
}

