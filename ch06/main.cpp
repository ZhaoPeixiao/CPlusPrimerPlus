#include<iostream>
#include<cctype>
#include<string>
#include<array>
#include<iomanip>
#include<fstream>
using namespace std;

void ex1()
{
	char ch = 0;
	while ((ch = cin.get()) != '@')
	{
		if (isdigit(ch))
		{
			continue;
		}
		else if (islower(ch))
		{
			cout << (char)toupper(ch);
		}
		else if (isupper(ch))
		{
			cout << (char)tolower(ch);
		}
	}

	cout << "Done!" << endl;
}

void ex2()
{
	const int SIZE = 10;
	double donations[SIZE] = { 0 };
	double donation = 0.0;
	int index = 0;
	double sum = 0.0;
	double avg = 0.0;

	cout << "Please enter up to ten double value, Non-digital to exit: " << endl;
	while (index < SIZE && (cin >> donation))
	{
		sum += donation;
		donations[index] = donation;
		index++;
	}
	avg = (index == 0 ? 0.0 : (sum / index));
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (donations[i] > avg)
		{
			count++;
		}
	}

	cout << "The average value is " << avg << ", and there are " << count << " double value large than agerage value!" << endl;
}

void ex3()
{
	char ch = 0;
	cout << "Please enter one of the following choices: " << endl;
	cout.flags(ios::left);
	cout << setw(20) << "c) carnivore" << "p) pianist" << endl;
	cout << setw(20) << "t) tree" << "g) game" << endl;
	bool bExit = false;

	while (!bExit && cin >> ch)
	{
		switch (ch)
		{
		case 'c':
			cout << "Tyrannosaurus rex is a carnivore." << endl;
			bExit = true;
			break;

		case 'p':
			cout << "Langlang is a pianist." << endl;
			bExit = true;
			break;

		case 't':
			cout << "A maple is a tree." << endl;
			bExit = true;
			break;

		case 'g':
			cout << "Dota2 is a game." << endl;
			bExit = true;
			break;

		default:
			cout << "Please enter a c, p, t or g: " << endl;
			break;
		}
	}
}

const int strsize = 50;
struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};
void diplayByName(const bop* bopArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << bopArray[i].fullname << endl;
	}
}
void displayByTitle(const bop* bopArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << bopArray[i].title << endl;
	}
}
void displayByBopname(const bop* bopArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << bopArray[i].bopname << endl;
	}
}
void displayByPreference(const bop* bopArray, const int size)
{
	for (int i = 0; i < size; i++)
	{
		switch (bopArray[i].preference)
		{
		case 0:
			cout << bopArray[i].fullname << endl;
			break;
		case 1:
			cout << bopArray[i].title << endl;
			break;
		case 2:
			cout << bopArray[i].bopname << endl;
			break;
		default:
			cout << bopArray[i].fullname << endl;
			break;
		}
	}
}

void ex4()
{
	const bop bopArray[5] = {
		{"Wimp Macho", "YYY", "Y----", 0},
		{"XXXXXXXX", "2XXXX", "3XXXXX", 1},
		{"AAAAAAAA", "2AAAA", "3AAAAA", 2},
		{"BBBBBBBB", "2BBBB", "3BBBBB", 0},
		{"CCCCCCCC", "4CCCC", "3CCCCC", 1}
	};

	char choice = 0;
	cout << "Benevolent Order of Proframers Report" << endl;
	cout << left << setw(30) << "a. display by name" << "b. display by title" << endl;
	cout << left << setw(30) << "c. display by bopname" << "d. display by preference" << endl;
	cout << left << setw(30) << "q. quit" << endl;
	cout << "Enter your choice: ";

	while (cin >> choice)
	{
		if (choice == 'q')
		{
			break;
		}
		switch (choice)
		{
		case 'a':
			diplayByName(bopArray, 5);
			break;

		case 'b':
			displayByTitle(bopArray, 5);
			break;

		case 'c':
			displayByBopname(bopArray, 5);
			break;

		case 'd':
			displayByPreference(bopArray, 5);
			break;
		default:
			break;
		}
		cout << "Next choice:";
	}
	cout << "Bye!" << endl;
	return;
}

const double RATE1 = 0.1;
const double RATE2 = 0.15;
const double RATE3 = 0.2;

