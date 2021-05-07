#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Header.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int main()
{
	setlocale(LC_ALL, "rus");
	List* begin = new List;
	begin->next = NULL;
	Start(&begin);
}