#include "pch.h"
#include "CFindPalindromes.h"
#include <string.h>

using namespace std;

//класс поиска палиндромов

CFindPalindromes::CFindPalindromes(string userString)  //перегруженный конструктор
{
	convertedString = userString;
	convertedStringLength = convertedString.length();
}

bool CFindPalindromes::checkForPalindrome()            //проверяем слово на палиндром
{
	int i = 0;                                           //записываем индексы начала и конца слова
	int j = wordLength - 1;

	while (wordFromString.at(i) == wordFromString.at(j)) //шагая от краев к центру слова, сравниваем по буквам 
	{
		i++;
		j--;
		if (i == middleOfTheWord - 1)
			break;                                       //выйдет из цикла после первого несовпадения или если достигнет середины 
	}
	if (i == middleOfTheWord - 1)       //возвращаем true или false в зависимости от того, палиндром это или нет
		return true;
	else
		return false;
}

void CFindPalindromes::deleteWord()                             //удаляем слово из строки
{
	convertedString = convertedString.substr(wordLength + 1);   //удаляем, собственно
	convertedStringLength -= wordLength + 1;                    //сокращаем длину строки
}

int CFindPalindromes::showConvertedStringLength()               //возращаем изменённую строку
{
	return convertedStringLength;
}

string CFindPalindromes::palindrome()       //эта функция объединяет всю последовательность действий в один метод, чтобы в main вызвать только его
{
	int i = 0;
	bool resultOfChecking;                  //результат проверки   
	while (convertedString.at(i) != ' ')    //пока не достигли первого пробела в строке
		i++;                                //считаем символы
	wordLength = i;                         //это и будет длина слова 
	if (wordLength > 2)                     //если букв в слове больше, чем две, то
	{
		wordFromString = convertedString.substr(0, wordLength);  //это слово вытаскиваем из строчки
		if (wordLength % 2 == 0)                                 //находим индекс символа в центре слова
			middleOfTheWord = wordLength / 2;
		else
			middleOfTheWord = wordLength / 2 + 1;
		resultOfChecking = checkForPalindrome();  //вызываем метод проверки на палиндром - он нам возращает true либо false
	}
	else                                    //если букв в слове меньше, чем две, то
		resultOfChecking = false;           //определенно false
	deleteWord();

	if (resultOfChecking == true)           //если проверка показала, что слово - палиндром, то
		return wordFromString;              //возвращаем это слово
	else                                    //иначе
		return "-1";                        //возвращаем -1
}
