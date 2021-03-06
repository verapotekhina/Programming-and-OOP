#include "stdafx.h"
#include <iostream>
 
//Потехина Вера Фт-170008 - Машинка
//Ограничения на скорость [0-200]
//Разгон и торможение пользователь делает сколь угодно много раз
//5 передач

using namespace std;

class CCar
{                    
private:             
	int v;        

public:              
	void init()      
	{                
		v = 0;
	}
	int speedup()     //разгон
	{
		if (v < 200)
			v++;
		return v;  
	}
	int speedout()   //торможение
	{
		if (v > 0)
			v--;
		return v;
	}
};

int main()
{
	CCar nissan;      
	nissan.init();     //зануляется скорость 
	int n, s = 0, t = 0;
	char c;
	cout << "Do you want to increase(+) or decrease(-) the speed? Enter + or -: "; //вопрошаем, что хочет пользователь
	cin >> c;

	while (c != '0') //пока пользователь не ввёл 0 - усердно меняем скорость и передачи
	{

		if (c == '+')
		{
			cout << "How much to increase the speed: "; //вопрошаем, на сколько хочет разогнаться пользователь
			cin >> n;
			for (int i = 0; i < n; i++) //желание пользователя - закон, разгоняем, но в разумных пределах (а пределы в классе, ага)
			{
				s = nissan.speedup();
			}
			cout << "Current speed: " << s << endl; //говорим пользователю, что молодцы, справились

			if (s <= 40) //определяем передачу
				t = 1;
			else if (s <= 80)
				t = 2;
			else if (s <= 120)
				t = 3;
			else if (s <= 160)
				t = 4;
			else
				t = 5;
			cout << "Current transmission: " << t << endl; //выводим передачу
		}
		else if (c == '-')
		{
			cout << "How much to reduce the speed: "; //вопрошаем, на сколько хочет замедлиться пользователь
			cin >> n;
			for (int i = 0; i < n; i++) //желание пользователя - закон, тормозим, но не в минус, конечно
			{
				s = nissan.speedout();
			}
			cout << "Current speed: " << s << endl; //говорим пользователю, что молодцы, справились

			if (s <= 40) //определяем передачу
				t = 1;
			else if (s <= 80)
				t = 2;
			else if (s <= 120)
				t = 3;
			else if (s <= 160)
				t = 4;
			else
				t = 5;
			cout << "Current transmission: " << t << endl; //выводим передачу
		}
		cout << "Do you want to increase(+) or decrease(-) the speed? To stop changes enter 0. Enter +, - or 0: "; //вопрошаем, что хочет пользователь, пока он не устанет
		cin >> c;
	}
	cout << "Current speed: " << s << endl; // пользователь устал, выводим то, на чём он остановился
	cout << "Current transmission: " << t << endl; 

	return 0;
}