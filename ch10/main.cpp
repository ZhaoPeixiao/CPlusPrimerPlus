#include<iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

#include"Sales.h"
#include"MyStack.h"
#include"MyList.h"

class BankAccount
{
private:
	string m_fullname;
	string m_banknumber;
	long m_balance;

public:
	BankAccount() {}

	BankAccount(string fullname, string banknumber, long balance)
	{
		m_fullname = fullname;
		m_banknumber = banknumber;
		m_balance = balance;
	}
	void showAccount()
	{
		cout << "BankCount full name: " << m_fullname << endl;
		cout << "BankCount number: " << m_banknumber << endl;
		cout << "BankCount balance: " << m_balance << endl;
	}
	void deposit(long amount)
	{
		m_balance += amount;
	}
	void withdraw(long amount)
	{
		m_balance -= amount;
	}
};
void ex1()
{
	BankAccount account("Jack", "123456", 1000);
	cout << "Original BankCount: " << endl;
	account.showAccount();

	cout << endl;
	cout << "After Deposit 5000: " << endl;
	account.deposit(5000);
	account.showAccount();

	cout << endl;
	cout << "After withdrawals 5000: " << endl;
	account.deposit(5000);
	account.showAccount();
}

class Person
{
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() { lname = ""; fname[0] = '\0'; }
	Person(const string& ln, const char* fn = "Heyyou");
	void Show() const;
	void FormalShow() const;
};
Person::Person(const string& ln, const char* fn)
{
	lname = ln;
	strncpy_s(fname, fn, LIMIT);
}
void Person::Show() const
{
	cout << fname << ", " << lname << endl;
}
void Person::FormalShow() const
{
	cout << lname << ", " << fname << endl;
}
void ex2()
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	one.FormalShow();

	cout << endl;
	two.Show();
	two.FormalShow();

	cout << endl;
	three.Show();
	three.FormalShow();
}

class golf
{
private:
	static const int LEN = 40;
	char fullname[LEN];
	int handicap;
public:
	golf();
	golf(const char* name, int hc);
	void setHandicap(int hc);
	void showGolf();
};
golf::golf()
{
	char tmp[LEN] = "";
	int hc = 0;
	cout << "Please enter the full name of golf player: ";
	cin.getline(tmp, LEN);
	cout << "Please enter the hanicap of golf player: ";
	cin >> hc;

	*this = golf(tmp, hc);
}
golf::golf(const char* name, int hc)
{
	strncpy_s(fullname, name, LEN);
	handicap = hc;
}
void golf::setHandicap(int hc)
{
	handicap = hc;
}
void golf::showGolf()
{
	cout << "golf full name: " << fullname << endl;
	cout << "golf handicap: " << handicap << endl;
}
void ex3()
{
	golf g1;
	golf g2("Jack", 100);

	g1.showGolf();
	g1.setHandicap(50);
	g1.showGolf();
}

using namespace SALES;
void ex4()
{
	double ar[3] = { 32.1, 23.2, 65.3 };
	Sales sales1(ar, 3);
	Sales sales2;

	sales1.showSales();
	sales2.showSales();
}

void ex5()
{
	MyStack stack;
	double total = 0.0;
	customer top;

	customer customer1 = { "jimmy", 1000 };

	if (stack.push(customer1))
	{
		cout << customer1.fullname << " push." << endl;
	}
	else
	{
		cout << "Stack full." << endl;
	}

	customer customer2 = { "hey", 200.0 };

	if (stack.push(customer2))
	{
		cout << customer2.fullname << " push." << endl;
	}
	else
	{
		cout << "Stack full." << endl;
	}

	if (stack.pop(top))
	{
		cout << top.fullname << " pop." << endl;
		total += top.payment;
	}
	else
		cout << "Stack empty." << endl;

	customer customer3 = { "kitty", 3000.0 };
	if (stack.push(customer3))
		cout << customer3.fullname << " push." << endl;
	else
		cout << "Stack full." << endl;

	if (stack.pop(top))
	{
		cout << top.fullname << " pop." << endl;
		total += top.payment;
	}
	else
		cout << "Stack empty." << endl;

	if (stack.pop(top))
	{
		cout << top.fullname << " pop." << endl;
		total += top.payment;
	}
	else
		cout << "Stack empty." << endl;

	if (stack.pop(top))
	{
		cout << top.fullname << " pop." << endl;
		total += top.payment;
	}
	else
		cout << "Stack empty." << endl;

	cout << "Total paymemt: " << total << endl;
}

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showMove() const;
	Move add(const Move& m) const;
	void reset(double a = 0, double b = 0);
};
Move::Move(double a, double b)
{
	x = a;
	y = b;
}
void Move::showMove() const
{
	cout << "x = " << x << ", y = " << y << "." << endl;
}
Move Move::add(const Move& m) const
{
	Move tmp;
	tmp.x = this->x + m.x;
	tmp.y = this->y + m.y;

	return tmp;
}
void Move::reset(double a, double b)
{
	x = a;
	y = b;
}
void ex6()
{
	Move move1(1.1, 2.2);
	move1.showMove();

	Move move2(3.3, 4.4);
	move2.showMove();

	Move move3 = move1.add(move2);
	move3.showMove();

	move3.reset(0.1, 0.2);
	move3.showMove();
}

class plorg
{
private:
	enum { LEN = 20 };
	char fullname[LEN];
	int CI;
public:
	plorg(const char* name = "Plorga", int CI = 50);
	void setCI(int CI);
	void showPlorg();
};
plorg::plorg(const char* name, int CI)
{
	strncpy_s(fullname, name, LEN);
	this->CI = CI;
}
void plorg::setCI(int CI)
{
	this->CI = CI;
}
void plorg::showPlorg()
{
	cout << "plorg full name: " << fullname << endl;
	cout << "plorg CI: " << CI << endl;
}
void ex7()
{
	plorg pl("Jimmy", 100);
	pl.showPlorg();

	plorg pl2;
	pl2.showPlorg();

	pl.setCI(150);
	pl.showPlorg();
}

void ex8()
{
	MyList list;
	if (list.isempty())
	{
		cout << "List is empty" << endl;
	}

	uItem item1 = 1;
	uItem item2 = 2;
	uItem item3 = 3;

	list.add(item1);
	list.add(item2);
	list.add(item3);

	if (list.isempty())
	{
		cout << "List is empty" << endl;
	}
	else if (list.isfull())
	{
		cout << "List is full" << endl;
	}
	else
	{
		cout << "Some items in the list" << endl;
	}

	list.visit(oringin);
	list.visit(x2);
	list.visit(half);
}

int main()
{
	ex8();

	system("pause");

	return 0;
}