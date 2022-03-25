#pragma once

namespace Musoeun
{
	MCommand* Key[5];

	void Initialize()
	{
		Key[0] = new LeftCommand();
		Key[1] = new RightCommand();
		Key[2] = new DownCommand();
		Key[3] = new JumpCommand();
		Key[4] = new RunCommand();
		//std::cout << "�ʱ�ȭ ��\n";

	}

	void Update()
	{
		//std::cout << "Update ��\n";

	}

	void Render()
	{
		//std::cout << "Rendering ��\n";
	}

	void Input()
	{
		int input;
		std::cin >> input;
		//std::cout << "�Է� ��\n";

		Key[input]->Execute();
	}
	void Release()
	{
		for (size_t i = 0; i < 5; i++)
		{
			delete(Key[i]);
		}
		//std::cout << "Release ��\n";
	}


	class MGameLoop
	{
	public:
		bool isGameRunning = false;
		MGameLoop() {}
		~MGameLoop() {}

		void Run()
		{
			isGameRunning = true;

			Initialize();

			while (isGameRunning)
			{
				Input();
				Update();
				Render();
			}
			Release();
		}
	};
}