#include<iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

#include"emp.h"
#include"store.h"

void ex1()
{
	cout << "Enter a sentence with a '$' in it: " << endl;
	int count = 0;
	char ch;
	while ((ch = cin.get()) != '$')
	{
		count++;;
	}
	cin.putback(ch);

	while (cin.get() != '\n')
	{
		continue;
	}

	cout << "There are " << count << " characters before $" << endl;
}

void ex2()
{
	string filename = "ex2.txt";
	ofstream ofs;
	ofs.open(filename, ios_base::out);

	cout << "Enter sentences: " << endl;
	char ch;
	while (cin.get(ch))
	{
		ofs.put(ch);
	}
	if (cin.eof())
	{
		cout << "\n It is EOF" << endl;
	}
	else
	{
		cerr << "Unkonwn error" << endl;
		exit(EXIT_FAILURE);
	}

	ofs.close();
}

// change it to main func.
void ex3(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "Usage: " << argv[0]
			<< " source-file target-file" << endl;
		exit(EXIT_FAILURE);
	}

	ifstream ifs(argv[1], ios_base::in);
	if (!ifs.is_open())
	{
		cerr << "Cant't open" << argv[1] << " for input" << endl;
		exit(EXIT_FAILURE);
	}

	ofstream ofs(argv[2], ios_base::out);
	if (!ofs.is_open())
	{
		cerr << "Can't open" << argv[2] << " for output" << endl;
		exit(EXIT_FAILURE);
	}

	char ch;
	while (ifs.get(ch))
	{
		ofs.put(ch);
	}

	cout << "Content of " << argv[1] << " copied to " << argv[2] << endl;
	ifs.close();
	ofs.close();
}

void ex4()
{
	string input_file1 = "ex4_input1.txt";
	string input_file2 = "ex4_input2.txt";
	string output_file = "ex4_output.txt";

	ifstream ifs1(input_file1, ios_base::in);
	ifstream ifs2(input_file2, ios_base::in);
	ofstream ofs(output_file, ios_base::out);

	if (!ifs1.is_open() || !ifs2.is_open())
	{
		cerr << "wrong input file!\n";
		exit(EXIT_FAILURE);
	}

	char ch;
	if (!ofs.is_open())
	{
		cerr << "wrong input file!\n";
		exit(EXIT_FAILURE);
	}
	while (!ifs1.eof() || !ifs2.eof())
	{
		if (!ifs1.eof())
		{
			while (ifs1.get(ch) && ch != '\n')
			{
				ofs << ch;
			}
			ofs << ' ';
		}
		if (!ifs2.eof())
		{
			while (ifs2.get(ch) && ch != '\n')
			{
				ofs << ch;
			}
			ofs << ' ';
		}
	}

	cout << "Done!" << endl;
	ifs1.close();
	ifs2.close();
	ofs.close();
}

void ex5()
{
	vector<string> mats;
	vector<string> pats;
	vector<string> all;

	ifstream fmat("mat.dat", ios_base::in), fpat("pat.dat", ios_base::in);
	if (!fmat.is_open() || !fpat.is_open())
	{
		cerr << "wrong input file!\n";
		exit(EXIT_FAILURE);
	}

	ofstream ofs("all.dat", ios_base::out);
	if (!ofs.is_open())
	{
		cerr << "wrong input file!\n";
		exit(EXIT_FAILURE);
	}

	string name;
	while (fmat >> name)
	{
		mats.push_back(name);
	}
	cout << "Mat's friends: " << endl;
	for (auto x : mats)
	{
		cout << x << " ";
	}
	cout << endl;

	while (fpat >> name)
	{
		pats.push_back(name);
	}
	cout << "Pat's friends: " << endl;
	for (auto x : pats)
	{
		cout << x << " ";
	}
	cout << endl;

	all.reserve(mats.size() + pats.size());
	all.insert(all.end(), mats.begin(), mats.end());
	all.insert(all.end(), pats.begin(), pats.end());
	sort(all.begin(), all.end());
	auto past_end = unique(all.begin(), all.end());
	cout << "All friends:" << endl;
	for (auto x : all)
		cout << x << " ";
	cout << endl;
}

inline void show_line(int n);
void show_menu();
inline void eatline();
const int MAX = 10;

