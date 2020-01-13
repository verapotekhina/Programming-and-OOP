#pragma once
#include <string>

using namespace std;

//заголовочный файл класса поиска палиндромов

class CFindPalindromes
{
private:
	string convertedString;              //строка, исправленная в классе преобразования
	int convertedStringLength;           //длина преобразованной строки
	string wordFromString;               //первое слово строки
	int wordLength;                      //длина первого слова
	int middleOfTheWord;                 //индекс+1 центра слова (если количество букв чётное, то индекс+1 буквы, стоящей левее середины)

public:
	CFindPalindromes(string);
	bool checkForPalindrome();
	void deleteWord();
	int showConvertedStringLength();
	string palindrome();
};

