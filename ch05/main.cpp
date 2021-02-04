#include<iostream>
#include<array>
#include<string>
using namespace std;

void ex1()
{
	int nStrat = 0;
	int nEnd = 0;

	cout << "Enter the start number: ";
	cin >> nStrat;

	cout << "Enter the end number: ";
	cin >> nEnd;

	int sum = 0;
	for (int i = nStrat; i <= nEnd; i++)
	{
		sum += i;
	}

	cout << "Sum = " << sum << endl;
}

const int ArrSize = 100;
void ex2()
{
	array<long double, ArrSize + 1> factorials;
	factorials[0] = factorials[1] = 1.0;
	for (int i = 2; i <= ArrSize; i++)
	{
		factorials[i] = i * factorials[i - 1];
	}

	for (int i = 0; i <= ArrSize; i++)
	{
		cout << i << "! = " << factorials[i] << endl;
	}
}

void ex3()
{
	int sum = 0;
	int nInput = 0;

	while (1)
	{
		cout << "Enter a number( 0 to exit): ";
		cin >> nInput;
		if (nInput == 0)
		{
			break;
		}
		sum += nInput;
		cout << "Until now, the sum of the number you inputed is " << sum << endl;
	}
	cout << "Done." << endl;
}

void ex4()
{
	double accountAaphne = 100;
	double accountCleo = 100;
	int year = 0;

	while (accountAaphne >= accountCleo)
	{
		accountAaphne += 10;
		accountCleo *= 1.05;
		year++;
	}
	cout << "After " << year << " years. " << "Cleo account which is "
		<< accountCleo << " will more than Daphne account which is "
		<< accountAaphne << "." << endl;
}

void ex5()
{
	string month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "Septempber", "October", "November", "December" };
	int sell[12];
	int totalSale = 0;

	cout << "Enter the sales of book <C++ for Fools> each month: " << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << month[i] << ": ";
		cin >> sell[i];
		totalSale += sell[i];
	}
	cout << "The total sales is " << totalSale << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << month[i] << ": " << sell[i] << endl;
	}
}

void ex6()
{
	string month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "Septempber", "October", "November", "December" };
	int sales[3][12] = { 0 };
	int totalSales[3] = { 0 };

	for (int i = 0; i < 3; i++)
	{
		cout << "Enter " << i + 1 << " year(s) sales of book <C++ for Fools> each month: " << endl;
		for (int j = 0; j < 12; j++)
		{
			cout << month[j] << ": ";
			cin >> sales[i][j];
			totalSales[i] += sales[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << " year(s) total sales is " << totalSales[i] << endl;
	}

	cout << "Three years total sales is " << totalSales[0] + totalSales[1] + totalSales[2] << endl;
}

struct Car
{
	string maker;
	int madeYear;
};

void ex7()
{
	int size = 0;
	cout << "How many cars do you wish to catalog? ";
	cin >> size;
	cin.get();

	Car* pCar = new Car[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Car #" << i + 1 << ":" << endl;
		cout << "Please enter the make: ";
		getline(cin, pCar[i].maker);

		cout << "Please enter the year make: ";
		cin >> pCar[i].madeYear;
		cin.get();
	}

	cout << "Here is your collection:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << pCar[i].maker << " " << pCar[i].madeYear << endl;
	}

	delete[] pCar;
}

void ex8()
{
	int nWord = 0;
	char cInput[128];

	cout << "Enter words (to stop, type the word done):" << endl;
	while (cin >> cInput)
	{
		if (strcmp(cInput, "done"))
		{
			nWord++;
		}
		else {
			break;
		}
	}
	cout << "You entered a total of " << nWord << " words." << endl;
}

void ex9()
{
	int nWord = 0;
	string input;

	cout << "Enter words (to stop, type the word done):" << endl;
	while (cin >> input)
	{
		if (input != "done")
		{
			nWord++;
		}
		else
		{
			break;
		}
	}

	cout << "You entered a total of " << nWord << " words." << endl;
}

void ex10()
{
	int nRow = 0;
	cout << "Enter number of rows: ";
	cin >> nRow;

	for (int i = 0; i < nRow; i++)
	{
		for (int j = 0; j < nRow - i - 1; j++)
		{
			cout << ".";
		}
		for (int j = nRow - i - 1; j < nRow; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

int main()
{
	ex10();

	system("pause");
	return 0;
}