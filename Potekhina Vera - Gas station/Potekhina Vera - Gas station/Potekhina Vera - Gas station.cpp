#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

//Потехина Вера Фт-270008 - Автозаправочная станция

/*
Смоделировать бензоколонку
3- 4 вида бензина, у каждого своя стоимость
Стартовое количество топлива по видам
Приезжают клиенты и заправляются
Не может налить больше, чем имеется в цистерне (то есть в минус уйти)
Учёт денег за каждый вид топлива, в сумме за всё, средние чеки
Наверное, должна работать до того момента, пока пользователь не пожелает выйти

Пояснения:
1) ССылки в методе и функциях проверки используются для того, чтобы значение менялось не только в методе или функции, но и 
в самой программе
2) Использовала строки, потому что так логичнее и красивее (потому что могу)

Косяки:
1) В классе есть один ввод/вывод, поэтому там же есть и одна проверка - я знаю, что плохо, но иначе не получилось 
*/

class CGasStation
{
private:
	float costOfGasoline; //стоимость определенного вида бензина
	float numberOfLitres; //количество литров этого бензина в цистерне
	float revenue; //выручка за этот вид бензина
	int numberOfChecks; //счётчик количества чеков по конкретному виду топлива

public:
	CGasStation(float cost) //конструктор
	{
		numberOfLitres = 8000; //начальное количество литров в каждой цистерне с бензином - мне не ответили, пользователь ли 
		                       //решает, сколько там бензина в начальный момент времени, поэтому я сделала так
		revenue = 0;           //выручка в начальный момент времени отсутствует
		costOfGasoline = cost; //стоимость бензина передаётся при создании объекта - аналогично с начальным количеством литров, я 
		                       //захотела так
		numberOfChecks = 0;    //количество чеков в начальный момент времени равно 0
	}

	void checkCorrectnessOfSymbol(char &symbol) //проверка корректного ввода только + и -
	{
		while ((symbol != '+') && (symbol != '-'))
		{
			cout << "Error input. Enter '+' or '-': ";
			cin >> symbol;
		}
	}

	float fillTheCar(float countOfLitres)            //заправить машину - на вход подается количество литров, которое  
	{                                                //желает клиент, возвращает количество, которое было влито в машинку	
		if (numberOfLitres - countOfLitres >= 0)                         //если количество литров, которое хочет клиент меньше, чем на
		                                                                 //данный момент есть в цистерне, то
		{
			numberOfLitres = numberOfLitres - countOfLitres;             //из цистерны убавляется
			addAmountToRevenue(countOfLitres);                           //в баке машинки прибавляется
			numberOfChecks++;                                            //к чекам прибавляется еще один чек    
		}
		else                                                             //если количество литров, которое хочет клиент больше, чем на
		                                                                 //данный момент есть в цистерне, то
		{
			char symbolFromTheUser;                                      //эта переменная отвечает за желание пользователя
			                                                             //вопрошаем, хочет ли пользователь взять всё, что осталось
			cout << "There are " << numberOfLitres << " litres in gas station. Do you want to fill remaining amount of litres? (if 'YES' enter '+', else enter '-'): ";
			cin >> symbolFromTheUser;          
			checkCorrectnessOfSymbol(symbolFromTheUser);                 //проверка на корректный ввод
			if (symbolFromTheUser == '+')                                //если пользователь согласен, то
			{
				countOfLitres = numberOfLitres;                          //количество литров, которое хочет пользователь меняется на 
				                                                         //количество литров, которое осталось в цистерне
				numberOfLitres = 0;                                      //цистерна опустошается
				addAmountToRevenue(numberOfLitres);                      //в баке машинки прибавляется
				numberOfChecks++;                                        //к чекам прибавляется еще один чек
			}
			else                                                         //иначе
				countOfLitres = 0;                                       //клиент уезжает ни с чем                          
		}
		return countOfLitres;                                            //возвращаем количество перелитых клиенту литров
	}

