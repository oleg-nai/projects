#include <iostream>
#include <math.h>
using namespace std;
/*
Задание №3. "Решить квадратное уравнение"
Найдович Олег, 1 курс, 7 группа 
*/
int main()
{
	int a, b, c;
	float x1, x2, d;
	cout << "enter 3 numbers" << endl;
	cin >> a >> b >> c;
	if (a != 0 && b != 0 && c != 0)
	{
		d = b * b - 4 * a * c;
		if (d > 0)
		{
			x1 = (-b + sqrt(d)) / 2 * a;
			x2 = (-b - sqrt(d)) / 2 * a;
			cout << "x1 = " << x1 << endl;
			cout << "x2 = " << x2 << endl;
		}
		else if (d == 0)
		{
			x1 = -b / 2 * a;
			cout << "x1 = " << x1 << endl;
		}
		else if (d < 0)
		{
			cout << "error, d < 0, no roots"<< endl;
		}
	}
	else if (a == 0 && b != 0 && c != 0)
	{
		x1 = -(c / b);
		cout << "x1 = " << x1 <<endl;
	}
	else if ((a == 0 && b == 0 && c != 0) || (a == 0 && b == 0 && c == 0))
	{
		cout << "error, no roots" << endl;
	}
	else if (a == 0 && b != 0 && c == 0)
	{
		cout << "x1 = 0" << endl;
	}
	else if (a != 0 && b == 0 && c != 0)
	{
		if (c > 0)
		{
			cout << "error, no roots" << endl;
		}
		else
		{
			x1 = sqrt(c / a);
			cout << "x1 = " << x1 << endl;
		}
	}
	else if (a != 0 && b != 0 && c == 0)
	{
		x1 = 0;
		x2 = b / a;
		cout << "x1 =" << x1 << "x2 = " << x2;
	}
	else if (a != 0 && b == 0 && c == 0)
	{
		cout << "x1 = 0";
	}
	return 0;
}