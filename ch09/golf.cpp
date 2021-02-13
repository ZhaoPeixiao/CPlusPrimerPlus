#include"golf.h"

void setgolf(golf& g, const char* name, int hc)
{
	strcpy_s(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g)
{
	cout << "Please enter the full name of golf player: ";
	cin.getline(g.fullname, Len);
	if (strcmp(g.fullname, "") == 0)
	{
		return 0;
	}
	cout << "Please enter the hanicap of golf player: ";
	cin >> g.handicap;
	cin.get();

	return 1;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	cout << "full name of golf player: " << g.fullname << endl;
	cout << "handicap of golf player: " << g.handicap << endl;
}