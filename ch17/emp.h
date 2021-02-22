#pragma once
#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum title { employee, manager, fink, high_fink };

class abstr_emp
{
private:
	string fname;
	string lname;
	string pos;

public:
	abstr_emp();
	abstr_emp(const string& fn, const string& ln, const string& p);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual ofstream& WriteAll(ofstream& ofs) const;
	friend ostream& operator<<(ostream& os, const abstr_emp& emp);
	virtual ~abstr_emp() = 0;
};

class Employee : virtual public abstr_emp
{
public:
	Employee();
	Employee(const string& fn, const string& ln, const string& p);
	virtual void ShowAll() const;
	virtual void SetAll();
	std::ofstream& WriteAll(std::ofstream& fout) const;
};

class Manager : virtual public abstr_emp
{
private:
	int inchargeof;

protected:
	int InChargeOf() const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }

public:
	Manager();
	Manager(const string& fn, const string& ln, const string& p, int ico = 0);
	Manager(const abstr_emp& e, int ico);
	Manager(const Manager& m);
	virtual void ShowAll() const;
	virtual void SetAll();
	std::ofstream& WriteAll(std::ofstream& fout) const;
};

class Fink : virtual public abstr_emp
{
private:
	string reportsto;

protected:
	const string ReportsTo() const { return reportsto; }
	string& ReportsTo() { return reportsto; }

public:
	Fink();
	Fink(const string& fn, const string& ln, const string& p, const string& rpo);
	Fink(const abstr_emp& e, const string& rpo);
	Fink(const Fink& f);
	virtual void ShowAll() const;
	virtual void SetAll();
	std::ofstream& WriteAll(std::ofstream& fout) const;
};

class HighFink : public Manager, public Fink
{
public:
	HighFink();
	HighFink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo,
		int ico);
	HighFink(const abstr_emp& e, const std::string rpo, int ico);
	HighFink(const Fink& f, int ico);
	HighFink(const Manager& m, const std::string rpo);
	HighFink(const HighFink& h);
	virtual void ShowAll() const;
	virtual void SetAll();
	std::ofstream& WriteAll(std::ofstream& fout) const;
};

#endif // !EMP_H_
