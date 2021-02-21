#pragma once
#include<iostream>
using namespace std;

struct Review
{
	string title;
	int rating;
	double price;
};

bool operator<(const shared_ptr<Review>& pl, const shared_ptr<Review>& p2);
bool RatingAsc(const shared_ptr<Review>& p1, const shared_ptr<Review>& p2);
bool PriceAsc(const shared_ptr<Review>& p1, const shared_ptr<Review>& p2);
bool PriceDesc(const shared_ptr<Review>& p1, const shared_ptr<Review>& p2);
bool FillReview(shared_ptr<Review>& rptr);
void ShowReview(const shared_ptr<Review>& rptr);
void ShowMenu();
