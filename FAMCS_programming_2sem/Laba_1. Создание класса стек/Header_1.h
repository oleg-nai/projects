#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;
int kol_vo = 0;

/*
2.4. �������. ������� ������ ���������.
��������� �������� ���������� � ���������� ������� ���������, ����: ����� ��������, �������.
(short, char*, double

��� ��������� �����(����, �������) ����������� ������ � ������:
1.	�������� ������ (������ ������ �� �����) +
2.	�������� �������  +
3.	��������  ��������  +
4.	�������� ���� ���������
5.	����� ������ �� ������� ��� � ����
6.	������� �� ���������� �������� �������� � ���� ����.
*/


struct human
{
	int number;
	char name[20];
	human* next;	
	human* prev;
};

class queue
{
public:
	human* head = 0, * tail = 0;

	queue() {};

	void push(int , char* );
	void Add_from_file();
	void Add_from_user(queue);
	void Pop(queue);
	void Print(queue);
	bool isEmpty();
	void Delete_all_elements(queue);
	~queue() {};
};

void Panel(queue);
