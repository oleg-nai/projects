#include "Header.h"

// Найдович Олег, 7 группа
// Я создал абстрактный класс machine, он является родителем (base class) для класса car(child class) и truck(child class). 
// Класс machine содержит отделный класс engine(двигатель), а т.к. machine - это класс родитель для car и truck, то engine также есть в car и truck
// Каждому новому объекту класса machine присваивается ID, 
// Добавил исключения
// Есть Counter - переменная, которая считает количество сохданных объектов класса machine

int Machine::Count = 0;

int main(void)
{
	setlocale(LC_ALL, "rus");
	

	Car volvo("volvo-x-360", 5000);
	cin >> volvo.engine;
	cout << volvo.engine << endl;

	volvo.showAllInfo();


	Truck maz("M-300", 8000, 5000);
	Truck belarus(maz);
	
	maz.showAllInfo();		// функция вывода из абстрактного класса Machine

	cin >> belarus.engine;
	cout << belarus << endl;// перегруженная функция вывода в классе Truck

	cout << "Count of machines : " << volvo.Count << endl; // показывает количество созданных объектов класса Machine

	return 0;
}	