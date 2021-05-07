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
2.4. Очередь. Элемент списка структура.
Структура содержит информацию о владельцах номеров телефонов, поля: номер телефона, фамилия.
(short, char*, double

Для обработки стека(дека, очереди) реализовать методы в классе:
1.	Создание списка (чтение данных из файла) +
2.	Добавить элемент  +
3.	Удаление  элемента  +
4.	Удаление всех элементов
5.	Вывод списка на консоль или в файл
6.	Запросы на выполнение операций оформить в виде меню.
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
