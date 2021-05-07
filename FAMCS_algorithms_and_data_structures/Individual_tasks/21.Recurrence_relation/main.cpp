#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int matrix[10][10][10] = {0};
	int n, m;
	int f, b, c, s;
	int x, y, z;

	ifstream fin("input.txt");
	fin >> n >> m;

	for (int temp = 0; temp < m; temp++)
	{
		fin >> f >> b >> c >> s;

		// ��� ��� m_f, m_b, m_c <= 9 => ������� ������� [10, 10, 10].
		// �� ����������� x, y, z ����� ���� �� ���� �����
		// f, b, � �� ����� ���� ������ 10 => ������ ������
		if (f > 9)
			f = 9;
		if (b > 9)
			b = 9;
		if (c > 9)
			c = 9;

		if (matrix[f][b][c] == 0)
			matrix[f][b][c] = s;
		else
		{ // ���� ���� ����� �������� ����, �� �������� ��������
			if (matrix[f][b][c] > s)
				matrix[f][b][c] = s;
		}

		// ���������, ����� �� �� ���������� ������� ��������� ����� ��������
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					if (matrix[i][j][k] != 0)
					{
						if (i + f < 10) x = i + f;
						else 			x = 9;

						if (j + b < 10) y = j + b;
						else 			y = 9;

						if (k + c < 10) z = k + c;
						else 			z = 9;
						// �������������, ���� �� ����� ����. ������� ����� ��������� ����� ��������, ��
						// �� ��� ����������
						if ((matrix[x][y][z] > matrix[i][j][k] + s) || (matrix[x][y][z] == 0))
							matrix[x][y][z] = matrix[i][j][k] + s;
					}
	}

	int money = INT_MAX;

	fin >> f >> b >> c;
	for (int i = f; i < 10; i++)
		for (int j = b; j < 10; j++)
			for (int k = c; k < 10; k++)
				if (matrix[i][j][k] != 0)
					if(matrix[i][j][k] < money)
						money = matrix[i][j][k];

	money = ceil(double(money) / n);

	ofstream fout("output.txt");
	fout << money << endl;
	
	return 0;
}