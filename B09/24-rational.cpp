#include <iostream>
#include <stdlib.h>
#include <numeric>	//lcm, gcd

class Ratio
{
	long numerator, denominator;
	void cancel();
public:
	Ratio(long numerator, long denominator);
	void set(long numerator, long denominator);
	Ratio operator+(const Ratio& b) const;
	Ratio operator-() const;
	Ratio operator-(const Ratio& b) const;
	Ratio operator*(const Ratio& b) const;
	Ratio operator/(const Ratio& b) const;
	operator double() const;
	void print();
};

Ratio::Ratio(long numerator, long denominator)
{
	set(numerator, denominator);
}

void Ratio::set(long numerator, long denominator)
{
	this->numerator = numerator;
	this-> denominator = denominator;
	this->cancel();
}

void Ratio::cancel()
{
	long gcd = std::gcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

	if(denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
}

Ratio Ratio::operator+(const Ratio& b) const
{
	long lcm = std::lcm(this->denominator, b.denominator);
	long faca = lcm/this->denominator, facb = lcm/b.denominator;

	Ratio r(faca*this->numerator + facb*b.numerator, lcm);
	r.cancel();
	return r;
}

Ratio Ratio::operator-() const
{
	return Ratio(-this->numerator, this->denominator);
}

Ratio Ratio::operator-(const Ratio& b) const
{
 	return *this + (-b);
}

Ratio Ratio::operator*(const Ratio& b) const
{
	Ratio r(this->numerator * b.numerator, this-> denominator * b.denominator);
	r.cancel();
	return r;
}

Ratio Ratio::operator/(const Ratio& b) const
{
	Ratio r(this->numerator * b.denominator, this-> denominator * b.numerator);
	r.cancel();
	return r;
}

Ratio::operator double() const
{
	return (double)(this->numerator)/(this->denominator);
}

void Ratio::print()
{
	std::cout << "(" << this->numerator << " / " << this->denominator << ")" << std::endl;
}

int main(int argc, char** argv)
{
	Ratio a(1, 2), b(1, 4);
	a.print();
	b.print();
	Ratio c = b - a;
	a.print();
	b.print();
	c.print();
	std::cout << (double)c << std::endl;
}
