#include <iostream>
using namespace std;
/*
Задание №2 "Вычислить факториал числа"
Найдович Олег
*/
int main()
{
	setlocale(LC_ALL, "rus");
	int a;
	int b = 1;
	cout << "Enter number" << endl;
	cin >> a;
	if (a < 0)
	{
		cout << "Невозможно посчитать факториал из отрицательного числа";
	}
	else
	{
		for (int i = 1; i <= a; ++i)
		{
			b *= i; // b умножается до тех пор, пока i не будет <=a
		}
		cout << b;
	}
	return 0;
}