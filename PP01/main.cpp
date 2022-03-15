#include <iostream>
#include <string>

using namespace std;

class Parent 
{
public:
     void fun1() 
    {
        cout << "이곳은 Parent클래스의 fun1함수입니다.\n";
    }
    virtual void fun2() // virtual을 통해 가상 함수로 지정
    {
        cout << "이곳은 Parent클래스의 fun2함수입니다.\n";
    }
    void fun3()
    {
        cout << "이곳은 Parent클래스의 fun3함수입니다.\n";
    }
};

class Child : public Parent
{
public:
    void fun1()
    {
        cout << "이곳은 Child 클래스의 fun1함수입니다.\n";
    }
    virtual void fun2()
    {
        cout << "이곳은 Child 클래스의 fun2함수입니다.\n";
    }
};


int main()
{   
    Parent* p = new Parent; 
    Child* c = new Child;

    p->fun1(); 
    c->fun1();
    p->fun2();
    c->fun2();
    p->fun3();
    c->fun3(); // Child클래스의 해당하는 fun3함수가 없기 때문에 부모 클래스인 Parent 클래스에서 fun3함수의 결과를 출력
    p = c;

    cout << "\n\n";
    p->fun1();// Parent 클래스의 fun1고정 함수이기 때문에 Parent클래스의 fun1함수 주소값이 고정 41번째 줄과 같은값 출력
    p->fun2();// p의 주소값이 c의 주소값이 되었기 때문에 Child클래스의 fun2함수값 출력
    p->fun3();// Child클래스의 해당하는 fun3함수가 없기 때문에 부모 클래스인 Parent 클래스에서 fun3함수의 결과를 출력
   
    return 0;
}
