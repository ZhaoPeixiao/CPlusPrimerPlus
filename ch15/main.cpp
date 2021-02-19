#include<iostream>
#include<cmath>
#include<typeinfo>
using namespace std;

#include"tv.h"
#include"exception.h"
#include"exceptionPlus.h"
#include"sales.h"

void ex1()
{
	Tv t;
	t.settings();

	Remote r;
	r.show_gmode();

	r.onoff(t);
	t.settings();

	t.set_gmode(r);
	r.show_gmode();
}

double hmean(double a, double b);
double gmean(double a, double b);
void ex2()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}
		catch (HmeanExcp& he)
		{
			cout << he.what();
			cout << "Try again.\n";
			continue;
		}
		catch (GmeanExcp& ge)
		{
			cout << ge.what();
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}
	}

	cout << "Bye!\n";
}

double hmean(double a, double b)
{
	if (a == -b)
		throw HmeanExcp();
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw GmeanExcp();
	return std::sqrt(a * b);
}

double hmean_plus(double a, double b);
double gmean_plus(double a, double b);
void ex3()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try {                  // start of try block
			z = hmean_plus(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean_plus(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}// end of try block
		catch (hmean_error& he)    // start of catch block
		{
			he.mesg();
			cout << "Try again.\n";
			continue;
		}
		catch (gmean_error& ge)
		{
			ge.mesg();
			cout << "Sorry, you don't get to play any more.\n";
			break;
		} // end of catch block
		catch (arg_error& ae)
		{
			ae.mesg();
			cout << "Sorry, you don't get to play any more.\n";
			break;
		}
	}
	cout << "Bye!\n";
}

double hmean_plus(double a, double b)
{
	if (a == -b)
		throw hmean_error(a, b, "hmean()");
	return 2.0 * a * b / (a + b);
}

double gmean_plus(double a, double b)
{
	if (a < 0 || b < 0)
		throw gmean_error(a, b, "gmean()");
	return std::sqrt(a * b);
}

void ex4()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double vals1[12] =
	{
		1220, 1100, 1122, 2212, 1232, 2334,
		2884, 2393, 3302, 2922, 3002, 3544
	};

	double vals2[12] =
	{
		12, 11, 22, 21, 32, 34,
		28, 29, 33, 29, 32, 35
	};

	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);

	cout << "First try block:\n";
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{
			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i <= 12; ++i)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n";
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		if (typeid(bad) == typeid(LabeledSales::nbad_index))
		{
			cout << "Company: " << ((LabeledSales::nbad_index&)bad).label_val() << endl;
		}
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "\nNext try block:\n";
	try
	{
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block 2.\n";
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		if (typeid(bad) == typeid(LabeledSales::nbad_index))
		{
			cout << "Company: " << ((LabeledSales::nbad_index&)bad).label_val() << endl;
		}
		cout << "bad index: " << bad.bi_val() << endl;
	}
	cout << "done\n";
}

int main()
{
	ex4();

	system("pause");

	return 0;
}