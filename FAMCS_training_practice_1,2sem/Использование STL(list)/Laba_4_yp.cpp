//
//Найдович Олег	7 группа
//				4 вариант

//	Разработать программу для работы со списком(использовать list).
//	Информационное поле каждого элемента вещественные числа.
//	Программа должна выводить на экран компьютера меню вида:
//
//		1.Просмотреть состояние списка	+
//		2.Удалить несколько элементов с заданной позиции +
//		3.Добавить несколько элементов в заданную позицию c друго list  +
//		4.Отсортировать список			+
//		5.Удалить элемент по значению	+
//		6.Перемножить поэлементно два списка, использовать алгоритм(transform). +
//		7.Выход из программы			+



#include <list>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void PrintList(const list<T>& mylist)
{
	if (mylist.empty() == true)
	{
		cout << "список пуст\n";
		return;
	}
	for (auto i = mylist.cbegin(); i != mylist.cend(); ++i)
	{
		cout << *i << endl;
	}
}

double signature(double x, double y) 
{
	//define multiplication function
	return x * y;
}

int main(void)
{
	setlocale(LC_ALL, "rus");
	list<double> mylist = {1.522, 5.41,6.13,7.986,4.851,85.51};
	auto it = mylist.begin();

	list<double> addlist = {1,2,3,4,5,6};

	int number_of_position;
	bool correct_input = false;
	do
	{
		cout << "\n1.Просмотреть состояние списка\n2.Удалить несколько элементов с заданной позиции \n";
		cout << "3.Добавить несколько элементов в заданную позицию c друго list\n4.Отсортировать список\n";
		cout << "5.Удалить элемент по значению\n6.Перемножить поэлементно два списка, использовать алгоритм(transform)\n";
		cout << "7.Выход из программы\n";
		correct_input = false;
		do
		{
			try
			{
				cout << "Введите номер операции(1-7): ";
				cin >> number_of_position;
				if (cin.fail())
					throw "\tYou've written wrong number/symbol, try again";
				cout << "\n";
				correct_input = true;
			}
			catch (const char* ex)
			{
				cout << ex << endl;
				cin.clear();			// return cin to 'normal' mode
				cin.ignore(32767, '\n');// delete the values of the previous input from the input buffer
			}
		} while (correct_input == false);
		
		system("cls");

		switch (number_of_position)
		{
			case 1:
			{
				cout << "Смотрим состояние списка:\n";
				PrintList(mylist);
				break;
			}

			case 2:
			{
				if (mylist.empty() == true)
				{
					cout << "Список пуст, удалять нечего!\n";
					break;
				}

				int posStartElementToDel, posEndElementToDel;
				cout << "Ввелите c какого по какой элемент нужно удалить улементы: ";
				cin >> posStartElementToDel >> posEndElementToDel;
				if (posEndElementToDel > mylist.size() + 1)
				{
					cout << "Ошибка! В списке слишком мало элементов\n";
					break;
				}
				auto start = mylist.begin();
				auto end = mylist.begin();

				advance(start, posStartElementToDel - 1);
				advance(end, posEndElementToDel);
				mylist.erase(start, end);
				break;
			}

			case 3:
			{
				cout << "Добавиление элемента в заданную позицию c друго list\n";
				int posStartSecondElement;
				int posEndSecondElement;
				cout << "С какого по какой элемент(включительно) из 2-го списка вы хотите добавить в 1-ый список: ";
				cin >> posStartSecondElement >> posEndSecondElement;
				if (posEndSecondElement > addlist.size())
				{
					cout << "Ошибка! Во 2-ом списке слишком мало элементов\n";
					break;
				}
				auto start = addlist.begin();
				advance(start, posStartSecondElement - 1);
				auto end = addlist.begin();
				advance(end, posEndSecondElement);
				if (mylist.size() == 0)
				{
					cout << "1-ый список пуст, элементы автоматически заполнят список\n";
					it = mylist.begin();
					mylist.insert(it, start, end);
					break;
				}
				else
				{
					int posFirstElement;
					cout << "На какую позицию в 1-ом списке вы хотите вставить элемент: ";
					cin >> posFirstElement;
					if (posFirstElement > mylist.size())
					{
						cout << "Ошибка! Во 2-ом списке слишком мало элементов\n";
						break;
					}
					it = mylist.begin();
					advance(it, posFirstElement - 1);
					mylist.insert(it, start, end);
					break;
				}
			}

			case 4:
			{
				if (mylist.empty() == true)
				{
					cout << "Список пуст, сортировать нечего!\n";
					break;
				}
				mylist.sort();
				cout << "Сортируем список!\n";
				break;
			}

			case 5:
			{
				if (mylist.empty() == true)
				{
					cout << "Список пуст, удалять нечего!\n";
					break;
				}
				double element_to_delete = 0;
				cout << "Удаляем элемент по значению!\n";
				cout << "Введите элемент, который вы хотите удалить: ";
				cin >> element_to_delete;
				mylist.remove(element_to_delete);
				break;
			}

			case 6:
			{
				if (mylist.empty() == true)
				{
					cout << "Список пуст, удалять нечего!\n";
					break;
				}
				if (mylist.size() != addlist.size())
				{
					cout << "Размеры двух списков должны совпадать!\n";
					break;
				}
				cout << "Умножаем поэлементно два списка!\n";
				transform(mylist.begin(), mylist.end(), addlist.begin(), mylist.begin(), signature);
				break;
			}
		}
	} while (number_of_position != 7);

	return 0;
}

