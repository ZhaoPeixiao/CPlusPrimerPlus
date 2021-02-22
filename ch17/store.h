#pragma once
#ifndef STORE_H_
#define STORE_H_

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Store
{
private:
	ostream& os;

public:
	Store(ostream& o) : os(o) {}
	void operator()(const string& s);
};

void Store::operator()(const string& s)
{
	size_t len = s.size();

	os.write((char*)&len, sizeof(size_t));
	os.write(s.data(), len);
}

#endif // !STORE_H_
