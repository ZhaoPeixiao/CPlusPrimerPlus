#define _CRT_SECURE_NO_WARNINGS
#include"Stock.h"
#include<cstring>
#include<iostream>
using namespace std;

Stock::Stock()
{
	int len = strlen("no name");
	company = new char[len + 1];
	strcpy(company, "no name");
	company[len] = '\0';

	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr)
{
	int len = strlen(co);
	company = new char[len + 1];
	strcpy(company, co);
	company[len] = '\0';

	if (n < 0)
	{
		cout << "Number of shares can't be negative; "
			<< company << " shares set to n.\n";
		shares = 0;
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	delete[] company;
	company = nullptr;
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show() const
{
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = cout.precision(3);

	cout << "Company: " << company
		<< " Shares: " << shares << '\n';
	cout << "Share Price: $" << share_val;
	cout.precision(2);
	cout << " Total Worth: $" << total_val << '\n';

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

ostream& operator<<(ostream& os, const Stock& st)
{
	ios_base::fmtflags orig =
		os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "Company: " << st.company
		<< " Shares: " << st.shares << '\n';
	os << " Share Price: $" << st.share_val;
	os.precision(2);
	os << " Total Worth: $" << st.total_val << '\n';

	os.setf(orig, ios_base::floatfield);
	os.precision(prec);

	return os;
}

const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
	{
		return s;
	}
	else
	{
		return *this;
	}
}