#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;
/* вычислить в последовательности A =(ai),
i = 1..n, n <=100
сколько раз встречается каждый элемент, не использовать сортировку.
*/
int main()
{
	srand((unsigned int)time(NULL));

	setlocale(LC_ALL, "rus");
	bool a = 1;
	int n = 0;
	int mas[100];
	for (int i = 0; i <= 99; i++)
	{
		mas[i] = rand() % 101;
	}
	for (int i = 0; i <= 99; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl << "---------------------------------------" << endl;


	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (mas[j] == i)
			{
				n++;
			}
			
		}
		if (n == 0)
		{
			n = 0;
			continue;
		}
		cout << "число " << i << " встречалось " << n << " раз" << endl;
		n = 0;
	}
}