void ex5()
{
	double salary = 0.0;
	double tax = 0.0;

	cout << "Please enter your salary:";
	while ((cin >> salary) && salary > 0)
	{
		if (salary <= 5000)
		{
			tax = 0.0;
		}
		else if (5000 < salary && salary <= 15000)
		{
			tax = (salary - 5000) * RATE1;
		}
		else if (15000 < salary && salary <= 35000)
		{
			tax = (15000 - 5000) * RATE1 + (salary - 15000) * RATE2;
		}
		else
		{
			tax = (15000 - 5000) * RATE1 + (35000 - 15000) * RATE2 + (salary - 35000) * RATE3;
		}

		cout << "salary = " << salary << ", tax = " << tax << endl;
	}
}

struct member
{
	string name;
	double amount;
};

void ex6()
{
	int contributors = 0;
	int count = 0;

	cout << "Enter the number of contributors:";
	cin >> contributors;
	cin.get();

	member* pContributors = new member[contributors];

	for (size_t i = 0; i < contributors; i++)
	{
		cout << "Enter the name of " << i + 1 << " contributor: ";
		getline(cin, pContributors[i].name);

		cout << "Enter the amount of donation: ";
		cin >> pContributors[i].amount;
		cin.get();
	}

	cout << "Grand Pators:" << endl;
	for (size_t i = 0; i < contributors; i++)
	{
		if (pContributors[i].amount > 10000)
		{
			cout << "Contributor name: " << pContributors[i].name << endl;
			cout << "Contrubutor amount: " << pContributors[i].amount << endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "none" << endl;
	}

	count = 0;
	cout << "Pators:" << endl;
	for (size_t i = 0; i < contributors; i++)
	{
		if (pContributors[i].amount < 10000)
		{
			cout << "Contributor name: " << pContributors[i].name << endl;
			cout << "Contrubutor amount: " << pContributors[i].amount << endl;
		}
	}
	if (count == 0)
	{
		cout << "none" << endl;
	}
}

void ex7()
{
	int vowels = 0;
	int consonants = 0;
	int others = 0;
	string input;

	cout << "Enter words (q to quit): " << endl;

	while (cin >> input)
	{
		if (input.length() == 1 && input[0] == 'q')
		{
			break;
		}

		if (isalpha(input[0]))
		{
			if (input[0] == 'a' || input[0] == 'e' || input[0] == 'i' || input[0] == 'o' || input[0] == 'u')
			{
				vowels++;
			}
			else
			{
				consonants++;
			}
		}
		else
		{
			others++;
		}
	}

	cout << vowels << " words beginning with vowels" << endl;
	cout << consonants << " words beginning with consonants" << endl;
	cout << others << " otners" << endl;
}

void ex8()
{
	string fileName;
	ifstream ifs;
	unsigned int num = 0;
	char ch = 0;

	cout << "Enter the file name:";
	getline(cin, fileName);

	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "File Not Opend!" << endl;
	}
	else
	{
		while ((ch = ifs.get()) != EOF)
		{
			//cout << ch;
			num++;
		}
	}

	cout << "There are " << num << " characters in " << fileName << " file." << endl;
}

void ex9()
{
	unsigned int contributors = 0;
	unsigned int count = 0;
	string fileName;
	ifstream ifs;

	cout << "Enter the file name:";
	getline(cin, fileName);

	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "File Not Opend!" << endl;
	}
	else
	{
		ifs >> contributors;
		ifs.get();

		member* pContributors = new member[contributors];

		for (size_t i = 0; i < contributors; i++)
		{
			//      cout << "Enter the name of " << i + 1 << " contributor: ";
			getline(ifs, pContributors[i].name);

			//      cout << "Enter the amount of donation: ";
			ifs >> pContributors[i].amount;
			ifs.get();
		}

		cout << "Grand Pators:" << endl;
		for (size_t i = 0; i < contributors; i++)
		{
			if (pContributors[i].amount > 10000)
			{
				cout << "Contributor name: " << pContributors[i].name << endl;
				cout << "Contrubutor amount: " << pContributors[i].amount << endl;
				count++;
			}
		}
		if (count == 0)
		{
			cout << "none" << endl;
		}

		count = 0;
		cout << "Pators:" << endl;
		for (size_t i = 0; i < contributors; i++)
		{
			if (pContributors[i].amount < 10000)
			{
				cout << "Contributor name: " << pContributors[i].name << endl;
				cout << "Contrubutor amount: " << pContributors[i].amount << endl;
				count++;
			}
		}
		if (count == 0)
		{
			cout << "none" << endl;
		}
	}
}

int main()
{
	ex9();

	system("pause");

	return 0;
}