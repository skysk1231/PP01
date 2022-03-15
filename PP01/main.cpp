#include <iostream>
#include <string>

using namespace std;// namespace 같은 함수 이름 구분 가능 
bool is_game_running = false; //글로벌 변수_다른 파일에서 접근 가능

class GameObject
{
public :
    GameObject() 
    {
        cout << "게임오브젝트 생성\n";
    }
    virtual ~GameObject()
    {
        cout << "게임오브젝트 소멸\n";
    }

    virtual void Start() // 기본형이 지정되어 있다고 가정
    {
        cout << "게임오브젝트 스타트\n";

    }
    virtual void Update() // 기본형이 지정되어 있다고 가정
    {
        cout << "게임오브젝트 업데이트\n";

    }
};

class Player : public GameObject
{
public:
    int HP = 100;
    Player()
    {
        cout << "플레이어 생성\n";
    }
    ~Player()
    {
        cout << "플레이어 소멸\n";
    }
    void Start()
    {
        cout << "플레이어의 HP는" << HP << "입니다\n";
    }
    void Update()
    {
        cout << "플레이어 업데이트\n";
    }
};

class Enemy : public GameObject
{
public:
    int HP = 100;
    Enemy()
    {
        cout << "적 생성\n";
    }
    ~Enemy()
    {
        cout << "적 소멸\n";
    }
    void Start()
    {
        cout << "적의 HP는" << HP <<"입니다\n";
    }
    void Update()
    {
        cout << "적 업데이트\n";
    }
};

int main()
{   
    static bool is_game_running = true;  // 스태틱 변수_다른 파일에서 접근 불가능

    GameObject* p = new Player();
    GameObject* e = new Enemy();


    p->Start(); // 동적 할당을 하게 되면 화살표 모양으로 표기
    e->Start();
    while (is_game_running)
    {
        p->Update();

        e->Update();
        cout << "입력해주세요 (1:게임 종료 , 2:게임 계속): ";
        int input;
        cin >> input;
        if (input == 1)
            is_game_running = false;
        else if (input == 2)
            is_game_running = true;
        else
            cout << "다시 입력해주세요\n";
    };

    delete(p); // 메모리 누수 생김 player가 생성 GameDbject만 제거 
    delete(e);

    return 0;
}
