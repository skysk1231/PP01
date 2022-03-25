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
		//std::cout << "초기화 중\n";

	}

	void Update()
	{
		//std::cout << "Update 중\n";

	}

	void Render()
	{
		//std::cout << "Rendering 중\n";
	}

	void Input()
	{
		int input;
		std::cin >> input;
		//std::cout << "입력 중\n";

		Key[input]->Execute();
	}
	void Release()
	{
		for (size_t i = 0; i < 5; i++)
		{
			delete(Key[i]);
		}
		//std::cout << "Release 중\n";
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