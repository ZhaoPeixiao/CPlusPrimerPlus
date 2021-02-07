#include<iostream>
#include <string>
#include <cctype>
using namespace std;

void ex1()
{
	double x, y;
	double avg = 0.0;

	cout << "Enter two numbers: ";
	cin >> x >> y;
	while (x != 0 && y != 0)
	{
		avg = 2.0 * x * y / (x + y);
		cout << "The average of " << x << " and " << y << " is " << avg << endl;

		cout << "Enter the next two numbers: ";
		cin >> x >> y;
	}
}

void GetInput(double* grade, unsigned int* number)
{
	cout << "You can enter up to 10 grades( -1 to quit): " << endl;
	while (cin >> grade[(*number)++])
	{
		if (grade[*number - 1] == -1)
		{
			break;
		}
	}
	(*number)--;
}
void PrintArray(const double* grade, const unsigned int number)
{
	cout << "The grade is: " << endl;

	for (unsigned int i = 0; i < number; i++)
	{
		cout << grade[i] << " ";
	}

	cout << endl;
}
void CalAvg(const double* grade, const unsigned int number)
{
	double sum = 0.0;
	for (unsigned int i = 0; i < number; i++)
	{
		sum += grade[i];
	}
	cout << "Avg = " << sum / number << endl;
}
void ex2()
{
	double grade[10];
	unsigned int number = 0;

	GetInput(grade, &number);
	PrintArray(grade, number);
	CalAvg(grade, number);
}

struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void PrintBoxByValue(box mBox)
{
	cout << "Box maker: " << mBox.maker << endl;
	cout << "Box height: " << mBox.height << endl;
	cout << "Box width: " << mBox.width << endl;
	cout << "Box length: " << mBox.length << endl;
	cout << "Box volume: " << mBox.volume << endl;
}
void CalBoxVolume(box* pBox)
{
	pBox->volume = pBox->height * pBox->height * pBox->length;
}
void ex3()
{
	struct box mbox = { "Jimmy Chen", 0.25, 4.0, 1.0, 0.0 };
	PrintBoxByValue(mbox);
	CalBoxVolume(&mbox);
	PrintBoxByValue(mbox);
}

long double GetProbability(unsigned int number, unsigned picks)
{
	long double result = 1.0;
	long double n = 0;
	unsigned p;
	for (n = number, p = picks; p > 0; n--, p--)
	{
		result = result * n / p;
	}

	return result;
}
void ex4()
{
	cout << "You have on chance in ";
	cout << GetProbability(47, 5) * GetProbability(27, 1);
	cout << " of winning.\n" << endl;
}

long long factorial(unsigned int number)
{
	if (number == 0 || number == 1)
	{
		return 1;
	}
	else
	{
		return number * factorial(number - 1);
	}
}
void ex5()
{
	long long result = 0;
	unsigned int input = 0;

	while (1)
	{
		cout << "Please enter the next number: ";
		cin >> input;

		if (input == -1)
		{
			break;
		}
		result = factorial(input);
		cout << "The result of " << input << "! is " << result << "." << endl;
	}
}

int Fill_array(double doubleArray[], int length)
{
	int nInput = 0;
	cout << "Enter double numbers (non-digital to quit): " << endl;
	for (size_t i = 0; i < length; i++)
	{
		if (cin >> doubleArray[i])
		{
			nInput++;
		}
		else
		{
			break;
		}
	}

	return nInput;
}
void Show_array(double doubleArray[], int length)
{
	cout << "The double array is :" << endl;
	for (size_t i = 0; i < length; i++)
	{
		cout << doubleArray[i] << " ";
		if ((i + 1) % 5 == 0)
		{
			cout << endl;
		}
	}
	if (length % 5 != 0)
	{
		cout << endl;
	}
}
void Reverse_array(double doubleArray[], int length)
{
	cout << "Revert the array" << endl;
	for (size_t i = 0; i < length / 2; i++)
	{
		double tmp = doubleArray[i];
		doubleArray[i] = doubleArray[length - 1 - i];
		doubleArray[length - 1 - i] = tmp;
	}
}
void ex6()
{
	double array[10];
	int nLen = 0;
	nLen = Fill_array(array, 10);
	Show_array(array, nLen);
	Reverse_array(array, nLen);
	Show_array(array, nLen);
}

