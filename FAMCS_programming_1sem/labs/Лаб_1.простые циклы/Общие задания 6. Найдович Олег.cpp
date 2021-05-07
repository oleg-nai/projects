#include <iostream>
#include <math.h>
using namespace std;

/*
Задание №6 "Найти Нод и нОК двух заданных натуральных чисел"
Найдович Олег, 7 группа, 1 курс
*/
int main()
{
	int a, b, nok, nod;
	cout << "enter 2 numbers" << endl;
	cin >> a;
	cin >> b;
	while (a < 0 || b < 0)
	{
		cout << "a and b shoold be >0";
		cin >> a >> b;
	}
	nok = a * b;
	while (a != 0 && b != 0)
	{
		if (a >= b)
		{
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	nod = a + b;
	nok /= nod; // nod (a,b) * nok (a*b) = a*b
	cout << "nok = " << nok << endl;
	cout << "nod = " << nod << endl;
}