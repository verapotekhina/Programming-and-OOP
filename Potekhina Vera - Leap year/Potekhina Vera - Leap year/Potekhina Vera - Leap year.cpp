#include "stdafx.h"
#include <iostream>

//Пoтехина Вера Фт-170008 - Високосный год (Задача Id28)

using namespace std;

int func(int a)
{
	int s;
	if (a % 4 == 0)
		if ((a % 100 == 0) && (a % 400 != 0))
			s = 365;
		else
			s = 366;
	else
		s = 365;
	return s;
}

int main()
{
	int n, s;
	cout << "Enter year: ";
	cin >> n;
	s = func(n);
	cout << "Amount of days: " << s << endl;
	return 0;
}

