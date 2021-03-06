#include "pch.h"
#include <iostream>
#include <string>

/*
1. Посчитать количество слов в строке (пользователь косячит)
Концепция:
Чистим строчку от знаков препинания и лишних пробелов
Затем считаем пробелы и выводим количество слов

2. Найти самую частую гласную
В цикле создаем объекты
Считаем для каждой буквы, заполняя массив
Далее работаем с двумя массивами, ибо индексы глассных соответствуют индексам их количества

Недоработки
1)Можно подключить setlocale() и сделать для русского алфавита тоже
2)можно попробовать разбить большой if в int main на несколько функций
3)комментариев сильно меньше, чем обычно (не считаю, что это критично плохо)
4)...

*/

using namespace std;

class CString                               //класс для строки - в целом можно было обойтись и функциями, но так симпатичнее, как минимум,
{                                           //и, наверное, для нескольких строк, преобразовать будет проще
private:
	string userString;                      //строка, введенная пользователем
	int stringLength;                       //длина строки

public:
CString(string inputString)                 //перегруженный конструктор
{
	userString = inputString;
	stringLength = userString.length();
}
                                           
void replacePunctuationMarks()              //замена знаков препинания - если символ равен одному из встречающихся при письме символов - 
{                                           //заменяем на пробел
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

void removeExtraSpaces()                    //удаление лишних пробелов
{
	int i = 0;

	while ((i + 1) != stringLength)         //удаляем повторяющиеся пробелы
	{
		if ((userString.at(i) == ' ')&&(userString.at(i + 1) == ' '))
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

	if ((userString.at(stringLength - 1) == ' ') && ((stringLength - 1) > 1) ) //аналогично для последнего
	{
		userString.erase(stringLength - 1, 1);
		stringLength--;
	}
	else
		i++;
}

int numberOfWords()                         //посчитать пробелы и вернуть количество слов
{
	int nubmer = 0;
	int i = 0;
	while (i != stringLength)
	{
		if (userString.at(i) == ' ')
		{
			nubmer++;
		}
		i++;
	}
	if ((nubmer >= 0) && (stringLength > 1))         //если в строке несколько пробелов есть,
		return nubmer + 1;                           //то слов на одно больше,
	else if (((nubmer == 1) && (stringLength == 1))) //если в строке один символ и это пробел,
		return nubmer - 1;                           //то слов 0,
	else                                             //иначе
		return nubmer;                               //это одно слово
}

};

class CVowel                                //класс для гласных 
{
private:
	char vowelFromArray;
	string userString;
public:
	CVowel(char vowel, string inputString)  //конструктор - при создании объекта передаем гласную и строчку
	{
		vowelFromArray = vowel;
		userString = inputString;
	}

	int numberOfVowels()                    //для заданной гласной подсчитываем количество её вхождений 
	{
		int number = 0;
		for (int i = 0; i < userString.length(); i++)
		{
			if (userString.at(i) == vowelFromArray)
				number++;
		}
		return number;                      //возвращаем это количество
	}
};

void inputValidation(string &input)         //функция проверки ввода
{
	while (input.length() == 0)                   
	{
		cout << "Enter string (to exit, enter *): ";
		getline(cin, input);
	}
}

int main()
{
	while (true)          //так случилось, потому что я устала запускать для каждого теста
	{
		int const numberOfVowels = 6;                                        //константа - для того, чтобы можно было увеличить количество гласных 
		                                                                     //(другого алфавита, например)
		char arrayOfVowels[numberOfVowels] = {'a', 'e', 'o', 'i', 'y', 'u'}; //массив гласных
		int quantityArray[numberOfVowels];                                   //массив для количества вхождений этих гласных
		string userString;                                                   //строчка, которую введет пользователь

		cout << "Enter string (to exit, enter *): ";        //запрос ввода
		getline(cin, userString);

		inputValidation(userString);                        //вызов функции проверки ввода

		if (userString != "*")                              //часть этой штуки, вероятнее всего, можно было запихнуть в функцию, но.. я не пробовала
		{
			CString firstString(userString);           
			firstString.replacePunctuationMarks();
			firstString.removeExtraSpaces();
			cout << "Number of words: " << firstString.numberOfWords() << endl;

			for (int i = 0; i < numberOfVowels; i++)        //для всех гласных из массива создаются объекты и в массиве количества вхождений, 
				                                            //соответственно, присваивается количество букв
			{
				CVowel vowel(arrayOfVowels[i], userString);
				quantityArray[i] = vowel.numberOfVowels();
			}

			int max = quantityArray[0];
			for (int i = 1; i < numberOfVowels; i++)   //ищем максимальное количество вхождений
			{
				if (quantityArray[i] > max)
					max = (quantityArray[i]);
			}
			cout << "the most frequent vowels: ";

			if (max != 0)                                  //если найдена хотя бы одна гласная
			{
				for (int i = 0; i < numberOfVowels; i++)   //выводим все гласные с количеством вхождений, равным максимальному
				{
					if (quantityArray[i] == max)
						cout << arrayOfVowels[i] << " ";
				}

			}
			else                                           //иначе говорим, что глассных из массива в строке нет
				cout << "Vowels of the array is not found.";

			cout << endl;
		}
		else
			return false;
	}
	return 0;
}