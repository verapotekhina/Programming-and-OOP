#pragma once
#include <string>

using namespace std;

//������������ ���� ������ ������ �����������

class CFindPalindromes
{
private:
	string convertedString;              //������, ������������ � ������ ��������������
	int convertedStringLength;           //����� ��������������� ������
	string wordFromString;               //������ ����� ������
	int wordLength;                      //����� ������� �����
	int middleOfTheWord;                 //������+1 ������ ����� (���� ���������� ���� ������, �� ������+1 �����, ������� ����� ��������)

public:
	CFindPalindromes(string);
	bool checkForPalindrome();
	void deleteWord();
	int showConvertedStringLength();
	string palindrome();
};

