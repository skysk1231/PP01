#include <iostream>
using namespace std;

class a
{
public :
	virtual void print()
	{
		cout << "����\n";
	}

};

class b : public a
{public:
	 void print()
	{
		 cout << "����\n";
	}

	 
};

void main()
{
	a* temp = new b();
	temp->print();
}