#include"sales.h"

namespace SALES
{
	using namespace std;

	void setSales(Sales& s, const double ar[], int n)
	{
		double total = 0.0;
		double max = ar[0];
		double min = ar[0];

		for (int i = 0; i < n; i++)
		{
			total += ar[i];
			s.sales[i] = ar[i];

			max = max > ar[i] ? max : ar[i];
			min = min < ar[i] ? min : ar[i];
		}

		for (int i = n; i < QUARTERS; i++)
		{
			s.sales[i] = 0.0;
		}

		s.average = total / n;
		s.max = max;
		s.min = min;
	}

	void setSales(Sales& s)
	{
		double total = 0.0;
		double max = 0.0;
		double min = 0.0;
		double input = 0.0;

		cout << "Enter 4 double number; " << endl;
		for (size_t i = 0; i < QUARTERS; i++)
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
			s.sales[i] = input;
		}
		s.average = total / QUARTERS;
		s.max = max;
		s.min = min;
	}

	void showSales(const Sales& s)
	{
		cout << "sales: ";
		for (size_t i = 0; i < QUARTERS; i++)
		{
			cout << s.sales[i] << " ";
		}

		cout << endl;
		cout << "average: " << s.average << endl;
		cout << "max: " << s.max << endl;
		cout << "min: " << s.min << endl;
	}
}