#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

/*
Посчитать количество вхождений подстроки в строку

P.S.: можно попробовать посчитать вхождения при пересечении 
*/

class CString
{
private:
	int lengthOfTheSubstring;     
	int lengthOfTheString;
	int position;
	int numberOfMatches;
	string originalString;
	string substring;

public:
	CString(string inputString, string inputSubString)     //перегруженный конструктор
	{
		lengthOfTheString = inputString.length();
		lengthOfTheSubstring = inputSubString.length();
		originalString = inputString;
		substring = inputSubString;
	}

	int countTheNumberOfMatches()                     //посчитать количество вхождений подстроки в строку
	{
		numberOfMatches = 0;                          //изначально - ноль
		for (int i = 0; i < lengthOfTheString; i++)   //пробегаемся по строке
		{
			position = originalString.find(substring);  
			if (position != -1)                       //если найдено вхождение 
			{
				numberOfMatches++;                    //прибавляем единицу к количеству вхождений
				originalString.erase(0, position + lengthOfTheSubstring); //удаляем часть строки, включающую в себя найденную подстроку и все, что до неё
				lengthOfTheString = lengthOfTheString - position - lengthOfTheSubstring;   //уменьшаем значение длины строки, соответственно
				i = 0;                                //ставим указатель на нулевой элемент
			}
		}
		return numberOfMatches;                       //возвращаем количество вхождений
	}
};

void inputValidation(string &input)                   //проверка на непустой ввод 
{
	while (input.length() == 0)
	{
		cout << "Enter string: ";
		getline(cin, input);
	}
}

int main()
{
	string inputString;
	string inputSubstring;
	cout << "Enter string: ";
	getline(cin, inputString);
	inputValidation(inputString);                          //проверка ввода строки

	cout << "Enter substring: ";
	getline(cin, inputSubstring);
	inputValidation(inputSubstring);                       //проверка ввода подстроки

	CString firstString(inputString, inputSubstring);      //создаем класс строки
	cout << firstString.countTheNumberOfMatches() << endl; //считаем количество вхождений и выводим на экран
	return 0;

}