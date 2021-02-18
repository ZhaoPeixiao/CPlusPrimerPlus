#define _CRT_SECURE_NO_WARNINGS
#include"Port.h"

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}

Port::Port(const Port& p)
{
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
	delete[] brand;

	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;

	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;

	return *this;
}

Port& Port::operator-=(int b)
{
	bottles -= b;

	return *this;
}

void Port::Show() const
{
	cout << "Brand: " << brand << endl;
	cout << "Style: " << style << endl;
	cout << "Bottles: " << bottles << endl;
}

ostream& operator<<(ostream& os, const Port& s)
{
	os << s.brand << ", " << s.style << ", " << s.bottles;

	return os;
}

VintagePort::VintagePort() : Port()
{
	nickname = new char[strlen("null") + 1];
	std::strcpy(nickname, "null");
	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) :
	Port(br, "Vintage", b)
{
	nickname = new char[strlen(nn) + 1];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp)
{
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	delete nickname;
	Port::operator=(vp);

	nickname = new char[strlen(vp.nickname) + 1];
	strcpy(nickname, vp.nickname);
	year = vp.year;

	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	cout << "Nickname: " << nickname << endl;
	cout << "Year: " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << Port(vp);
	os << ", " << vp.nickname << ", " << vp.year;

	return os;
}