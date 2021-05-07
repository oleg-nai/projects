#include <iostream>

using namespace std;

class engine
{
public:
	string name;
	int power;
	engine(void):power(0),name("noName") {}
	engine(engine& r):power(0), name("") {}
	virtual ~engine() {}
	virtual bool IsEmpty() const = 0;
	virtual bool NoName() const = 0;
};
class car : engine
{

	bool IsEmpty()
	{
		if (name == "" || power == 0)
			return true;
		else
			return false;
	}
};



int main()
{
	
}