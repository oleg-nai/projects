#include <iostream>
#include <math.h>
using namespace std;
/*
	Проверить, будет ли число N = произведению простых делителей, без дублирования основных делителей. Делители вывести
	Найдович Олег, 7группа, 1 курс
*/

int main()
{
	int n;
	int n2 = 1;
	bool a = 0;
	cout << "enter the number" << endl;
	cin >> n;

	while (n < 10)
	{
		cout << "n should be > 0 " << endl;
		cout << "enter n = ";
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
				n2 = i*i;
			cout << i << " ";
		}
		a = 0;
	}
	if (n2 == n)
		cout << "yes" << endl;
	else
	{
		cout << "no" << endl;
	}
}
