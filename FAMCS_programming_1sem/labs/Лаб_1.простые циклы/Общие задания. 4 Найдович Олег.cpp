#include <iostream>
#include <math.h>
using namespace std;
/*
Задание №4 "Вычислити X^n, n - любое , не обязательное целое."
Найдович Олег
*/
int main()
{
	int a, b, sum;
	cout << "Enter 2 numbers" << endl;
	cin >> a >> b;
	sum = pow(a, b); // возводим число а в степень b
	cout << sum; // можно было обойтись без sum. просто cout << pow(a,b);
	return 0;
}
