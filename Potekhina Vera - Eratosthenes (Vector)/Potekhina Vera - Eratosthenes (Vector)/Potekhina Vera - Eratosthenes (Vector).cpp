#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cout << "enter n: ";
	cin >> n;
	vector<bool> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		a[i] = true;
	int j = 0;
	for (int i = 2; i < n; i++)
	{
		if (a[i])
		{
			b[j] = i;
			j++;
			for (int k = i; k < n; k++)
				if 
				a[k] = false;
		}
	}
	for (int i = 0; i < j; i++)
		cout << b[i] << " ";
	return 0;

}

/*void erat(int n, vector<bool> &a, vector<int> &b)
{
	int num = 0;
	for (int i = 2; i < n*n; i++)
		a[i] = true;
	while (num != n)
	{
		

		for (int i = 2; i*i < n; i++)
			if (a[i])
			{
				for (int j = i * i; j < n*n; j += i)
				{
					a[j] = false;
				}
				num++;
				cout << num << " " << i*i << endl;
			}

	}
	for (int i = 2; i < n*n; i++)
	{
		if (a[i])
			b.push_back(i);
	}
}

int main()
{
	int n;

	cout << "enter n: ";
	cin >> n;
	vector<bool> a(n*n);
	vector<int> b(n);
	erat(n, a, b);
	
	for (int i = 0; i < b.size(); i++)
	{
		//if (b[i] != 0)
			cout << b[i] << " ";
	}
		
	cout << endl;
}*/