#pragma once
#ifndef WINE1_H_
#define WINE1_H_

#include<iostream>
#include<array>
#include<string>
#include<valarray>
#include"Pairs.h"
using namespace std;

typedef valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:
	int year;
	string label;
	PairArray pArray;

public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	~Wine();
	void GetBottles();
	void Show();
	string& Label();
	int sum();
};

#endif // !WINE1_H_
