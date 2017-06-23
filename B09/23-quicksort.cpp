#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

int partition(double* a, int s, int t)
{
	double pivot = a[t];
	int i = s - 1;

	for(int j = s; j <= t; j++)
	{
		if(a[j] <= pivot)
		{
			i += 1;
			if(i != j)
			{
				double temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	return i;
}

void quicksort(double* a, int s, int t)
{
	if(s < t)
	{
		int p = partition(a, s, t);
		quicksort(a, s, p - 1);
		quicksort(a, p + 1, t);
	}
}

int main(int argc, char** argv)
{
	srand((unsigned int)time(0));

	int N = 1000;
	double A[N];

	for(int i = 0; i < N; i++)
		A[i] = double(rand())/RAND_MAX;

	quicksort(A, 0, N - 1);

	for(int i = 0; i < N; i++)
		std::cout << A[i] << std::endl;
}
