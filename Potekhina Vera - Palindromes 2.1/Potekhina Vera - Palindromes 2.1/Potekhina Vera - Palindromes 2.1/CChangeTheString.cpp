#include "pch.h"
#include "CChangeTheString.h"
#include <string.h>

using namespace std;

//��������� ������������������ ����� ���������, ��� � ����������� ���� ����������� �� ��������� �������� ����

CChangeTheString::CChangeTheString(string inputString)
{
	userString = inputString;
	stringLength = userString.length();
}

void CChangeTheString::replacePunctuationMarks()  //������ ������ ���������� - ���� ������ ����� ������ �� ������������� ��� ������ �������� -
{                                                 //�������� �� ������
	int i = 0;
	while (i != stringLength)
	{
		if ((userString.at(i) == '!') || (userString.at(i) == ',') || (userString.at(i) == '.') || (userString.at(i) == '_') || (userString.at(i) == '?') || (userString.at(i) == '-') || (userString.at(i) == ':') || (userString.at(i) == ';') || (userString.at(i) == '"'))
		{
			userString.replace(i, 1, " ");
		}
		else
			i++;
	}
}

void CChangeTheString::removeExtraSpaces()
{
	{
		int i = 0;

		while ((i + 1) != stringLength)         //������� ������ ������� � ��������� �����������
		{
			if ((userString.at(i) == ' ') && (userString.at(i + 1) == ' ')) //������� ������������� �������
			{
				userString.erase(i + 1, 1);
				stringLength--;
			}
			else
				i++;
		}

		if ((userString.at(0) == ' ') && (stringLength > 1)) //�������� ������� ������� ������ �� ������ - ���� �� ���� - �������
		{
			userString.erase(0, 1);
			stringLength--;
		}
		else
			i++;

		if ((userString.at(stringLength - 1) != ' ') && (stringLength > 1)) //������ � ����� ������, ���� ��� ���
		{
			userString += " ";
			i++;
		}
	}
}

void CChangeTheString::changeCase()                 //��������� ��� ����� � ������ �������
{
	int i = 0;
	while (i != stringLength)
	{
		userString.at(i) = tolower(userString.at(i));
		i++;
	}
}

string CChangeTheString::showUserString()          //���������� ��������������� �������
{
	return userString;
}
