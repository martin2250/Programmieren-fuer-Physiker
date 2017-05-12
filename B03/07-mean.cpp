#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <cfloat>

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cout << "dickhead" << std::endl;
		return 1;
	}

	double x[3];

	double h = DBL_MIN, l = DBL_MAX;

	for(int i = 0; i < 3; i++)
	{
		x[i] = atof(argv[i+1]);
		l = std::min(l, x[i]);
		h = std::max(h, x[i]);
	}

	double sum = 0.;

	for(int i = 0; i < 3; i++)
	{
		sum += x[i] * (x[i] != l && x[i] != h);
	}


	std::cout << sum << std::endl;
	return 0;
}
