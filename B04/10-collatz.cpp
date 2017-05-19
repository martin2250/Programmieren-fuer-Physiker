#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <cfloat>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "dickhead" << std::endl;
		return 1;
	}

	int a = atoi(argv[1]);
	int n = 0, max = 0, start = a;

	while(a != 1)
	{
		if(a & 1)
			a = 3*a + 1;
		else
			a /= 2;

		std::cout << std::setw(4) << ++n << ":\t" << std::setw(4) << a << std::endl;

		max = std::max(max, a);
	}

	std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "a_0:" << start << std::endl;
	std::cout << "max a_n:" << max << std::endl;
	std::cout << "n:" << n << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;

	return 0;
}
