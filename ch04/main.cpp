#include<iostream>
#include<string>
#include<vector>
#include<array>
using namespace std;

void ex1()
{
	char firstName[128];
	char lastName[128];
	char letterGrade;
	int age;

	cout << "What is your first name? ";
	cin.getline(firstName, 128);

	cout << "What is your last name? ";
	cin.getline(lastName, 128);

	cout << "What letter grade do you deserve?  ";
	cin >> letterGrade;

	cout << "What is your age? ";
	cin >> age;

	cout << "Name: " << lastName << ", " << firstName << endl;
	cout << "Grade: " << letterGrade << endl;
	cout << "Age: " << age << endl;
}

void ex2()
{
	string name;
	string dessert;

	cout << "Enter your name:\n";
	getline(cin, name);

	cout << "Enter your favourite dessert:\n";
	getline(cin, dessert);

	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
}

void ex3()
{
	char firstName[256];
	char lastName[256];

	cout << "Enter your fitst name:";
	cin.getline(firstName, 256);

	cout << "Enter your last name:";
	cin.getline(lastName, 256);

	cout << "Here's your infomation is a single string: " << lastName << ", " << firstName << endl;
}

void ex4()
{
	string firstName;
	string lastName;

	cout << "Enter your fitst name:";
	getline(cin, firstName);

	cout << "Enter your last name:";
	getline(cin, lastName);

	cout << "Here's your infomation is a single string: " << lastName << ", " << firstName << endl;
}

struct CandyBar
{
public:
	string name;
	double weight;
	int calories;

	CandyBar()
	{
	}

	CandyBar(string name, double weight, int calories)
	{
		this->name = name;
		this->weight = weight;
		this->calories = calories;
	}

	void toString()
	{
		cout << "Name: " << this->name << ", "
			<< "Weight: " << this->weight << ", "
			<< "Calories: " << this->calories << ". "
			<< endl;
	}
};

void ex5()
{
	CandyBar snack("Mocha Munch", 2.3, 350);
	snack.toString();
}

void ex6()
{
	CandyBar candybars[3] = {
		{"Mocha Munch", 2.3, 350},
		{"Banana", 3.5, 400},
		{"HAHAHAHA", 3.0, 370}
	};

	for (int i = 0; i < sizeof(candybars) / sizeof(CandyBar); i++)
	{
		candybars[i].toString();
	}
}

struct PizzaInfo
{
	friend void ex8();

private:
	string mBrand;
	double mSize;
	double mWeight;

public:
	PizzaInfo();

	PizzaInfo(string brand, double size, double weight);

	void setBrand(string brand);
	void setSize(double size);
	void setWeight(double weight);

	void toString();
};

PizzaInfo::PizzaInfo()
{
}

PizzaInfo::PizzaInfo(string brand, double size, double weight)
{
	mBrand = brand;
	mSize = size;
	mWeight = weight;
}

void PizzaInfo::setBrand(string brand)
{
	mBrand = brand;
}

void PizzaInfo::setSize(double size)
{
	mSize = size;
}

void PizzaInfo::setWeight(double weight)
{
	mWeight = weight;
}

void PizzaInfo::toString()
{
	cout << "Brand: " << mBrand << ", "
		<< "Size: " << mSize << ", "
		<< "Weight: " << mWeight << ". "
		<< endl;
}

void ex7()
{
	string brand;
	double size;
	double weight;

	cout << "Enter the pizza company name: ";
	getline(cin, brand);

	cout << "Enter the pizza size: ";
	cin >> size;

	cout << "Enter the pizza weight: ";
	cin >> weight;

	PizzaInfo pizza(brand, size, weight);
	pizza.toString();
}

void ex8()
{
	PizzaInfo* pizza = new PizzaInfo;

	string brand;
	double size;
	double weight;

	cout << "Enter the pizza size: ";
	cin >> size;
	//pizza->mSize = size;
	pizza->setSize(size);

	cout << "Enter the pizza company name: ";
	getline(cin, brand);
	//pizza->mBrand = brand;
	pizza->setBrand(brand);

	cout << "Enter the pizza weight: ";
	cin >> weight;
	//pizza->mWeight = weight;
	pizza->setWeight(weight);

	pizza->toString();

	delete pizza;
}

void ex9()
{
	CandyBar* candyBars = new CandyBar[3];
	candyBars[0] = { "Mocha Munch", 2.3, 350 };
	candyBars[1] = { "Banana", 3.5, 400 };
	candyBars[2] = { "HAHAHAHA", 3.0, 370 };

	for (int i = 0; i < 3; i++)
	{
		candyBars[i].toString();
	}

	delete[] candyBars;
}

void ex10(int a)
{
	vector<double> times;
	double time = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the " << (i + 1) << "th results time of runing 40 meters: ";
		cin >> time;
		times.push_back(time);
	}

	double sum = 0.0;
	cout << "Result: " << endl;
	for (auto t : times)
	{
		sum += t;
		cout << t << endl;
	};

	cout << "Avg: " << sum / 3 << endl;
}

void ex10()
{
	array<double, 3> times;
	double avgTime = 0.0;

	printf("Enter three results time of runing 40 meters: \n");
	cin >> times[0];
	cin >> times[1];
	cin >> times[2];

	avgTime = (times[0] + times[1] + times[2]) / 3;
	cout << "Result: " << times[0] << ", " << times[1] << ", " << times[2] << endl;
	cout << "Average result: " << avgTime << endl;;
}

int main()
{
	ex10();

	system("pause");

	return 0;
}