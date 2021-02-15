#include"Stonewt1.h"
using namespace std;

void Stonewt1::update()
{
	if (ft == STONES)
	{
		stone = total;
		ipounds = (int)stone * Lbs_per_stn;
		dpounds = stone * Lbs_per_stn;
	}
	else if (ft == IPOUND)
	{
		ipounds = total;
		stone = ipounds / Lbs_per_stn;
		dpounds = ipounds;
	}
	else if (ft == DPOUND)
	{
		dpounds = total;
		stone = dpounds / Lbs_per_stn;
		ipounds = (int)dpounds;
	}
}

Stonewt1::Stonewt1()
{
	total = 0;
	ft = STONES;
	update();
}
Stonewt1::Stonewt1(double n, format f)
{
	total = n;
	ft = f;
	update();
}

Stonewt1 Stonewt1::operator+(double n) const
{
	Stonewt1 st(total + n, ft);
	return st;
}
Stonewt1 Stonewt1::operator-(double n) const
{
	Stonewt1 st(total - n, ft);
	return st;
}
Stonewt1 Stonewt1::operator*(double n) const
{
	Stonewt1 st(total * n, ft);
	return st;
}

Stonewt1 operator+(double n, const Stonewt1& st)
{
	return st + n;
}
Stonewt1 operator-(double n, const Stonewt1& st)
{
	return st - n;
}
Stonewt1 operator*(double n, const Stonewt1& st)
{
	return st * n;
}

ostream& operator<<(ostream& os, const Stonewt1& st)
{
	if (st.get_format() == st.STONES)
	{
		cout << "Stone: " << st.get_stone();
	}
	else if (st.get_format() == st.IPOUND)
	{
		cout << "pounds in int: " << st.get_ipounds();
	}
	else if (st.get_format() == st.DPOUND)
	{
		cout << "pounds in double: " << st.get_dpounds();
	}

	return os;
}