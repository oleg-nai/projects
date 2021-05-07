/*
					Лабораторная №9
					   Рекурсия.
	Общее задание:
Для индивидуального задания  обработать динамический массив.
Элементы считать из текстового файла. Результаты записать в текстовый файл.

	Индивидуальные задачи.
4.	Вычисление суммы каждых 3-х элементов массива. Сумму считать с 1-го, 2-го, 3-го и т.д. элементов

*/

#include <iostream>
#include <fstream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

void func(int* arr, int kol_vo_element, int sum, int s4et_1_2_3, int s4et_for_na4ala_ots4eta, int s4et, int* mass_for_writing_on_file)
{
	s4et_1_2_3++;
	s4et++;
	if (s4et_for_na4ala_ots4eta + 2 == kol_vo_element)
	{
		cout << "Рассчет закончен" << endl;
		return;
	}
	sum += arr[s4et_1_2_3 - 1];

	if (s4et % 3 == 0)
	{
		cout << "Сумма 3 чисел начиная от " << s4et_for_na4ala_ots4eta + 1 << " элемента = " << sum << endl;
		mass_for_writing_on_file[s4et_for_na4ala_ots4eta] = sum;
		sum = 0;
		//s4et_1_2_3 = 0;
		//s4et_for_na4ala_ots4eta++;
		s4et_1_2_3 = ++s4et_for_na4ala_ots4eta;
	}
	func(arr, kol_vo_element, sum, s4et_1_2_3, s4et_for_na4ala_ots4eta, s4et, mass_for_writing_on_file);

}

int main()
{
	setlocale(LC_ALL, "rus");
	int* arr;
	int* mas = new int[50];
	string line;

	ifstream vvod;
	vvod.open("vvod.txt");

	int kol_vo = NULL;
	if (!vvod.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		int a = 0;
		int b = 1;

		while (!vvod.eof()) // берет по 1 набору элементов
		{
			vvod >> line;
			cout << "[" << b << "] - " << line << endl;
			mas[a] = atoi(line.c_str()); // массив с мусором
			kol_vo++;
			a++;
			++b;
		}
		cout << "\nЗапись из файла в int-овый массив закончена!" << endl;
	}

	arr = new int[kol_vo];
	for (int i = 0; i < kol_vo; i++) // опять переводит в массив, но уже без мусора
	{
		arr[i] = mas[i];
	}
	delete[] mas;
	vvod.close();     // закрываем файл

	if (!vvod.is_open())
	{
		cout << "Файл успешно закрыт!" << endl;
	}
	else
	{
		cout << "Файл не закрылся!" << endl;
	}


	int s4et_1_2_3 = 0;
	int sum = 0;
	int s4et = 0;
	int s4et_for_na4ala_ots4eta = 0;
	int kol_vo_element = kol_vo;


	int* mass_for_writing_on_file= new int[kol_vo-2];
	
	cout << "Вычисление суммы каждых 3-х элементов массива. Сумму считать с 1-го, 2-го, 3-го и т.д. элементов" << endl;
	func(arr, kol_vo_element, sum, s4et, s4et_for_na4ala_ots4eta,s4et, mass_for_writing_on_file);

	cout << "Сумма завершена!" << endl;
	ofstream file_vivod;
	string path_exit = "vivod.txt";
	file_vivod.open(path_exit);
	if (!file_vivod.is_open())
	{
		cout << "Ошибка открытия файла" << path_exit << endl;
	}
	else
	{
		cout << "Файл для записи открыт" << endl;
		for (int i = 0; i < kol_vo- 2; i++)
		{
			file_vivod << mass_for_writing_on_file[i];
			file_vivod << " ";
		}
	}




	file_vivod.close();
	cout << "Запись в файл завершена!" << endl;
}
