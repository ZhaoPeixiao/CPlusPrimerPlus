#pragma once
#ifndef STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum { MAX = 10 };
	Item* pitems;
	int size;
	int top;

public:
	Stack(int n = MAX);
	Stack(const Stack& st);
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const Item& item);
	bool pop(Item& item);
	Stack& operator=(const Stack& st);
};
#endif // !STACK_H_
