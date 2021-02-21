#include"review.h"
#include <string>

bool operator<(const shared_ptr<Review>& p1, const shared_ptr<Review>& p2)
{
	return p1->title < p2->title;
}

bool RatingAsc(const shared_ptr<Review>& p1, const shared_ptr<Review>& p2)
{
	return p1->rating < p2->rating;
}

bool PriceAsc(const shared_ptr<Review>& p1, const shared_ptr<Review>& p2)
{
	return p1->price < p2->price;
}

bool PriceDesc(const shared_ptr<Review>& p1, const shared_ptr<Review>& p2)
{
	return p1->price > p2->price;
}

bool FillReview(shared_ptr<Review>& rptr)
{
	rptr = shared_ptr<Review>(new Review);

	cout << "Enter book title (q to quit): ";
	getline(cin, rptr->title);
	if (rptr->title == "q")
	{
		return false;
	}

	cout << "Enter book rating: ";
	cin >> rptr->rating;
	if (!cin)
	{
		return false;
	}

	cout << "Enter book price: ";
	cin >> rptr->price;
	if (!cin)
	{
		return false;
	}

	while (std::cin.get() != '\n')
	{
		continue;
	}

	return true;
}

void ShowReview(const shared_ptr<Review>& rptr)
{
	cout << rptr->rating << "\t" << rptr->title << "\t" << rptr->price << endl;
}

void ShowMenu()
{
	cout << "---------------------------------------------------------" << endl;
	cout << "1.original order   2.alphabet order    3.rating ascending" << endl;
	cout << "4.price ascending  3.price descending  6.quit" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "Your choice: ";
}