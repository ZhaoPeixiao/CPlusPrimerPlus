#include"MyStack.h"

MyStack::MyStack()
{
	top = 0;
}
bool MyStack::isEmpty()
{
	return top == 0;
}
bool MyStack::isFull()
{
	return top == MAX;
}
bool MyStack::push(const Item& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	return false;
}
bool MyStack::pop(Item& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	return false;
}