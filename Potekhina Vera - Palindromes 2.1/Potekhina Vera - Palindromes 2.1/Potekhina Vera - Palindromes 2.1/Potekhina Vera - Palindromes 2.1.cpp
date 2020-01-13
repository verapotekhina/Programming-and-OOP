#include "pch.h"
#include <iostream>
#include <string>
#include "CChangeTheString.h"
#include "CFindPalindromes.h"

using namespace std;

/* Потехина Вера Фт-270008 - Поиск палиндромов в строке (версия 2.1 - многофайловый проект с небольшими исправлениями)

Концепция
У нас имеется строчка, которая:
1) не имеет знаков препинания;
2) имеет по одному пробелу между словами;
3) не имеет пробела в начале, но обязательно имеет пробел в конце;
4) все буквы в строчке нижнего регистра.
Такую строчку получили, используя часть программы, где искали слова, разве что чуть-чуть её изменив.

Что мы хотим:
1)добавить пробел в начале и в конце -- это тоже в методы класса, который меняет строчку
2)от начала строчки до пробела смотреть слово, считать количество букв
3)относительно количества букв считать индекс символа в середине слова, запускать функцию проверки
5)если палиндром - выводим его и удаляем до пробела, иначе - просто удаляем, не забывая сократить длину строки

(Комментарии скопированы точно так же, как и часть программы, где искали слова)
*/

void inputValidation(string &input)         //функция проверки ввода
{
	while (input.length() == 0)             //просим ввести что-нибудь, а не перевод строки
	{
		cout << "Enter string (to exit, enter *): ";
		getline(cin, input);
	}
}

int main()
{
	while (true)                            //ну, очевидно, что запускать для каждого теста лениво
	{
		string userString;                                 //строчка, которую введет пользователь

		cout << "Enter string (to exit, enter *): ";       //запрос ввода
		getline(cin, userString);
		inputValidation(userString);                       //вызов функции проверки ввода

		if (userString != "*")
		{
			CChangeTheString inputString(userString);  //создали объект класса - строка, введённая пользователем 
			inputString.replacePunctuationMarks();     //убрали все знаки препинания
			inputString.removeExtraSpaces();           //убрали лишние пробелы и добавили пробел в конце
			inputString.changeCase();                  //сделали все буквы в строке нижнего регистра
			userString = inputString.showUserString(); //вернули себе строчку приятного вида 
			cout << "Modified string: " << userString << endl; //оценили её прекрасность

			cout << "Palindromes: ";
			string resultOfTheCheckWords;                           //результат проверки - либо слово, если оно палиндром, либо -1                
			CFindPalindromes modifiedString(userString);            //создали объект класса - строчка приятного вида, в который сами же и привели
			while (true)                                            //пока цикл не прервётся из-за выполненного условия, делаем
			{
				if (modifiedString.showConvertedStringLength() < 3) //если длина строки меньше трёх - выходим из цикла
					break;

				resultOfTheCheckWords = modifiedString.palindrome();//вызвали метод, который вернул нам либо слово, если оно - палиндром, либо -1
				if (resultOfTheCheckWords != "-1")                  //если это слово
					cout << resultOfTheCheckWords << " ";           //то выводим его
			}
			cout << endl;                              //чтобы было красивенько
		}
		else
			return false;
	}
	return 0;
}
