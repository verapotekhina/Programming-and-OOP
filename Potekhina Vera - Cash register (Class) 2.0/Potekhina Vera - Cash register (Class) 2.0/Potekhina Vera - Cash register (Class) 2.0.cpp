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
	float money, card_money, inc, receipt, card_receipt, comeback, card_comeback, aver;
	int i;
	char r;

public:
	CCash()                                      //новый кассовый день - конструктор 
	{
		money = 275;                             //сумма денег в кассе
		card_money = 0;                          //сумма денег на счёте
		inc = 0;                                 //выручка, которую забрали из кассы
		receipt = 0;                             //сумма приходов в кассу
		card_receipt = 0;                        //сумма приходов на счёт
		comeback = 0;                            //сумма возвратов
		card_comeback = 0;                       //сумма возвратов на карту
		i = 0;                                   //количество чеков прихода
		aver = 0;                                //средний чек
	}

	float payment(float s)                       //оплата через кассу
	{
		if (s + money <= 100000)
		{
			money = money + s;
			i = i + 1;
		}
		else
		{
			cout << "The amount will exceed 100000. Do you want to pay by card? If 'Yes' enter '+', else enter '-' and call the senior cashier: " << endl;
			                                     //если превышает 100000, предлагает оплатить картой
			cin >> r;
			if (r == '+')
				card_payment(s);
		}

		return money;
	}

	float card_payment(float s)                  //оплата картой
	{
		card_money = card_money + s;
		i = i + 1;                              
		return card_money;
	}

	float refund(float s)                        //возврат через кассу
	{
		if (money - s >= 0)
			money = money - s;
		else
		{
			cout << "Not enough money. Do you want to return to the card? If 'Yes' enter '+', else enter any other character and try again later: ";
			                                     //если в кассе не хватает денег для возврата, предлагает вернуть на карту либо попробовать позже
			cin >> r;
			if (r == '+')
				card_refund(s);                  //отправляет в метод для возврата на карту
		}
			                                        
		return money;
	}

	float card_refund(float s)                   //возврат на карту
	{
		if ((card_money - s) >= 0)
			card_money = card_money - s;
		else
		{
			cout << "Not enough money. Do you want to return in cash? If 'Yes' enter '+', else enter any other character and try again later: ";
			                                     //если не хватает денег на счёте для возврата, предлагает вернуть через кассу или попробовать позже
			cin >> r;
			if (r == '+')
				refund(s);                       //отправляет в метод для возврата на карту
		}
		return card_money;
	}

	float amount()                               //сумма в кассе
	{
		return money;
	}

	float card_amount()                          //сумма на счёте
	{
		return card_money;
	}

	float received(float s)                      //сумма приходов в кассу
	{
		if (money <= 100000)
			receipt = receipt + s;
		return receipt;
	}

	float card_received(float s)                 //сумма приходов на счёт
	{
		card_receipt = card_receipt + s;
		return card_receipt;
	}

	float returned(float s)                      //сумма возвратов через кассу
	{
		if (money >= 0)
			comeback = comeback + s;
		return comeback;
	}

	float card_returned(float s)                 //сумма возвратов со счёта
	{
		if (card_money - s >= 0)
			card_comeback = card_comeback + s;
		return card_comeback;
	}

	float average_check(float s)                 //средний чек
	{
		if (i == 0)
			aver = 0;
		else
			aver = (receipt + card_receipt) / i;
		return aver;
		
	}

	float income(float s)                        //забрать выручку - прибыль
	{
		inc = inc + s;
		money = money - s;
		return inc;
	}

	void unite_payment(float s)                  //два метода оплаты через кассу
	{
		payment(s);                              //оплата через кассу
		received(s);                             //в сумму приходов в кассу
	}

	void unite_card_payment(float s)             //два метода оплаты картой
	{
		card_payment(s);                         //оплата картой
		card_received(s);                        //в сумму приходов на счёт
	}

	void unite_refund(float s)                   //два метода возврата через кассу
	{
		refund(s);                               //возврат в кассу
	    returned(s);                             //в сумму возвратов в кассу
	}

	void unite_card_refund(float s)              //два метода возврата на карту
	{
		card_refund(s);                          //возврат на карту
		card_returned(s);                        //в сумму приходов на счёт
	}
};

