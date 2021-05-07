/*
•	Выполнить  сортировку с помощью  стандартной функции qsort.
•	 Добавить элемент в массив по индексу(позиция), при этом увеличить размер массива.
•	Удалить элемент из  массива, при этом сократить размер массива.
•	 Выполнить поиск элемента в массиве с помощью  стандартной функции bsearch.
•	Использовать указатели на функции
•	Использовать функцию с переменным количеством параметров(для добавления и удаления).
•	Выполнить сортировку (см. индивидуальный вариант)
•	Генераця элементов массива-случайная
*/

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);           // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2	
}



void qsort_1(int* arr, int n)
{
	cout << "\n=======================================\n";

	int* mas;
	mas = new int[n];
	for (int i = 0; i <n; i++)
	{
		mas[i] = arr[i];
	}
	qsort(mas, n, sizeof(int), compare);      // сортируем массив чисел
	cout << "Сортировка qsort: " << endl;
	for (int i = 0; i < n; i++) // выводит начальный массив
	{
		cout << "[" << i + 1 << "] = " << mas[i] << endl;
	}
	delete[] mas;
	cout << "\n=======================================\n";

}

void zadanie_2(int* arr, int n)
{
	cout << "\n=======================================\n";

	int ind, element;
	cout << "Введите индекс и элемент, который вы хотите вставить: ";

	int a = 1;
	while (a == 1) {
		cout << "ind = "; 
		cin >> ind;
		cout << endl << "element = "; 
		cin >> element;
		if (ind > n || ind <= 0)
		{
			cout << "введите ind, который <= " << n << endl;
			continue;
		}
		a = 0;
	}
	int* mas;
	mas = new int[(n+1)];
	
	if (ind == n)
	{
		for (int i = 0; i < (n-1); i++)
		{
			mas[i] = arr[i];
		}	
		mas[n - 1] = element;
		mas[n] = arr[n - 1];
	}
	else
	{
		for (int i = 0; i <= n; i++)
		{
			if (i == ind)
			{
				mas[ind - 1] = element;
				for (int j = ind-1; j < n; j++)
				{
					mas[j + 1] = arr[j];
				}
				break;
			}
			mas[i] = arr[i];
		}
	}
	for (int i = 0; i < n+1; i++) // выводит начальный массив
	{
		cout << "[" << i + 1 << "] = " << mas[i] << endl;
	}
	delete[] mas;
	cout << "\n=======================================\n";

}

void zadanie_3(int* arr, int n)
{
	cout << "\n=======================================\n";

	int ind;
	cout << "Введите индекс элемента, которого вы хотите удалить: ";

	int a = 1;
	while (a == 1) {
		cout << "ind = ";
		cin >> ind;
		if (ind > n || ind < 1)
		{
			cout << "введите ind, который <= " << n << endl;
			continue;
		}
		a = 0;
	}

	int* mas;
	mas = new int[(n - 1)];

	for (int i = 0; i < n; i++)
	{
		if (i == (ind - 1))
		{
			for (int j = i; j < n; j++)
			{
				mas[j] = arr[j + 1];
			}
			break;
		}
		mas[i] = arr[i];
		
	}


	for (int i = 0; i < n - 1; i++) // выводит начальный массив
	{
		cout << "[" << i + 1 << "] = " << mas[i] << endl;
	}
	delete[] mas;
	cout << "\n=======================================\n";
}


int funccmp(const void* x1, const void* x2)                            // функция сравнения
{
	return (*(int*)x1 - *(int*)x2);                                           // если результат вычитания - 0, значит числа равны
}


void zadanie_4(int* arr, int n)
{
	cout << "\n=======================================\n";
	int* mas;
	mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = arr[i];
	}
	int a = 1;
	while (a == 1)
	{
		cout << "Введите элемент, который вы хотите найти: ";

		int key;
		cout << endl << "key = ";
		cin >> key;

		int* p = (int*)bsearch(&key, mas, n, sizeof(int), funccmp);
		if (p == NULL)
		{
			cout << key << " нет в массиве " << endl;
			a = 1;
		}
		else
		{
			cout << key << " есть в массиве" << endl;
			a = 0;
		}
			
	}
}
void zadanie_6(int* arr, int n, int l, ...)
{
	cout << "\n=======================================\n";
	int* mas;
	int b = *(&l );
	int c = *(&l + 1);
	int d = *(&l + 2);
	int f = *(&l + 3);

	mas = new int[n+4];
	for (int i = 0; i < n; i++)
	{
		mas[i] = arr[i];
	}
	mas[n] = b;
	mas[n + 1] = c;
	mas[n + 2] = d;
	mas[n + 3] = f;

	// 		zadanie_6(arr, n, a, b, c, d);

	for (int i = 0; i < n + 4; i++) // выводит начальный массив
	{
		cout << "[" << i + 1 << "] = " << mas[i] << endl;
	}
}

