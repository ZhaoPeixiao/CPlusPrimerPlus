#pragma once

class Customer
{
private:
	long arrive;
	int process_time;

public:
	Customer() { arrive = process_time = 0; };
	void set(long when);
	long when() const { return arrive; };
	int ptime()const { return process_time; };
};

typedef Customer cItem;

class Queue
{
private:
	struct Node { cItem item; struct Node* next; };
	enum { Q_SIZE = 10 };
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	Queue(const Queue& q) :qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; };

public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const cItem& item);
	bool dequeue(cItem& item);
};