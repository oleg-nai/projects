#include "iostream"
#include <math.h>
using namespace std;
/*
9. Является ли число  палиндромом.
Найдович Олег, 7 группа
*/
int main()
{
	// Программа работает только для 5-значных чисел
	setlocale(LC_ALL, "rus");
	int num, a, b, c, d, e;
	cout << "Введите число ";
	cin >> num;
	while (num <0)
	{
		cout << "num shoold be >0"
		cin >> num;
	}
	if (num > 0 && num < 10)
	{
		cout << "Число является палиндромом" << endl;
	}
	else if (num > 9 && num <= 99)
	{
		a = num / 10;
		b = num % 10;
		if (a == b)
		{
			cout << "Число является палиндромом" << endl;
		}
		else
		{
			cout << "Число не является палиндромом" << endl;
		}
	}
	else if (num > 99 && num < 1000)
	{
		a = num / 100; // находим 1 цифру
		b = num % 100 / 10; // находим вторую цифру
		c = num % 10; // назодим третью цифру
		if (a == c)
		{
			cout << "Число является палиндромом" << endl;
		}
		else
		{
			cout << "Число не является палиндромом" << endl;
		}
	}
	else if (num >= 1000 && num < 10000)
	{
		a = num / 1000; // находим 1 цифру
		b = num % 1000 / 100; // находим 2 цифру
		c = num % 100 / 10; // находим 3 цифру и так далее
		d = num % 10;
		if (a == d && b == c)
		{
			cout << "Число является палиндромом" << endl;
		}
		else
		{
			cout << "Число не является палиндромом" << endl;
		}
	}
	else if (num >= 10000 && num < 100000)
	{
		a = num / 10000;
		b = num % 10000 / 1000;
		d = num % 100 / 10;
		e = num % 10;
		if (a == e && b == d)
		{
			cout << "Число является палиндромом" << endl;
		}
		else
		{
			cout << "Число не является палиндромом" << endl;
		}
	}
	else
	{
		cout << "Число слишком большое! " << endl;
	}
}