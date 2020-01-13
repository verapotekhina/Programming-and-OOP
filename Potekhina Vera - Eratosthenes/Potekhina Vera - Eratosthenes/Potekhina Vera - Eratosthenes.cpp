#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "enter n: ";
	cin >> n;
	bool *a = new bool[n];
	for (int i = 2; i < n; i++)
		a[i] = true;

	for (int i = 2; i*i < n; i++)
		if (a[i])
		{
			for (int j = i*i; j < n; j += i)
			{
				a[j] = false;
			}
		}
	for (int i = 2; i < n; i++)
	{
		if (a[i])
			cout << i << endl;
	}
		 
}

