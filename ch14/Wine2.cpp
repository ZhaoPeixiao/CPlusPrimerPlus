#include"Wine2.h"

WinePlus::WinePlus(const char* l, int y, const int yr[], const int bot[]) :
	string(l), PairArray(ArrayInt(y), ArrayInt(y))
{
	year = y;
	for (int i = 0; i < year; i++)
	{
		PairArray::first()[i] = yr[i];
		PairArray::second()[i] = bot[i];
	}
}

WinePlus::WinePlus(const char* l, int y) :
	string(l), PairArray(ArrayInt(y), ArrayInt(y))
{
	year = y;
	for (int i = 0; i < y; i++)
	{
		PairArray::first()[i] = 0;
		PairArray::second()[i] = 0;
	}
}

WinePlus::~WinePlus()
{
}

void WinePlus::GetBottles()
{
	cout << "Enter " << (const std::string)*this << " data for " << year
		<< " year(s): " << endl;
	for (int i = 0; i < year; i++)
	{
		cout << "Enter year: ";
		cin >> PairArray::first()[i];
		cout << "Enter bootles for that year: ";
		cin >> PairArray::second()[i];
	}
}

void WinePlus::Show()
{
	cout << "Wine: " << (const std::string)*this << endl;
	cout << "  Year    Bootles" << endl;
	for (int i = 0; i < year; i++)
	{
		cout << "  " << PairArray::first()[i] << " "
			<< PairArray::second()[i] << endl;
	}
}

string& WinePlus::Label()
{
	return (string&)*this;
}

int WinePlus::sum()
{
	int sum = 0;
	for (int i = 0; i < year; i++)
	{
		sum += PairArray::second()[i];
	}

	return sum;
}