#pragma once
#ifndef MYLIST_H
#include<iostream>
using namespace std;

typedef unsigned long uItem;

class MyList
{
	enum { MAX = 20 };
	uItem items[MAX];
	int top;
public:
	MyList() { top = 0; };
	int add(uItem& item);
	bool isempty();
	bool isfull();
	void visit(void(*pf)(uItem&));
};

void oringin(uItem& item);
void x2(uItem& item);
void half(uItem& item);

#endif // !MYLIST_H
