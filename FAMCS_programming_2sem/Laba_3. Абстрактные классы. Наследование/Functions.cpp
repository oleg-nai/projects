#include "Header.h"

int j = 0;

Engine::Engine(void) : power(0), name_of_engine("NONE") // default constructor
{

}
Engine::Engine(string name_str, int power_engine) // default constructor
{
	cout << "Creat engine" << endl;
	name_of_engine = name_str;
	power = power_engine;
}
ostream& operator << (ostream& os, Engine r) // method of output, operator overload << like friendly functions
{
	cout << "Name of engine: " << r.name_of_engine << endl;
	cout << "Power of engine: " << r.power << endl;
	return os;
}
istream& operator >> (istream& os, Engine& r) // method of insert, operator overload >> like friendly functions
{
	cout << "Enter the name of the engine: ";
	cin >> r.name_of_engine;


	while (true)
	{
		try
		{
			cout << "\nEnter the power of the engine(interger): ";
			cin >> r.power;
			if (cin.fail())
				throw "You've written wrong number/symbol, try again\n";
			cout << "\n";
			return os;
		}
		catch (const char* ex)
		{
			cout << ex << endl;
			cin.clear();			// �� ���������� cin � '�������' ����� ������
			cin.ignore(32767, '\n');// � ������� �������� ����������� ����� �� �������� ������
		}
	}
	// ����� ���� �������� � ��� try
	/*
	 while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ����� ���������� ��������
    {
		cout << "\nEnter the power of the engine(interger): ";
		cin >> r.power;
 
        if (cin.fail()) // ���� ���������� ���������� ��������� ���������,
        {
			cin.clear(); // �� ���������� cin � '�������' ����� ������
            cin.ignore(32767,'\n'); // � ������� �������� ����������� ����� �� �������� ������
        }
        else // ���� �� ������, �� ���������� a
            return os;
    }
	*/
}
Engine::Engine(const Engine& r) // copy constructor, needed when creating
{
	name_of_engine = r.name_of_engine;
	power = r.power;
}
Engine::~Engine(void) // default destructor
{
	//cout << "Delete engine" << endl;
}


Machine::Machine(void) : price(0), mark_of_machine("NONE"), ID(::j++) // default constructor
{
	Count++;
	cout << "Creat Machine (truck or car)\n" << endl;
}
Machine::Machine(string mark, int i) : ID(::j++) // default constructor
{
	Count++;
	cout << "Creat Machine (truck or car)\n" << endl;
	mark_of_machine = mark;
	price = i;
}
Machine::Machine(const Machine& r): ID(::j++) // copy constructor
{
	Count++;
	mark_of_machine = r.mark_of_machine;
	price = r.price;
	engine = r.engine;
}
Machine::~Machine() // default destructor
{
	Count--;
}


Car::Car(void) : Machine()// default constructor
{
}
Car::Car(string mark, int i) : Machine(mark, i) // default constructor
{
}
Car::Car(const Car& r) : Machine(r) // copy constructor
{
}
Car::~Car() // default destructor
{
}
void Car::showAllInfo(void)
{
	cout << "Name of car: " << mark_of_machine << endl;
	cout << "Price of car: " << price << endl;
	cout << "ID: " << ID << endl;
	cout << engine << endl;
}


Truck::Truck(void) : Machine(), carrying_capacity(0) // default constructor
{
}															// Truck is descendant (���������) of an abstract class
Truck::Truck(string mark, int i, int m) : Machine(mark, i)	// m = carrying_capacity, 
{															// default constructor
	carrying_capacity = m;
}
Truck::Truck(const Truck& r) : Machine(r) // copy constructor, needed when creating
{
	carrying_capacity = r.carrying_capacity;
}
Truck::~Truck() // default destructor
{
}
void Truck::showAllInfo(void)
{
	cout << "Name of truck: " << mark_of_machine << endl;
	cout << "Price of truck: " << price << endl;
	cout << "Carrying_capacity: " << carrying_capacity << endl;
	cout << "ID: " << ID << endl;
	cout << engine << endl;
}
ostream& operator << (ostream& os, Truck r) // method of insert, operator overload >> like friendly functions
{
	cout << "Name of Truck: " << r.mark_of_machine << endl;
	cout << "Price of engine: " << r.price << endl;
	cout << "Carrying_capacity: " << r.carrying_capacity << endl;
	cout << "ID: " << r.ID << endl;
	cout << r.engine << endl;
	return os;
}
