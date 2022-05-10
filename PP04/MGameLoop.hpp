#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

using namespace std;
// 메소드를 여러개 만들어서 해결할수 있는가?
// int형의 자료를 받는 개수 만큼 만들어서 값을 해결?
// 꾸준히 랜더링을 해줘야하기 때문에 힘든 상황
// 1개 2개 3개 총 3가지의 메소드를 만들어서 처음 한번 지정해주면 알아서 만들수 있도록?
namespace MuSeoun_Engine
{
	class MGameLoop
	{
	private:
		bool _isGameRunning;
		MConsoleRenderer cRenderer;
		chrono::system_clock::time_point startRenderTimePoint;
		chrono::duration<double> renderDuration;
		Player p;
		Enemy e;
		bool Gameoff = false;

	public:
		MGameLoop() { _isGameRunning = false; }
		~MGameLoop() {}

		void Run()
		{
			_isGameRunning = true;
			Initialize();

			startRenderTimePoint = chrono::system_clock::now();
			while (_isGameRunning)
			{

				Input();
				Update();
				Render();

			}
			Release();
		}
		void Stop()
		{
			_isGameRunning = false; // 게임루프를 멈춤
		}


	private:
		void Initialize()
		{
			int b;
			MakingEnemy( b = rand() % 4);
		}
		void Release()
		{
		}

		void Input()
		{
			if (Gameoff == true)// 게임이 끝났을때 스페이스바를 누르면 다시 시작하게 함
			{
				if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
				{
					Gameoff = false;
					e.x = 50;
				}
			}
			else if (Gameoff == false) // 게임이 끝나지 않으면 플레이어가 점프를 하게 함
			{
				if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
				{

					if (p.y >= 4)
					{
						p.y--;
					}
					this_thread::sleep_for(chrono::milliseconds(20));
				}
				else
				{
					if (p.y <= 6)
					{
						p.y++;
					}
					this_thread::sleep_for(chrono::milliseconds(20));
				}
			}



			if (e.x == 0)
			{
				int b;
				e.x == 50;
				MakingEnemy(b = rand() % 4);
			}


		}
		void Update()
		{
			//string d = "Gameover \n 다시 시작은 스페이스 바를 눌러주세요"; // 게임 오버시 출력 문구
			//if (e.x == p.x && e.y == p.y) // Enemy와 Player의 좌표값을 확인해서 충돌을 확인하는 시스템
			//{
			//	Gameoff = true;
			//	cRenderer.MoveCursor(10, 3);
			//	cRenderer.DrawString(d);
			//	this_thread::sleep_for(chrono::milliseconds(20));
			//}

			if (Gameoff == false) { e.EnemyMove(); } // 게임 오버가 아닐경우 Enemy가 움직이게 함
		}
		void Render()
		{

			cRenderer.Clear(); // 콘솔창을 한번 지워주는 역활

			cRenderer.MoveCursor(p.x, p.y); //x좌표와 y좌표에 p을 찍어 플레이어를 만들어줌
			cRenderer.DrawString("P");
			cRenderer.MoveCursor(10, 20); // FPS를 찍어주는 좌표를 이동

			renderDuration = chrono::system_clock::now() - startRenderTimePoint; //FPS를 찍어주는 역활
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::milliseconds(20));

		}

		void MakingEnemy(int b)
		{
			string d = "Gameover \n 다시 시작은 스페이스 바를 눌러주세요"; // 게임 오버시 출력 문구

			switch (b)
			{
				case 0:
					cRenderer.MoveCursor(e.x, e.y);
					cRenderer.DrawString("E");
					
					if (e.x == p.x && e.y == p.y) // Enemy와 Player의 좌표값을 확인해서 충돌을 확인하는 시스템
					{
						Gameoff = true;
						cRenderer.MoveCursor(10, 3);
						cRenderer.DrawString(d);
						this_thread::sleep_for(chrono::milliseconds(20));
					}

					break;
				case 1:
					cRenderer.MoveCursor(e.x, e.y);
					cRenderer.DrawString("E");
					cRenderer.MoveCursor(e.x, e.y+1);
					cRenderer.DrawString("E");
					if (e.x == p.x && (e.y == p.y || p.y == e.y+1)) // Enemy와 Player의 좌표값을 확인해서 충돌을 확인하는 시스템
					{
						Gameoff = true;
						cRenderer.MoveCursor(10, 3);
						cRenderer.DrawString(d);
						this_thread::sleep_for(chrono::milliseconds(20));
					}
					break;
				case 2:
					cRenderer.MoveCursor(e.x, e.y);
					cRenderer.DrawString("E");
					cRenderer.MoveCursor(e.x, e.y + 1);
					cRenderer.DrawString("E");
					cRenderer.MoveCursor(e.x, e.y + 2);
					cRenderer.DrawString("E");
					if (e.x == p.x && (e.y == p.y || p.y == e.y + 1)) // Enemy와 Player의 좌표값을 확인해서 충돌을 확인하는 시스템
					{
						Gameoff = true;
						cRenderer.MoveCursor(10, 3);
						cRenderer.DrawString(d);
						this_thread::sleep_for(chrono::milliseconds(20));
					}
					break;
				case 3:
					cRenderer.MoveCursor(e.x, e.y + 2);
					cRenderer.DrawString("E");
					cRenderer.MoveCursor(e.x, e.y + 3);
					cRenderer.DrawString("E");
					if (e.x == p.x && (e.y == p.y || p.y == e.y + 1)) // Enemy와 Player의 좌표값을 확인해서 충돌을 확인하는 시스템
					{
						Gameoff = true;
						cRenderer.MoveCursor(10, 3);
						cRenderer.DrawString(d);
						this_thread::sleep_for(chrono::milliseconds(20));
					}
					break;
			}
		}

		//void Cheak() // 플레이어가 닿았는지 확인하는 시스템
		//{
		//	string d = "Gameover \n 다시 시작은 스페이스 바를 눌러주세요"; // 게임 오버시 출력 문구
		//	if (e.x == p.x && e.y == p.y) // Enemy와 Player의 좌표값을 확인해서 충돌을 확인하는 시스템
		//	{
		//		Gameoff = true;
		//		cRenderer.MoveCursor(10, 3);
		//		cRenderer.DrawString(d);
		//		this_thread::sleep_for(chrono::milliseconds(20));
		//	}
		//}

		//cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

		//int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
		//if (remainingFrameTime > 0)
		//	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));




	};






}