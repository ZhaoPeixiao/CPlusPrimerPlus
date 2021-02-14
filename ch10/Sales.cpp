#include"Sales.h"

using namespace std;
using namespace SALES;

Sales::Sales()
{
	double total = 0.0;
	double max = 0.0;
	double min = 0.0;
	double input = 0.0;

	cout << "Enter 4 double number; " << endl;
	for (int i = 0; i < QUARTERS; i++)
	{
		cin >> input;
		if (i == 0)
		{
			max = input;
			min = input;
		}

		max = max > input ? max : input;
		min = min < input ? min : input;

		total += input;
		sales[i] = input;
	}
	this->average = total / QUARTERS;
	this->max = max;
	this->min = min;
}

Sales::Sales(double ar[], int n)
{
	double total = 0.0;
	double max = ar[0];
	double min = ar[0];

	for (int i = 0; i < n; i++)
	{
		total += ar[i];
		sales[i] = ar[i];

		max = max > ar[i] ? max : ar[i];
		min = min < ar[i] ? min : ar[i];
	}
	for (int i = n; i < QUARTERS; i++)
	{
		sales[i] = 0.0;
	}

	this->average = total / n;
	this->max = max;
	this->min = min;
}

void Sales::showSales()
{
	cout << "sales: ";
	for (size_t i = 0; i < QUARTERS; i++)
	{
		cout << sales[i] << " ";
	}

	cout << endl;
	cout << "average: " << average << endl;
	cout << "max: " << max << endl;
	cout << "min: " << min << endl;
}