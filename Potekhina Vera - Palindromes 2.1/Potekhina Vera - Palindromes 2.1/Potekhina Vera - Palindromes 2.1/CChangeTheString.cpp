#include "pch.h"
#include "CChangeTheString.h"
#include <string.h>

using namespace std;

//Наименнее откомментированная часть программы, ибо в большинстве своём скопирована из программы подсчёта слов

CChangeTheString::CChangeTheString(string inputString)
{
	userString = inputString;
	stringLength = userString.length();
}

void CChangeTheString::replacePunctuationMarks()  //замена знаков препинания - если символ равен одному из встречающихся при письме символов -
{                                                 //заменяем на пробел
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

		while ((i + 1) != stringLength)         //удаляем лишние пробелы и добавляем необходимый
		{
			if ((userString.at(i) == ' ') && (userString.at(i + 1) == ' ')) //удаляем повторяющиеся пробелы
			{
				userString.erase(i + 1, 1);
				stringLength--;
			}
			else
				i++;
		}

		if ((userString.at(0) == ' ') && (stringLength > 1)) //проверка первого символа строки на пробел - если он есть - удаляем
		{
			userString.erase(0, 1);
			stringLength--;
		}
		else
			i++;

		if ((userString.at(stringLength - 1) != ' ') && (stringLength > 1)) //ставим в конце пробел, если его нет
		{
			userString += " ";
			i++;
		}
	}
}

void CChangeTheString::changeCase()                 //переводим все буквы в нижний регистр
{
	int i = 0;
	while (i != stringLength)
	{
		userString.at(i) = tolower(userString.at(i));
		i++;
	}
}

string CChangeTheString::showUserString()          //возвращаем преобразованную строчку
{
	return userString;
}
