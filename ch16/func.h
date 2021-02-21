#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

bool func1(const string& s)
{
	string rev(s.rbegin(), s.rend());

	return rev == s;
}

bool func2(const string& s)
{
	string res;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		char ch = *it;
		if (isalpha(ch))
		{
			res.push_back(tolower(ch));
		}
	}

	return func1(res);
}

void func3(const char* filename, vector<string>& wordlist)
{
	ifstream ifs;
	ifs.open(filename);
	if (!ifs.is_open())
	{
		cout << "failed to open file " << filename << endl;
		exit(EXIT_FAILURE);
	}
	string word;
	while (ifs >> word)
	{
		wordlist.push_back(word);
	}
}

void showArr(long arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int func4(long arr[], int n)
{
	sort(arr, arr + n);
	auto past = unique(arr, arr + n);

	return (past - arr);
}

template<class T>
int func5(T arr[], int n)
{
	sort(arr, arr + n);
	auto past = unique(arr, arr + n);

	return (past - arr);
}

template<class T>
void showTemplate(T arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

vector<int> lotto(int total, int select)
{
	vector<int> all;
	for (int i = 1; i <= total; i++)
	{
		all.push_back(i);
	}
	random_shuffle(all.begin(), all.end());

	return vector<int>(all.begin(), all.begin() + select);
}