#include <iostream>
#include <math.h>
using namespace std;
/*
Задание №1 "Найти сумму чисел целого числа"
Найдович Олег
*/
int main()
{
	int n;
	int sum = 0;
	
	cout << "enter n = ";
	cin >> n;
	while (n < 0)
	{
		cout << "enter n > 0";
		cin >> n;
	}

	while (n != 0) // можно while (n), а можно и while (n != 0)
	{
		sum += n % 10; // последняя цифра из числа (n) прибавляется к sum 
		n /= 10; // избавляемся от последней цифры в n
	}
	cout << "sum = " << sum << endl;
	return 0;
}