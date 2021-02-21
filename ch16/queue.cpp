#include"queue.h"
#include<cstdlib>

void Customer::set(long when)
{
	processtime = rand() % 3 + 1;
	arrive = when;
}