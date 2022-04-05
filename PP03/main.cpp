#include <iostream>
using namespace std;

class a
{
public :
	virtual void print()
	{
		cout << "µ¥Çì\n";
	}

};

class b : public a
{public:
	 void print()
	{
		 cout << "ÇìÇò\n";
	}

	 
};

void main()
{
	a* temp = new b();
	temp->print();
}