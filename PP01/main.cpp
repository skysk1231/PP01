#include <iostream>
#include <string>

using namespace std;// 밑에 std 제거 가능

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

int main()
{   
    Player2 pl2;

    Player *player = new Player(); //메모리가 만들어졌지만 소멸하지 않음
    delete(player); // 소멸 시킴

    return 0;
}
