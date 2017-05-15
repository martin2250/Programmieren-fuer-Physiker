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

	for(int i = 0; i < 3; i++)
		x[i] = atof(argv[i + 1]);

	for(int i = 0; i < 3; i++)
	{
		double a = x[i], b = x[(i+1)%3], c = x[(i+2)%3];

		if(std::min(a, c) <= b && b <= std::max(a, c))
		{
			std::cout << b << std::endl;
			return 0;
		}
	}

	std::cout << "error" << std::endl;
	return 0;
}
