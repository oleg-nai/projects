/*
				������������ �8
����������� ������������ �6 , ��������� String.

������ ���������� �� ��������� ������ OC Windows.

����� �������:

��������� ������������ �� ��������� ������( ������������ ��������� ������� main.)

*/


/*
6.4 ����������� ���������, ������� ����������� � ������������ 2 ������.
������ ������ �������� �����������. ��������� ������ ������ �� ������� � ����������
� ��� ����� �����  � 2-� �\� (���������� � ������� b) , 10-� �\� - ������� �����.
����� �� 2-� �\�  ��������� � 8-� �\�  � �������� �� � �������������� ������.

��������� �� ��������� ����� ����� ����� ������ (����� � ������� ����������� ��������������).

��������� ���� �� ����� ������� ���������.

��������� ������� � ����.
*/

/*
�������:

������ ������: ����� �� 2-� �\�  ��������� � 8-� �\�  � �������� �� � �������������� ������.

������ ������: ��������� �� ��������� ����� ����� ����� ������ (����� � ������� ����������� ��������������).

*/


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

/*
strcpy
.find_first_of
getline
erase - ��������
substr
find_first_not_of
strtod

atoi
to_string
*/

int revers(int num) // // ������� �������������� int (1234 -> 4321)
{
	int reversedNumber = 0, remainder;
	int n = num;
	while (n != 0)
	{
		remainder = n % 10;
		reversedNumber = reversedNumber * 10 + remainder;
		n /= 10;
	}
	return reversedNumber;
}


int perevod_v_8(int num)
{
	int a = num;
	int b = 0;
	int result = 0;
	while (num != 0)
	{
		a = num % 10;
		num = num / 10;
		if (b == 0)
			b = 1;
		if (b != 0)
			a *= b;
		result += a;
		b *= 2;
	}
	int result_2 = result;
	int lengh = 0;
	// � resolt � ��� 10-�������� �����
	while (result_2 != 0) // ���������� ����� �����
	{
		result_2 /= 10;
		lengh += 1;
		if (result_2 == 0)
			break;
	}

	// lengh - ������ �����
	int* mas;
	mas = new int[lengh];
	for (int i = 0; i < lengh; i++)
	{
		mas[i] = result % 8;
		result = result / 8;
	}
	result = 0;
	for (int i = 0; i < lengh; i++)
	{
		if (mas[i] == 0)
		{
			result = 10;
		}
		result += mas[i];
		if (i == lengh - 1)
			break;
		result *= 10;
	}

	result = revers(result); // ������� �������������� int (1234 -> 4321)
	// resolt - ��� ����� � 8-������ ������� ���������
	return result;
}

void methodOfCalculation(int n, int mass[], int sortedMass[])
{
	int k;

	for (int i = 0; i < n; i++)
	{
		k = 0;
		for (int j = 0; j < n; j++)
		{
			if (mass[i] > mass[j])
				k++;
		}
		sortedMass[k] = mass[i];
	}
}

void main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");

	string str_first = argv[1];
	string str_leksema = argv[2];
	string for_1;
	string for_2;
	string for_3;
	string s;

	char* for_translation; // �� sting -> char
	for_translation = new char[256];
	for_translation[0] = '\0';
	int number_0_1 = 0;
	int num = 0;
	int size = 0;
	unsigned pos1 = 0, pos2;
	short int len_of_str = 0;

	/*cout << "������� ���������!!! �������� ����� ����� ����������� ����� (.)  (� 2 �/� ������: b11101)\n";
	getline(cin, str_first);

	cout << "\n������� ����������� (����� (.)): ";
	getline(cin, str_leksema);*/

	str_first = str_first + str_leksema;

	while ((pos1 = str_first.find_first_not_of(str_leksema, pos1)) != -1)
		//���� � �������� ������ ���� �������, �������� �� ��������������������, ��������� ����:
	{
		//�������� � ������ str, ������� � ������� pos1, ����� ������� �����������. 
		pos2 = str_first.find_first_of(str_leksema, pos1);
		//�������� � ������ s ������� ������ str, ������� � ������� pos1, � ���������� pos2 � pos1.
		s = str_first.substr(pos1, pos2 - pos1);
		// ������ � s � ��� ���� ������ �������
		str_first.erase(0, s.length() + 1);

		if (s.find("b") != -1) // ���� ���� b � ������, �� ���������
		{
			strcpy(for_translation, s.c_str());
			number_0_1 = atoi(for_translation);

			for (int j = 0; j < strlen(for_translation) - 1; j++) // ������� ������ ������� � ������� 
			{
				for_translation[j] = for_translation[j + 1];
				if (j == strlen(for_translation) - 2)
				{
					for_translation[j + 1] = '\0';
				}
			}
			number_0_1 = atoi(for_translation);
			num = perevod_v_8(number_0_1);
			for_1 += to_string(num) + ",";
			for_2 += to_string(num) + "_";
			for_3 += to_string(num) + " ";
			size++;
			continue;
		}
		else
		{
			strcpy(for_translation, s.c_str()); // � for_translation � ��� s � char
			for (int i = 0; i < strlen(for_translation); i++) // �������� �� .
			{
				if (s[i] == '.')
				{
					for_1 += s + ",";
					for_2 += s + "_";
					for_3 += s + " ";
					size++;
				}
				continue;
			}

			bool isd = true;
			char* p = for_translation;
			while (*p)
			{
				if (!isdigit(*p++))
				{
					isd = false;
					break;
				}
			}
			if (isd)
			{
				for_1 += s + ",";
				for_3 += s + " ";
				size++;
			}
		}
	}

	ofstream file;
	file.open("main.txt", ios::app);

	file << "\n������ ������: " << for_1;
	file << "\n������ ������: " << for_2;
	file << "\n�����, ������� �� ����� �����������: " << for_3;

	cout << "\n������ ������: " << for_1;
	cout << "\n������ ������: " << for_2;
	cout << "\n�����, ������� �� ����� �����������: " << for_3;

	char* pch;
	strcpy(for_translation, for_3.c_str());
	int* arr = new int[size];
	int* arr_2 = new int[size];
	int x = 0;

	pch = strtok(for_translation, " ");	// ������� strtok ��������� ����� ������ � ������ string
	while (pch != NULL)
	{
		int full = atoi(pch);
		arr[x] = full;
		pch = strtok(NULL, " "); // ����� ��������� �������� � ������
		++x;
	}

	methodOfCalculation(size, arr, arr_2);
	cout << "\n��������������� �����: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr_2[i] << " ";
		file << arr_2[i] << " ";
	}
	file.close();
	//���������� ������� ��������
}