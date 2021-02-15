#include"Stonewt2.h"

Stonewt2::Stonewt2(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - (int)lbs;
	pounds = lbs;
}

Stonewt2::Stonewt2(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

Stonewt2::Stonewt2()
{
	stone = pds_left = pounds = 0;
}

Stonewt2::~Stonewt2()
{
}

void Stonewt2::show_stn() const
{
	cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt2::show_lbs() const
{
	cout << pounds << " pounds\n";
}

bool Stonewt2::operator<(const Stonewt2& st) const
{
	return pounds < st.pounds;
}

bool Stonewt2::operator>(const Stonewt2& st) const
{
	return pounds > st.pounds;
}

bool Stonewt2::operator<=(const Stonewt2& st) const
{
	return pounds <= st.pounds;
}

bool Stonewt2::operator>=(const Stonewt2& st) const
{
	return pounds >= st.pounds;
}

bool Stonewt2::operator==(const Stonewt2& st) const
{
	return pounds == st.pounds;
}

bool Stonewt2::operator!=(const Stonewt2& st) const
{
	return pounds != st.pounds;
}