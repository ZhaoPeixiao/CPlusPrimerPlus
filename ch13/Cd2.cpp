#define _CRT_SECURE_NO_WARNINGS
#include"Cd2.h"

#include<cstring>
using namespace std;

CdPlus::CdPlus(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];

	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

CdPlus::CdPlus(const CdPlus& c)
{
	performers = new char[strlen(c.performers) + 1];
	label = new char[strlen(c.label) + 1];

	strcpy(performers, c.performers);
	strcpy(label, c.label);
	selections = c.selections;
	playtime = c.playtime;
}

CdPlus::CdPlus()
{
	int null_length = strlen("null");
	performers = new char[null_length + 1];
	label = new char[null_length + 1];

	std::strcpy(performers, "null");
	std::strcpy(label, "null");
	selections = 0;
	playtime = 0;
}

CdPlus::~CdPlus()
{
	delete[] performers;
	delete[] label;

	performers = nullptr;
	label = nullptr;
}

void CdPlus::Report() const
{
	cout << "Performers: " << performers << endl;
	cout << "Label: " << label << endl;
	cout << "Selections: " << selections << endl;
	cout << "Playtime: " << playtime << endl;
}

CdPlus& CdPlus::operator=(const CdPlus& c)
{
	delete[] performers;
	delete[] label;
	performers = nullptr;
	label = nullptr;

	performers = new char[strlen(c.performers) + 1];
	label = new char[strlen(c.label) + 1];

	strcpy(performers, c.performers);
	strcpy(label, c.label);
	selections = c.selections;
	playtime = c.playtime;

	return *this;
}

ClassicPlus::ClassicPlus(const char* s1, const char* s2, const char* s3, int n, double x) :
	CdPlus(s1, s2, n, x)
{
	mainfiles = new char[strlen(s3) + 1];
	strcpy(mainfiles, s3);
}

ClassicPlus::ClassicPlus(const CdPlus& c, char* s3) : CdPlus(c)
{
	mainfiles = new char[strlen(s3) + 1];
	strcpy(mainfiles, s3);
}

ClassicPlus::ClassicPlus(const ClassicPlus& c) :CdPlus(c)
{
	mainfiles = new char[strlen(c.mainfiles) + 1];
	strcpy(mainfiles, c.mainfiles);
}

ClassicPlus::ClassicPlus() :CdPlus()
{
	int null_length = strlen("null");
	mainfiles = new char[null_length + 1];
	strcpy(mainfiles, "null");
}

ClassicPlus::~ClassicPlus()
{
	delete[] mainfiles;
	mainfiles = nullptr;
}

void ClassicPlus::Report() const
{
	CdPlus::Report();
	cout << "Mainfile: " << mainfiles << endl;
}

ClassicPlus& ClassicPlus::operator=(const ClassicPlus& c)
{
	CdPlus::operator=(c);
	delete[] mainfiles;
	mainfiles = nullptr;
	mainfiles = new char[strlen(c.mainfiles) + 1];
	strcpy(mainfiles, c.mainfiles);

	return *this;
}