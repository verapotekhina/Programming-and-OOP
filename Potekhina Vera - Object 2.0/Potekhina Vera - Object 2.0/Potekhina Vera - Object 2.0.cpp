#include "stdafx.h"
#include <iostream>

//Потехина Вера Фт-170008 - Тело, на которое умеет действовать сила

/*
МАССЫ СПРАШИВАЮТСЯ В НАЧАЛЕ ПРОГРАММЫ И НЕ МЕНЯЮТСЯ ДО ЗАВЕРШЕНИЯ
Создать класс, моделирующий лежащее на горизонтальной поверхности тело.
Создать в программе 2 тела.
Рассчитать, какую силу необходимо приложить, чтобы сдвинуть с места покоящиеся тела.
Смоделировать увеличение прикладываемой силы и реакцию тела на неё.

F_тр = μ*m*g, где
μ - коэффициент трения,
m - масса тела,
g - ускорение свободного падения - константа g = 9,8 (м/с^2).
*/

using namespace std;

class CObject
{
private:
	float F_tr, g, F, a;                                  //F - сила тяги,  g - ускорение свободного падения, F_tr - сила трения, a - ускорение тела 
	char character;                                       //переменная для вывода характера движения тела

public:
	CObject() : g(9.8){}                                  //конструктор
	float friction_force(float m, float coefficient)      //метод определения силы трения (сопротивления) поверхности
	{
		F_tr = m * coefficient * g;                       //m - масса
		return F_tr;
	}

	float tracktive_force(float amount)                  //метод для силы тяги
	{
		F = amount;
		return F;
	}
	char character_of_movement()                         //характер движения
	{
		if (F < F_tr)
			character = '0';
		else if (F == F_tr)
		{
			character = '=';
		}
		else if (F > F_tr)
		{
			character = '+';
		}
		return character;
	}

	float acceleration(float m)                         //ускорение - для F > f_tr
	{
		if (F > F_tr)
			a = (F - F_tr) / m;                         //m - масса
		else
			a = 0;
		return a;
	}
};


int main()
{
	CObject object1;
	CObject object2;
	float coef, massa1, massa2, force;
	char n = '5', f;

	cout << "Enter coefficient of friction (from 0 to 1): ";           //запрашивает коэффициент трения поверхности
	cin >> coef;
	while ((coef <= 0) || (coef >= 1))                                 //коэффициент трения не может быть меньше нуля или больше 1 (чисто теоретически - может,
	{                                                                  //но тогда возникает сила адгезии - взаимодействие между молекулами этих тел - не наш случай)
		cout << "Enter coefficient of friction (from 0 to 1): ";
		cin >> coef;
	}

	cout << "Enter the mass of the object No. 1: ";                                       //запрашивает массу тела номер 1
	cin >> massa1;
	while (massa1 <= 0)                                                                   //масса должна быть положительной величиной                                               
	{
		cout << "Enter the mass of the object: ";
		cin >> massa1;
	}

	cout << "Enter the mass of the object No. 2: ";                                        //запрашивает массу тела номер 2
	cin >> massa2;
	while (massa2 <= 0)                                                                    //масса должна быть положительной величиной                                               
	{
		cout << "Enter the mass of the object: ";
		cin >> massa2;
	}

	while (n != '0')
	{
		cout << "Enter number of object (1 or 2). To exit enter 0: ";                       //номер тела
		cin >> n;
		while ((n != '1') && (n != '2') && (n != '0'))                                      //проверка на корректный ввод
		{
			cout << "Enter number of object (1 or 2). To exit enter 0: ";
			cin >> n;
		}

		if ((n == '1') || (n == '2'))
		{		
			cout << "Enter the amount of applied force: ";                                  //введите величину силы тяги 
			cin >> force;
			while (force <= 0)                                                              //значение силы должно быть положительным 
			{
				cout << "Enter the amount of applied force:  ";
				cin >> force;
			}

			if (n == '1')
			{
				cout << "Object No.1" << endl;
				cout << "The force you need to move object: " << object1.friction_force(massa1, coef) << endl;
				cout << "Tracktive forse: " << object1.tracktive_force(force) << endl;
				cout << "Character of movement: ";
				f = object1.character_of_movement();
				if (f == '0')                                     //тело покоится
					cout << "Object does not move." << endl;
				else if (f == '=')                                //тело движется равномерно
					cout << "Object evenly." << endl;
				else if (f == '+')                                //тело движется с ускорением
				{
					cout << "Object move wich acceleration." << endl;
					cout << "Acceleration: " << object1.acceleration(massa1) << endl;
				}
			}

			if (n == '2')
			{
				cout << "Object No.2" << endl;
				cout << "The force you need to move object: " << object2.friction_force(massa2, coef) << endl;
				cout << "Tracktive forse: " << object2.tracktive_force(force) << endl;
				cout << "Character of movement: ";
				f = object2.character_of_movement();
				if (f == '0')                                     //тело покоится
					cout << "Object does not move." << endl;
				else if (f == '=')                                //тело движется равномерно
					cout << "Object evenly." << endl;
				else if (f == '+')                                //тело движется с ускорением
				{
					cout << "Object move wich acceleration." << endl;
					cout << "Acceleration: " << object2.acceleration(massa2) << endl;
				}
			}
		}
	}
	cout << "Mission is completed." << endl;                      //корректное завершение
	return 0;
}


