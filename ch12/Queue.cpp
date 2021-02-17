#include"Queue.h"
#include<iostream>
using namespace std;

Queue::Queue(int qs) :qsize(qs)
{
	front = rear = 0;
	items = 0;
}

Queue::~Queue()
{
	Node* tmp;
	while (front != NULL)
	{
		tmp = front;
		front = front->next;
		delete tmp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::enqueue(const cItem& item)
{
	if (isfull())
	{
		return false;
	}

	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;
	items++;
	if (front == NULL)
	{
		front = newNode;
	}
	else {
		rear->next = newNode;
	}
	rear = newNode;
	return true;
}

bool Queue::dequeue(cItem& item)
{
	if (front == NULL)
	{
		return false;
	}
	item = front->item;
	items--;
	Node* tmp = front;
	front = front->next;
	delete tmp;

	if (items == 0)
	{
		rear = NULL;
	}
	return true;
}

void Customer::set(long when)
{
	process_time = rand() % 3 + 1;
	arrive = when;
}