/*
6.4 Разработать программу, которая запрашивает у пользователя 2 строки.
Вторая строка содержит разделители. Разбивает первую строку на лексемы и определяет
в ней целые числа  в 2-й с\с (начинаются с символа b) , 10-й с\с - дробные числа.
Числа из 2-й с\с  переводит в 8-ю с\с  и заменяет их в первоначальной строке.

Формирует из найденных групп чисел новые строки (числа в строках разделяются подчёркиванием).

Сортирует одну из строк методом «подсчёта».

Результат выводит в файл.
*/

#include <iostream>
#include <cstring>
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;


int perevod_v_int(char* a1)
{
	int a = 0;
	for (int i = 0; i < strlen(a1); i++)
	{
		a = a * 10;
		a += a1[i] - '0';
	}
	return a;
}

int revers(int num)
{
	int reversedNumber = 0, remainder;
	int n = num;
	while (n != 0)
	{
		remainder = n % 10;
		reversedNumber = reversedNumber * 10 + remainder;
		n /= 10;
	}
	return reversedNumber;
}


int perevod_v_8(int num)
{
	int a = num;
	int b = 0;
	int result = 0;
	while (num != 0)
	{
		a = num % 10;
		num = num / 10;
		if (b == 0)
			b = 1;
		if (b != 0)
			a *= b;
		result += a;
		b *= 2;
	}
	int result_2 = result;
	int lengh = 0;
	// в resolt у нас 10-тиричное число
	while (result_2 != 0) // определяем длину числа
	{
		result_2 /= 10;
		lengh += 1;
		if (result_2 == 0)
			break;
	}

	// lengh - длинна числа
	int* mas;
	mas = new int[lengh];
	for (int i = 0; i < lengh; i++)
	{
		mas[i] = result % 8;
		result = result / 8;
	}
	result = 0;
	for (int i = 0; i < lengh; i++)
	{
		if (mas[i] == 0)
		{
			result = 10;
		}
		result += mas[i];
		if (i == lengh - 1)
			break;
		result *= 10;
	}

	result = revers(result); // функция переворачивает int (1234 -> 4321)
	// resolt - это число в 8-ричной системе счисления
	return result;
}

//сортировка методом подсчета
void methodOfCalculation(int n, int mass[], int sortedMass[])
{
	int k;
	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < n; j++)
		{
			if (mass[i] > mass[j])
				k++;
		}
		sortedMass[k] = mass[i];
	}
}


