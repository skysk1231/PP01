#pragma once

#include "MCommand.hpp"



class JumpCommand : public Musoeun ::MCommand
{
public:
	void Execute()
	{
		std::cout << "점프\n";
	}
};
class RunCommand : public  Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "달리기\n";
	}
};
class LeftCommand : public  Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "왼쪽\n";
	}
};
class RightCommand : public  Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "오른쪽\n";
	}
};
class DownCommand : public  Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "아래\n";
	}
};
