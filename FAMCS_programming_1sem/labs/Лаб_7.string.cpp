/*
				Лабораторная №8
Реализовать лабораторную №6 , используя String.

Запуск приложения из командной строки OC Windows.

Общее задание:

Выполнить лабораторную из командной строки( использовать параметры функции main.)

*/


/*
6.4 Разработать программу, которая запрашивает у пользователя 2 строки.
Вторая строка содержит разделители. Разбивает первую строку на лексемы и определяет
в ней целые числа  в 2-й с\с (начинаются с символа b) , 10-й с\с - дробные числа.
Числа из 2-й с\с  переводит в 8-ю с\с  и заменяет их в первоначальной строке.

Формирует из найденных групп чисел новые строки (числа в строках разделяются подчёркиванием).

Сортирует одну из строк методом «подсчёта».

Результат выводит в файл.
*/

/*
выводит:

первая строка: Числа из 2-й с\с  переводит в 8-ю с\с  и заменяет их в первоначальной строке.

вторая строка: Формирует из найденных групп чисел новые строки (числа в строках разделяются подчёркиванием).

*/


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

/*
strcpy
.find_first_of
getline
erase - удаление
substr
find_first_not_of
strtod

atoi
to_string
*/

int revers(int num) // // функция переворачивает int (1234 -> 4321)
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

void main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	string str_first = argv[1];
	string str_leksema = argv[2];
	string for_1;
	string for_2;
	string for_3;
	string s;

	char* for_translation; // из sting -> char
	for_translation = new char[256];
	for_translation[0] = '\0';
	int number_0_1 = 0;
	int num = 0;
	int size = 0;
	unsigned pos1 = 0, pos2;
	short int len_of_str = 0;

	/*cout << "Введите различные!!! элеметны через любой разделитель кроме (.)  (в 2 с/с пример: b11101)\n";
	getline(cin, str_first);

	cout << "\nВведите разделитель (кроме (.)): ";
	getline(cin, str_leksema);*/

	str_first = str_first + str_leksema;

	while ((pos1 = str_first.find_first_not_of(str_leksema, pos1)) != -1)
		//Пока в исходной строке есть символы, отличные от символов–разделителей, выполняем цикл:
	{
		//Выполним в строке str, начиная с позиции pos1, поиск первого разделителя. 
		pos2 = str_first.find_first_of(str_leksema, pos1);
		//Копируем в строку s символы строки str, начиная с позиции pos1, в количестве pos2 – pos1.
		s = str_first.substr(pos1, pos2 - pos1);
		// сейчас в s у нас есть первая лексема
		str_first.erase(0, s.length() + 1);

		if (s.find("b") != -1) // если есть b в строке, то переводим
		{
			strcpy(for_translation, s.c_str());
			number_0_1 = atoi(for_translation);

			for (int j = 0; j < strlen(for_translation) - 1; j++) // удаляем первый элемент в массиве 
			{
				for_translation[j] = for_translation[j + 1];
				if (j == strlen(for_translation) - 2)
				{
					for_translation[j + 1] = '\0';
				}
			}
			number_0_1 = atoi(for_translation);
			num = perevod_v_8(number_0_1);
			for_1 += to_string(num) + ",";
			for_2 += to_string(num) + "_";
			for_3 += to_string(num) + " ";
			size++;
			continue;
		}
		else
		{
			strcpy(for_translation, s.c_str()); // в for_translation у нас s в char
			for (int i = 0; i < strlen(for_translation); i++) // проверка на .
			{
				if (s[i] == '.')
				{
					for_1 += s + ",";
					for_2 += s + "_";
					for_3 += s + " ";
					size++;
				}
				continue;
			}

			bool isd = true;
			char* p = for_translation;
			while (*p)
			{
				if (!isdigit(*p++))
				{
					isd = false;
					break;
				}
			}
			if (isd)
			{
				for_1 += s + ",";
				for_3 += s + " ";
				size++;
			}
		}
	}

	ofstream file;
	file.open("main.txt", ios::app);

	file << "\nПервая строка: " << for_1;
	file << "\nВторая строка: " << for_2;
	file << "\nЧисла, которую мы будем сортировать: " << for_3;

	cout << "\nПервая строка: " << for_1;
	cout << "\nВторая строка: " << for_2;
	cout << "\nЧисла, которую мы будем сортировать: " << for_3;

	char* pch;
	strcpy(for_translation, for_3.c_str());
	int* arr = new int[size];
	int* arr_2 = new int[size];
	int x = 0;

	pch = strtok(for_translation, " ");	// Функция strtok выполняет поиск лексем в строке string
	while (pch != NULL)
	{
		int full = atoi(pch);
		arr[x] = full;
		pch = strtok(NULL, " "); // берет следующее значение в строке
		++x;
	}

	methodOfCalculation(size, arr, arr_2);
	cout << "\nОтсортированные числа: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr_2[i] << " ";
		file << arr_2[i] << " ";
	}
	file.close();
	//сортировка методом подсчета
}