void ex6()
{
	abstr_emp* pc[MAX];
	int ct = 0;

	string fname, lname, job, reportsto;
	int inchargeof;

	ifstream fin("out.txt", ios_base::in);
	if (fin.good())
	{
		int kind;
		while (fin >> kind)
		{
			switch (kind)
			{
			case employee:
				fin >> fname;
				fin >> lname;
				fin >> job;
				pc[ct] = new Employee(fname, lname, job);
				break;
			case manager:
				fin >> fname;
				fin >> lname;
				fin >> job;
				fin >> inchargeof;
				pc[ct] = new Manager(fname, lname, job, inchargeof);
				break;
			case fink:
				fin >> fname;
				fin >> lname;
				fin >> job;
				fin >> reportsto;
				pc[ct] = new Fink(fname, lname, job, reportsto);
				break;
			case high_fink:
				fin >> fname;
				fin >> lname;
				fin >> job;
				fin >> reportsto;
				fin >> inchargeof;
				pc[ct] = new HighFink(fname, lname, job, reportsto, inchargeof);
			}
			ct++;
		}

		// show content in file
		cout << "content in out.txt" << endl;
		for (int i = 0; i < ct; ++i)
			pc[i]->ShowAll();
	}

	// fill the array
	show_menu();
	char choice;
	abstr_emp* p;
	while (cin >> choice && choice != 'q' && ct < MAX)
	{
		eatline();
		switch (choice)
		{
		case 'a':  // employee
			p = new Employee;
			p->SetAll();
			pc[ct] = p;
			break;
		case 'b':  // manager
			p = new Manager;
			p->SetAll();
			pc[ct] = p;
			break;
		case 'c':  // fink
			p = new Fink;
			p->SetAll();
			pc[ct] = p;
			break;
		case 'd':  // highfink
			p = new HighFink;
			p->SetAll();
			pc[ct] = p;
			break;
		}
		ct++;
		show_menu();
	}

	for (int i = 0; i < ct; ++i)
		pc[i]->ShowAll();

	ofstream fout("out.txt", ios_base::out);
	for (int i = 0; i < ct; ++i)
	{
		pc[i]->WriteAll(fout);
		fout << endl;
	}
	fout.close();

	cout << "content in array are written to out.txt" << endl;

	for (int i = 0; i < ct; ++i)
		delete pc[i];
}

inline void ShowStr(const string& s);
void GetStrs(ifstream& ifs, vector<string>& vistr);
void ex7()
{
	vector<string> vec;
	string tmp;

	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, tmp) && tmp[0] != '\0')
	{
		vec.push_back(tmp);
	}
	cout << "Here is your input" << endl;
	for_each(vec.begin(), vec.end(), ShowStr);

	ofstream ofs("ex7.dat", ios_base::out | ios_base::binary);
	for_each(vec.begin(), vec.end(), Store(ofs));
	ofs.close();

	vector<string> vistr;
	ifstream ifs("ex7.dat", ios_base::in | ios_base::binary);
	if (!ifs.is_open())
	{
		cerr << "Could not open file for input." << endl;
		exit(EXIT_FAILURE);
	}
	GetStrs(ifs, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
}

inline void ShowStr(const string& s)
{
	std::cout << s << std::endl;
}

void GetStrs(ifstream& ifs, vector<string>& vistr)
{
	size_t len;
	while (ifs.read((char*)&len, sizeof(size_t)))
	{
		string str;
		char ch;
		for (size_t i = 0; i < len; ++i)
		{
			ifs.read(&ch, sizeof(char));
			str.push_back(ch);
		}

		// put string to vector
		vistr.push_back(str);
	}
}

int main()
{
	ex7();

	system("pause");

	return 0;
}

void show_menu()
{
	ios_base::fmtflags old_fmt = cout.setf(ios_base::left, ios_base::adjustfield);

	show_line(35);
	cout.width(20);
	cout << "a. employee";
	cout << "b. manager" << endl;
	cout.width(20);
	cout << "c. fink";
	cout << "d. highfink" << endl;
	cout << "q. quit" << endl;
	show_line(35);
	cout << "Select a type: " << endl;

	cout.setf(old_fmt);
}

inline void show_line(int n)
{
	cout.fill('-');
	cout.width(n);
	cout << "-" << endl;
	cout.fill(' ');
}

inline void eatline()
{
	while (cin.get() != '\n')
		continue;
}