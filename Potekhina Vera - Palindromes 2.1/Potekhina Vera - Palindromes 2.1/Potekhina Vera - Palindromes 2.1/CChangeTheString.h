#pragma once
#include <string>

using namespace std;

//������������ ���� ������ �������������� ������ � ����������� ����

class CChangeTheString
{
private:
	string userString;                      //������, ��������� �������������
	int stringLength;                       //����� ������

public:
	CChangeTheString(string inputString);
	void replacePunctuationMarks();
	void removeExtraSpaces();
	void changeCase();
	string showUserString();
};