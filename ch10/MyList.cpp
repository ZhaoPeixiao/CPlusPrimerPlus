#include"MyList.h"

int MyList::add(uItem& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool MyList::isempty()
{
	return top == 0;
}

bool MyList::isfull()
{
	return top == (MAX - 1);
}

void MyList::visit(void(*pf)(uItem&))
{
	for (int i = 0; i < top; i++)
	{
		cout << "#" << i << ": ";
		pf(items[i]);
	}
}

void oringin(uItem& item)
{
	cout << item << endl;
}

void x2(uItem& item)
{
	item = item * 2;
	cout << item << endl;
}

void half(uItem& item)
{
	item = item / 2;
	cout << item << endl;
}