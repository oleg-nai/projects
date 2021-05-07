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
	int		size;			// actual size of array							( размерность массива )
	int*	arr;			// pointer to array								( указатель на массив ) 
	int		tail;			// index of the last element in array			( индекс первого и последнего занятого элемента )
	int		n;				// number of items in the queue					( количество элементов в очереди ) 
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

// abstract base class Iterator ( абстрактный базовый класс Итератор )
class AbstractIterator
{
public:
	virtual ~AbstractIterator() {};
	virtual bool InRange() const = 0;		// index within acceptable limits?		( индекс в допустимых пределах? ) 
	virtual void Reset() = 0;				// reset index to beginning				( сбросить индекс в начало )
	virtual int& operator *() const = 0;	// dereferencing (for reading an item)  ( разыменование (для чтение элемента) )
	virtual void operator ++() = 0;			// element shift						( сдвиг на элемент )
};
	
// class Queue Iterator ( класс Итератор очереди )
class QueueIterator : public AbstractIterator
{
	ArrayQueue& t;					// queue reference				( ссылка на очередь )
	int		position;				// current iterator position	( текущая позиция итератора )
	QueueIterator();
public:
	QueueIterator(ArrayQueue& _t);
	bool InRange() const;			// index within acceptable limits?		( индекс в допустимых пределах? ) 
	void Reset();					// reset index to beginning				( сбросить индекс в начало )
	int& operator *() const;		// dereferencing (for reading an item)  ( разыменование (для чтение элемента) )
	void operator ++();				// element shift						( сдвиг на элемент )
};