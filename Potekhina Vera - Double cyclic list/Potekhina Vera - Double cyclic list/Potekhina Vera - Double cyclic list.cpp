#include "pch.h"
#include <iostream>

/*
общая форма списка
имеется:
1)структура - через неё реализуются элементы списка - узлы (node)
	в ней есть:
	информация
	указатель на следующий элемент
	указатель на предыдущий элемент
	после }; имя списка с указателем на голову списка
2) функция добавления элемента
3) функция удаления элемента
4) функция вывода списка
5) int main()
*/

using namespace std;

struct DoubleCyclicList  //структура для элементов списка
{
	int data;               //данные, которые хранит объект
	DoubleCyclicList *next; //указатель на следующий элемент списка
	DoubleCyclicList *prev; //указатель на предыдущий элемент списка
};
DoubleCyclicList *head; //указатель на голову списка
DoubleCyclicList *tail; //указатель на хвост списка


void addNode(int value) //добавление элемента в список
{
	DoubleCyclicList *node = new DoubleCyclicList; //динамически создается объект структуры
	node->next = NULL;   //указатель на следующий элемент указывает на нничего
	node->data = value;  //данным присваивается значение

	if (head != NULL)    //если голова - не ничего, то
	{
		node->prev = tail;  //предыдущим элементом является хвост
		tail->next = node;  //для хвоста следующим является введенный элемент
		tail = node;
	}
	else              //иначе
	{
		node->prev = NULL; //предыдущий элемент - ничего
		head = node; //потому что не поле структуры, голова - сам введенный элемент
		tail = node; //потому что не поле структуры, голова - сам введенный элемент
	}
	cout << "Element is added\n\n";
}

void deleteNode(int position) //удаление элемента
{
	if (head == NULL)    //если в списке пусто
	{ 
		cout << "The list is empty.\n\n"; //говорим, что он пустой
		//return 0;
	}
		
	else if (head == head->next) //если в списке один элемент
	{
		delete head; //удаляем его 
		head = NULL; //голова становится равной ничему
	}
	else   //иначе
	{
		DoubleCyclicList *node = head; //указатель ставим на голову
		for (int i = position; i > 1; i--) 
			node = node->next; //и доходим до заданной позиции
		if (node == head) //если элемент первый
			head = node->next; //- то делаем первым - следующий
		node->prev->next = node->next; //делаем так, чтобы предыдущий ссылался на следующий
		node->next->prev = node->prev; //а следующий - на предыдущий
		delete node; //удаляем элемент
	}
	cout << "Element is deleted\n\n";
}

void showList()
{
	//с начала
	DoubleCyclicList *node = head; //начиная с головы
	while (node != NULL) //пока не ничего (т.е. до конца)
	{
		cout << node->data << " "; //показываем значение элементов
		node = node->next; //и переходим на следующий
	}
	cout << endl;

	//с конца
	node = tail; //начиная с хвоста
	while (node != NULL) //пока не ничего (т.е. до начала)
	{
		cout << node->data << " "; //показываем значение элементов
		node = node->prev;  //и переходим на предыдущий
	}
	cout << endl << "\n\n";
	 
}

void inputValidation(int &input) //проверка ввода
{
	while ((input != 1) && (input != 2) && (input != 3) && (input != 4))
	{
		cout << "Your choice: ";
		cin >> input;
	}
}

void menu() //меню
{
	cout << "Enter 1, if you want add element to the list;" << endl;
	cout << "Enter 2, if you want to see the list;" << endl;
	cout << "Enter 3, if you want delete element to the list;" << endl;
	cout << "To exit, enter 4." << endl;
	cout << "Your choice: ";
}

int main()
{
	int numberOfOptions; 
	while (true) //пока того хочет пользователь - работает
	{
		menu();
		cin >> numberOfOptions;//считывание выбора опции
		inputValidation(numberOfOptions); //проверка ввода
		if (numberOfOptions == 1) //ввести элемент
		{
			int value;
			cout << "Enter value: ";
			cin >> value;
			addNode(value);
		}
		else if (numberOfOptions == 2) //посмотреть список
			showList();
		else if (numberOfOptions == 3) //удались элемент
		{
			int position;
			cout << "Enter position of the deleted element: ";
			cin >> position;
			deleteNode(position);
		}
			
		else
			return false; //выход
	}
	return 0;
}
