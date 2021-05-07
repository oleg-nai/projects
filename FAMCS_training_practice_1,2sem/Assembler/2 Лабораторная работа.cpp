#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int n, m, max = 0, j;
	cout << "Введите число n: ";
	cin >> n;
	m = n;
	_asm
	{
		mov eax, n

		cycle_1 :
		mov edx, 0
			mov ebx, 10
			div ebx
			cmp edx, max
			jge cycle_2
			jl cycle_3

			cycle_2 :
		mov max, edx
			cmp eax, 0
			je cycle_4
			jne cycle_1

			cycle_3 :
		cmp eax, 0
			je cycle_4
			jne cycle_1




			cycle_4 :
		mov eax, m
			mov ecx, 0
			jmp cycle_5

			cycle_5 :
		mov edx, 0
			mov ebx, 10
			div ebx
			cmp edx, max
			je cycle_6
			jne cycle_7

			cycle_6 :
		imul ecx, 10
			add ecx, edx
			jmp cycle_7

			cycle_7 :
		imul ecx, 10
			add ecx, edx
			cmp eax, 0
			je cycle_8 // выходит из цикла, если eax = 0
			jne cycle_5 // продолжает циклиться


			cycle_8 : // самое главное число хранится в ecx
		mov eax, ecx
			mov ecx, 0
			jmp cycle_9

			cycle_9 :
		mov edx, 0
			mov ebx, 10
			div ebx
			jmp cycle_10

			cycle_10 :
		imul ecx, 10
			add ecx, edx
			cmp eax, 0
			je cycle_11
			jne cycle_9

			cycle_11 :
		mov n, ecx
	}

	cout << n;
}
