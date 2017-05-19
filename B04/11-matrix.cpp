#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <cfloat>
#include <fstream>

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "dickhead" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);

	double matrix[3][3];
	double* continuous = (double*)matrix;

	for(int i = 0; i < 9; i++)
		input >> continuous[i];

	input.close();


	double det = 0;

	for(int i = 0; i < 3; i++)
	{
		double pdet = 1, ndet = 1;

		for(int j = 0; j < 3; j++)
		{
			pdet *= matrix[(i + j)%3][j];
			ndet *= matrix[(3 + i - j)%3][j];
		}

		det += pdet - ndet;
	}

	double norm = 0;

	for(int i = 0; i < 3; i++)
	{
		double colsum = 0;

		for(int j = 0; j < 3; j++)
		{
			colsum += std::abs(matrix[j][i]);
		}

		norm = std::max(norm, colsum);
	}

	for(int i = 0; i < 3; i++)
	{
		if(i == 1)
			std::cout << "A = ";
		else
			std::cout << "    ";

		for(int j = 0; j < 3; j++)
			std::cout << std::setw(5) << matrix[i][j];

		std::cout << std::endl;
	}

	std::cout << "det(A) = " << det << std::endl;
	std::cout << "||A|| = " << norm << std::endl;

	return 0;
}
