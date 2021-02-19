#pragma once
#ifndef WINE2_H_
#define WINE2_H_

#include<iostream>
#include<string>
#include<valarray>
#include"Pairs.h"
using namespace std;

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class WinePlus :public PairArray, public string
{
private:
	int year;

public:
	WinePlus(const char* l, int y, const int yr[], const int bot[]);
	WinePlus(const char* l, int y);
	~WinePlus();
	void GetBottles();
	void Show();
	std::string& Label();
	int sum();
};

#endif // !WINE2_H_
