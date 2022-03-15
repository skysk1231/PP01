#include <iostream>
#include <string>

using namespace std;// 밑에 std 제거 가능

namespace normal //print가 중복되기 때문에 namespace를 지정해서 나눔
{
    void print(std::string str)
    {
        std::cout << str;
    }
}


namespace visual_novel //print가 중복되기 때문에 namespace를 지정해서 나눔
{
    void print(std::string str)
    {
        std::cout << "이은석 : " << str; // print를 지정해서 사용
    }
}

using namespace visual_novel; //28번째 줄에 사용할것이라고 지정

int main()
{
    std::cout << ("평화롭고 아름다운 프로그래밍 패턴 시간\n"); //c++의 기본형
    normal::print("평화롭고 아름다운 프로그래밍 패턴시간\n"); // namespace의 노말을 가짐
    visual_novel::print ("평화롭고 아름다운 프로그래밍 패턴시간\n"); // namespace의 visual_novel에서 가지고옴
    print("평화롭고 아름다운 프로그래밍 패턴시간\n"); // 22줄에서 namespace visual_novel을 사용한다고 지정
    return 0;
}
