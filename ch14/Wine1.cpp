#include"Wine1.h"

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
	pArray = PairArray(ArrayInt(y), ArrayInt(y));
	label = l;
	year = y;
	for (int i = 0; i < y; i++)
	{
		pArray.first()[i] = yr[i];
		pArray.second()[i] = bot[i];
	}
}

Wine::Wine(const char* l, int y)
{
	pArray = PairArray(ArrayInt(y), ArrayInt(y));
	label = l;
	year = y;
	for (int i = 0; i < y; i++)
	{
		pArray.first()[i] = 0;
		pArray.second()[i] = 0;
	}
}

Wine::~Wine()
{
}

void Wine::GetBottles()
{
	cout << "Enter " << label << " data for " << year << " year(s):" << endl;
	for (int i = 0; i < year; i++)
	{
		cout << "Enter year: ";
		cin >> pArray.first()[i];
		cout << "Enter bootles for that year: ";
		cin >> pArray.second()[i];
	}
}

void Wine::Show()
{
	cout << "Wine: " << label << endl;
	cout << "  Year    Bottles" << endl;
	for (int i = 0; i < year; i++)
	{
		cout << "  " << pArray.first()[i] << " " << pArray.second()[i] << endl;
	}
}

string& Wine::Label()
{
	return label;
}

int Wine::sum()
{
	int sum = 0;
	for (int i = 0; i < year; i++)
	{
		sum += pArray.second()[i];
	}

	return sum;
}