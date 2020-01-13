#include "pch.h"
#include "CFindPalindromes.h"
#include <string.h>

using namespace std;

//����� ������ �����������

CFindPalindromes::CFindPalindromes(string userString)  //������������� �����������
{
	convertedString = userString;
	convertedStringLength = convertedString.length();
}

bool CFindPalindromes::checkForPalindrome()            //��������� ����� �� ���������
{
	int i = 0;                                           //���������� ������� ������ � ����� �����
	int j = wordLength - 1;

	while (wordFromString.at(i) == wordFromString.at(j)) //����� �� ����� � ������ �����, ���������� �� ������ 
	{
		i++;
		j--;
		if (i == middleOfTheWord - 1)
			break;                                       //������ �� ����� ����� ������� ������������ ��� ���� ��������� �������� 
	}
	if (i == middleOfTheWord - 1)       //���������� true ��� false � ����������� �� ����, ��������� ��� ��� ���
		return true;
	else
		return false;
}

void CFindPalindromes::deleteWord()                             //������� ����� �� ������
{
	convertedString = convertedString.substr(wordLength + 1);   //�������, ����������
	convertedStringLength -= wordLength + 1;                    //��������� ����� ������
}

int CFindPalindromes::showConvertedStringLength()               //��������� ��������� ������
{
	return convertedStringLength;
}

string CFindPalindromes::palindrome()       //��� ������� ���������� ��� ������������������ �������� � ���� �����, ����� � main ������� ������ ���
{
	int i = 0;
	bool resultOfChecking;                  //��������� ��������   
	while (convertedString.at(i) != ' ')    //���� �� �������� ������� ������� � ������
		i++;                                //������� �������
	wordLength = i;                         //��� � ����� ����� ����� 
	if (wordLength > 2)                     //���� ���� � ����� ������, ��� ���, ��
	{
		wordFromString = convertedString.substr(0, wordLength);  //��� ����� ����������� �� �������
		if (wordLength % 2 == 0)                                 //������� ������ ������� � ������ �����
			middleOfTheWord = wordLength / 2;
		else
			middleOfTheWord = wordLength / 2 + 1;
		resultOfChecking = checkForPalindrome();  //�������� ����� �������� �� ��������� - �� ��� ��������� true ���� false
	}
	else                                    //���� ���� � ����� ������, ��� ���, ��
		resultOfChecking = false;           //����������� false
	deleteWord();

	if (resultOfChecking == true)           //���� �������� ��������, ��� ����� - ���������, ��
		return wordFromString;              //���������� ��� �����
	else                                    //�����
		return "-1";                        //���������� -1
}