void zadanie_8(int* arr, int n)
{
	cout << "\n=======================================\n";

	int* mas;
	mas = new int[n];
	int* m;
	m = new int[n];

	for (int i = 0; i < n; i++)
	{
	a: m[i] = rand() % n;
		for (int j = 0; j < i; j++)
		{
			if (m[j] == m[i]) goto a;
		}
	}

	for (int i = 0; i < n; i++)
	{
		mas[m[i]] = arr[i];
	}

	for (int i = 0; i < n; i++) // выводит начальный массив
	{
		cout << "[" << i + 1 << "] = " << mas[i] << endl;
	}
	delete[] mas;
	cout << "\n=======================================\n";
}

/*
Суть данного метода заключается в следующем:
Во  введенной последовательности сравниваются
элементы, отстоящие  друг от друга на опреде-
ленном расстоянии h (h обычно выбирают равным
n div 2, где n-количество  элементов)  и  при
необходимости меняются местами. Далее (после
того, как просмотрена с данным шагом вся пос-
ледовательность),  шаг уменьшается  в 2  раза
(h:=h div 2)  и последовательность просматри-
вается снова и т.д.пока шаг не станет равен 1.
С единичным шагом  последовательность просма-
тривается последний  раз и на выходе получаем
отсортированную последовательность.
*/

void shella(int* mas, int n)
{
	cout << "\n=======================================\n";
	cout << "Сортировка методом Шелла: " << endl;
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2) {	// Выбор шага
		for (i = step; i < n; i++) 	    // Перечисление элементов, которые сортируются на определённом шаге
		{
			tmp = mas[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < mas[j - step])
					mas[j] = mas[j - step];
				else
					break;
			}
			mas[j] = tmp;
		}
	}
	for (int i = 0; i < n + 1; i++) // выводит начальный массив
	{
		cout << "[" << i + 1 << "] = " << mas[i] << endl;
	}
	delete[] mas;
}
// ======================================


void vibor(int* arr, int n)
{
	int viv;
	cout << "Какое задание вы хотите проверить?\n";
	cout << "1 - Выполнить  сортировку с помощью  стандартной функции qsort." << endl;
	cout << "2 - Добавить элемент в массив по индексу(позиция), при этом увеличить размер массива." << endl;
	cout << "3 - Удалить элемент из  массива, при этом сократить размер массива." << endl;
	cout << "4 - Выполнить поиск элемента в массиве с помощью  стандартной функции bsearch." << endl;
	cout << "5 - Использовать указатели на функции" << endl;
	cout << "7 - Выполнить сортировку(см.индивидуальный вариант)" << endl;
	cout << "8 - Генераця элементов массива - случайная" << endl;
	cout << "10- Если вы хотите выйти" << endl;
	
	int a = 1;
	while (a == 1)
	{
		cout << "viv = ";
		cin >> viv;
	switch (viv)
	{
	case 1: // •	Выполнить  сортировку с помощью  стандартной функции qsort.
	{
		qsort_1(arr, n); 
		vibor(arr, n);
	}
	case 2:  // •	 Добавить элемент в массив по индексу(позиция), при этом увеличить размер массива.
	{
		void (*zadanie)(int* arr, int n);
		zadanie = zadanie_2;
		zadanie(arr, n);
		vibor(arr, n);
	}
	case 3:  // •	Удалить элемент из  массива, при этом сократить размер массива.
	{
		zadanie_3(arr, n);
		vibor(arr, n);
	}
	case 4: // •	 Выполнить поиск элемента в массиве с помощью  стандартной функции bsearch.
	{
		zadanie_4(arr, n);
		vibor(arr, n);
	}
	//case 5: // •	Использовать указатели на функции

	//{

	//}
	case 6: //•	Использовать функцию с переменным количеством параметров(для добавления и удаления).
	{
		cout << "Вводите 4 элемента" << endl;
		int a, b, c, d;
	
		cin >> a >> b >> c >> d;
		zadanie_6(arr, n, a, b, c, d);
		vibor(arr, n);
	}

	case 7: // •	Выполнить сортировку (см. индивидуальный вариант)
	{
		qsort_1(arr, n);
		shella(arr, n);
		vibor(arr, n);
	}
	case 8: // • Генераця элементов массива-случайная
	{
		zadanie_8(arr, n);
		vibor(arr, n);
	}
	case 10:
	{
		a = 0;
		break;
	}
	default:
	{	
		cout << "Введите верное число! - ";
		a = 1;
	}
	}

}

}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	// ===================================
	// первый массив массив

	int n = 0;
	int* arr = NULL;
	cout << "Введите размерность массива n: "; 
	cin >> n;
	arr = new int[n];
	cout << "=======================================\n";
	cout << "Начальный массив: " << endl;
	for (int i = 0; i < n; i++) // выводит начальный массив
	{
		*(arr + i) = rand() % 100;
		cout << "[" << i + 1 << "] = " << arr[i] << endl;
	}

	cout << "\n=======================================\n";
	vibor(arr, n);
}