#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <cfloat>
#include <string.h>

void pascal(int zeile, int* buffer)
{
	for(int n = zeile - 1; n > 0; n--)
		buffer[n] = buffer[n] + buffer[n - 1];
}

int main(int argc, char **argv)
{
	int maxn = 10;

	if(argc == 2)
	{
		maxn = atoi(argv[1]);
	}

	int *zeile = (int*)malloc(maxn  * sizeof(int));
	memset(zeile, 0, maxn  * sizeof(int));

	zeile[0] = 1;

	for(int n = 1; n <= maxn; n++)
	{
		pascal(n, zeile);

		for(int i = n; i < maxn; i++)
			std::cout << "   ";

		for(int i = 0; i < n; i++)
			std::cout << std::setw(6) << zeile[i];

		std::cout << std::endl;
	}

	free(zeile);
}
