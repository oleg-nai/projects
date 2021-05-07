#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int kol_vo = 0;


void Init(List** begin) // ���������� � �����, �������������
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
		cout << "������ �������� �����" << endl;
		return;
	}
	else
	{
		while (getline(file, line))
		{
			kol_vo++;
			string name;
			int num;

			istringstream iss(line);//�������� ����� ��� ���������� ������ �� �������

			iss >> name >> num;		//������ ����� ����������� �������� >> ������� ������
									//��������� ���� ������ ��� � �������� ����������� ����
			char* str = new char[name.length() + 1];
			strcpy(str, name.c_str()); // �.�. � ��� � struct char, �� ��������� string -> char*
			sled->a.name = str;
			sled->a.phone = num;
			if (file.eof()) // ���� ������
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
		cout << "������ �������� �����" << endl;
		return;
	}
	while (kol_vo_2)
	{
		file << t->a.name << "\n" << t->a.phone << "\n\n";
		kol_vo_2--;
		t = t->next;
	}
}

void Print(List* s) // �����
{
	List* print = s;
	while (print)
	{
		cout << "\n���: " << print->a.name << endl;
		cout << "�����: " << print->a.phone << endl;
		cout << "\n";
		print = print->next;
	}
}

void Insert(List** begin) // �������� ��������� � i-� �������
{
	List* t = (*begin);

	string name;
	int position, number;
	cout << "\n�� ����� ������� �� ������ �������� �������: ";
	cin >> position;
	//while (position > kol_vo)
	//{
	//	cout << "��� ������� �����������! ������� ������ �������\n�� 1 �� " << kol_vo << ": ";
	//	cin >> position;
	//}

	cout << "\n������� ���: ";
	cin >> name;
	cout << "������� �����: ";
	cin >> number;
	cout << "\n";

	List* insert = new List; // ������� ��������� � � ��� �������� ������

	char* str = new char[name.length() + 1];
	strcpy(str, name.c_str()); // �.�. � ��� � struct char, �� ��������� string -> char*
	insert->a.name = str;
	insert->a.phone = number;

	if (*begin == NULL) // �������� �� ������� ������
	{
		insert->next = NULL;
		*begin = insert;
		return;
	}
	if (position == 1) // �������� �� 1 �������
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
	cout << "\n������� ����� ��������, ������� ������ �������: ";
	cin >> position;
	while (position > kol_vo)
	{
		cout << "��� ������� �����������! ������� ������ �������\n�� 1 �� " << kol_vo << ": ";
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
	if (*begin == NULL) // �������� �� ������� ������
	{
		cout << "������ ����!" << endl;
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
	cout << "����� ������� �� ������ ����� � ����������\n1-���, 2-�����: ";
	cin >> vibor;
	while (vibor < 1 || vibor > 2)
	{
		cout << "\n������� ������ ����� (1 ��� 2)";
		cin >> vibor;
	}

	if (vibor == 1)
	{
		cout << "������� ���, ������� �� ������ �����: ";
		cin >> name;
		char* str = new char[name.length() + 1];
		strcpy(str, name.c_str()); // �.�. � ��� � struct char, �� ��������� string -> char*
		while (kol_vo_2)
		{
			if (strcmp(t->a.name, str) == 0) // 0 � ���� ������������ ������ ���������.
			{
				cout << "\n���: " << t->a.name << "\n�����: " << t->a.phone << endl;
				return;
			}
			t = t->next;
			kol_vo_2--;
		}
	}
	else if (vibor == 2)
	{
		cout << "������� �����, ������� �� ������ �����: ";
		cin >> number;
		while (kol_vo_2)
		{
			if (t->a.phone == number)
			{
				cout << "\n���: " << t->a.name << "\n�����: " << t->a.phone << endl;
				return;
			}
			t = t->next;
			kol_vo_2--;
		}
	}
	cout << "������ �������� �� ���������� � ����������" << endl;
}

void Sort(List** begin) // ���������� ������ �� ������� �������� ���������.
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
		cout << "\n1. �������� ������ (������ ������ �� �����)" << endl;
		cout << "2.	�������� � ������ i-� (�� i-� �������) �������" << endl;
		cout << "3. ��������  i-�� �������� �� ������" << endl;
		cout << "4.	�������� ������ (���� ���������)" << endl;
		cout << "5.	����� �������� � ������ (�� ������ �� ����� ���������), ����� ����� �������� (���������) �� �������." << endl;
		cout << "6.	�����  ������ � ��������� ����." << endl;
		cout << "7.	���������� ������ �� ������� �������� ���������." << endl;
		cout << "8.	�������� �������� �� ������ ������: �������� �� ������� ��������� ������� ����" << endl;
		cout << "\n�������, ����� ������� �� ������ ����������� (�� 1-8)\n��� ������ ������� 0: ";
		cin >> choise;

		switch (choise)
		{
		case 1: // 1. �������� ������ (������ ������ �� �����)
		{
			Init(begin);
			Print(*begin);
			break;
		}
		case 2: // 2.	�������� � ������ i-� (�� i-� �������) �������
		{
			Insert(begin);
			Print(*begin);
			break;
		}
		case 3: // 3.	��������  i-�� �������� �� ������
		{
			Delete(begin);
			Print(*begin);
			break;
		}
		case 4: // 4.	�������� ������ (���� ���������)
		{
			Free(begin);
			break;
		}
		case 5: // 5.����� �������� � ������ (�� ������ �� ����� ���������), ����� ����� �������� (���������) �� �������.
		{
			Poisk(begin);
			break;
		}
		case 6: // 6.	�����  ������ � ��������� ����.
		{
			Vivod_V_File(begin);
			break;
		}
		case 7: // 7.	���������� ������ �� ������� �������� ���������.
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
			cout << "������� ������ ��������(1-8)\n��� ������ ������� 0: ";
			cin >> choise;
		}
		}

	}
}