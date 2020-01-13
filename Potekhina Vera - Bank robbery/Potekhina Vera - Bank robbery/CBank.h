#pragma once

/*
1. ������������ (��� ��������� ����� ������� �������� �������)
	2. ����� (��� ��������� ����� ����� �������� �������)
	3. ����� ������ (�� ����� � ������� � �������)
	4. ���������� (1 ��� � 3 ���) ( ���������� ������ ��������� ����� ����� ������ ���������� �������,
	���� ����� ���������� ������, ���������� �� ���������)

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
		CBank(); //������������� �����������
		int returnOperationNumber();
		void readUserSelection();
		void functionsOfTheBank();
		void creditFunction(int);
		void depositFunction();
		void functionOfCurrencyExchange();
		void encashmentFunction();
};

