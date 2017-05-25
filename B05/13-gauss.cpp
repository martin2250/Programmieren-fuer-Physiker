#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <cfloat>
#include <fstream>
#include <string.h>


const int showsolvesteps = 0;
int size;

void printEq(double** A, double* B)
{
	for(int row = 0; row < size; row++)
	{
		for(int col = 0; col < size; col++)
			std::cout << std::setw(10) << A[row][col];

		std::cout << " |" << std::setw(10) << B[row] << std::endl;
	}
}

void printEqW(double** A, double* B)
{
	std::cout << "{";

	for(int row = 0; row < size; row++)
	{
		std::cout << "{";

		for(int col = 0; col < size; col++)
		{
			std::cout << std::setw(5) << A[row][col] << ((col == (size-1))?"":",");
		}
		std::cout <<((row == (size-1))?"}":"},\n");
	}
	std::cout << "}\n\n{";

	for(int row = 0; row < size; row++)
	{
		std::cout << std::setw(5) << B[row] << ((row == (size-1))?"}\n":",");
	}
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cout << "dickhead\n";
		std::cout << "usage:\n" << argv[0] << " source.dat [pivot/nopivot]\n";
		return 1;
	}

	int pivot = 1;

	if(argc == 3 && !strcmp(argv[2], "nopivot"))
	{
		pivot = 0;
		std::cout << "column pivot disabled\n";
	}
	else
		std::cout << "column pivot enabled\n";


	std::ifstream input(argv[1]);

	input >> size;

	/*	ALLOCATE MEMORY	*/
	double** A = (double**)malloc(size * sizeof(double*));

	for(int i = 0; i < size; i++)
		A[i] = (double*)malloc(size * sizeof(double));

	double* B = (double*)malloc(size * sizeof(double));

	/*	READ ARRAY	*/
	for(int row = 0; row < size; row++)
		for(int col = 0; col < size; col++)
			input >> A[row][col];
	for(int i = 0; i < size; i++)
		input >> B[i];

	input.close();

	/*	PRINT EQUATION	*/

	std::cout << "\ninput matrix:\n";
	printEq(A, B);

	/*	SOLVE	*/
	std::cout << "\n\nsolving equation\n";
	for(int col = 0; col < size; col++)
	{
		if(showsolvesteps)
			std::cout << "minimizing column " << col << std::endl;

		/*	SELECT ROW WITH LARGEST VALUE	*/
		if(pivot)
		{
			double max = 0.;
			int rowx = col;

			for(int row = col; row < size; row++)
			{
				if(std::abs(A[row][col]) > max)
				{
					rowx = row;
					max = std::abs(A[row][col]);
				}
			}

			if(max == 0.)
			{
				if(showsolvesteps)
					std::cout << "column already minimized, skipping\n";
				continue;
			}

			if(showsolvesteps)
				std::cout << "chose row " << rowx << ", rearranging array\n";

			/*	swapping rows	*/
			double* oldAzero = A[col];
			A[col] = A[rowx];
			A[rowx] = oldAzero;

			double oldBzero = B[col];
			B[col] = B[rowx];
			B[rowx] = oldBzero;
		}

		/*	NORMALIZE ROW	*/
		{
			double rowxfactor = 1./A[col][col];
			for(int colb = col; colb < size; colb++)
				A[col][colb] *= rowxfactor;
			B[col] *= rowxfactor;
		}

		/*	APPLY ROWX (now at row=col) TO ALL ROWS BELOW	*/
		for(int row = (col + 1); row < size; row++)
		{
			double factor = A[row][col];

			if(showsolvesteps)
				std::cout << "applying row " << col << " to row " << row << " with factor " << factor << std::endl;

			A[row][col] = 0;

			for(int colb = (col + 1); colb < size; colb++)
			{
				A[row][colb] -= A[col][colb] * factor;
			}

			B[row] -= B[col] * factor;
		}

		if(showsolvesteps)
			printEq(A, B);
	}

	std::cout << "\n\nreduced row echelon form:\n";
	printEq(A, B);

	std::cout << "\nsolving further:\n";

	for(int row = (size - 1); row > 0; row--)
	{
		for(int rowb = row - 1; rowb >= 0; rowb--)
		{
			double factor = A[rowb][row];

			for(int col = row; col < size; col++)
			{
				A[rowb][row] = 0;	//technically not neccessary
			}

			B[rowb] -= factor * B[row];
		}
	}
	printEq(A, B);

	for(int i = 0; i < size; i++)
		free(A[i]);
	free(A);
	free(B);
	return 0;
}
