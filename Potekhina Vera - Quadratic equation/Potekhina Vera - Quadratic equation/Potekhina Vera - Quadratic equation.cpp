#include "stdafx.h"
#include <iostream>
#include <math.h>

//Потехина Вера Фт-170008 - Квадратное уравнение 

using namespace std;

void ur(float x, float y, float z)
{
	float d;
	d = y * y - 4 * x*z;
	if (d < 0)
		cout << "No decision" << endl;
	else if (d == 0)
	{
		cout << "x = " << (0 - y) / (2 * x) << endl;
	}
	else if (d > 0)
	{
		cout << "x1 = " << (0 - y + sqrt(d)) / (2 * x) << endl << "x2 = " << (0 - y - sqrt(d)) / (2 * x) << endl;
	}
}

int main()
{
	float a, b, c;
	cout << "Enter a, b, c: ";
	cin >> a >> b >> c;
	ur(a, b, c);
	return 0;
}

