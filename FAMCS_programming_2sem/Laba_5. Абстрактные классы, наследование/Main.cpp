/*
						Лабораторная № 5
				Абстрактные классы, наследование.

				
Сдать оформленные работы до 26.04.

Найдович Олег	7 группа
				4 вариант
				
// 4. Используя абстрактные классы, реализовать конкретные классы: ArrayQueue( на массиве), QueueIterator

*/

#include "Header.h"
	
int main(void)
{
	setlocale(LC_ALL, "rus");

	ArrayQueue test_for_fun(3);
	int size_queue;
	cout << "Enter max size of queue: "; cin >> size_queue;
	ArrayQueue test(size_queue);

	int item;
	cout << "Enter the elements of the queue. To stop enter '12345' \n";
	do
	{
		try
		{
			if (test.IsFull())
			{
				cout << "queue filled" << endl;
				break;
			}
			cin >> item;
			if (cin.fail())
				throw "You've written wrong number/symbol, try again\n";

			if (item != 12345) {
				test.push(item);
			}
		}
		catch (const char* ex)
		{
			cout << ex << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (item != 12345);
	test.Print(1); // выводятся только элементы, которые вы вписали в очередь; чтобы вывести всю очередь, напишите test.Print(0)

	
	cout << "\nRemoving an item from the end of the queue\n";			// Удаление элемента из конца очереди
	test.pop();
	test.Print(1);
	
	cout << "\nInsert an item at the top of the queue.\nEnter item: ";	// Вставка элемента в начало очереди.
	cin >> item;
	test.push(item);
	test.Print(1);

	QueueIterator iterator(test);
	cout << "\nMoving index iterator to the beginning queue\n";			// итератор индекса переместили в начало
	iterator.Reset();
	cout << "\nOutput using an iterator" << endl;						//Вывод c помощью итератор
	while (iterator.InRange())
	{
		cout << *iterator << " ";
		++iterator;
	}

	cout << "\n\nDelete all elements in queue\n";
	test.Delete();
	test.Print(0);  // выводятся только элементы, которые вы вписали в очередь; чтобы вывести всю очередь, напишите test.Print(0)
	return 0;

}