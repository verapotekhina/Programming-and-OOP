#include "stdafx.h"
#include <iostream>

//Потехина Вера Фт-170008 "Арифметические прогрессии"
//Вычисление n-ного элемента и суммы n элементов арифметической прогрессии

using namespace std;

int main()
{
	int v;
	cout << "Do you want to calculate the progression element with number n? If Yes - enter 1, else - enter 0: ";
	cin >> v;
	if (v == 1)
	{
		cout << "Enter first element of a progration, progression element with number n and difference: ";
		int n;
		float a, b, d;
		cin >> a >> n >> d;
		b = a + (n - 1)*d;
		cout << "Progression element with number n = " << b << endl;
	};
	cout << "Do you want to calculate sum of the first n elements? If Yes - enter 1, else - enter 0: ";
	cin >> v;
	if (v == 1)
	{
		cout << "Enter first element of a progration, progression element with number n and difference: ";
		int n;
		float a, b, d;
		cin >> a >> n >> d;
		b = (a + (n - 1)*d/2)*n;
		cout << "Sum of the first n elements = " << b << endl;
	} else 
		cout << "You didn't want to calculate anything." << endl;

	return 0;
}


