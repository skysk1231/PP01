#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

using namespace std;
// �޼ҵ带 ������ ���� �ذ��Ҽ� �ִ°�?
// int���� �ڷḦ �޴� ���� ��ŭ ���� ���� �ذ�?
// ������ �������� ������ϱ� ������ ���� ��Ȳ
// 1�� 2�� 3�� �� 3������ �޼ҵ带 ���� ó�� �ѹ� �������ָ� �˾Ƽ� ����� �ֵ���?
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
			_isGameRunning = false; // ���ӷ����� ����
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
			if (Gameoff == true)// ������ �������� �����̽��ٸ� ������ �ٽ� �����ϰ� ��
			{
				if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
				{
					Gameoff = false;
					e.x = 50;
				}
			}
			else if (Gameoff == false) // ������ ������ ������ �÷��̾ ������ �ϰ� ��
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
			//string d = "Gameover \n �ٽ� ������ �����̽� �ٸ� �����ּ���"; // ���� ������ ��� ����
			//if (e.x == p.x && e.y == p.y) // Enemy�� Player�� ��ǥ���� Ȯ���ؼ� �浹�� Ȯ���ϴ� �ý���
			//{
			//	Gameoff = true;
			//	cRenderer.MoveCursor(10, 3);
			//	cRenderer.DrawString(d);
			//	this_thread::sleep_for(chrono::milliseconds(20));
			//}

			if (Gameoff == false) { e.EnemyMove(); } // ���� ������ �ƴҰ�� Enemy�� �����̰� ��
		}
		void Render()
		{

			cRenderer.Clear(); // �ܼ�â�� �ѹ� �����ִ� ��Ȱ

			cRenderer.MoveCursor(p.x, p.y); //x��ǥ�� y��ǥ�� p�� ��� �÷��̾ �������
			cRenderer.DrawString("P");
			cRenderer.MoveCursor(10, 20); // FPS�� ����ִ� ��ǥ�� �̵�

			renderDuration = chrono::system_clock::now() - startRenderTimePoint; //FPS�� ����ִ� ��Ȱ
			startRenderTimePoint = chrono::system_clock::now();
			string fps = "FPS : " + to_string(1.0 / renderDuration.count());
			cRenderer.DrawString(fps);

			this_thread::sleep_for(chrono::milliseconds(20));

		}

		void MakingEnemy(int b)
		{
			string d = "Gameover \n �ٽ� ������ �����̽� �ٸ� �����ּ���"; // ���� ������ ��� ����

			switch (b)
			{
				case 0:
					cRenderer.MoveCursor(e.x, e.y);
					cRenderer.DrawString("E");
					
					if (e.x == p.x && e.y == p.y) // Enemy�� Player�� ��ǥ���� Ȯ���ؼ� �浹�� Ȯ���ϴ� �ý���
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
					if (e.x == p.x && (e.y == p.y || p.y == e.y+1)) // Enemy�� Player�� ��ǥ���� Ȯ���ؼ� �浹�� Ȯ���ϴ� �ý���
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
					if (e.x == p.x && (e.y == p.y || p.y == e.y + 1)) // Enemy�� Player�� ��ǥ���� Ȯ���ؼ� �浹�� Ȯ���ϴ� �ý���
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
					if (e.x == p.x && (e.y == p.y || p.y == e.y + 1)) // Enemy�� Player�� ��ǥ���� Ȯ���ؼ� �浹�� Ȯ���ϴ� �ý���
					{
						Gameoff = true;
						cRenderer.MoveCursor(10, 3);
						cRenderer.DrawString(d);
						this_thread::sleep_for(chrono::milliseconds(20));
					}
					break;
			}
		}

		//void Cheak() // �÷��̾ ��Ҵ��� Ȯ���ϴ� �ý���
		//{
		//	string d = "Gameover \n �ٽ� ������ �����̽� �ٸ� �����ּ���"; // ���� ������ ��� ����
		//	if (e.x == p.x && e.y == p.y) // Enemy�� Player�� ��ǥ���� Ȯ���ؼ� �浹�� Ȯ���ϴ� �ý���
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