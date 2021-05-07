#include <iostream>
#include <math.h>
using namespace std;
/*
	Найти все простые делители числа n
	Найдович Олег, 7группа, 1 курс
*/
int main()
{
	int n;
	bool a = 0;
	cout << "enter the number" << endl;
	cin >> n;
	while (n < 0)
	{
		cout << "n shoold be n>0";
		cin >> n;
	}
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			for (int j = 2; j <= sqrt(i); j++)
			{
				if (i % j == 0)
				{
					a = 1;
					break;
				}
			}
			if (a == 0)
				cout << i << " ";
		}
		a = 0;
	}
}
