#pragma once

#include "MCommand.hpp"



class JumpCommand : public Musoeun ::MCommand
{
public:
	void Execute()
	{
		std::cout << "����\n";
	}
};
class RunCommand : public  Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "�޸���\n";
	}
};
class LeftCommand : public  Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "����\n";
	}
};
class RightCommand : public  Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "������\n";
	}
};
class DownCommand : public  Musoeun::MCommand
{
public:
	void Execute()
	{
		std::cout << "�Ʒ�\n";
	}
};
