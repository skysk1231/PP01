#include <iostream>
#include <string>

using namespace std;// namespace 같은 함수 이름 구분 가능 

class Parent 
{
public:
    void print() // virtual void print() 로 적을시에 32번 줄의 출력값이 이곳은 Child입니다 로 변경 
    {
        cout << "이곳은 Parent입니다.\n";
    }
};

class Child : public Parent
{
public:
    void print()
    {
        cout << "이곳은 Child입니다.\n";
    }
};


int main()
{   
    Parent* p = new Parent; 
    Child* c = new Child;

    p->print(); //Parent클레스의 print 함수를 호출 -> 결과값이 이곳은 Parent입니다 출력
    p = c;// p의 주소값을 c의 주소값으로 변경
    p->print(); //Child클래스의 print 함수를 호출 But p의 주소값이 고정되어 있어서 결과값이 이곳은 Parent입니다 출력

    // 해결법 p의 주소값이 고정되는 것을 막기 위해서 virtual함수를 사용해서 동적 정수로 함수를 선언
    return 0;
}
