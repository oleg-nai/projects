#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class Engine
{
private:
	int power;
	string name_of_engine;
public:
	Engine(void);		// default constructor
	Engine(string, int);// default constructor
	friend ostream& operator << (ostream&, Engine);  // method of insert, operator overload << like friendly functions
	friend istream& operator >> (istream&, Engine&); // method of output, operator overload >> like friendly functions

	Engine(const Engine&);	// copy constructor
	~Engine(void);			// default destructor
};


class Machine // abstract class
{
public:
	
	static int Count;	// variable for counting quantity of class heirs
	const int ID;		// unique ID
	
	
	Engine engine;
	string mark_of_machine; 
	int price;

	Machine(void);		 // default constructor
	Machine(string, int);// default constructor

	Machine(const Machine&);// copy constructor
	~Machine(void);			// default destructor
	
	int showCount(void) { return Count; }

	virtual void showAllInfo() = 0;
};

class Car : public Machine
{
public:
	Car(void);		 // default constructor
	Car(string, int);
	Car(const Car& r);
	// default constructor
	~Car(void);
	void showAllInfo(void);
};

class Truck : public Machine
{
public:
	int carrying_capacity;
	Truck(void);
	Truck(string, int, int);
	Truck(const Truck&);
	~Truck(void);
	void showAllInfo(void);
	friend ostream& operator << (ostream&, Truck); // method of output, operator overload >> like friendly functions

};