#include <iostream>
#include <cmath>

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
const double ex = 1e-4;
const double ef = 1e-3;

#define F2

#ifdef F1
double f(double x)
{
	return cos(x) - x;
}
double x0 = -10, x1 = 10;
#endif

#ifdef F2
double f(double x)
{
	return exp(x) - x*x*x;
}
double x0 = 2, x1 = 10;
#endif

int main(int argc, char** argv)
{
	if(sgn(f(x0)) == sgn(f(x1)))
	{
		std::cout << "no zero crossing in interval";
		return 1;
	}

	double xtest = (x0 + x1)/2;

	while(std::abs(x0 - x1) > ex && std::abs(f(xtest)) > ef)
	{
		if(sgn(f(xtest)) == sgn(f(x0)))
			x0 = xtest;
		else
			x1 = xtest;

		xtest = (x0 + x1)/2;
	}

	std::cout << "f( " << xtest << " ) = " << f(xtest) << std::endl;
}
