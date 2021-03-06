#include "stdafx.h"
#include <iostream>

//Потехина Вера Фт-170008 - Сложный банковский процент
//Сумма вклада (s)
//% годовых [7..14] - т.е. может быть не только целым, но и дробным (p)
//Количество месяцев - целое и не превышает 36 (3 года) (n)
//Минимальный срок вклада - 2 месяца
//Процент начисляется ежемесячно и реинвестируется
//Расчёт процентов через функцию

using namespace std;

float s, p;
float res;

float per(int f) //рекурсивная функция
{
	if ((f == 0)) //частное решение
		return s;
	else
	{
		res = per(f - 1) + per(f - 1) / 100 / 12 * p; // функция вызывает саму себя, вычисляет сумму в i-тый месяц
		return res;
	}
}

int main()
{
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
	for (int i = 0; i < n; i++)
	{
		per(i); // вызов рекурсивной функции
	}
	if (n == 1)
		cout << "Total amount = " << s << endl;
	else
	cout << "Total amount = " << per(n) << endl;

	return 0;
}