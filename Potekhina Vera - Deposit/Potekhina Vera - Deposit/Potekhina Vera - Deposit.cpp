#include "stdafx.h"
#include <iostream>

//Потехина Вера Фт-170008 - Сложный банковский процент
//Сумма вклада (s)
//% годовых [7..14] - т.е. может быть не только целым, но и дробным (p)
//Количество месяцев - целое и не превышает 36 (3 года) (n)
//Минимальный срок вклада - 2 месяца
//Процент начисляется ежемесячно и реинвестируется

using namespace std;

int main()
{
	float s, p, w = 0;
	int n;
	cout << "Enter amount of deposit what is more then 0: ";
	cin >> s;
	cout << "Enter percent [7..14]: ";
	cin >> p;
	cout << "Enter number of months from 1 to 36: ";
	cin >> n;
	while (s <= 0)
	{
		cout << "You entered wrong amount of deposit. Enter other amount of deposit: ";
		cin >> s;
	};
	while ((p < 7) || (p > 14))
	{
		cout << "You entered wrong percent. Enter other percent: ";
		cin >> p;
	};
	while ((n < 1) || (n > 36))
	{
		cout << "You entered wrong number of months. Enter other number of months: ";
		cin >> n;
	};
	if (n > 1)
	{
		for (int i = 0; i < n; i++)
		{
			w = s / 100 / 12 * p; //прибавляется в месяц w рублей
			s = s + w;
		};
	};

	cout << "Total amount = " << s << endl;
	return 0;
}

