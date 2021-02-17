#pragma once
#ifndef STOCK_H_
#include<iostream>
using namespace std;
class Stock
{
private:
	char* company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; };

public:
	Stock();
	Stock(const char* co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double proce);
	void update(double price);
	void show() const;
	friend ostream& operator<<(ostream& os, const Stock& st);
	const Stock& topval(const Stock& s) const;
};

#endif // !STOCK_H_
