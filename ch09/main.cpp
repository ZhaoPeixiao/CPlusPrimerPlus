#include<iostream>
#include<string>
#include <cstring>
#include <cctype>
#include <new>
using namespace std;

#include"golf.h"
#include"sales.h"

void ex1()
{
	golf g[10];
	int n = 0;
	cout << "Enter the information of golf player: " << endl;

	while ((n < 10) && (setgolf(g[n])))
	{
		n++;
		cout << "Next golf player: " << endl;
	}

	cout << "Show all golf player information: " << endl;
	for (int i = 0; i < n; i++)
	{
		showgolf(g[i]);
	}
}

const int ArSize = 10;
void strcount(const string str)
{
	static int total = 0;
	int count = 0;

	cout << "\"" << str << "\" contains ";
	while (str[count])
	{
		count++;
	}
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
void ex2()
{
	string input;
	cout << "Enter a line:\n";
	getline(cin, input);
	while (cin)
	{
		strcount(input);
		cout << "Enter next line (empty line to quit): \n";
		getline(cin, input);
		if (input == "")
		{
			break;
		}
	}

	cout << "Bye\n";
}

struct chaff
{
	char dross[20];
	int slag;
};
char buffer[1024];
void ex3()
{
	chaff* pcha = new (buffer) chaff[2];
	char* pc = new char[1024];
	chaff* pcha2 = new (pc)chaff[2];
	char dross[20] = { 0 };
	int slag = 0;

	for (int i = 0; i < 2; i++)
	{
		cout << "Enter dross of #" << i << " chaff: " << endl;
		cin.getline(dross, 20);
		cout << "Enter slag of #" << i << " chaff: " << endl;
		cin >> slag;
		cin.get();

		strcpy_s(pcha[i].dross, dross);
		strcpy_s(pcha2[i].dross, dross);
		pcha[i].slag = pcha2[i].slag = slag;
	}

	for (int i = 0; i < 2; i++)
	{
		cout << "staff #" << (i + 1) << ":" << endl;
		cout << "pcha.dross: " << pcha[i].dross << ". pcha.slag: " << pcha[i].slag << endl;
		cout << "pcha2.dross: " << pcha2[i].dross << ". pcha2.slag: " << pcha2[i].slag << endl;
	}

	cout << "address of buffer: " << (void*)buffer << endl;
	cout << "address of pcha: " << pcha << ". address of pcha[0]: " << &pcha[0] << ". address of pcha[1]: " << &pcha[1] << endl;
	cout << "address of pc: " << (void*)pc << endl;
	cout << "address of pcha2:" << pcha2 << ". address of pcha2[0]: " << &pcha2[0] << ". address of pcha2[1]: " << &pcha2[1] << endl;;

	delete[] pc;
}

void ex4()
{
	SALES::Sales sales1;
	SALES::Sales sales2;

	double ar[3] = { 32.1, 23.2, 65.3 };
	SALES::setSales(sales1, ar, 3);
	SALES::setSales(sales2);

	SALES::showSales(sales1);
	SALES::showSales(sales2);
}

int main()
{
	ex4();

	system("pause");

	return 0;
}