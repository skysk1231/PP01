#include <iostream>
#include <string>

using namespace std;// namespace 같은 함수 이름 구분 가능 

class Player //접근자 없을시 private
{
public : 
    Player() // 생성자
    {
        cout << "주인공 생성되었습니다! 아 맑은 공기 아름다운 세상"<< endl; // 메모리 아끼기
    }
    ~Player()// 소멸자
    {
        cout << "앗" << endl; //성능 속도가 빠름
    }
private:
};

class Player2//접근자 없을시 private
{
public:
    Player2() // 생성자
    {
        cout << "주인공2 생성되었습니다! 아 맑은 공기 아름다운 세상" << endl; // 메모리 아끼기
    }
    ~Player2()// 소멸자
    {
        cout << "앗.. 안돼" << endl; //성능 속도가 빠름
    }
private:
};

class Player3//접근자 없을시 private
{
public:
    Player3() // 생성자
    {
        cout << "주인공3 생성되었습니다! 아 맑은 공기 아름다운 세상" << endl; // 메모리 아끼기
    }
    ~Player3()// 소멸자
    {
        cout << "앗.. 안돼....." << endl; //성능 속도가 빠름
    }
private:
};

void a()
{
    Player3 pl3;
}

int main()
{   
    a();

    Player2 pl2; // Player보다 먼저 생성되고 나중에 소멸됨 // 정적 할당 // 스택
   
    Player *player = new Player(); //메모리가 만들어졌지만 소멸하지 않음 // 동적 할당 // 소멸시키시기 전까지 소멸 X //힙
    delete(player); // 소멸 시킴 

    return 0;
}
