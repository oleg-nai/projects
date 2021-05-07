#include <iostream>

using namespace std;


template<typename T1, typename T2>
void Sum(T1 a, T2 b)
{
	cout << "a + b = " << a + b;;
}

template<typename T>
T Sum(T a, T b)
{
	return a + b;
}

// template(typename) и template(class) - это одно и то же
template <typename T>
class MyClass
{
	T value;
public:
	
	MyClass(T value):
	{
		this->value = value;
	}
	~MyClass()
	{
	}
	void DataTypeSize()
	{
		cout << sizeof(value);
	}
};

int main()
{
	int a = 5;
	MyClass<unsigned char> c('4');
	c.DataTypeSize();
}




//
//template<class T>
//void Search(T& r)
//{
//	bool NONE = true;
//	bool rightNumber = false;
//	cout << "\nSearching for studends\n";
//	int k = 0;
//	do
//	{
//		try
//		{
//			cout << "Enter the number of books: ";
//			cin >> k;
//			if (cin.fail())
//				throw "\tYou've written wrong number/symbol, try again";
//			cout << "\n";
//			rightNumber = true;
//		}
//		catch (const char* ex)
//		{
//			cout << ex << endl;
//			cin.clear();			// return cin to 'normal' mode
//			cin.ignore(32767, '\n');// delete the values of the previous input from the input buffer
//		}
//	} while (rightNumber != true);
//
//	cout << "\nSearching for studends, who have more then " << k << " books" << endl << endl;
//	int i = 0;
//	while (i < r.count)
//	{
//		if (r.M[i] > k)
//		{
//			NONE = false;
//			cout << r.M[i] << endl;
//		}
//		i++;
//	}
//	if (NONE == true)
//		cout << "NONE\n";
//	cout << "--------------------------------------------------------------------------------------" << endl << endl;
//};
//
//template<class T>
//class Student
//{
//	int count;
//	T* M;
//public:
//	Student(void) : M(new T[10], count(NULL))
//	{}
//	Student(Student <T>& r)
//	{
//		count = r.count;
//		M = r.M;
//	}
//
//	Student& operator = (const Student& r)
//	{
//		int i = 0;
//		while (i < r.count)
//		{
//			M[i] = r.M[i];
//			i++;
//		}
//		count = r.count;
//		return *this;
//	}
//
//	T& operator [] (int index)
//	{
//		return M[index];
//	}
//
//	template<class T1, class T2>
//	void Cheaker(const Student<T1>& a, const Student<T2>& b)	// a - Container1(TakeBooks), b - Container2(ReturnBooks), NotReturnBooks = TakeBooks, NotReturnBooks != ReturnBooks 
//	{
//		Student<NotReturnBooks> last;
//		int q = 0;
//		for (int i = 0; i < count; i++)
//		{
//			for (int j = 0; j < a.count; j++)
//			{
//				for (int k = 0; k < b.count; k++)
//				{
//					if (M[i] == a.M[j] && M[i] != b.M[k])
//					{
//						last.M[q++] = M[i];
//						break;
//					}
//				}
//			}
//		}
//		last.count = q - 1;
//		*this = last;
//	}
//
//	~Student(void)
//	{
//		delete[] M;
//		count = 0;
//	}
//};
