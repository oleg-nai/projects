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

struct gift
{
	char* name;
	float price;
};
struct List
{
	gift a;
	List* next;
};

float SB = 0, SP = 0, NSP = 0;
//int kol_vo_gift;
//int kol_vo_brak;

void Init_for_DisCount(List** begin, string filesname, int &kol_vo)
{
	kol_vo = 0;
	(*begin) = new List;
	(*begin)->next = NULL;
	List* sled = new List;
	sled = (*begin);

	string path = filesname;

	char* line = new char[250];
	line[0] = '\0';

	char* pch;
	char* for_save;
	char* name_for_struct = new char[255];
	name_for_struct[0] = '\0';
	float price_for_struct = 0;

	ifstream file;
	file.open(path);

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла, проверьте наличие файла в папке!" << endl;
		return;
	}
	else
	{
		cout << "Файл " << filesname << " открыт!" << endl;
		while (file.getline(line, 255)) // в line у нас вся строка
		{
			kol_vo++;
			pch = strtok(line, " -_:");
			while (pch != NULL)
			{
				for_save = pch;
				pch = strtok(NULL, " -_:"); // берет следующее значение в строке
				if (pch == NULL)
				{
					price_for_struct = atof(for_save);
					name_for_struct[strlen(name_for_struct) - 1] = '\0';
				}
				else
				{
					name_for_struct = strcat(name_for_struct, for_save);
					name_for_struct = strcat(name_for_struct, "_");
				}
			}
			char* name = new char[250];
			name[0] = '\0';

			strcat(name, name_for_struct);
			sled->a.name = name;
			sled->a.price = price_for_struct;

			if (file.eof()) // если пустой
			{
				sled->next = NULL;
				break;
			}

			sled->next = new List;
			sled = sled->next;
			sled->next = NULL;

			name_for_struct[0] = '\0';
			price_for_struct = 0;
		}
		sled = NULL;
	}
	file.close();
}

void Init(List** begin, string filesname, int &kol_vo)
{
	(*begin) = new List;
	(*begin)->next = NULL;
	List* sled = new List;
	sled = (*begin);

	string path = filesname;

	char* line = new char[250];
	line[0] = '\0';

	char* pch;
	char* for_save;
	char* name_for_struct = new char[255];
	name_for_struct[0] = '\0';
	float price_for_struct = 0;

	ifstream file;
	file.open(path);

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла, проверьте наличие файла в папке!" << endl;
		return;
	}
	else
	{
		cout << "Файл " << filesname << " открыт!" << endl;
		file.getline(line, 4);
		kol_vo = atoi(line);
		while (file.getline(line, 255)) // в line у нас вся строка
		{
			pch = strtok(line, " -_:");
			while (pch != NULL)
			{
				for_save = pch;
				pch = strtok(NULL, " -_:"); // берет следующее значение в строке
				if (pch == NULL)
				{
					price_for_struct = atof(for_save);
					name_for_struct[strlen(name_for_struct) - 1] = '\0';
				}
				else
				{
					name_for_struct = strcat(name_for_struct, for_save);
					name_for_struct = strcat(name_for_struct, "_");
				}
			}

			char* name = new char[250];
			name[0] = '\0';

			strcat(name,name_for_struct);
			sled->a.name = name;
			sled->a.price = price_for_struct;

			if (file.eof()) // если пустой
			{
				sled->next = NULL;
				break;
			}

			sled->next = new List;
			sled = sled->next;
			sled->next = NULL;

			name_for_struct[0] = '\0';
			price_for_struct = 0;
		}
		sled = NULL;
	}
	file.close();
}

void Print(List* s) // вывод
{
	List* print = s;
	while (print)
	{
		cout << "\nИмя: " << print->a.name << endl;
		cout << "Номер: " << print->a.price << endl;
		cout << "\n";
		print = print->next;
	}
}

void Sort(List** begin, int kol_vo) // Сортировка списка по первому элементу структуры.
{
	float num;
	char* name;
	for (int i = 0; i < kol_vo; i++)
	{
		List* t = *begin;
		List* t1 = t->next;
		while (t1 != NULL)
		{
			if (strcmp(t->a.name, t1->a.name) > 0)
			{
				num = t->a.price;
				name = t->a.name;
				t->a.name = t1->a.name;
				t1->a.name = name;
				t->a.price = t1->a.price;
				t1->a.price = num;
			}
			t = t->next;
			t1 = t->next;
		}
	}
}

void Sort_po_price(List** begin, int kol_vo) // Сортировка списка по первому элементу структуры.
{
	float num;
	char* name;
	for (int i = 0; i < kol_vo; i++)
	{
		List* t = *begin;
		List* t1 = t->next;
		while (t1 != NULL)
		{
			if (t1->a.price > t->a.price)
			{
				num = t->a.price;
				name = t->a.name;
				t->a.name = t1->a.name;
				t1->a.name = name;
				t->a.price = t1->a.price;
				t1->a.price = num;
			}
			t = t->next;
			t1 = t->next;
		}
	}
}

void Vivod_V_File(List** begin, int kol_vo, string filesname)
{
	List* t = (*begin);
	int kol_vo_2 = kol_vo;

	ofstream file;
	string path = filesname;

	file.open(path, ofstream::app);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	while (kol_vo_2)
	{
		file << t->a.name << " " << t->a.price << "\n";
		kol_vo_2--;
		t = t->next;
	}
	file.close();
}

