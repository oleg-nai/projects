// Перегрузка.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Ar2020
{
    int* M;
    int count;
public:
    Ar2020(void)                    // конструктор по умолчанию 
    {
        M = new int[0];
        count = 0;
    }
    Ar2020(const Ar2020& r)         // конструктор копирования
    {
        count = r.count;
        M = new int[count];
        for (int i = 0; i < count; i++)
            M[i] = r.M[i];
    }
    Ar2020(int* _M, int _count)     // конструктор с параметрами
    {
        count = _count;
        M = new int[count];
        for (int i = 0; i < count; i++)
            M[i] = _M[i];
    }
    Ar2020 operator = (const Ar2020& r)
    {
        if (this != &r)
        {
            count = r.count;
            M = new int[count];
            for (int i = 0; i < count; i++)
                M[i] = r.M[i];
        }
        return *this;
    }
    int operator [] (int index)
    {
        if (index >= 0 && index < count)
           return M[index];

        else
            return 0;
    }
    friend ostream& operator << (ostream& os, Ar2020 r)
    {
        for (int i = 0; i < r.count; i++)
            os << r.M[i];
        return os;
    }
    friend istream& operator >> (istream& os, Ar2020 r)
    {
        os >> r.count;
        for (int i = 0; i < r.count; i++)
        {
            os >> r.M[i];
        }
        return os;
    }
    Ar2020 operator + (const Ar2020& r)
    {
        Ar2020 a(*this);
        a.count = r.count;
        for (int i = 0; i < a.count; i++)
            a.M[i] = r.M[i];
        return a;
    }
    friend bool operator == (const Ar2020 a , const Ar2020 r)
    {
        if (a.count != r.count)
            return false;
        for (int i = 0; i < a.count; i++)
        {
            if (a.M[i] != r.M[i])
                return false;
        }
        return true;
    }
    Ar2020& operator ++()           // префикс
    {

    }
    Ar2020& operator ++(int)        // постфикс
    {

    }

    ~Ar2020(void)                   // деструктор
    {
        delete[] M;
        count = 0;
    }
};

int main()
{
    int arr[] = { 1,2,3,4,5 };
    Ar2020 A(arr, 5);
    Ar2020 B(A), C(A);

    if (B == C)
        cout << "hello world";

    return 0;
}
