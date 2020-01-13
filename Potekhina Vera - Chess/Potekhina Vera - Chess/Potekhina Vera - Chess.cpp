#include "pch.h"
#include <iostream>
#include <fstream>

/*
48 = код 0
97 = код a
a b c d e f g h
0 1 2 3 4 5 6 7

1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7

шахматная доска 8 на 8
три фигуры - ферзь, ладья, конь
ферзь - вертикаль, диагональ, горизонталь
ладья - вертикаль, горизонталь
конь - две прямо, одна в сторону и одна прямо, две в сторону

посчитать количество пустых полей, которые находятся под ударом

есть текстовый файл input.txt - в нем через пробел координаты фигур
создать файл output.txt - c ответом

пример 
вход
d1 d3 e5
выход 
29
*/
using namespace std;

void parsingInput(int number, char string[], int &coordX, int &coordY)
{
	int *X = &coordX; 
	int *Y = &coordY;

	for (int k = 1, i = 0; k < 3 * number - 1; k += number, i++)
	{
		X[i] = string[k] - 49; //не 48, потому что нам надо нумерацию с нуля - столбцы
	}

	for (int k = 0, i = 0; k < 3 * number - 1; k += number, i++)
	{
		Y[i] = string[k] - 97; //строчки
	}
}

int main()
{
	const int sizeField = 8, numberOfShapes = 3; //размерность поля
	int chessBoard[sizeField][sizeField]; //игровое поле
	int coordinateX[numberOfShapes]; //массив координат х фигур
	int coordinateY[numberOfShapes]; //массив координат y фигур
	char userString[3*numberOfShapes]; //строчка пользователя из файла - я не знаю, почему оно работает только с указанием, что символов в строке n+1, при реальных n
	int counter;

	for (int i  = 0; i < sizeField; i++) //заполняем поле нулями
		for (int j = 0; j < sizeField; j++)
		{
			chessBoard[i][j] = 0;
		}

	ifstream inputFile("INPUT.txt");
	inputFile.getline(userString, 3 * numberOfShapes); //считывание строки из файла

	parsingInput(numberOfShapes, userString, *coordinateX, *coordinateY);

	for (int i = 0; i < numberOfShapes; i++) //присваиваем местам, где стоят фигуры единицы
	{
		chessBoard[coordinateX[i]][coordinateY[i]] = 1;
	}
	
	//для ферзя
	//горизонталь, т.е. она фиксирована
	for (int i = 0; i < sizeField; i++)
		if (chessBoard[i][coordinateY[0]] == 0)
			chessBoard[i][coordinateY[0]] = 2;
	//вертикаль, т.е. она фиксирована
	for (int i = 0; i < sizeField; i++)
		if (chessBoard[coordinateX[0]][i] == 0)
			chessBoard[coordinateX[0]][i] = 2;
	//диагональ
	
	for (int i = coordinateX[0], j = coordinateY[0]; i < sizeField, j < sizeField; ++i, ++j)
		if (chessBoard[i][j] == 0)
			chessBoard[i][j] = 2;

	for (int i = coordinateX[0], j = coordinateY[0]; i < sizeField, j >= 0; i++, j--)
		if (chessBoard[i][j] == 0)
			chessBoard[i][j] = 2;
	
	for (int i = coordinateX[0], j = coordinateY[0]; i >= 0, j < sizeField; i--, j++)
		if (chessBoard[i][j] == 0)
			chessBoard[i][j] = 2;

	for (int i = coordinateX[0], j = coordinateY[0]; i >= 0, j >= 0; i--, j--)
		if (chessBoard[i][j] == 0)
			chessBoard[i][j] = 2;
	

	//для ладьи
	//горизонталь, т.е. она фиксирована
	for (int i = 0; i < sizeField; i++)
		if (chessBoard[i][coordinateY[1]] == 0)
			chessBoard[i][coordinateY[1]] = 2;
	//вертикаль, т.е. она фиксирована
	for (int i = 0; i < sizeField; i++)
		if (chessBoard[coordinateX[1]][i] == 0)
			chessBoard[coordinateX[1]][i] = 2;

	//для коня - просто суть расскажу 
	//выставляла для каждой строчки, учитывая граничные случаи
	if (coordinateX[2] - 2 >= 0)
	{
		if ((coordinateY[2] + 1 >= 0) && (chessBoard[coordinateX[2] - 2][coordinateY[2] + 1] != 1))
		{
			chessBoard[coordinateX[2] - 2][coordinateY[2] + 1] = 2;
		}
		if ((coordinateY[2] - 1 < sizeField) && (chessBoard[coordinateX[2] - 2][coordinateY[2] - 1] != 1))
		{
			chessBoard[coordinateX[2] - 2][coordinateY[2] - 1] = 2;
		}
	}

	if (coordinateX[2] - 1 >= 0)
	{
		if ((coordinateY[2] + 2 >= 0) && (chessBoard[coordinateX[2] - 1][coordinateY[2] + 2] != 1))
		{
			chessBoard[coordinateX[2] - 1][coordinateY[2] + 2] = 2;
		}
		if ((coordinateY[2] - 2 < sizeField) && (chessBoard[coordinateX[2] - 1][coordinateY[2] - 2] != 1))
		{
			chessBoard[coordinateX[2] - 1][coordinateY[2] - 2] = 2;
		}
	}
	
	if (coordinateX[2] + 1 < sizeField)
	{
		if ((coordinateY[2] + 2 >= 0) && (chessBoard[coordinateX[2] + 1][coordinateY[2] + 2] != 1))
		{
			chessBoard[coordinateX[2] + 1][coordinateY[2] + 2] = 2;
		}
		if ((coordinateY[2] - 2 < sizeField) && (chessBoard[coordinateX[2] + 1][coordinateY[2] - 2] != 1))
		{
			chessBoard[coordinateX[2] + 1][coordinateY[2] - 2] = 2;
		}
	}
	
	if (coordinateX[2] + 2 < sizeField)
	{
		if ((coordinateY[2] + 1 >= 0) && (chessBoard[coordinateX[2] + 2][coordinateY[2] + 1] != 1))
		{
			chessBoard[coordinateX[2] + 2][coordinateY[2] + 1] = 2;
		}
		if ((coordinateY[2] - 1 < sizeField) && (chessBoard[coordinateX[2] + 2][coordinateY[2] - 1] != 1))
		{
			chessBoard[coordinateX[2] + 2][coordinateY[2] - 1] = 2;
		}
	}

	counter = 0;
	for (int i = 0; i < sizeField; i++) //просмотр доски - потому что красивенько
	{
		for (int j = 0; j < sizeField; j++)
		{
			cout << chessBoard[i][j] << " ";
			if (chessBoard[i][j] == 2)  //и подсчёт всех полей под боем
				counter++;
		}
		cout << endl;
	}
	cout << endl << counter; //можно закомментировать, но просто мне лениво файл проверять

	ofstream outputFile("OUTPUT.txt");
	outputFile << counter; //запись в файл
}
