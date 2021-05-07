# include <iostream>
using namespace std;
void main()
{
	int A[10];
	cout << "Enter 10 numbers" << endl;
	for (int i = 0; i <= 9; ++i)
	{
		cout << "A[" << i << "]-> ";
		cin >> A[i];
	}
	cout << "In reverse order:" << endl;
	_asm
	{
		pushad
		mov esi, 0
		mov ecx, 10
		L1:
		mov eax, A[esi]  // можно без еах
			push eax
			add esi, 4
			loop L1

			mov esi, 0
			mov ecx, 10
			L2:
		pop A[esi]
			add esi, 4
			loop L2
			popad
	}
	for (int j = 0; j <= 9; ++j)
	{
		cout << "A[" << j << "]-> " << A[j] << endl;
	}
}