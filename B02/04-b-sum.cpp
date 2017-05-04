#include <iostream>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "dickhead" << std::endl;
		return 1;
	}

	int N = atoi(argv[1]);

	double sum = 0;

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= i; j++)
			sum += 1. / (i * j);
	}

	std::cout << sum << std::endl;
}
