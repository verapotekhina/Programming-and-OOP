#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "enter n: ";
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i*2;
		cout << a[i] << " ";
	}
}