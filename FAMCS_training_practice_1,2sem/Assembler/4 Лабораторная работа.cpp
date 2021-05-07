#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int n, m;
	cout << "Enter matrix size: ";
	cin >> n >> m;

	int** arr = new int* [n];

	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			arr[i][j] = rand() % 10;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
	cout << endl;


	/*for (int j = cols - 1; j >= 0; j--)
	 {
	 for (int i = 0; i < rows; i++)
	 cout Â« arr[i][j] Â« ' ';
	 cout Â« endl;
	 }*/

	int** arr2 = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr2[i] = new int[n];
	}

	/*for (int i = 0; i <rows; i++)
	 {
	 for (int j = 0; j < cols; j++)
	 arr2[cols-j-1][i] = arr[i][j];
	 }*/

	__asm
	{
		mov ecx, 0

	loop2:
		mov ebx, 0

		loop1:
			mov esi, arr
			mov edi, [esi + 4 * ecx] //i+4*n
			mov eax, [edi + 4 * ebx]//j+4*m
			mov esi, arr2
			mov edx, m
			sub edx, ebx
			dec edx//m-j-1
			mov edi, [esi + 4 * edx]//[m-j-1][ ]
			mov[edi + 4 * ecx], eax


			inc ebx
			cmp ebx, m
			jl loop1
			inc ecx
			cmp ecx, n
			jl loop2
	}
	/*mov esi, arr
		mov edi, [esi + 4 * ecx] //i+4*n
		mov eax, [edi + 4 * ebx]//j+4*m
		mov esi, arr2
		mov edx, cols
		sub edx, ebx
		dec edx//m-j-1
		mov edi, [esi + 4 * edx]//[m-j-1][ ]
		mov[edi + 4 * ecx], eax*///
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr2[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	cout << endl;
}