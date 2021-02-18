#include<iostream>
#include<string>
using namespace std;

#include"Cd1.h"
#include"Cd2.h"
#include"Dma.h"
#include"Port.h"

void Bravo(const Cd& disk)
{
	disk.Report();
}
void ex1()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;

	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function whit a cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
}

void Bravo(const CdPlus& disk)
{
	disk.Report();
}
void ex2()
{
	CdPlus c1("Beatles", "Capitol", 14, 35.5);
	ClassicPlus c2 = ClassicPlus("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	CdPlus* pcd = &c1;

	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function whit a cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	ClassicPlus copy;
	copy = c2;
	copy.Report();
}

const int CLIMENTS = 5;
void ex3()
{
	BaseDMA* dma[CLIMENTS];
	string label;
	int rating;
	char choice;
	string color;
	string style;

	for (int i = 0; i < CLIMENTS; i++)
	{
		cout << "Enter lable: ";
		getline(cin, label);
		cout << "Enter rating: ";
		cin >> rating;
		cout << "Enter 1 for baseDMA or 2"
			" for lacksDMA or 3 for hasDMA: ";
		while (cin >> choice && (choice != '1' && choice != '2' && choice != '3'))
		{
			cout << "Enter 1 or 2 or 3: ";
		}
		while (cin.get() != '\n');
		if (choice == '1')
		{
			dma[i] = new BaseDMA(label.c_str(), rating);
		}
		else if (choice == '2')
		{
			cout << "Enter color: ";
			getline(cin, color);
			dma[i] = new LacksDMA(color.c_str(), label.c_str(), rating);
		}
		else
		{
			cout << "Enter style: ";
			getline(cin, style);
			dma[i] = new HasDMA(style.c_str(), label.c_str(), rating);
		}
	}
	cout << endl;
	for (int i = 0; i < CLIMENTS; i++)
	{
		dma[i]->View();
		cout << endl;
	}

	for (int i = 0; i < CLIMENTS; i++)
	{
		delete dma[i];
	}

	cout << "Done.\n";
}

void ex4()
{
	Port port1("Gallo", "tawny", 20);
	VintagePort vp("None", 20, "The Noble", 1997);

	port1.Show();
	vp.Show();

	VintagePort vp2 = vp;
	Port port2 = port1;

	cout << vp2 << endl;
	cout << port2 << endl;
}

int main()
{
	ex4();

	system("pause");

	return 0;
}