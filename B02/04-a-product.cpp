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

	int product = 1;

	for(int i = 1; i <= N; i++)
		product *= 3*i - 1;

	std::cout << product << std::endl;
}
