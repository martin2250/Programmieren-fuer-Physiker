#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <cfloat>
#include <fstream>
#include <string.h>
#include <unistd.h>

const int maxl = 20;
double X[maxl], Y[maxl];
int length = 0;

double L(int i, double x)
{
	double prod = 1;

	for(int k = 0; k < length; k++)
	{
		if(k == i)
			continue;

		prod *= (x - X[k]) / (X[i] - X[k]);
	}

	return prod;
}

double f(double x)
{
	double sum = 0;

	for(int i = 0; i < length; i++)
	{
		sum += Y[i] * L(i, x);
	}

	return sum;
}

int main(int argc, char **argv)
{

	std::ifstream input("a16-interpol.dat");

	while((length < maxl) && (input >> X[length] >> Y[length]))
	{
		length++;
	}

	input.close();
	
	std::cout << "loaded " << length << " data points\n";

	std::ofstream output("interpolated.dat");

	for(double x = X[0]; x <= X[length - 1]; x += 0.05)
	{
		output << x << "\t" << f(x) << "\n";
	}

	output.close();
}
