//							Лабораторная работа № 5
//		Использование STL.Обработка контейнеров, с использование алгоритмов.
//		Найдович Олег	7 группа
//						4 вариант
//


//		Разработать программу для работы с отображениями(multimap).
//		Информационное поле каждого элемента представляет собой : имя(строку) - ключ, возраст(целое число).
//		Использовать собственный критерий сортировки.Программа должна выводить на экран компьютера меню вида и результаты работы :
//			1. Добавить элемент в заданную позицию
//			2. Удалить элемент
//			3. Поиск элементов ключ которых, меньше заданному ключу
//			4. Обменивает  значения двух объектов(отображений)
//			5. Замена элемента
//			6. Сравнение отображений
//			7. Выход из программы

#include <map>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "rus");
	multimap<string, int> myMap_boys = { {"Oleg", 18}, {"Artem", 15},{"Iliya", 30}, {"Kostya", 25}, {"Petya", 11}, {"Allan", 32} };
	auto it = myMap_boys.end();
	multimap<string, int> myMap_girls = { {"Katya", 61}, {"Lera", 21},{"Uliana", 41}, {"Jenya", 14}, {"Masha", 13}, {"Cashya", 100} };

	bool correct_input = false;
	int number_of_position;
	do
	{
		cout << "\n1.Добавить элемент в заданную позицию\n2.Удалить элемент\n";
		cout << "3.Поиск элементов ключ которых, меньше заданному ключу\n4.Обменивает значения двух объектов(отображений)\n";
		cout << "5.Замена элемента\n6.Сравнение отображений\n";
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
				string name;
				int age;
				cout << "Добавляем элемент в заданную позицию\n"; // multimap предствалняет из себя дерево у которого тут нет позиции элемента, только ключ и значение
				cout << "Введите ключ(string) и значение элемента(int): ";
				cin >> name >> age;
				myMap_boys.emplace(name, age);
				//myMap.insert({name, age});
				break;
			}

			case 2:
			{
				if (myMap_boys.size() == false)
				{
					cout << "Словарь пуст! Удалять нечего!\n";
					break;
				}
				string name;
				cout << "Удаляем элемент\n";
				cout << "Введите ключ элемента, который вы хотите удалить: ";
				cin >> name;
				if (myMap_boys.find(name) ==myMap_boys.end())
				{
					cout << "Такого ключа нет!\n";
					break;
				}
				myMap_boys.erase(name);
				break;
			}

			case 3:
			{
				if (myMap_boys.size() == false)
				{
					cout << "Словарь пуст! Искать нечего!\n";
					break;
				}
				cout << "Поиск элементов ключ которых, меньше заданному ключу\n";

				string name;
				cout << "Введите ключ: ";
				cin >> name;
				if (myMap_boys.find(name) == myMap_boys.end())
				{
					cout << "Такого ключа нет!\n";
					break;

				}

				for (auto i = myMap_boys.find(name); i != myMap_boys.begin(); --i)
				{
					cout << i->first << "\t" << i->second << endl;
				}
				cout << myMap_boys.begin()->first << "\t" << myMap_boys.begin()->second << endl;
				break;
			}

			case 4:
			{
				cout << "Обмениваемся значениями двух объектов\n";
				if (myMap_boys.size() != myMap_girls.size())
				{
					cout << "Размеры 2-ух словарей разные!" << endl;
					break;
				}
				myMap_boys.swap(myMap_girls);
				break;
			}
			
			case 5:
			{
				string name;
				int age;
				cout << "Замена элемента\n";
				cout << "Введите ключ элемента, который вы хотите изменить. И значение, которое вы хотите вставить: ";
				cin >> name >> age;
				if (myMap_boys.find(name) == myMap_boys.end())
				{
					cout << "Такого ключа нет!\n";
					break;
				}
				auto it = myMap_boys.find(name);
				myMap_boys.erase(it);
				myMap_boys.emplace(name, age);
				break;
			}

			case 6:
			{
				cout << "Сравнение отображений\n";
				if (myMap_boys.size() > myMap_girls.size())
					cout << "1 словарь больше 2-го словаря\n"<< endl;
				else if (myMap_boys.size() < myMap_girls.size())
					cout << "2 словарь больше 1-го словаря\n" << endl;
				else if ((myMap_boys.size() == myMap_girls.size()))
				{
					cout << "Словари равны\n" << endl;
				}
				break;
			}
		}	
	} while (number_of_position != 7);
	return 0;
}


