#include <iostream>
#include <math.h>

using namespace std;
// 2 лаба, 1 задание, "ряды тейлора"
int main()
{
	setlocale(LC_ALL, "rus");
	double x;
	double k = 0, e, f, sum = 0, t;
	int n = 1, z = 2;

	cout << "Введите точность e и x: \n";
	cout << "Точность e = ";
	cin >> e;
	cout << "\nЧисло (x < 1 и x > -1) x = ";
	cin >> x;

	while (x < -1 || x > 1)
	{
		cout << "x должен быть (x > -1) и (x < 1)" << endl;
		cout << "enter x = ";
		cin >> x;
	}

	while (e < 0)
	{
		cout << "\ni должно быть больше 0" << endl;
		cout << "Введите точность e = ";
		cin >> e;
	}

	k = sqrt(1 + x);

	f = x / 2;
	sum = 1;

	while (fabs(f) > e)
	{
		sum += f;

		f = f * x * n * (-1) / (2. * z);
		z++;
		n += 2;
	}

	t = 1 / e;
	sum *= t;
	sum = round(sum);
	sum /= t;

	cout << "Ответ через sqrt    = " <<  k << endl;
	cout << "Ответ через Тейлора = " << sum;
}