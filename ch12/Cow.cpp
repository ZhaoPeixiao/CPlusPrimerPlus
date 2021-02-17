#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Cow.h"
using namespace std;

Cow::Cow()
{
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strncpy(name, nm, 20);
	int ho_length = strlen(ho);
	hobby = new char[ho_length + 1];
	strncpy(hobby, ho, ho_length);
	hobby[ho_length] = '\0';
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strncpy_s(name, c.name, 20);
	int ho_length = strlen(c.hobby);
	hobby = new char[ho_length + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
	hobby = nullptr;
}

Cow& Cow::operator=(const Cow& c)
{
	delete[] hobby;
	strncpy_s(name, c.name, 20);
	int ho_length = strlen(c.hobby);
	hobby = new char[ho_length + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	cout << "Cow name: " << name << endl;
	cout << "Cow hobby: " << hobby << endl;
	cout << "Cow weight: " << weight << endl;
}