#include "pch.h"
#include "CBank.h"
#include <iostream>

using namespace std;
CBank::CBank()  //перегруженный конструктор
{
	initialAmountOfDollars = 100000;
	initialAmountOfRubles = 500000;
	timeCounter = 9;
	operationCount = 0;
}

int CBank::returnOperationNumber()
{
	return operationCount;
}

void CBank::readUserSelection()
{
	cin >> userSelection;
}

void CBank::functionsOfTheBank()
{
	//if (userSelection == 1)

}

void CBank::creditFunction(int amountOfTheCredit)
{
}

void CBank::depositFunction()
{
}

void CBank::functionOfCurrencyExchange()
{
}

void CBank::encashmentFunction()
{
}

