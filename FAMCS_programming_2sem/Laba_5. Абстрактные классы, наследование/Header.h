#pragma once

#include <iostream>
using namespace std;

// =================================================================
//								queue
// =================================================================

class AbstractContainer
{
public:
	AbstractContainer() {};						// default constructor
	AbstractContainer(AbstractContainer&) {};	// copy constructor
	virtual ~AbstractContainer() {};			// default destructor
	virtual bool IsEmpty() const = 0;			// container is empty
	virtual bool IsFull()  const = 0;			// container is full
};

class AbstractQueue : public AbstractContainer
{
public:
	virtual void push(const int& n) = 0;// add to queue
	virtual void pop(void) = 0;			// remove from queue
};

class QueueIterator;

// class queue
class ArrayQueue : public AbstractQueue
{
protected:
	int		size;			// actual size of array							( ����������� ������� )
	int*	arr;			// pointer to array								( ��������� �� ������ ) 
	int		tail;			// index of the last element in array			( ������ ������� � ���������� �������� �������� )
	int		n;				// number of items in the queue					( ���������� ��������� � ������� ) 
public:
	friend class QueueIterator;

	ArrayQueue(int _size);			// default constructor
	ArrayQueue(ArrayQueue& q);		// copy constructor
	~ArrayQueue();					// default destructor
	void Print(int index);
	void Delete();
	void push(const int& item);		// add to queue
	void pop(void);					// remove from queue
	bool IsEmpty() const;
	bool IsFull() const;
};

// =================================================================
//						for Iterator
// =================================================================

// abstract base class Iterator ( ����������� ������� ����� �������� )
class AbstractIterator
{
public:
	virtual ~AbstractIterator() {};
	virtual bool InRange() const = 0;		// index within acceptable limits?		( ������ � ���������� ��������? ) 
	virtual void Reset() = 0;				// reset index to beginning				( �������� ������ � ������ )
	virtual int& operator *() const = 0;	// dereferencing (for reading an item)  ( ������������� (��� ������ ��������) )
	virtual void operator ++() = 0;			// element shift						( ����� �� ������� )
};
	
// class Queue Iterator ( ����� �������� ������� )
class QueueIterator : public AbstractIterator
{
	ArrayQueue& t;					// queue reference				( ������ �� ������� )
	int		position;				// current iterator position	( ������� ������� ��������� )
	QueueIterator();
public:
	QueueIterator(ArrayQueue& _t);
	bool InRange() const;			// index within acceptable limits?		( ������ � ���������� ��������? ) 
	void Reset();					// reset index to beginning				( �������� ������ � ������ )
	int& operator *() const;		// dereferencing (for reading an item)  ( ������������� (��� ������ ��������) )
	void operator ++();				// element shift						( ����� �� ������� )
};