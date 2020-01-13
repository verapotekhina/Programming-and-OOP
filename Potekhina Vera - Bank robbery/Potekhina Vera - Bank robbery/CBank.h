#pragma once

/*
1. Кредитование (для упрощения будет возврат денежных средств)
	2. Вклад (для упрощения будет прием денежных средств)
	3. Обмен Валюты (из рубля в доллары и обратно)
	4. Инкассация (1 раз в 3 дня) ( инкассация всегда оставляет банку сумму равную начальному условию,
	если сумма составляет меньше, инкассация не приезжает)

*/
class CBank
{
	private:
		int initialAmountOfDollars;
		int initialAmountOfRubles;
		int timeCounter;
		int operationCount;
		int userSelection;
	public:
		CBank(); //перегруженный конструктор
		int returnOperationNumber();
		void readUserSelection();
		void functionsOfTheBank();
		void creditFunction(int);
		void depositFunction();
		void functionOfCurrencyExchange();
		void encashmentFunction();
};

