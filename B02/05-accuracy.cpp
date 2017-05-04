#include <iostream>
#include <stdlib.h>

int main(int argc, char **argv)
{
	double epsilon = 1.;

	while(1 != (1 + epsilon))
		epsilon /= 2.;

	std::cout << 2 * epsilon << std::endl;
}
