#include <iostream>
#include <string.h>

int value_of_rmchar(char rm)
{
	char roman_numerals[] = "IVXLCDM";
	int equivalent[] = {1, 5, 10, 50, 100, 500, 1000};

	char *ptr = strchr(roman_numerals, rm);

	if(ptr)
		return equivalent[ptr - roman_numerals];
	return 0;
}

char to_upper(char c)	//just...why?
{
	return (char)toupper(c);
}


int main(int argc, char **argv)
{
	char input[20];

	while(1)
	{
		std::cin >> input;
		if(to_upper(input[0]) == 'E')	//exit on 'E'
			return 0;

		char *ptr = input;
		int result = 0;
		int lastval = 0;

		while(*ptr)
		{
			*ptr = to_upper(*ptr);	//format niecly for output while we're at it
			int val = value_of_rmchar(*ptr);

			if(val > lastval)
				result -= lastval;
			else
				result += lastval;

			lastval = val;
			ptr++;
		}

		result += lastval;

		std::cout << input << " is " << result << std::endl;
	}
}
