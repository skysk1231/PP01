#include <iostream>
using namespace std;

class A
{
public:
	virtual void dynamic_print()
	{
		cout << "ÇìÇò\n";
	}

	void static_print()
	{
		cout << "µ¥Çò\n";
	}
};

class B : public A
{
public:
	void dynamic_print()
	{
		cout << "ÇìÇìÇò\n";
	}
	void static_print()
	{
		cout << "µ¥ÇìÇò\n";
	}

	void static_print(int a)
	{
		cout << a << "µ¥È÷\n";
	}
};

void main()
{
	A* tempA;
	B* tempB = new B();
	tempA = tempB;
	tempA->static_print();
	tempB->static_print();

	tempA->dynamic_print();
	tempB->dynamic_print();
}