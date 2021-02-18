#include<iostream>
using namespace std;

#include"Cd1.h"
#include"Cd2.h"

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





int main()
{
	ex2();

	system("pause");

	return 0;
}