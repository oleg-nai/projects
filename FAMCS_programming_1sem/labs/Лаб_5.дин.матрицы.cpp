#include <iostream>
#include <time.h>
#include <cstdlib> 	
/*
5.4. Разработать программу, запрашивающую у пользователя матрицу размером MxN.
Выполнить поворот ее на 90 против часовой стрелки.
Размерность матрицы  считать с консоли,  элементы матрицы - случайным образом. Результаты вывести на консоль. 
Элементы матрицы вещественные числа.
*/

// m - горизонталь
// n - вертикаль	

using namespace std;


void povorot(int** arr, int n, int m)
{
	int** mas;

	mas = new int* [m]; // создаем новый массив для последующего его удаления
	for (int i = 0; i < m; i++)
	{
		mas[i] = new int[n];
	}


	// ДОПИСАТЬ ТУТ КОД, ПОООООВОРОТ
	for (int i = 0, k = 0; i < m; i++, k++) 
	{
		for (int j = 0, b = 0; j < n; j++, b++)
		{
			mas[i][j] = arr[b][k];
		}
	}

	int tmp;

	for (int i = 0, l = m-1; i < m/2; i++, l--) // ЗАМЕТИМ, ЧТО L = M - 1 !!!!
	{
		for (int j = 0, x = 0; j < n; j++, x++)
		{
			tmp = mas[i][j];
			mas[i][j] = mas[l][x];
			mas[l][x] = tmp;
		}
	}

	cout << "\n====================================\n";

	for (int i = 0; i < m; i++) // вывод матрицы
	{
		for (int j = 0; j < n; j++)
		{
			cout << mas[i][j] << "\t";
		}
		cout << endl;
	}

	delete [] mas;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int** arr;
	int n, m;
	cout << "горизонталь - N: "; cin >> n;
	cout << endl << "вертикаль - M: "; cin >> m;
	cout << "\n====================================\n";

	arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 100; // от 0 до 100
		}
	}

	for (int i = 0; i < n; i++) // вывод матрицы
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	povorot(arr, n, m);	
}