int FSum(List* begin, float &Sum)
{
	if (begin == NULL)
	{
		cout << "цена всех gift: " << Sum << "\n\n";
		return Sum;
	}
	else
	{
		Sum += begin->a.price;
		begin = begin->next;
		FSum(begin, Sum);
	}
}

void Delete(List** begin_gift, List* begin_brak, List* begin_DisCount)
{
	char* name_to_delete;

	List* sled_begin_DisCount= new List;
	sled_begin_DisCount = begin_DisCount;

	List* sled_begin_gift = new List;
	sled_begin_gift = (*begin_gift);

	name_to_delete = begin_brak->a.name;

	while (begin_brak != NULL)
	{
		while (sled_begin_gift != NULL)
		{
			if (strcmp(sled_begin_gift->a.name, name_to_delete) == 0)
			{
				SB += sled_begin_gift->a.price;
				while (sled_begin_DisCount)
				{
					if (sled_begin_gift->a.price > sled_begin_DisCount->a.price)
					{
						sled_begin_gift->a.name = sled_begin_DisCount->a.name;
						sled_begin_gift->a.price = sled_begin_DisCount->a.price;
						break;
					}
					else
					{
						if (sled_begin_DisCount->next == NULL)
						{
							sled_begin_gift->a.name = sled_begin_DisCount->a.name;
							sled_begin_gift->a.price = sled_begin_DisCount->a.price;
							break;
						}
						sled_begin_DisCount = sled_begin_DisCount->next;
					}
				}
			}
			else
			{
			}
			sled_begin_gift = sled_begin_gift->next;
			sled_begin_DisCount = begin_DisCount;
		}
		begin_brak = begin_brak->next;
		if (begin_brak == NULL)
			break;
		name_to_delete = begin_brak->a.name;
		sled_begin_gift = (*begin_gift);
	}
}

void bsearch_by_myself(List* begin_gift, float person_price)
{
	while (begin_gift)
	{
		if (begin_gift->a.price == person_price)
		{
			cout << "Название продукта: "  <<  begin_gift->a.name << endl;
			cout << "Название продукта: " << begin_gift->a.price << endl;
		}
		begin_gift = begin_gift->next;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	// 1 *************************************************
	List* begin_gift = new List;
	begin_gift->next = NULL;

	int kol_vo_gift;
	int kol_vo_brak;

	Init(&begin_gift, "Gift.txt", kol_vo_gift);

	Print(begin_gift);

	// 2 *************************************************

	List* begin_brak = new List;
	begin_brak->next = NULL;

	cout << "***************************\nБракованные вещи:" << endl;
	Init(&begin_brak, "Brak.txt", kol_vo_brak);
	Print(begin_brak);

	// 3 *************************************************

	cout << "***************************\nОтсортированные вещи gift:" << endl;
	Sort(&begin_gift, kol_vo_gift); // сортировка по названию 
	Print(begin_gift);
	cout << "\n\n" << "отсортированные бракованные вещи: " << endl;

	Sort(&begin_brak, kol_vo_gift); // сортировка по названию 
	Print(begin_brak);

	ofstream file;
	file.open("SortGift.txt");
	file << "gift не бракованные вещи: " << "\n";
	file.close();

	Vivod_V_File(&begin_gift, kol_vo_gift, "SortGift.txt"); // ввод в файл

	file.open("SortGift.txt", ofstream::app);
	file << "\n\n" << "Бракованные вещи: " << "\n";
	file.close();
	Vivod_V_File(&begin_brak, kol_vo_brak, "SortGift.txt");

	// 4 *************************************************

	float S = 0;
	//float Sum_1 = 0;

	FSum(begin_gift, S);
	cout << "\nS - " << S << endl;
	// 5 *************************************************

	List* begin_DisCount = new List;
	begin_DisCount->next = NULL;
	int kol_vo_Discount = 0;
	
	Init_for_DisCount(&begin_DisCount, "DisCount.txt", kol_vo_Discount);
	cout << "\n\n" << "ДО сортировки dis" << endl;
	Print(begin_DisCount);
	Sort_po_price(&begin_DisCount, kol_vo_Discount);
	cout << "\n\n" << "после сортировки dis" << endl;
	Print(begin_DisCount);

	// 6 *************************************************

	Delete(&begin_gift, begin_brak, begin_DisCount);
	cout << "Вывести замененные продукты \n\n";
	Print(begin_gift);

	// 7 *************************************************
	float Sum_after = 0;
	FSum(begin_gift, Sum_after);

	// 8 *************************************************
	SP = S - SB;
	NSP = SB - S + Sum_after;

	cout << "S - " << S << endl;
	cout << "SB - " << SB << endl;
	cout << "SP - " << SP << endl;
	cout << "NSP - " << NSP << endl;
	cout << "Sum_after - общая потраченная " << Sum_after << endl;
	cout << "остаток диняк " << S - Sum_after << endl;
	

	file.open("NewGift.txt");
	file << "S - " << S << endl;
	file << "SB - " << SB << endl;
	file << "SP - " << SP << endl;
	file << "NSP - " << NSP << endl;
	file << "Sum_after - общая потраченная " << Sum_after << endl;
	file << "остаток диняк " << S - Sum_after << "\n\n";
	file.close();

	file.open("NewGift.txt", ofstream::app);
	Vivod_V_File(&begin_gift, kol_vo_gift, "NewGift.txt");
	file.close();
	// 9 *************************************************
	float person_price =0;
	cout << "Введите цену, которуе вы хотите найти: ";
	cin >> person_price;
	bsearch_by_myself(begin_gift, person_price);
}