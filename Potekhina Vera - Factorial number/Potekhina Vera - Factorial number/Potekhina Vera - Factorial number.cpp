#include "stdafx.h"
#include <iostream>

//Потехина Вера Фт-170008 "Факториал числа"
//Вычисление факториала введенного числа

using namespace std;

int main()
{
	int n, s = 1;
	cout << "Enter number: ";
	cin >> n;
	if (n >= 0)
	{
		for (int i = 1; i <= n; i++)
			s = s * i;
		cout << s << endl;
	}
	else
		cout << "Error: you entered a negative number" << endl;
	return 0;
}


