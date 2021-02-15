#pragma once
#ifndef STONEWT2_H_
#include<iostream>
using namespace std;

class Stonewt2
{
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;

public:
	Stonewt2(double lbs);
	Stonewt2(int stn, double lbs);
	Stonewt2();
	~Stonewt2();
	void show_lbs() const;
	void show_stn() const;

	bool operator==(const Stonewt2& st) const;
	bool operator!=(const Stonewt2& st) const;
	bool operator<(const Stonewt2& st) const;
	bool operator>(const Stonewt2& st) const;
	bool operator<=(const Stonewt2& st) const;
	bool operator>=(const Stonewt2& st) const;
};

#endif // !STONEWT2_H_
