#include "stdafx.h"
#include <iostream>

//Пoтехина Вера Фт-170008 - Деление и остаток от деления, используя "-" и "+" (Задача While3)

using namespace std;

void func(int a, int b)
{
	int s = 0;
	while (a >= b)
	{
		a = a - b;
		s = s + 1;
	}
	cout << "Quotient: " << s << endl;
	cout << "Remainder of the division: " << a << endl;
}

int main()
{
	int n, k;
	cout << "Enter N: ";
	cin >> n;
	cout << "Enter K: ";
	cin >> k;
	func(n, k);
	return 0;
}