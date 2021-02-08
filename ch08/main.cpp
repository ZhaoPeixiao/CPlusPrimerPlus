#include<iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

void PrintString(char* str, int printTimes = 0)
{
	cout << "String: " << str << " , print_times: " << printTimes << endl;
	if (printTimes > 1)
	{
		printTimes--;
		PrintString(str, printTimes);
	}
}
void ex1()
{
	char str[128];
	int printTimes = 0;
	cout << "Enter the string you want to print: ";
	cin.getline(str, 128);
	cout << "Enter the times you want to print: ";
	cin >> printTimes;
	cout << "Test two prematers: " << endl;
	PrintString(str, printTimes);
	cout << "Test one premater: " << endl;
	PrintString(str);
}

struct CandyBar
{
	char brand[128];
	double weight;
	int heat;
};
void PrintCandybar(const CandyBar& candybar)
{
	cout << "CandyBar brand: " << candybar.brand << endl;
	cout << "CandyBar weight: " << candybar.weight << endl;
	cout << "CandyBar heat: " << candybar.heat << endl;
}
void FillCandybar(CandyBar& candybar, char* brand, double weight, int heat)
{
	strcpy_s(candybar.brand, brand);
	candybar.weight = weight;
	candybar.heat = heat;
}
void ex2()
{
	CandyBar candybar;
	char brand[128];
	double weight = 0.0;
	int heat = 0;

	cout << "Enter the company of candybar: ";
	cin.getline(brand, 128);

	cout << "Enter the weight of candybar: ";
	cin >> weight;

	cout << "Enter the heat of candybar: ";
	cin >> heat;

	FillCandybar(candybar, brand, weight, heat);
	PrintCandybar(candybar);
}

void ToUpperCase(string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	cout << str << endl;
}
void ex3()
{
	string input;

	cout << "Enter a string (q to quit): ";

	getline(cin, input);
	while (input != "q")
	{
		ToUpperCase(input);
		cout << "Enter a string (q to quit): ";
		getline(cin, input);
	}
}

struct stringy
{
	char* str;
	int ct;
};
void set(stringy& input, char* str)
{
	int len = strlen(str);
	input.str = new char(len + 1);
	input.str = str;
	input.ct = len;
}
void show(const stringy& input, int times = 1)
{
	for (int i = 0; i < times; i++)
	{
		cout << "member string of struct stringy: " << input.str << endl;
	}
}
void show(const char* str, int times = 1)
{
	for (int i = 0; i < times; i++)
	{
		cout << "char string: " << str << endl;
	}
}
void ex4()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!");
}

template<class T>
T max5(T arr[])
{
	T max = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
void ex5()
{
	int intArray[5] = { 32, 43, 66, 23, 54 };
	double doubleArray[5] = { 32.4, 33.3, 61.3, 646.3, 23.5 };

	int intArrayMax = max5(intArray);
	double doubleArrayMax = max5(doubleArray);

	cout << "max of int array: " << intArrayMax << endl;
	cout << "max of double array: " << doubleArrayMax << endl;
}

template<class T>
T maxn(T arr[], int size)
{
	T max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
template <> const char* maxn(const char* arr[], int size)
{
	const char* max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (strlen(max) < strlen(arr[i]))
		{
			max = arr[i];
		}
	}
	return max;
}
void ex6()
{
	int int_array[6] = { 43, 235, 54, 232, 123, 65 };
	double double_array[4] = { 32.1, 453.2, 53.3, 67.4 };
	const char* str_array[5] = { "Hello Jimmy!", "Hello World!", "ABCDEFG,HIJKLMN", "Today is a goood day!", "C++ Primer Plus!" };

	int int_max = maxn(int_array, 6);
	double double_max = maxn(double_array, 4);
	const char* length_max_str = maxn(str_array, 5);

	cout << "max of int array: " << int_max << endl;
	cout << "max of double array: " << double_max << endl;
	cout << "max length string of string array: " << length_max_str << endl;
}

template<typename T>
T SumArray(T arr[], int n);

template<typename T>
T SumArray(T* arr[], int n);

struct debts
{
	char name[50];
	double amount;
};
void ex7()
{
	int thing[6] = { 13, 31, 103, 301, 310, 130 };
	int int_sum = 0;
	struct debts mr_E[3] =
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double* pd[3];
	double double_sum = 0.0;

	for (size_t i = 0; i < 3; i++)
	{
		pd[i] = &mr_E[i].amount;
	}

	int_sum = SumArray(thing, 6);
	double_sum = SumArray(pd, 3);

	cout << "Sum of int array: " << int_sum << endl;
	cout << "Sum of double* array: " << double_sum << endl;
}

template<class T>
T SumArray(T arr[], int n)
{
	T sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}

template<typename T>
T SumArray(T* arr[], int n)
{
	T sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += *(arr[i]);
	}
	return sum;
}

int main()
{
	ex7();

	system("pause");

	return 0;
}