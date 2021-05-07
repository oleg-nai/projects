#include "Header.h"



// copy constructor
ArrayQueue::ArrayQueue(ArrayQueue& q): size(q.size), n(q.n), tail(q.tail)
{
	arr = new int[size];		
	for (int i = 0; i < size; i++)
		arr[i] = q.arr[i];
}

// default constructor
ArrayQueue::ArrayQueue(int _size): size(_size), n(0), tail(0)
{
	arr = new int[_size + 1];
	for (int i = 0; i < _size; i++) 
		arr[i] = 0;
}

ArrayQueue :: ~ArrayQueue()				// default destructor
{
	//head = 0;
	n = 0;
	size = 0;
	tail = 0;
	delete[] arr;
}

void ArrayQueue::push(const int& item)	// add to queue
{
	if (n == size)
		cout << "Unable to insert new item - queue is full\n";
	else
	{
		for (int i = tail+1; i >= 1; i--)
			arr[i] = arr[i - 1];
		arr[0] = item; 
		tail++;
		n++;
	}
}

void ArrayQueue::pop(void)				// remove from queue
{
	if (n == 0)
		cout << "Queue is empty\n";
	else
	{
		arr[tail--] = 0;
		n--;
	}
}
bool ArrayQueue::IsEmpty(void) const	// is container empty?
{
	if (n == 0)
		return true;
	else
		return false;
}

bool ArrayQueue::IsFull(void) const
{
	if (n == size)
		return true;
	else
		return false;
}
void ArrayQueue::Print(int index = 1)
{
	if (index)
	{
		cout << "-----Printing queue-----\n";
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		cout << "-----Printing queue-----\n";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
}

void ArrayQueue::Delete()
{
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

// =================================================================
//						for Iterator
// =================================================================


QueueIterator::QueueIterator(ArrayQueue& _t): position(0), t(_t)	// copy constructor
{
	if (_t.IsEmpty())
	{
		cout << "Queue is empty, iterator will be automatically set to -1\n";
		position = -1;
	}
}

bool QueueIterator::InRange() const		// index within acceptable limits?		( индекс в допустимых пределах? ) 
{
	if (position < t.n)
		return true;
	else
		return false;
}

void QueueIterator::Reset()				// reset index to beginning				( сбросить индекс в начало )
{
	position = 0;
	t.arr[position];
}

int& QueueIterator:: operator *() const	// dereferencing (for reading an item)  ( разыменование (для чтение элемента) )
{
	return t.arr[position];
}

void QueueIterator:: operator ++()		// element shift						( сдвиг на элемент )
{
	position++;
}
