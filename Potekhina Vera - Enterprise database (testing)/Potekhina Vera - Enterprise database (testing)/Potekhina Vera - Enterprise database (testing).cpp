#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CWorker
{
private:
	string name;
	int age;

public:
	CWorker(string inputFullName, int inputAge)
	{
		name = inputFullName;
		age = inputAge;
	}

	CWorker()
	{
		name = " ";
		age = -1;
	}

	string showName()
	{
		return name;
	}
	int showAge()
	{
		return age;
	}

};

int main()
{
	string name1, name2;
	int age1, age2;

	cout << "enter name1, age1: ";
	cin >> name1;
	cin >> age1;

	cout << "enter name2, age2: ";
	cin >> name2;
	cin >> age2;

	CWorker worker1(name1, age1), worker2(name2, age2), foundWorker;

	ofstream outFile("Employee data base.dat", ios::binary); //для записи
	outFile.write(reinterpret_cast<char*>(&worker1), sizeof(worker1)); //записали объект в файл
	outFile.write(reinterpret_cast<char*>(&worker2), sizeof(worker2)); //записали объект в файл
	outFile.close();

	ifstream inFile("Employee data base.dat", ios::binary); //для чтения
	while(inFile)
	{
		inFile.read(reinterpret_cast<char*>(&foundWorker), sizeof(CWorker));
		cout << foundWorker.showName() << endl;
		cout << foundWorker.showAge() << endl;
	} 
	outFile.close();
	return 0;
}