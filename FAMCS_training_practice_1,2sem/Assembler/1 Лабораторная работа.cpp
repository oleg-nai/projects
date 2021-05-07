#include <iostream>
using namespace std;
/*
	Найдович Олег	
	1 задача на ассемблере
*/
int main()
{
	setlocale(LC_ALL, "rus");
	int  x, y;
	int  c;
	int  ass;
	cout << "Введите число x = ";
	cin >> x;
	cout << endl << "Введите число y = ";
	cin >> y;
	cout << endl;
	c = ((x + y) / (y + 1)) - ((x * y - 12) / (34 + x));
	if (y == -1)
	{
		cout << "ERROR";
		return 0;
	}
	if (x == -34)
	{
		cout << "EROOR";
		return 0;
	}
	cout << "Ответ в C++ = " << c << endl;
	_asm
	{
		mov eax, x
		mov ebx, y
		add eax, ebx
		add ebx, 1
		cdq 
		idiv ebx
		mov ebx, 0
		mov ebx, eax // в ebx 1 часть
		mov eax , 0
		mov eax, x
		mov ecx, 0
		mov ecx, y
		imul ecx
		sub eax, 12
		mov ecx, 0
		mov ecx, x
		add ecx, 34
		idiv ecx
		sub ebx, eax
		mov ass, ebx
	}
	cout << "--------------------------------" << endl;
	cout << "Ответ на ассемблере = " << ass << endl;
	cout << "Ответ на c++ = " << ass << endl;
}