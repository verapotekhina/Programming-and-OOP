#include "stdafx.h"
#include <iostream>

//Потехина Вера Фт-170008 - Кассовый аппарат 

/*
Модель кассового аппарата
Старт программы - начало нового кассового дня
В начале дня в кассе есть 275 рублей
1 основная операция : прием оплаты за товар(вводится сумма покупки)
2 основная операция : возврат денег, если покупатель принес товар обратно(вводится сумма к возврату)
Касса считает количество денег в ящике и сумму приходов отдельно
Старший кассир в любой момент времени может попросить показать сумму денег в кассе, сумму приходов за день, сумму возвратов, сумму среднего чека(средний чек = сумма приходов / количество чеков ПРИХОДА, чеки возврата не учитываются).
В кассе не может быть меньше, чем 0 рублей и не должно быть больше, чем 100 000 рублей.
Кассир, может сдать старшему кассиру часть выручки(вводится), либо всю выручку, оставив базовые 275 рублей.
Программа работает до тех пор, пока этого желает пользователь.
(Дополнительно)
Дать возможность пользователю выбирать форму оплаты - нал или карта
Должен быть организован раздельный учет, т.к.при безнале нет факта пополнения кассового ящика, соответственно, приход идет, но налички не прибавляется, и ограничение на 100 000 рублей не распространяется.
Идет суммарный учет выручки(нал + безнал), а старший кассир может увидеть, сколько оплачено налом, сколько безналом.
Возврат товара по желанию покупателя производится либо налом, либо на карту(соответственно, расчет в этих двух вариантах будет разный).
*/

using namespace std;

class CCash
{
private:
	float money, inc, receipt, comeback, check, aver;
	int i;

public:
	CCash()                                      //новый кассовый день - конструктор 
	{
		money = 275;                             //сумма денег в кассе
		inc = 0;                                 //выручка, которую забрали из кассы
		receipt = 0;                             //сумма приходов
		comeback = 0;                            //сумма возвратов
		check = 0;                               //сумма всех чеков прихода
		i = 0;                                   //количество чеков прихода
		aver = 0;                                //средний чек
	}
	
	float payment(float s)                       //оплата
	{
		if (s + money <= 100000)
		{
			money = money + s;
			i = i + 1;
		}
		else
			cout << "The amount will exceed 100000. Call the senior cashier." << endl;
		return money;
	}

	float refund(float s)                        //возврат
	{
		if (money - s >= 0)
			money = money - s;
		else                                     
			cout << "Not enough money. Try again later." << endl; //в кассе недостаточно средств для  возврата                                        
		return money;
	}

	float amount()                               //сумма в кассе
	{
		return money;
	}
		
	float received(float s)                      //сумма приходов
	{
		if (s + money <= 100000)
			receipt = receipt + s;
		return receipt;
	}

	float returned(float s)                      //сумма возвратов
	{
		if (money - s >= 0)
			comeback = comeback + s;
		return comeback;
	}

	float average_check(float s)                 //средний чек
	{
		if (s + money <= 100000)
			check = check + s;
		if (i == 0)
			aver = 0;
		else
			aver = check / i;
		return aver;
	}

	float income(float s)                        //забрать выручку - прибыль
	{
		inc = inc + s;
		money = money - s;
		return inc;
	}
};

int main()
{
	CCash till;
	float sum;                                   //сумма с клавиатуры
	char c, d, f;                                //отвечаeт за желания пользователя
	cout << "To exit, enter '0'. Are you a senior cashier? Enter '+' or '-': ";
	cin >> c;
	//проверка на корректный ввод 
	/*while ((c != '0') && (c != '+') && (c != '-'))
	{
		cout << "To exit, enter '0'. Are you a senior cashier? Enter '+' or '-': ";
		cin >> c;
	};*/

	while(c != '0')                             //работает, пока пользователь не пожелает выйти (пока не введет 0)
	{
		if (c == '+')                           //старший кассир 
		{
			cout << "To exit the mode of senior cashier enter '0'." << endl;       //выйти из режима старшего кассира
			cout << "To see the amount of money in cash enter '1'." << endl;           //увидеть сумму в кассе
			cout << "To see the amount of profit enter '2'." << endl;              //чтобы увидеть сумму приходов
			cout << "To see the amount of returns enter '3'." << endl;             //увидеть сумму возвратов
			cout << "To see the average check enter '4'." << endl;                 //увидеть средний чек
			cout << "To take money from the cash enter '5'." << endl;              //чтобы забрать выручку
			cout << "Enter 0, 1, 2, 3, 4 or 5: ";
			cin >> d;

			if (d == '0')                        //завершить работу или выйти из режима старшего кассира 
			{
				cout << "Do you want to enter the buyers mode? If 'Yes', enter '+', else enter '-': ";
				cin >> f;
				if (f == '+')
					c = '-';
				else if (f == '-')
					c = '0';
			}

			else if (d == '1')                                                          //увидеть сумму в кассе
				cout << "The amount of money in cash: " << till.amount() << endl;

			else if (d == '2')                                                          //чтобы увидеть сумму приходов
				cout << "The amount of profit: " << till.received(0) << endl;

			else if (d == '3')                                                          //увидеть сумму возвратов
				cout << "The amount of returns: " << till.returned(0) << endl;

			else if (d == '4')                                                          //увидеть средний чек
				cout << "The average check: " << till.average_check(0) << endl;

			else if (d == '5')                                                          //чтобы забрать выручку
			{
				cout << "Do you want to leave initial amount of money? (+ or -): ";
				cin >> f;
				if (f == '+')                   //если хочет оставить стартовую сумму - вычитаем стартовую из количества денег в кассе и вызываем метод с этой суммой
					sum = till.amount() - 275;
				else if ('-')                   //если сам хочет ввести сумму, которую нужно забрать - вызываем метод с введённым числом
				{
					cout << "Enter sum: ";
					cin >> sum;
					while ((till.amount() - sum) < 275) //проверка на то, чтобы после операции в кассе осталось не менее 275 рублей
					{
						cout << "The remaining amount must not be less than 275. Enter another sum or enter 0: ";
						cin >> sum;
					}	
				}
				cout << "The income: " << till.income(sum) << endl;
			}
		}

		else if (c == '-')                      //это обычный покупатель
		{
			cout << "To exit the mode of buyers enter '0'. If this is a payment enter '+', if this is a refund enter '-': ";                                 
			cin >> d;
			
			if (d == '+')                       //оплата
			{
				cout << "Enter sum: ";          //сумма с клавиатуры
				cin >> sum;
				while (sum <= 0)                //проверка суммы на корректный ввод
				{
					cout << "Enter another sum: "; //сумма с клавиатуры
					cin >> sum;
				}
				till.payment(sum);              //оплата
				till.received(sum);             //в сумму приходов
				till.average_check(sum);        //в средний чек

			}
			else if (d == '-')                  //возврат
			{
				cout << "Enter sum: ";          //сумма с клавиатуры
				cin >> sum;
				while (sum <= 0)                //проверка суммы на корректный ввод
				{
					cout << "Enter another sum: "; //сумма с клавиатуры
					cin >> sum;
				}
				till.refund(sum);              //возврат
				till.returned(sum);            //в сумму возвратов
				
			}
			else if (d == '0')                  //завершить работу или выйти из режима покупателей
			{
				cout << "Do you want to enter the senior cashier mode? If 'Yes', enter '+', else enter '-': ";
				cin >> f;
				if (f == '+')
					c = '+';
				else if (f == '-')
					c = '0';
			}
		}
	}
	cout << "The work is complited." << endl;
	return 0;
}