#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;

/*
Описать класс, представляющий треугольник. Предусмотреть методы для создания объектов, вычисления площади, периметра и
точки пересечения медиан. Описать свойства для получения состояния объекта.
*/

class CTriangle
{
private:
	int sideA;
	int sideB;
	int sideC;
public:
	CTriangle(int a, int b, int c)
	{
		sideA = a;
		sideB = b;
		sideC = c;
	}
	float calculateTheAria()
	{
		float halfMeter;
		halfMeter = (calcutaleThePerimeter() / 2.0);
		float aria;
		aria = sqrt(halfMeter*(halfMeter - sideA)*(halfMeter - sideB)*(halfMeter - sideC));
		return aria;
	}

	int calcutaleThePerimeter()
	{
		return sideA + sideB + sideC;
	}

	void determineThePointOfmedians()
	{
		cout << "Ma = " << sqrt(2 * sideB*sideB + 2 * sideC *sideC - sideA * sideA)/2 << endl;
		cout << "Mb = " << sqrt(2 * sideA*sideA + 2 * sideC *sideC - sideB * sideB)/2 << endl;
		cout << "Mc = " << sqrt(2 * sideB*sideB + 2 * sideA *sideA - sideC * sideC)/2 << endl;
	}
};

void inputValidation(int &n)
{
	while ((n < 1) || (n > 5))
	{
		cout << "Your choise : ";
		cin >> n;
	}
}


int menu()
{
	int n;
	cout << "Menu:" << endl;
	cout << "Enter 1, if you want to calculate the aria of triangle;" << endl;
	cout << "Enter 2, if you want to calculate the perimeter of triangle;" << endl;
	cout << "Enter 3, if you want to see the point of intersection of medians;" << endl;
	cout << "Enter 4, if you want to see all properties;" << endl;
	cout << "For exit, enter 5." << endl;
	cout << "Your choise: ";
	cin >> n;
	inputValidation(n);
	return n;
}


int main()
{
	
	int a, b, c;
	while (true)
	{
		cout << "Enter side of triangle: ";
		cin >> a >> b >> c;
		CTriangle triangle(a, b, c);
		int numberOpersion = menu();
		if (numberOpersion == 1)
			cout << "Aria = " << triangle.calculateTheAria() << endl;
		else if (numberOpersion == 2)
			cout << "Perimeter = " << triangle.calcutaleThePerimeter() << endl;
		else if (numberOpersion == 3)
			triangle.determineThePointOfmedians();
		else if (numberOpersion == 4)
		{
			cout << "Aria = " << triangle.calculateTheAria() << endl;
			cout << "Perimeter = " << triangle.calcutaleThePerimeter() << endl;
			triangle.determineThePointOfmedians();
		}
		else if (numberOpersion == 5)
		{
			cout << endl;
			return false;
		}
	}
	return 0;
}

