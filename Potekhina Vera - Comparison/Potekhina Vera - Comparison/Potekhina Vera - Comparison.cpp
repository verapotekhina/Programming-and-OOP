#include "stdafx.h"
#include <iostream>

using namespace std;


void comp(int x, int y)
{
	if (x > y)
		cout << "a more b" << endl;
	else if (x < y)
		cout << "b more a" << endl;
	else if (x == y)
		cout << "a and b are equal" << endl;
}

int main()
{
	int a, b;
	cout << "Enter a and b: ";
	cin >> a >> b;
	while ((a != 0) && (a != b))
	{
		comp(a, b);
		cout << "Enter a and b: ";
		cin >> a >> b;
	}
    return 0;
}

