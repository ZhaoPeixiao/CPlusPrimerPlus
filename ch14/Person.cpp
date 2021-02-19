#include <iostream>
#include <cstdlib>
#include <ctime>
#include "person.h"

void Person::Data() const
{
	std::cout << firstname << std::endl;
	std::cout << lastname << std::endl;
}

void Person::Show() const
{
	Data();
}

void Person::Set()
{
	std::cout << "Enter firstname: ";
	std::cin >> firstname;
	std::cout << "Enter lastname: ";
	std::cin >> lastname;
}

void Gunslinger::Data() const
{
	std::cout << "Draw: " << drawtime << std::endl;
	std::cout << "Notches: " << notches << std::endl;
}

void Gunslinger::Show() const
{
	Person::Data();
	Data();
}

void Gunslinger::Set()
{
	Person::Set();
	std::cout << "Enter Drawtime: ";
	std::cin >> drawtime;
	std::cout << "Enter Notches: ";
	std::cin >> notches;
}

int PokerPlayer::Draw() const
{
	srand(time(0));
	return int(rand()) % 52;
}

void BadDude::Data() const
{
	Gunslinger::Data();
	PokerPlayer::Data();
}

void BadDude::Show() const
{
	Data();
}

void BadDude::Set()
{
	Gunslinger::Set();
}