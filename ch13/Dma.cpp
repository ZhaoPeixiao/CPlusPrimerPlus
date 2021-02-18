#define _CRT_SECURE_NO_WARNINGS
#include"Dma.h"

#include<iostream>
#include<cstring>
using namespace std;

DMA::DMA()
{
}

DMA::~DMA()
{
}

BaseDMA::BaseDMA(const char* l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}

BaseDMA::BaseDMA(const BaseDMA& rs)
{
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}

BaseDMA::~BaseDMA()
{
	delete[] label;
	label = nullptr;
}

BaseDMA& BaseDMA::operator=(const BaseDMA& rs)
{
	delete[] label;
	label = nullptr;

	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;

	return *this;
}

ostream& operator<<(ostream& os, const BaseDMA& rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating;

	return os;
}

void BaseDMA::View()
{
	cout << "Label: " << label << endl;
	cout << "Rating: " << rating << endl;
}

LacksDMA::LacksDMA(const char* c, const char* l, int r) : BaseDMA(l, r)
{
	strcpy(color, c);
}

LacksDMA::LacksDMA(const char* c, const BaseDMA& rs) : BaseDMA(rs)
{
	strcpy(color, c);
}

ostream& operator<<(ostream& os, const LacksDMA& rs)
{
	operator<<(os, (BaseDMA)rs) << endl;
	os << "Color: " << rs.color;

	return os;
}

void LacksDMA::View()
{
	BaseDMA::View();
	cout << "Color: " << color << endl;
}

HasDMA::HasDMA(const char* s, const char* l, int r) :
	BaseDMA(l, r)
{
	int style_length = std::strlen(s);
	style = new char[style_length + 1];

	std::strcpy(style, s);
}

HasDMA::HasDMA(const char* s, const BaseDMA& rs) :
	BaseDMA(rs)
{
	int style_length = std::strlen(s);
	style = new char[style_length + 1];

	std::strcpy(style, s);
}

HasDMA::HasDMA(const HasDMA& hs) :
	BaseDMA(hs)
{
	int style_length = std::strlen(hs.style);
	style = new char[style_length + 1];

	std::strcpy(style, hs.style);
}

HasDMA::~HasDMA()
{
	delete[] style;
	style = nullptr;
}

HasDMA& HasDMA::operator=(const HasDMA& rs)
{
	BaseDMA::operator=(rs);
	delete[] style;

	int style_length = std::strlen(rs.style);
	style = new char[style_length + 1];

	std::strcpy(style, rs.style);

	return *this;
}

std::ostream& operator<<(std::ostream& os, const HasDMA& rs)
{
	operator<<(os, BaseDMA(rs)) << std::endl;
	os << "Style: " << rs.style;

	return os;
}

void HasDMA::View()
{
	BaseDMA::View();
	std::cout << "Style: " << style << std::endl;
}