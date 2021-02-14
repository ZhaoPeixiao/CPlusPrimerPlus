#pragma once
#ifndef MYSTACK_H

struct customer
{
	char fullname[35];
	double payment;
};

typedef customer Item;

class MyStack
{
private:
	enum { MAX = 10 };
	Item items[MAX];
	int top;

public:
	MyStack();
	bool isEmpty();
	bool isFull();
	bool push(const Item& item);
	bool pop(Item& item);
};

#endif // !MYSTACK_H
