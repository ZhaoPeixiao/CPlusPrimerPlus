#pragma once
#include<iostream>

namespace SALES
{
	const int QUARTERS = 4;
	class Sales
	{
	private:
		double sales[QUARTERS];
		double average;
		double max;
		double min;

	public:
		Sales(double ar[], int n);
		Sales();
		void showSales();
	};
}