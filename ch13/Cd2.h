#pragma once
#ifndef CD2_H_
#define CD2_H_

#include<iostream>

class CdPlus
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;

public:
	CdPlus(const char* s1, const char* s2, int n, double x);
	CdPlus(const CdPlus& c);
	CdPlus();
	virtual ~CdPlus();
	virtual void Report() const;
	virtual CdPlus& operator=(const CdPlus& c);
};

class ClassicPlus : public CdPlus
{
private:
	char* mainfiles;

public:
	ClassicPlus(const char* s1, const char* s2, const char* s3, int n, double x);
	ClassicPlus(const CdPlus& c, char* s3);
	ClassicPlus(const ClassicPlus& c);
	ClassicPlus();
	virtual ~ClassicPlus();
	virtual void Report() const;
	virtual ClassicPlus& operator=(const ClassicPlus& c);
};
#endif // !CD2_H_
