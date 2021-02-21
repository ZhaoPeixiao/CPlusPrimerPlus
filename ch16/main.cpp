#include<iostream>
#include<queue>
#include<list>
#include<memory>
using namespace std;

#include"func.h"
#include"queue.h"
#include"review.h"
void ex1()
{
	string input;
	cout << "Enter a word(q to quit): ";
	while (getline(cin, input) && input != "q")
	{
		if (func1(input))
		{
			cout << input << " is palindrome!" << endl;
		}
		else
		{
			cout << input << " is not palindrome" << endl;
		}
		cout << "Enter anthor word(q to quit): ";
	}

	cout << "Bye!" << endl;
}

void ex2()
{
	string input;
	cout << "Enter a word(q to quit): ";
	while (getline(cin, input) && input != "q")
	{
		if (func2(input))
		{
			cout << input << " is palindrome!" << endl;
		}
		else
		{
			cout << input << " is not palindrome" << endl;
		}
		cout << "Enter anthor word(q to quit): ";
	}

	cout << "Bye!" << endl;
}

void ex3()
{
	vector<string> word_list;
	func3("words.txt", word_list);
	int num = word_list.size();
	cout << num << " words in words.txt" << endl;

	srand(time(0));
	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = word_list[std::rand() % num];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
			<< " letters, and you guess\n"
			<< "one letter at a time. You get " << guesses
			<< " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter; // add to string
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				// check if letter appears again
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";

		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "Bye\n";
}

void ex4()
{
	long arr[10] = { 12, 12, 5, 6, 11, 5, 6, 77, 11, 12 };
	showArr(arr, 10);
	int newsize = func4(arr, 10);
	showArr(arr, newsize);
}

void ex5()
{
	cout << "long test\n";
	long arr[10] = { 12, 12, 5, 6, 11, 5, 6, 77, 11, 12 };
	showTemplate(arr, 10);
	int newsize = func5(arr, 10);
	showTemplate(arr, newsize);

	cout << "string test\n";
	string str_arr[5] = {
		"zhao", "zhao", "peixiao", "pei", "xiao"
	};
	showTemplate(str_arr, 5);
	newsize = func5(str_arr, 5);
	showTemplate(str_arr, newsize);
}

const int MIN_PER_HR = 60;
bool newcustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);
}
void ex6()
{
	std::srand(std::time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	queue<Item> line;

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;

	long cyclelimit = MIN_PER_HR * hours;

	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust))
		{
			if (line.size() == qs)
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);
				line.push(temp);
			}
		}
		if (wait_time <= 0 && !line.empty())
		{
			line.pop();
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.size();
	}

	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "         turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
}

const int TOT = 51;
const int SELECT = 6;
void ex7()
{
	cout << "Play?<y/n>: ";
	string choice;
	vector<int> res;

	while (cin >> choice && choice != "n")
	{
		res = lotto(TOT, SELECT);
		for (auto x : res)
		{
			cout << x << " ";
		}
		cout << endl;

		cout << "Play again?<y/n>: ";
	}

	cout << "Bye~" << endl;
}

inline void show(string& s) { cout << s << " "; };
void ex8()
{
	vector<string> mat_friends, pat_friends;
	string name;

	cout << "Mat! Enter your friends(Enter q to stop): ";
	while (getline(cin, name) && name != "q")
	{
		mat_friends.push_back(name);
		cout << "Another name: ";
	}

	cout << "Pat! Enter your friends(Enter q to stop): ";
	while (getline(cin, name) && name != "q")
	{
		pat_friends.push_back(name);
		cout << "Another name: ";
	}

	sort(mat_friends.begin(), mat_friends.end());
	sort(pat_friends.begin(), pat_friends.end());

	cout << "Mat's friends: " << endl;
	for_each(mat_friends.begin(), mat_friends.end(), show);
	cout << endl;
	cout << "Pat's friends: " << endl;
	for_each(pat_friends.begin(), pat_friends.end(), show);
	cout << endl;

	vector<string> all_friends;
	all_friends.reserve(mat_friends.size() + pat_friends.size());
	all_friends.insert(all_friends.end(), mat_friends.begin(), mat_friends.end());
	all_friends.insert(all_friends.end(), pat_friends.begin(), pat_friends.end());

	sort(all_friends.begin(), all_friends.end());
	auto new_end = std::unique(all_friends.begin(), all_friends.end());
	cout << "All friends: " << endl;
	for_each(all_friends.begin(), new_end, show);
	cout << endl;
}

const int SIZE = 1000000;
void ex9()
{
	vector<int> base(SIZE, 0);
	for (int i = 0; i < SIZE; ++i)
	{
		base.at(i) = rand();
	}

	vector<int> vec(base);
	list<int> list(SIZE, 0);
	copy(vec.begin(), vec.end(), list.begin());

	clock_t start = clock();
	sort(vec.begin(), vec.end());
	clock_t end = clock();
	cout << "sort vector time: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;

	start = clock();
	list.sort();
	end = clock();
	cout << "sort list time: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;

	// operation d
	copy(base.begin(), base.end(), list.begin());
	start = clock();
	copy(list.begin(), list.end(), base.begin());
	sort(vec.begin(), vec.end());
	copy(vec.begin(), vec.end(), list.begin());
	end = clock();
	cout << "copy+sort+copy time: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;
}

void ex10()
{
	vector<shared_ptr<Review> > books;

	shared_ptr<Review> temp_ptr;
	while (FillReview(temp_ptr))
	{
		books.push_back(temp_ptr);
	}

	if (books.size() > 0)
	{
		ShowMenu();
		char choice;
		while (cin >> choice && choice != '6')
		{
			vector<shared_ptr<Review> > books_cpy(books);
			switch (choice)
			{
			case '1':
				cout << "Original order:" << endl;
				cout << "Rating\tBook\tPrice\n";
				for_each(books_cpy.begin(), books_cpy.end(), ShowReview);
				break;
			case '2':
				cout << "Alphabet order:" << endl;
				cout << "Rating\tBook\tPrice\n";
				sort(books_cpy.begin(), books_cpy.end());
				for_each(books_cpy.begin(), books_cpy.end(), ShowReview);
				break;
			case '3':
				cout << "Rating ascending:" << endl;
				cout << "Rating\tBook\tPrice\n";
				sort(books_cpy.begin(), books_cpy.end(), RatingAsc);
				for_each(books_cpy.begin(), books_cpy.end(), ShowReview);
				break;
			case '4':
				cout << "Price ascending:" << endl;
				cout << "Rating\tBook\tPrice\n";
				sort(books_cpy.begin(), books_cpy.end(), PriceAsc);
				for_each(books_cpy.begin(), books_cpy.end(), ShowReview);
				break;
			case '5':
				cout << "Price descending:" << endl;
				cout << "Rating\tBook\tPrice\n";
				sort(books_cpy.begin(), books_cpy.end(), PriceDesc);
				for_each(books_cpy.begin(), books_cpy.end(), ShowReview);
				break;
			default:
				cout << "Invalid Choice!" << endl;
				break;
			}
			system("pause");
			system("cls");
			ShowMenu();
		}
	}
	else
	{
		cout << "No entries. ";
	}

	cout << "Bye.\n";
}

int main()
{
	ex10();

	system("pause");

	return 0;
}