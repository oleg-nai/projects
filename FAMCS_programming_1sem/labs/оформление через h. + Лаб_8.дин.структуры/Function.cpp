#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int kol_vo = 0;


void Init(List** begin) // считывание с файла, инициализация
{
	(*begin) = new List;
	(*begin)->next = NULL;
	List* sled = new List;
	sled = (*begin);

	ifstream file;
	string path = "main.txt";
	file.open(path);

	string line;
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	else
	{
		while (getline(file, line))
		{
			kol_vo++;
			string name;
			int num;

			istringstream iss(line);//Создадим поток для считывания данных из строчки

			iss >> name >> num;		//Теперь через стандартный оператор >> считаем данные
									//Программа сама поймет что в качестве разделителя надо
			char* str = new char[name.length() + 1];
			strcpy(str, name.c_str()); // т.к. у нас в struct char, то переведем string -> char*
			sled->a.name = str;
			sled->a.phone = num;
			if (file.eof()) // если пустой
			{
				sled->next = NULL;
				break;
			}
			sled->next = new List;
			sled = sled->next;
			sled->next = NULL;
		}
		sled = NULL;
	}
	file.close();
}

void Vivod_V_File(List** begin)
{
	List* t = (*begin);
	int kol_vo_2 = kol_vo;
	ofstream file;
	string path = "vivod.txt";
	file.open(path);
	if (!file.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	while (kol_vo_2)
	{
		file << t->a.name << "\n" << t->a.phone << "\n\n";
		kol_vo_2--;
		t = t->next;
	}
}

void Print(List* s) // вывод
{
	List* print = s;
	while (print)
	{
		cout << "\nИмя: " << print->a.name << endl;
		cout << "Номер: " << print->a.phone << endl;
		cout << "\n";
		print = print->next;
	}
}

void Insert(List** begin) // вставить структуру в i-ю позицию
{
	List* t = (*begin);

	string name;
	int position, number;
	cout << "\nНа какую позицию вы хотите вставить элемент: ";
	cin >> position;
	//while (position > kol_vo)
	//{
	//	cout << "Эта позиция недопустима! Введите верную позицию\nОт 1 до " << kol_vo << ": ";
	//	cin >> position;
	//}

	cout << "\nВведите Имя: ";
	cin >> name;
	cout << "Введите номер: ";
	cin >> number;
	cout << "\n";

	List* insert = new List; // создали структуру и в нее впихнули данные

	char* str = new char[name.length() + 1];
	strcpy(str, name.c_str()); // т.к. у нас в struct char, то переведем string -> char*
	insert->a.name = str;
	insert->a.phone = number;

	if (*begin == NULL) // проверка на нулевой список
	{
		insert->next = NULL;
		*begin = insert;
		return;
	}
	if (position == 1) // проверка на 1 позицию
	{
		insert->next = (*begin);
		*begin = insert;
		return;
	}

	int i = 0;
	while (i != position - 2)
	{
		t = t->next;
		i++;
	}
	insert->next = t->next;
	t->next = insert;
	kol_vo++;
}

void Delete(List** begin)
{
	int position = 0;
	cout << "\nВведите номер элемента, который хотите удалить: ";
	cin >> position;
	while (position > kol_vo)
	{
		cout << "Эта позиция недопустима! Введите верную позицию\nОт 1 до " << kol_vo << ": ";
		cin >> position;
	}
	int i = 0;
	List* t = *begin;
	while (i != position - 2)
	{
		t = t->next;
		i++;
	}
	t->next = t->next->next;
	kol_vo--;
}

void Free(List** begin)
{
	if (*begin == 0)
		return;
	List* p = *begin;
	List* t;

	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*begin = NULL;
	kol_vo = 0;
}

void Proverka(List** begin)
{
	if (*begin == NULL) // проверка на нулевой список
	{
		cout << "Список пуст!" << endl;
		return;
	}
}

void Poisk(List** begin)
{
	int vibor = 0;
	int number;
	int kol_vo_2 = kol_vo;
	string name;
	List* t = (*begin);
	cout << "Какой элемент вы хотите найти в структурах\n1-имя, 2-номер: ";
	cin >> vibor;
	while (vibor < 1 || vibor > 2)
	{
		cout << "\nВведите верный номер (1 или 2)";
		cin >> vibor;
	}

	if (vibor == 1)
	{
		cout << "Введите имя, которое вы хотите найти: ";
		cin >> name;
		char* str = new char[name.length() + 1];
		strcpy(str, name.c_str()); // т.к. у нас в struct char, то переведем string -> char*
		while (kol_vo_2)
		{
			if (strcmp(t->a.name, str) == 0) // 0 – если сравниваемее строки идентичны.
			{
				cout << "\nИмя: " << t->a.name << "\nНомер: " << t->a.phone << endl;
				return;
			}
			t = t->next;
			kol_vo_2--;
		}
	}
	else if (vibor == 2)
	{
		cout << "Введите номер, который вы хотите найти: ";
		cin >> number;
		while (kol_vo_2)
		{
			if (t->a.phone == number)
			{
				cout << "\nИмя: " << t->a.name << "\nНомер: " << t->a.phone << endl;
				return;
			}
			t = t->next;
			kol_vo_2--;
		}
	}
	cout << "Такого элемента не существует в структурах" << endl;
}

void Sort(List** begin) // Сортировка списка по первому элементу структуры.
{
	int num;
	char* name;
	for (int i = 0; i < kol_vo; i++)
	{
		List* t = *begin;
		List* t1 = t->next;
		while (t1 != NULL)
		{
			if (strcmp(t->a.name, t1->a.name) > 0)
			{
				num = t->a.phone;
				name = t->a.name;
				t->a.name = t1->a.name;
				t1->a.name = name;
				t->a.phone = t1->a.phone;
				t1->a.phone = num;
			}
			t = t->next;
			t1 = t->next;
		}
	}
}

void Start(List** begin)
{
	short int choise = 1;
	while (choise != 0)
	{
		cout << "\n1. Создание списка (чтение данных из файла)" << endl;
		cout << "2.	Добавить в список i-й (на i-ю позицию) элемент" << endl;
		cout << "3. Удаление  i-го элемента из списка" << endl;
		cout << "4.	Удаление списка (всех элементов)" << endl;
		cout << "5.	Поиск элемента в списке (по одному из полей структуры), вывод всего элемента (структуры) на консоль." << endl;
		cout << "6.	Вывод  списка в текстовый файл." << endl;
		cout << "7.	Сортировка списка по первому элементу структуры." << endl;
		cout << "8.	Добавить проверки на пустой список: выводить на консоль сообщение «Список пуст»" << endl;
		cout << "\nВведите, какую функцию вы хотите реализовать (от 1-8)\nДля выхода введите 0: ";
		cin >> choise;

		switch (choise)
		{
		case 1: // 1. Создание списка (чтение данных из файла)
		{
			Init(begin);
			Print(*begin);
			break;
		}
		case 2: // 2.	Добавить в список i-й (на i-ю позицию) элемент
		{
			Insert(begin);
			Print(*begin);
			break;
		}
		case 3: // 3.	Удаление  i-го элемента из списка
		{
			Delete(begin);
			Print(*begin);
			break;
		}
		case 4: // 4.	Удаление списка (всех элементов)
		{
			Free(begin);
			break;
		}
		case 5: // 5.Поиск элемента в списке (по одному из полей структуры), вывод всего элемента (структуры) на консоль.
		{
			Poisk(begin);
			break;
		}
		case 6: // 6.	Вывод  списка в текстовый файл.
		{
			Vivod_V_File(begin);
			break;
		}
		case 7: // 7.	Сортировка списка по первому элементу структуры.
		{
			Sort(begin);
			Print(*begin);
			break;
		}
		case 8:
		{
			Proverka(begin);
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "Введите верное значение(1-8)\nДля выхода введите 0: ";
			cin >> choise;
		}
		}

	}
}