int fill_array(double* arrBegin, double* arrEnd)
{
	double temp;
	int i = 0;
	double* pArr = nullptr;
	for (pArr = arrBegin; pArr != arrEnd; pArr++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
			{
				continue;
			}
			cout << "Bad input; input preocess terminated.\n";
			break;
		}
		else if (temp < 0)
		{
			break;
		}

		*pArr = temp;
		i++;
	}
	return i;
}
void show_array(const double* arrBegin, const double* arrEnd)
{
	const double* pArr = nullptr;
	int i = 0;
	for (pArr = arrBegin; pArr != arrEnd; pArr++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << *pArr << endl;
		i++;
	}
}
void revalue(double* arrBegin, double* arrEnd, double r)
{
	double* pArr = nullptr;
	for (pArr = arrBegin; pArr != arrEnd; pArr++)
	{
		*pArr *= r;
	}
}
const int MAX = 5;
void ex7()
{
	double properties[MAX];
	int size = fill_array(properties, properties + MAX);
	show_array(properties, properties + size);
	if (size > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(properties, properties + size, factor);
		show_array(properties, properties + size);
	}

	cout << "Done.\n";
}

const int Seasons = 4;
const char* Snames[Seasons] = { "Spring", "Summer", "Fall", "Winter" };
struct cost
{
	double expenses[Seasons];
};
void fill(double* pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}
void show(double* pa)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << pa[i] << endl;
		total += pa[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
void fill(struct cost* pCost)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pCost->expenses[i];
	}
}
void show(struct cost* pCost)
{
	double total = 0.0;
	cout << "\nEXPENSE\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << pCost->expenses[i] << endl;
		total += pCost->expenses[i];
	}
	cout << "Total Expense: $" << total << endl;
}
void ex8()
{
	// situation a
	cout << "Situation a: " << endl;
	double pa[Seasons] = { 0 };
	fill(pa);
	show(pa);

	// situation b
	cout << endl << endl;
	cout << "Situation b: " << endl;
	struct cost* pCost = new struct cost;
	fill(pCost);
	show(pCost);
	delete pCost;
}

const int SLEN = 30;
struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
int getinfo(student pa[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the infomation of student #" << i + 1 << endl;
		cout << "Enter full name (blank line to quit): ";
		cin.getline(pa[i].fullname, SLEN);
		cout << "Enter hobby: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << "Enter ooplevel: ";
		cin >> pa[i].ooplevel;
		while (cin.get() != '\n')
			continue;
		count++;
	}
	return count;
}
void display1(student st)
{
	cout << "Using display1(student st): " << endl;
	cout << "Full name: " << st.fullname << endl;
	cout << "Hobby: " << st.hobby << endl;
	cout << "Ooplevel: " << st.ooplevel << endl;
}
void display2(const student* st)
{
	cout << "Using display2(const student *st)" << endl;
	cout << "Full name: " << st->fullname << endl;
	cout << "Hobby: " << st->hobby << endl;
	cout << "Ooplevel: " << st->ooplevel << endl;
}
void display3(const student pa[], int n)
{
	cout << "Using display3(const student pa[], int n)" << endl;;
	for (int i = 0; i < n; i++)
	{
		cout << "Infomation of student #" << i + 1 << ": " << endl;
		cout << "Full name: " << pa[i].fullname << endl;
		cout << "Hobby: " << pa[i].hobby << endl;
		cout << "Ooplevel: " << pa[i].ooplevel << endl;
	}
}
void ex9()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);

	delete[] ptr_stu;
	cout << "Done.\n";
}

double add(double x, double y)
{
	return x + y;
}
double mul(double x, double y)
{
	return x * y;
}
double calculate(double x, double y, double(*fun)(double, double))
{
	return fun(x, y);
}
void ex10()
{
	double x = 0.0;
	double y = 0.0;

	cout << "Enter two double number: ";
	while (cin >> x >> y)
	{
		if (x == -1 || y == -1)
		{
			break;
		}
		cout << "Call add, the result of " << x << " and " << y << " is " << calculate(x, y, add) << endl;
		cout << "Call mul, the result of " << x << " abd " << y << " is " << calculate(x, y, mul) << endl;

		cout << "Enter next two double number: ";
	}
}

int main()
{
	ex10();

	system("pause");

	return 0;
}