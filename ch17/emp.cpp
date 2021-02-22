#include"emp.h"

abstr_emp::abstr_emp()
{
	fname = "Null";
	lname = "Null";
	pos = "Null";
}

abstr_emp::abstr_emp(const string& fn, const string& ln, const string& p)
{
	fname = fn;
	lname = ln;
	pos = p;
}

abstr_emp::~abstr_emp()
{
}

void abstr_emp::ShowAll() const
{
	cout << "firstname: " << fname << std::endl;
	cout << "lastname: " << lname << std::endl;
	cout << "position: " << pos << std::endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter firstname: ";
	std::getline(std::cin, fname);
	cout << "Enter lastname: ";
	std::getline(std::cin, lname);
	cout << "Enter job: ";
	getline(std::cin, pos);
}

ofstream& abstr_emp::WriteAll(std::ofstream& fout) const
{
	fout << fname << " " << lname << " " << pos;
	return fout;
}

ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << e.lname << " " << e.fname << ", " << e.pos;
	return os;
}

Employee::Employee()
{
}

Employee::Employee(const string& fn, const string& ln, const string& p) :abstr_emp(fn, ln, p)
{
}

void Employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void Employee::SetAll()
{
	abstr_emp::SetAll();
}

std::ofstream& Employee::WriteAll(std::ofstream& fout) const
{
	fout << employee << " ";
	abstr_emp::WriteAll(fout);
	return fout;
}

Manager::Manager()
{
	inchargeof = 0;
}

Manager::Manager(const std::string& fn, const std::string& ln,
	const std::string& j, int ico)
	: abstr_emp(fn, ln, j), inchargeof(ico)
{
}

Manager::Manager(const abstr_emp& e, int ico)
	: abstr_emp(e)
{
	inchargeof = ico;
}

Manager::Manager(const Manager& m)
	: abstr_emp(m)
{
	inchargeof = m.inchargeof;
}

void Manager::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "Inchargeof: " << inchargeof << std::endl;
}

void Manager::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter inchargeof: ";
	std::cin >> inchargeof;
	std::cin.get();
}

std::ofstream& Manager::WriteAll(std::ofstream& fout) const
{
	fout << manager << " ";
	abstr_emp::WriteAll(fout);
	fout << " " << inchargeof;
	return fout;
}

Fink::Fink()
{
	reportsto = "none";
}

Fink::Fink(const string& fn, const string& ln, const string& p, const string& rpo)
	: abstr_emp(fn, ln, p), reportsto(rpo)
{
}

Fink::Fink(const abstr_emp& e, const std::string& rpo)
	: abstr_emp(e), reportsto(rpo)
{
}

Fink::Fink(const Fink& f)
	: abstr_emp(f)
{
	reportsto = f.reportsto;
}

void Fink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "Reportsto: " << reportsto << std::endl;
}

void Fink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter reportsto: ";
	std::getline(std::cin, reportsto);
}

std::ofstream& Fink::WriteAll(std::ofstream& fout) const
{
	fout << fink << " ";
	abstr_emp::WriteAll(fout);
	fout << " " << reportsto;
	return fout;
}

HighFink::HighFink() {}

HighFink::HighFink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo,
	int ico)
	: abstr_emp(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo)
{
}

HighFink::HighFink(const abstr_emp& e, const std::string rpo, int ico)
	: abstr_emp(e), Manager(e, ico), Fink(e, rpo)
{
}

HighFink::HighFink(const Fink& f, int ico)
	: abstr_emp(f), Fink(f), Manager((const abstr_emp&)f, ico)  // ????
{
}

HighFink::HighFink(const Manager& m, const std::string rpo)
	: abstr_emp(m), Manager(m), Fink((const abstr_emp&)m, rpo)
{
}

HighFink::HighFink(const HighFink& h)
	: abstr_emp(h), Manager(h), Fink(h)
{
}

void HighFink::ShowAll() const
{
	abstr_emp::ShowAll();
	std::cout << "Inchargeof: " << Manager::InChargeOf() << std::endl;
	std::cout << "Reportsto: " << Fink::ReportsTo() << std::endl;
}

void HighFink::SetAll()
{
	abstr_emp::SetAll();
	std::cout << "Enter reportsto: ";
	getline(std::cin, Fink::ReportsTo());
	std::cout << "Enter Inchargeof: ";
	std::cin >> Manager::InChargeOf();
	std::cin.get();
}

std::ofstream& HighFink::WriteAll(std::ofstream& fout) const
{
	fout << high_fink << " ";
	abstr_emp::WriteAll(fout);
	fout << " " << Manager::InChargeOf() << " " << Fink::ReportsTo();
	return fout;
}