int main()
{
	CCash till;
	float sum;                                         //сумма с клавиатуры
	char c = ' ', d, f;                                //отвечаeт за желания пользователя
	 
	while ((c != '0') && (c != '+') && (c != '-'))     //проверка на корректный ввод
	{
	cout << "To exit, enter '0'. Are you a senior cashier? Enter '+' or '-': ";
	cin >> c;
	}

	while (c != '0')                                   //работает, пока пользователь не пожелает выйти (пока не введет 0)
	{
		if (c == '+')                                  //старший кассир 
		{
			cout << "To exit the mode of senior cashier enter '0'." << endl;       //выйти из режима старшего кассира
			cout << "To see the amount of money in cash enter '1'." << endl;       //увидеть сумму в кассе
			cout << "To see the amount of profit enter '2'." << endl;              //чтобы увидеть сумму приходов
			cout << "To see the amount of returns enter '3'." << endl;             //увидеть сумму возвратов
			cout << "To see the average check enter '4'." << endl;                 //увидеть средний чек
			cout << "To take money from the cash enter '5'." << endl;              //чтобы забрать выручку
			cout << "Enter 0, 1, 2, 3, 4 or 5: ";
			cin >> d;

			if (d == '0')                              //завершить работу или выйти из режима старшего кассира 
			{
				cout << "Do you want to enter the buyers mode? If 'Yes', enter '+', else enter '-': ";
				cin >> f;
				if (f == '+')
					c = '-';
				else if (f == '-')
					c = '0';
			}

			else if (d == '1')                         //увидеть сумму в кассе
				cout << "The amount of money in cash: " << till.amount() << endl;

			else if (d == '2')                         //чтобы увидеть сумму приходов                      
			{
				cout << "The amount of profit: " << till.received(0) + till.card_received(0) << endl;
				cout << "If you want to see amount of profit on the account enter '+', if you want to see amount of profit to cash enter '-', else enter '0': ";
				//вопрошает, хочет ли пользователь увидеть по отдельности сумму приходов наличными и на карту
				cin >> f;
				if (f == '+')
					cout << "The amount of profit on the account: " << till.card_received(0) << endl;     //отдельно приход на счёт
				else if (f == '-')
					cout << "The amount of profit to cash: " << till.received(0) << endl;                 //отдельно приход в кассу
			}


			else if (d == '3')                         //увидеть сумму возвратов
			{
				cout << "The amount of returns: " << till.returned(0) + till.card_returned(0) << endl;
				cout << "If you want to see amount of returns on the card enter '+', if you want to see amount of returns to cash enter '-', else enter '0': ";
				//вопрошает, хочет ли пользователь увидеть по отдельности сумму возвратов наличными и на карту
				cin >> f;
				if (f == '+')
					cout << "The amount of returns on the card: " << till.card_returned(0) << endl;       //отдельно возврат на карту
				else if (f == '-')
					cout << "The amount of returns to cash: " << till.returned(0) << endl;                //отдельно возврат в кассу
			}

			else if (d == '4')                                                                            //увидеть средний чек
				cout << "The average check: " << till.average_check(0) << endl;

			else if (d == '5')                                                                            //чтобы забрать выручку
			{
				cout << "Do you want to leave initial amount of money? (+ or -): ";
				                                        //вопрошает, хочет ли пользователь оставить стартовую сумму в кассе или ввести сумму, которую нужно забрать из кассы
				cin >> f;
				if (f == '+')                           //если хочет оставить стартовую сумму - вычитаем стартовую из количества денег в кассе и вызываем метод с этой суммой
					sum = till.amount() - 275;
				else if ('-')                           //если сам хочет ввести сумму, которую нужно забрать - вызываем метод с введённым числом
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

		else if (c == '-')                              //это обычный покупатель
		{
			cout << "To exit the mode of buyers enter '0'. If this is a payment enter '+', if this is a refund enter '-': ";
			                                            //для выхода из режима покупателя - '0', для оплаты - '+', для возврата - '-'
			cin >> d;

			if (d == '+')                               //оплата
			{
				cout << "Do you want to payment of card? If 'Yes' enter '+', else enter '-': "; 
				                                        //вопрошает, наличными или картой хочет произвести оплату
				cin >> f;
				while ((f != '+') && (f != '-'))        //проверка на корректный ввод
				{
					cout << "Do you want to payment of card? If 'Yes' enter '+', else enter '-': ";
					cin >> f;
				}
				cout << "Enter sum: ";                  //сумма с клавиатуры
				cin >> sum;
				while (sum <= 0)                        //проверка суммы на корректный ввод
				{
					cout << "Enter another sum: ";      //сумма с клавиатуры
					cin >> sum;
				}

				if (f == '+')
				{
					till.unite_card_payment(sum);       //два метода для оплаты картой
				}
				else if (f == '-')
				{
					till.unite_payment(sum);            //два метода для оплаты через кассу
				}

			}
			else if (d == '-')                          //возврат
			{
				cout << "Do you want to return to the card? If 'Yes' enter '+', else enter '-': ";
				                                        //вопрошает, наличными или на карту сделать возврат
				cin >> f;
				while ((f != '+') && (f != '-'))        //проверка на корректный ввод
				{
					cout << "Do you want to return to the card? If 'Yes' enter '+', else enter '-': ";
					cin >> f;
				}
				cout << "Enter sum: ";                  //сумма с клавиатуры
				cin >> sum;
				while (sum <= 0)                        //проверка суммы на корректный ввод
				{
					cout << "Enter another sum: ";      //сумма с клавиатуры
					cin >> sum;
				}

				if (f == '+')
				{
					till.unite_card_refund(sum);        //два метода для возврата на карту
				}
				else if (f == '-')
				{
					till.unite_refund(sum);             //два метода для возврата через кассу
				}
			}
			else if (d == '0')                          //завершить работу или выйти из режима покупателей
			{
				cout << "Do you want to enter the senior cashier mode? If 'Yes', enter '+', else enter '-': ";
				                                        //вопрошает, хочет ли пользователь войти в режим старшего кассира
				cin >> f;
				if (f == '+')
					c = '+';
				else if (f == '-')
					c = '0';
			}
		}
	}
	cout << "The work is completed." << endl;           //корректное завершение работы
	return 0;
}