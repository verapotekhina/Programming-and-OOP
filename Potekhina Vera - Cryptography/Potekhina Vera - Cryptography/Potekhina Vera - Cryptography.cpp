#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int num = 0, sum;
	int requests;
	int const n = 1000;
	int i = 0;
	int a[n];
	int pos;
	
	while (num != n)
	{
		sum = 0;
		i++;
		for (int j = 2; j*j <= i; j++)
		{
			if (i % j == 0)
				sum++;
		}

		if (sum==0)
		{
			a[num] = i;	
			num++;
		}	
	}

	cout << "enter number of requests: ";
	cin >> requests;
	int *b = new int[requests];
	for (int i = 0; i < requests; i++)
		cin >> b[i];
	for (int i = 0; i < requests; i++)
	{
		pos = b[i];
		cout << a[pos] << " ";
	}
}
