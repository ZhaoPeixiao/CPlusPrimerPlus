#define _CRT_SECURE_NO_WARNINGS
#include "Cd1.h"

#include <cstring>
#include<ios>
using namespace std;

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	strcpy(performers, "null");
	strcpy(label, "null");
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
	cout << "Performers: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "Playtime: " << playtime << endl;
}

Cd& Cd::operator=(const Cd& d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

// Classic
Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x) :
	Cd(s1, s2, n, x)
{
	strcpy(mainfile, s3);
}

Classic::Classic(const Cd& d, char* s3) : Cd(d)
{
	strcpy(mainfile, s3);
}

Classic::Classic(const Classic& d) : Cd(d)
{
	strcpy(mainfile, d.mainfile);
}

Classic::Classic() : Cd()
{
	strcpy(mainfile, "null");
}

Classic::~Classic()
{
}

void Classic::Report() const
{
	Cd::Report();
	cout << "Mainfile: " << mainfile << endl;
}

Classic& Classic::operator=(const Classic& d)
{
	Cd::operator=(d);
	strcpy(mainfile, d.mainfile);
	return *this;
}