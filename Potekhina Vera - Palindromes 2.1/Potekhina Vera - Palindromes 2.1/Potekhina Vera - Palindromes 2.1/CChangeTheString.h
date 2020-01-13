#pragma once
#include <string>

using namespace std;

//заголовочный файл класса преобразования строки к нормальному виду

class CChangeTheString
{
private:
	string userString;                      //строка, введенная пользователем
	int stringLength;                       //длина строки

public:
	CChangeTheString(string inputString);
	void replacePunctuationMarks();
	void removeExtraSpaces();
	void changeCase();
	string showUserString();
};