#pragma once
#ifndef STONEWT1_H_
#define STONEWT1_H_
#include<iostream>
using namespace std;

class Stonewt1
{
public:
	enum format { STONES, IPOUND, DPOUND };
private:
	enum { Lbs_per_stn = 14 };
	format ft;
	int stone;
	int ipounds;
	double dpounds;

	double total;
	void update();
public:
	Stonewt1();
	Stonewt1(double n, format f = STONES);
	format get_format() const { return ft; };
	int get_stone() const { return stone; };
	int get_ipounds() const { return ipounds; };
	int get_dpounds() const { return dpounds; };

	Stonewt1 operator+(double n) const;
	Stonewt1 operator-(double n) const;
	Stonewt1 operator*(double n) const;

	friend Stonewt1 operator+(double n, const Stonewt1& st);
	friend Stonewt1 operator-(double n, const Stonewt1& st);
	friend Stonewt1 operator*(double n, const Stonewt1& st);

	friend ostream& operator<<(ostream& os, const Stonewt1& st);
};

#endif // !STONEWT1_H_
