#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <cfloat>
#include <fstream>
#include <string.h>
#include <unistd.h>

const char tochar[] = ".,~=+:?$78DIMNOZ";

int main(int argc, char **argv)
{
	int width, height, x = 0, y = 0;

	std::ifstream input(argv[1]);
	input >> width >> height;

	while(y < height)
	{
		int ch, num;
		if(!(input >> ch >> num))
			break;

		for(;num > 0; num --)
		{
			std::cout << tochar[ch];

			if(++x == width)
			{
				std::cout << std::endl;
				x = 0;
				y++;
			}
		}
	}

	input.close();
	std::cout << std::endl;
}