	void addAmountToRevenue(float totalNumberOfLitres)          //добавить сумму к выручке по определенному виду бензина
	{
		revenue = revenue + costOfGasoline * totalNumberOfLitres;
	}

	float showTheAmountOfRevenue()                              //возвращает выручку по определенному виду бензина
	{
		return revenue;
	}

	float showAverageCheck()                                    //возвращает средний чек  по определенному виду бензина
	{
		if (numberOfChecks != 0)
			return revenue / numberOfChecks;
		else
			return 0;
	}

	float showTheRestOfTheGasoline()                            //возвращает остаток определенного типа бензина
	{
		return numberOfLitres;
	}

	int showTheNumberOfChecks()                                  //возвращает количество чеков
	{
		return numberOfChecks;
	}
};

float workWithTheClass(string number, CGasStation& object, float litres)    //функция основной работы - для заданной операции и типа
                                                                            //бензина выполняется соответствующее им что-то
{
	if (number == "1")
	{
		cout << "There was poured liters: ";                //еще один вывод в функции, но по-другому красиво и последовательно не получалось
		return object.fillTheCar(litres);
	}
	else if (number == "2")
		return object.showTheAmountOfRevenue();
	else if (number == "3")
		return object.showTheRestOfTheGasoline();
	else if (number == "4")
		return object.showAverageCheck();
	else                                                    //по идее не должно дойти до этого момента, потому что есть проверки
		return -1;
}

float revenuePerType(CGasStation& object)                    //выручка по видам бензина
{
	return object.showTheAmountOfRevenue();
}

int numberOfChecksByType(CGasStation& object)                //количество чеков по видам бензина
{
	return object.showTheNumberOfChecks(); 
}

//проверки

void checkTheCorrectnessOfNumbers(string &number)             //проверка корректного ввода номера операции
{  
	                                                          //пока пользователь косячит
	while ((number != "1") && (number != "2") && (number != "3") && (number != "4") && (number != "5") && (number != "6") && (number != "*"))
	{
		cout << "Error input. Enter 1, 2, 3, 4, 5, 6 or *: "; //говорим, что пользователь не прав и просим ввести заново
		cin >> number;
	}		
}

void checkTheCorrectnessFuelType(string &type)               //проверка корректного ввода типа бензина
{
	                                                         //пока пользователь косячит
	while ((type != "DT") && (type != "A92") && (type != "A95") && (type != "A98"))
	{
		cout << "Error input. Enter DT, A92, A95, A98: ";    //говорим, что пользователь не прав и просим ввести заново
		cin >> type;
	}		
}

void checkTheCorrectOfLitres(float &litres)                  //проверка корректного ввода количества литров
{
	while (true)
	{
		if ((cin.fail()) || (litres < 0))                    //если предыдущее извлечение было провальным или количество литров отрицательно
		{
			cin.clear();                                     //возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n');                         //и удаляем значения предыдущего ввода из входного буфера
			cout << "Error input. Enter number of liters: "; //говорим, что пользователь не прав и просим ввести заново
			cin >> litres;                             
		}
		else
			break;                                            //когда пользователь перестал косячить, выходим из цикла
	}
}


