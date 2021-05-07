#include <iostream>
#include <cstring>
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


/* 

.............................................................................

 Лаботаросная рабоать №2: ASM, строки
 Designed by: Naidovich Oleg

 5.4 Разработать программу, которая запрашивает у пользователя строку.
 Лексемы разделены _
 
 1. Определяет  в ней лексемы-непалиндромы. 
 2. Ввести 2-ю строку, найти её в строке..  
 3. Вставить после 1-й лексемы в строке произвольную строку (или 2-ю строку, если она не найдена)
 4. Результаты вывести на консоль.
 .............................................................................
 */

using namespace std;


void Reverse(char* str)
{
	char* p = str;

	while (*p && *(p + 1) && *p++);

	while ((p > str) && (*str += *p) && (*p = *str - *p) && (*str++ -= *p--));
}

char* Mystrstr(const char* str, const char* pstr)
{
	char* st, * pst;
	int n1 = strlen(str);
	int n2 = strlen(pstr);
	st = new char[n1 + 1];
	pst = new char[n2 + 1];
	strcpy(st, str);
	strcpy(pst, pstr);
	char* p = new char[n1 + 1];
	int k = 0, i = 0;
	if (n1 < n2) return NULL;
	if (strcmp(st, pst) == 0) return st;
	while (i < n2 && k < n1)
	{
		while (st[k] != pst[i] && k < n1)
			k++;
		p = st + k;
		if (k != n1)
		{
			while (st[k] == pst[i] && i < n2)
			{
				k++;
				i++;
			}
			if (i == n2) break;
			else i = 0;
		}
	}
	if (i == 0) return NULL;
	else return p;
}

char* AsmStrstr(const char* str_, const char* pstr)
{
	char* st_, * pst;
	int n1 = strlen(str_);
	int n2 = strlen(pstr);
	st_ = new char[n1 + 1];
	pst = new char[n2 + 1];
	char* p = new char[n1 + 1];
	int k = 0, i = 0;
	__asm
	{
		//  strcpy(st,str);
		cld
		mov edi, st_
		mov esi, str_
		mov ecx, n1
		inc ecx
		rep   movsb
		// strcpy(pst,pstr);
		mov edi, pst
		mov esi, pstr
		mov ecx, n2
		inc ecx
		f1_ : mov bl, [esi]
		mov[edi], bl
		inc esi
		inc edi
		loop f1_
	}

	_asm
	{
		//  if (n1<n2) return NULL;
		mov ebx, n1
		cmp ebx, n2
		jge solve1
		mov eax, 0
	}
	return;

	_asm
	{solve1:
	// if (strcmp(st_,pst)) return pst;
	cld
		mov edi, st_
		mov esi, pst
		mov ecx, n1
		inc ecx
		rep   cmpsb
		cmp ecx, 0
		jne solve2
		mov eax, pst
	}
	return;
	_asm
	{solve2:
	// while (i<n2 && k<n1)
 //	{
	mov ebx, i
		mov edx, k
		cmp ebx, n2
		jge then1_
		cmp  edx, n1
		jge then1_
		//	  while(st_[k]!=pst[i]&& k<n1)
		//			  k++;
		mov ecx, n1
		inc ecx
		cld
		mov edi, st_
		mov esi, pst
		mov al, [esi]
		rep  scasb
		mov esi, st_
		sub edi, esi
		mov k, edi
	}
	p = st_ + k;
	if (k != n1)
	{
		while (st_[k] == pst[i] && i < n2)
		{
			k++;
			i++;
		}
		if (i == n2) goto then2;// break;
		else i = 0;
	}


	_asm
	{
	then1_:
	}

then2:
	if (i == 0) return NULL;
	else return p;
}

int main(void)
{
    setlocale(LC_ALL, ".1251");
    char* str_user = new char[256];
	char* str_save_user = new char[256];
    cout << "Введите строку: ";
    cin.getline(str_user, 256);
    int str_size = strlen(str_user);
	strcpy(str_save_user, str_user);

    char* str_leksema = new char[2];
    strcpy(str_leksema, "_");

//......................................................
//  №1 Определяет  в ней лексемы-непалиндромы. 
//.......................................................
    
    char* pch = new char[50];
	char* pch_naoborot = new char[50];
	pch = strtok(str_user, str_leksema);
    while (pch != NULL)
    {
		int size_new = strlen(pch);
		int indicator = 0;
		strcpy(pch_naoborot, pch);
		Reverse(pch_naoborot);
        _asm
        {
            cld	//задаем направление сканирования (сбрасываем флаг DF-флаг направления).
				//данный флаг учитывается в строковых операциях.Если флаг равен 1, то в строковых операциях 
				//адрес автоматически уменьшается.Мы сбрасываем этот флаг,чтобы адрес автоматически увеличивался
			mov ecx, size_new
			mov esi, pch
			mov edi, pch_naoborot
			repe cmpsb // Команда CMPSW сравнивает слово из памяти по адресу DS:SI со словом по адресу ES:DI. 
						// Аналогична по действию команде CMP.
			jne mismatch // признак ZF = 0, если сравниваемые cтроки не совпадают (mismatch)
			
		match:			// если совпали 
			mov indicator, 1
			jmp exit_1

		mismatch:		// если не совпали
			mov indicator, 0

		exit_1:
		}
		if (indicator == 1)
			cout << pch << " палиндром!" << endl;
		else
			cout << pch << " НЕ палиндром!" << endl;
		pch = strtok(NULL, str_leksema);
    }

    
//......................................................
//  №2. Ввести 2-ю строку, найти её в строке
//.......................................................
    
    char* str_find = new char[256];
	char* p_my;
	strcpy(str_user, str_save_user);
    cout << "\nВведите строку, которую нужно найти: ";
    cin.getline(str_find, 256);

	pch = strtok(str_user, str_leksema);
    while(pch != NULL)
    {
	//	p_my = Mystrstr(pch, str_find);
		p_my = AsmStrstr(pch, str_find);
		if (p_my != 0)
			cout << pch << " эквивалентна " << str_find << endl;
		else
			cout << pch << " не равна " << str_find << endl;
		pch = strtok(NULL, str_leksema);
    }
//......................................................
//  №3. Вставить после 1-й лексемы в строке произвольную строку 
//		(или 2-ю строку, если она не найдена)
//.......................................................
	strcpy(str_user, str_save_user);
	pch = strtok(str_user, str_leksema);
	int size_pch = strlen(pch);
	int size_str_find = strlen(str_find);
	char* str_final = new char[50];
	_asm
	{
		mov edi, pch
		xor al, al
		cld
		rep scasb
		mov esi, str_find
		mov ecx, size_str_find
		rep movsb
	}
	strcpy(str_final, pch);
	strcat(str_final, str_leksema);
	pch = strtok(str_user, str_leksema);
	while (pch != NULL)
	{
		strcat(str_final, pch);
		strcat(str_final, "_");
		pch = strtok(NULL, str_leksema);
	}
	printf( str_final);
	return 0;
}