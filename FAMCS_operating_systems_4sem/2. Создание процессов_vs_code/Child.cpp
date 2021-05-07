#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

// 3. Сортировка методом “пузырька”. Тип элементов - вещественные числа двойной точности
int main(int argc, char* argv[]) {
	cout << "The array before sort:\n";
	double* arr = new double[argc]; // - 1 --> as the first arg is the Child.exe

	for (int i = 1; i < argc; i++) {
		cout << argv[i] << "\n";
		arr[i - 1] = stod(argv[i]); // move all to double array
	}

	// sorting by method "bubble sort"
	cout << "We are sorting the array.\n";
	double temp = 0;
	for (int i = 0; i < argc - 1; i++) {
		for (int j = i; j < argc - 1; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "Sorted arr:\n";
	for (int i = 0; i < argc - 1; i++) {
		cout << arr[i] << " ";
	}
	_cputs("\nPress any key to finish.\n");
	_getch();
	ExitProcess(0);



}