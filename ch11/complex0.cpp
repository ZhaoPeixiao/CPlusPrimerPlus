#include <iostream>
using namespace std;

#include "complex0.h"

complex::complex()
{
	real = imaginary = 0;
}

complex::complex(double real, double imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

complex complex::operator+(const complex& cx) const
{
	return complex(real + cx.real, imaginary + cx.imaginary);
}

complex complex::operator-(const complex& cx) const
{
	return complex(real - cx.real, imaginary - cx.imaginary);
}

complex complex::operator*(const complex& cx) const
{
	return complex(real * cx.real - imaginary * cx.imaginary,
		real * cx.imaginary + imaginary * cx.real);
}

complex operator~(const complex& cx)
{
	return complex(cx.real, -cx.imaginary);
}

complex operator*(int x, const complex& cx)
{
	return complex(x * cx.real, x * cx.imaginary);
}

std::istream& operator>>(std::istream& is, complex& cx)
{
	cout << "real: ";
	is >> cx.real;
	if (!is)
	{
		return is;
	}
	cout << "imaginary: ";
	is >> cx.imaginary;
	cin.get();

	return is;
}

std::ostream& operator<<(std::ostream& os, const complex& cx)
{
	os << "(" << cx.real << ", " << cx.imaginary << "i)";

	return os;
}