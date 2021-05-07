#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
//#include "Header.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

struct employee
{
	char name[255];
	int TSUM;
	int SUM;
	int RSUM;
	int SUMD;

};


int compare(const void* x1, const void* x2) // нужно для qsort
{
	return ((struct employee*)x1)->SUM - ((struct employee*)x2)->SUM;
}

void SLVE(int SUM, int TSUM, int PRC, int &RSUM, int &SUMD)
{
	RSUM = SUM * (1 + PRC / 100);
	SUMD = RSUM - TSUM;
}

void Print(struct employee* employees, int num) // вывод
{
	
	for (int i = 0; i < num; i++)
	{
		cout << employees[i].name << " - " << employees[i].TSUM << " - " << employees->SUM << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	struct employee employees[20];
	int num_employees = 0;

	char* pch;

	char str[80]; // промежуточная строка для хранения

	
	int ALLSUM = 0;;
	int persent = 0;

	char line[50];

	// 1 *****************************

	ifstream file;
	file.open("Spisok.txt");

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return 0;
	}
	cout << "Файл Spisok.txt открыт!" << endl;
	file.getline(line, 10);
	ALLSUM = atoi(line);
	file.getline(line, 10);
	persent = atoi(line);

	while (file.getline(line, 255))
	{
		int i = 0;
		pch = strtok(line, " ");
		while (pch != NULL)
		{
			if (i ==1)
			{
				strcat(employees[num_employees].name, pch);
				i++;
			}
			else if (i == 0)
			{
				strcpy(employees[num_employees].name, pch); // вырезает ее
				strcat(employees[num_employees].name, " "); // добавляет строку

				i++;
			}
			else if (i == 2)
			{
				employees[num_employees].TSUM = atoi(pch);
				i++;
			}
			else if (i == 3)
			{

				employees[num_employees++].SUM = atoi(pch);
				i++;
			}
			pch = strtok(NULL, " ");
		}
	}
	
	file.close();

	Print(employees, num_employees);

	// 2 *****************************

	qsort(employees, num_employees, sizeof(struct employee), compare);

	// 3 *****************************
	// void SLVE(int SUM, int TSUM, int PRC, int &RSUM, int &SUMD)

	for (int i = 0; i < num_employees; i++)
	{
		SLVE(employees[i].SUM, employees[i].TSUM, persent , employees[i].RSUM, employees[i].SUMD);
	}
	// 4 *****************************

}
