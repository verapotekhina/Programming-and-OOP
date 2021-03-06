#include "pch.h"
#include <iostream>

using namespace std;

/*
Бинарный поиск с сортировкой рандомно генерирующегося массива из чисел до 100 с заданным количеством элементов
Сортировка пузырьком (исправить бы)
*/

void Sort(int *a, int n) 
{
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < (n - i - 1); j++)
			if (a[j] > a[j + 1])
			{
				int c = a[j];
				a[j] = a[j + 1];
				a[j + 1] = c;
			}
	}
}

/*int Search(int n, int x, int *a)
{
	int left = 0;
	int right = n - 1;
	int middle = right;
	while ((x != a[middle])&&(left < right))
	{
		if (x > a[middle])
		{
			left = middle + 1;
		}
		else
			right = middle - 1;
		middle = (right + left) / 2;
	}
	if (x == a[middle])
		return middle;
	else
		return -1;
}*/
int Search(int n, int x, int* a)
{
	int left = -1;
	int right = n;
	int middle = (right + left) / 2;
	while ((x != a[middle]) && (left < right-1))
	{
		if (x > a[middle])
		{
			left = middle;
		}
		else
			right = middle;
		middle = (right + left) / 2;
	}
	if (x == a[middle])
		return middle;
	else
		return left;
}

int main()
{
	int number;
	
	int key;
	cout << "Enter	number of elements in array: ";
	cin >> number;
	
	int *arr = new int[number];
	cout << "Array element: ";
	for (int i = 0; i < number; i++)
	{
		arr[i] = rand() % 100;
		cout << arr[i] << ' ';
	}

	cout << "\nSort: ";
	Sort(arr, number);
	for (int i = 0; i < number; i++)
		cout << arr[i] << ' ';
	
	cout <<"\nEnter x: ";
	cin >> key;
	
	int find = Search(number, key, arr);
	if (find != -1)
		cout << "Index: " << find << "; nubmer: " << find + 1;
	else
		cout << "This key is missing in array.";
	return 0;
}