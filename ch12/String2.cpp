#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "String2.h"

using std::cin;
using std::cout;

int String2::num_strings = 0;

int String2::HowMany()
{
	return num_strings;
}

String2::String2(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String2::String2()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String2::String2(const String2& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

String2::~String2()
{
	--num_strings;
	delete[] str;
}

String2& String2::operator=(const String2& st)
{
	if (this == &st)
	{
		return *this;
	}
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String2& String2::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char& String2::operator[](int i)
{
	return str[i];
}

const char& String2::operator[](int i) const
{
	return str[i];
}

bool operator<(const String2& st, const String2& st2)
{
	return(std::strcmp(st.str, st2.str) < 0);
}

bool operator>(const String2& st, const String2& st2)
{
	return(std::strcmp(st.str, st2.str) > 0);
}

bool operator==(const String2& st, const String2& st2)
{
	return(std::strcmp(st.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String2& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String2& st)
{
	char temp[String2::CINLIM];
	is.get(temp, String2::CINLIM);
	if (is)
	{
		st = temp;
	}
	while (is && is.get() != '\n')
	{
		continue;
	}
	return is;
}

String2 String2::operator+(const String2& st) const
{
	int total_len = len + st.len;
	char* temp = new char[total_len + 1];
	std::strcpy(temp, str);
	std::strcpy(temp + len, st.str);
	temp[total_len] = '\0';
	return String2(temp);
}

String2 String2::operator+(const char* s) const
{
	int total_len = len + strlen(s);
	char* temp = new char[total_len + 1];
	std::strcpy(temp, str);
	std::strcpy(temp + len, s);
	temp[total_len] = '\0';
	return String2(temp);
}

String2 operator+(const char* s, const String2& st)
{
	return String2(s) + st;
}

void String2::Stringlow()
{
	for (int i = 0; i < len + 1; i++)
	{
		str[i] = tolower(str[i]);
	}
}

void String2::Stringup()
{
	for (int i = 0; i < len + 1; i++)
	{
		str[i] = toupper(str[i]);
	}
}

int String2::has(char c)
{
	int same = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			same++;
		}
	}

	return same;
}