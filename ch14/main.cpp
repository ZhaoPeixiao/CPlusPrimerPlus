#include<iostream>
using namespace std;

#include"Wine1.h"
#include"Wine2.h"
#include"QueueTp.h"
#include"Worker.h"
#include"Person.h"
#include"emp.h"

void ex1()
{
	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();

	cout << "Total bottles for " << more.Label()
		<< ": " << more.sum() << endl;

	cout << "Bye\n";
}

void ex2()
{
	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	WinePlus holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	WinePlus more("Gushing Grape Red", YRS, y, b);
	more.Show();

	cout << "Total bottles for " << more.Label()
		<< ": " << more.sum() << endl;

	cout << "Bye\n";
}

void ex3()
{
	QueueTp<Worker>* qWorker = new QueueTp<Worker>(20);

	Worker w1("Alice", 0);
	Worker w2("Bob", 1);
	if (qWorker->isempty())
	{
		cout << "Qworker is empty!\n";
	}
	qWorker->enqueue(w1);
	qWorker->enqueue(w2);
	cout << "Qworker count: " << qWorker->queuecount() << endl;
	Worker w3("Calvin", 3);
	qWorker->enqueue(w3);
	qWorker->enqueue(w2);
	cout << "Qworker count: " << qWorker->queuecount() << endl;

	Worker temp;
	qWorker->dequeue(temp);
	cout << "Dequeue: " << endl;
	temp.Show();

	qWorker->dequeue(temp);
	cout << "Dequeue: " << endl;
	temp.Show();

	cout << "Qworker count: " << qWorker->queuecount() << endl;
}

const int SIZE = 5;
void ex4()
{
	int ct, i;
	Person* gang[SIZE];

	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the gang category: \n"
			<< "o: ordinary person  g: gunslinger  "
			<< "p: pokerplayer  b: bad dude  q: quit \n";
		cin >> choice;
		while (strchr("ogpbq", choice) == NULL)
		{
			cout << "Please enter an o, g, p, b, or q: ";
			cin >> choice;
		}

		if (choice == 'q')
			break;

		switch (choice)
		{
		case 'o': gang[ct] = new Person;
			break;
		case 'g': gang[ct] = new Gunslinger;
			break;
		case 'p': gang[ct] = new PokerPlayer;
			break;
		case 'b': gang[ct] = new BadDude;
			break;
		}

		cin.get();
		gang[ct]->Set();
	}

	cout << "\nHere is your gang: \n";
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		gang[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete gang[i];
	cout << "Bye" << endl;
}

void ex5()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();

	highfink hf(ma, "Cury Kew");
	hf.ShowAll();

	cout << "Press a key for next phase:" << endl;
	cin.get();
	highfink hf2;
	hf2.SetAll();

	cout << "Using an abstr_emp * pointer: \n";
	abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();
}

int main()
{
	ex5();

	system("pause");

	return 0;
}