int main()
{
	string operationNumber;     //номер операции
	string fuelType;            //тип бензина
	float numberOfLitres = 0;   //количество литров, которое хочет клиент
	float totalRevenue = 0;     //полная выручка
	int sumOfAllChecks = 0;     //все чеки
	CGasStation DT(44.69f);      //объекты класса - виды топлива на бензоколонке
	CGasStation A92(42.08f);
	CGasStation A95(52.69f);
	CGasStation A98(44.69f);

	while (true)               //бесконечный цикл - мы же ленивые запускать каждый раз - работает, пока того желает пользователь
	{
		cout << "If you want to fill the car enter '1'; " << endl;
		cout << "if you want to see the amount of revenues enter '2'; " << endl;
		cout << "if you want to see the rest of the gasoline in the tank enter '3'; " << endl;
		cout << "if you want to see the amount of average check enter '4'; " << endl;
		cout << "if you want to see the full revenue enter '5'; " << endl;
		cout << "if you want to see the average check for all revenue enter '6';" << endl;
		cout << "enter * for exitif you want to exit enter *;" << endl;
	    cout << "Enter 1, 2, 3, 4, 5, 6 or *: ";
		cin >> operationNumber;
		checkTheCorrectnessOfNumbers(operationNumber); //проверка корректности ввода номера операции

		if (operationNumber == "*")  //корректный выход из программы, если запустили и решили не выполнять ни одного действия
			break;
		
		if ((operationNumber != "5") && (operationNumber != "6")) //эти две операции не зависят от типа бензина, 
			                                                      //поэтому для них не спрашиваем
		{
			cout << "Enter type of gasoline: (DT, A92, A95, A98): ";
			cin >> fuelType;
			checkTheCorrectnessFuelType(fuelType);  //проверка корректности ввода типа бензина
		}
		                                            
		if (operationNumber == "1")               
		{
			cout << "Enter number of liters: ";
			cin >> numberOfLitres;
			checkTheCorrectOfLitres(numberOfLitres);  //проверка на корректность ввода количества литров
		}
		else if (operationNumber == "2")
			cout << "The amount of revenues: ";
		else if (operationNumber == "3")
			cout << "The rest of the gasoline in the tank: ";
		else if (operationNumber == "4")
			cout << "The amount of average check: ";
		else if (operationNumber == "5")             //четыре раза вызывается функция, которая вызывает метод, который вернет значение
		{                                            //выручки по запрошенному типу бензина - получим сумму всех выручек
			totalRevenue = revenuePerType(DT) + revenuePerType(A95) + revenuePerType(A98) + revenuePerType(A92);
			cout << "The full amount of revenue: " << totalRevenue << endl;
			cout << endl;                            //перевод строки для красоты в консольке
		}
		else if (operationNumber == "6")
		{                                            //аналогично для выручки и количества чеков
			totalRevenue = revenuePerType(DT) + revenuePerType(A95) + revenuePerType(A98) + revenuePerType(A92);
			sumOfAllChecks = numberOfChecksByType(DT) + numberOfChecksByType(A92) + numberOfChecksByType(A95) + numberOfChecksByType(A98);
			if (sumOfAllChecks == 0)                  //если операции не совершались предусмотрительно не позволяем разделить на ноль
				cout << "Рayment was not made. The full amount of average check 0." << endl;
			else
				cout << "The full amount of average check: " << totalRevenue / sumOfAllChecks << endl;
			cout << endl;                             //перевод строки для красоты в консольке
		}
		else           //по идее вообще не дойдет до этого места, ибо есть проверка ввода, но мало ли, вдруг кто-то талантливый
		{
			cout << "I have broken something that mustn’t be broken" << endl;
			return -1;
		}	 

		if ((operationNumber != "5") && (operationNumber != "6"))  //если это не пятая и не шестая операции, то по заданному бензину,
		{                                                          //номеру операции и количеству литров вызывается функция, которая
			                                                       //которая соответственно выполняет то, что пользователь хочет
			if (fuelType == "A95")
				cout << workWithTheClass(operationNumber, A95, numberOfLitres) << endl;
			else if (fuelType == "A98")
				cout << workWithTheClass(operationNumber, A98, numberOfLitres) << endl;
			else if (fuelType == "A92")
				cout << workWithTheClass(operationNumber, A92, numberOfLitres) << endl;
			else if (fuelType == "DT")
				cout << workWithTheClass(operationNumber, DT, numberOfLitres) << endl;
			else       //по идее вообще не дойдет до этого места, ибо есть проверка ввода, но мало ли, вдруг кто-то талантливый
			{
				cout << "I have broken something that mustn’t be broken" << endl;
				return -1; 
			}		
			cout << endl;                   //перевод строки для красоты в консольке
		}
	}
	return 0;
}