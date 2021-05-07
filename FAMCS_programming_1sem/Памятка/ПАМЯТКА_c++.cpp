/*
// **************************************
//          Стандартный набор

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
}


*/
// **************************************
//        Работа с char, file, string
/*

cin.getline(t1, 255); // берет целую строчку для char 
getline(cin, str); // ввод строки, а не одного слова

getline(file, s) - чтение всей строки из файла
file.getline(line, 10); // из файла(file) читает строку(в line)


atoi(ИМЯ_ПЕРЕМЕННОЙ) // превод из char в int
atof(ИМЯ_ПЕРЕМЕННОЙ) // превод из char в float
atol(ИМЯ_ПЕРЕМЕННОЙ) // превод из char в long int 


	pch = strtok(str1, str2);	// Функция strtok выполняет поиск лексем в строке string
   	while (pch != NULL)			// пока есть лексемы
    {
        .
        .
        .
        .
    	pch = strtok(NULL, str2); // берет следующее значение в строке

    }


ofstream out("tt.txt"); - поток для записи
ifstream file("tt.txt"); - для чтения
out.open("main.txt", ofstream::app ); // окрываем файл для записи
file.close(); - закрыть файл


strcat(str1, str2) // добавляет строку
strcpy(str1, str2) // заменяет!


str.find_first_of ("&!>") - находит первое упоминание одного из символов
str.find(".", n) - находит первое упоминание начиная с n-ного места
str.substr(n, m) - вырезает подстроку (n - c какого символа, m - сколько символов)
str.size() - длинна строки
sizeof(str) - длинна строки 
str.c_str() - перевод из string в char


*/
// **************************************


// **************************************
//             для qsort
/*

int compare(const void* x1, const void* x2) // нужно для qsort
{
	return ((struct employee*)x1)->SUM - ((struct employee*)x2)->SUM;
}

*/
// **************************************