int main()
{
	setlocale(LC_ALL, "rus");

	int size = 0;

	char* str1;
	char* str2;

	str1 = new char[256];
	str2 = new char[256];

	cout << "Введите элеметны через любой разделитель кроме (.) (в 2 с\с как b11101)\n";
	cin.getline(str1, 256);
	cout << "\nВведите разделитель: ";
	cin.getline(str2, 256);

	char* str_1; // для второй строки
	char* str_2; // для второй строки

	str_1 = new char[256];

	for (int i = 0; i < strlen(str1); i++) // копирует из str1 в str_1 именно так, а не str_1 = str1
	{
		str_1[i] = str1[i];
		if (i == strlen(str1) - 1)
		{
			str_1[i + 1] = '\0';
		}
	}

	str_2 = str2;


	char* str_3; // для 1 строки
	char* str_4; // для 2 строки
	char* str_5; // для сортировки

	str_3 = new char[256];
	str_4 = new char[256];
	str_5 = new char[256];

	str_3[0] = '\0'; // чтобы он не был заполнен мусором
	str_4[0] = '\0'; // чтобы он не был заполнен мусором
	str_5[0] = '\0'; // чтобы он не был заполнен мусором

	char* pch;


	pch = strtok(str1, str2);	// Функция strtok выполняет поиск лексем в строке string

	ofstream out; // поток для записи
	out.open("main.txt"); // окрываем файл для записи

	while (pch != NULL)			// пока есть лексемы
	{
		for (int i = 0; i < strlen(pch); i++)
		{
			if (pch[i] == '.')
			{
				strcat(str_4, pch);
				strcat(str_4, "_");
			}
		}
		for (int i = 0; i < strlen(pch); i++)
		{
			if (pch[i] == 'b' && (pch[i + 1] == '1' || pch[i + 1] == '0')) // если b10010
			{
				char* pch_2 = 0;
				pch_2 = new char[256];

				for (int j = 0; j < strlen(pch) - 1; j++) // удаляем первый элемент в массиве 
				{
					pch_2[j] = pch[j + 1];
					if (j == strlen(pch) - 2)
					{
						pch_2[j + 1] = '\0';
					}
				}

				int num = 0;
				char* num_char;
				num_char = new char[256];
				num = atoi(pch_2); // atoi переводит из char в int 
			   //num = perevod_v_int(pch_2); // переводит из char в int
				num = perevod_v_8(num); // переводит из 2-чной в 8-ричную
				sprintf(num_char, "%d", num);// переводит из int в char

				str_3 = strcat(str_3, num_char); // склеивает строки
				strcat(str_3, ","); // добавляет лексему

				str_4 = strcat(str_4, num_char);
				strcat(str_4, "_");

				str_5 = strcat(str_5, num_char);
				strcat(str_5, " ");
				size++;
				break;
			}

			else if (pch[i] == 'b' && (pch[i + 1] != 1 || pch[i + 1] != 0)) // если b5125, это проверка на b в начале слова babuska
			{
				str_3 = strcat(str_3, pch);
				strcat(str_3, ",");


				// перекидываем pch в 1 строку
				break;
			}
			else if (pch[i] == '.') // здесь фича для дробных чилес, просто их перекидываем в 2 (там где _) и 1 строки
			{
				str_3 = strcat(str_3, pch);
				strcat(str_3, ",");

				str_4 = strcat(str_4, pch);
				strcat(str_4, "_");
				break;
			}
			else // весь остальной шлак
			{
				str_3 = strcat(str_3, pch);
				strcat(str_3, ",");

				str_5 = strcat(str_5, pch);
				strcat(str_5, " ");
				size++;
				break;
				// перекидываем в 1 строку
			}
		}
		pch = strtok(NULL, str2); // берет следующее значение в строке
	}







	int len = strlen(str_3); // нужно для удаление . или _ в конце строки
	str_3[len - 1] = '\0';
	cout << "Первая строка: " << str_3;
	cout << "\n";

	out << str_3 << "\n";

	int len_2 = strlen(str_4); // нужно для удаление . или _ в конце строки
	str_4[len_2 - 1] = '\0';
	cout << "Вторая строка: " << str_4;
	cout << "\n";

	out << str_4 << "\n";

	int len_3 = strlen(str_5); // нужно для удаление . или _ в конце строки
	str_5[len_3 - 1] = '\0';

	cout << "Числа, которую мы будем сортировать: " << str_5 << "\n";



	int* arr;
	arr = new int[size];// ТУТ ПРОБЛЕМА С ПРАВИЛЬНЫМ ВЫДЕЛЕНИЕМ ПАМЯТИ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//ПОРЕШАТЬ С УЧИЛКОЙ!!!!!!!!!!!!!

	int* arr_2;
	arr_2 = new int[size]; // ТУТ ПРОБЛЕМА С ПРАВИЛЬНЫМ ВЫДЕЛЕНИЕМ ПАМЯТИ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	int x = 0;

	pch = strtok(str_5, " ");	// Функция strtok выполняет поиск лексем в строке string
	while (pch != NULL)
	{
		int full = atoi(pch);
		arr[x] = full;

		pch = strtok(NULL, " "); // берет следующее значение в строке
		++x;
	}

	// в arr у нас сейчас массив из элементов, которые нужно отсортировать

	methodOfCalculation(size, arr, arr_2);
	for (int i = 0; i < size; i++)
	{
		cout << arr_2[i] << " ";
	}
	out << "\n" << arr_2;
	out.close();
}

//
////сортировка методом подсчета
//void methodOfCalculation(int n, int mass[], int sortedMass[])
//{
//	int k;
//	for (int i = 0; i < n; i++)
//	{
//		k = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (mass[i] > mass[j])
//				k++;
//		}
//		sortedMass[k] = mass[i];
//	}
//}
//
//// strcut strcpu