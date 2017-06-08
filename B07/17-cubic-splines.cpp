#include <iostream>
#include <string.h>
#include <fstream>

const int maxl = 20;
int length = 0;

double X[maxl], Y[maxl];

double mu[maxl], d[maxl], M[maxl];

//renamed gamma as there is already a function with that name
double beta[maxl], gamma_a[maxl], delta[maxl];

double lambda(int j)
{
	if(j == 0)
		return 0.;

	return (X[j + 1] - X[j])/(X[j + 1] - X[j - 1]);
}

//initial values for mu and d
double mu_init(int j)
{
	if(j == (length - 1))
		return 0.;

	if(j == 0)
		return 2;

	return (X[j] - X[j-1])/(X[j + 1] - X[j - 1]);
}

double d_init(int j)
{
	if((j == (length - 1)) || (j == 0))
		return 0.;

	double a = (Y[j + 1] - Y[j])/(X[j + 1] - X[j]);
	double b = (Y[j] - Y[j-1])/(X[j] - X[j-1]);

	return 6. * (a - b) / (X[j + 1] - X[j - 1]);
}

double S(double x)
{
	int j = 0;

	while(X[j + 1] < x)
	{
		j++;
		if(j == (length - 1))
		{
			std::cout << "warning: x = " << x << " is out of range\n";
			return 0.;
		}
	}

	return
		Y[j]
		+ beta[j] * (x - X[j])
		+ gamma_a[j] * (x - X[j]) * (x - X[j])
		+ delta[j] * (x - X[j]) * (x - X[j]) * (x - X[j]);
}

int main(int argc, char **argv)
{
	std::ifstream input("../B06/a16-interpol.dat");

	while((length < maxl) && (input >> X[length] >> Y[length]))
	{
		length++;
	}

	input.close();

	std::cout << "loaded " << length << " data points\n";

	//populate arrays with initial values
	for(int i = 0; i < length; i++)
	{
		mu[i] = mu_init(i);
		d[i] = d_init(i);
	}

	for(int i = 1; i < length; i++)
	{
		double f = -mu[i]/mu[i-1];
		mu[i] = 2. + f * lambda(i - 1);
		d[i] = d[i] + f * d[i - 1];
	}

	for(int i = 0; i < length; i++)
		M[i] = d[i]/mu[i];

	for(int i = length - 2; i >= 0; i--)
	{
		M[i] = (d[i] - lambda(i) * M[i + 1])/mu[i];
	}

	//populate final arrays
	for(int j = 0; j < (length - 1); j++)
	{
		beta[j] = (Y[j + 1] - Y[j])/(X[j + 1] - X[j]) - (2. * M[j] + M[j + 1]) * (X[j + 1] - X[j]) / 6.;
		gamma_a[j] = M[j] / 2.;
		delta[j] = (M[j + 1] - M[j])/(6.*(X[j + 1] - X[j]));
	}

	//generate output file
	std::ofstream output("interpolated.dat");

	const int points = 300;

	for(int i = 0; i < points; i++)
	{
		double x = X[0] + (X[length - 1] - X[0]) * ((double)i)/(points - 1);

		output << x << "\t" << S(x) << "\n";
	}

	output.close();
}
