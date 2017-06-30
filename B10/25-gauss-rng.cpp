#include <iostream>
#include <ctime>
#include <cmath>

#define RND (2.0*rand()/(double)RAND_MAX - 1.)

class normal_generator
{
	double rnd_next = 0.;
	int used = 1;
public:
	double get();
};

double normal_generator::get()
{
	if(!used)
	{
		used = 1;
		return rnd_next;
	}

	double v1, v2, s;
	do
	{
		v1 = RND, v2 = RND;
		s = v1*v1 + v2*v2;
	}
	while(s == 0 || s >= 1);

	rnd_next = v1 * sqrt(-2*log(s)/s);
	used = 0;
	return v2 * sqrt(-2*log(s)/s);

}

int main(int argc, char** argv)
{
	srand((unsigned int)time(0));

	normal_generator rng;

	int N = 100000;

	double* X = (double*)malloc(N * sizeof(double));

	for(int i = 0; i < N; i++)
		X[i] = rng.get();

	double sum = 0., sum2 = 0.;

	for(int i = 0; i < N; i++)
	{
		sum += X[i];
		sum2 += X[i] * X[i];
	}

	double m = sum/N;
	double var = sqrt((sum2 - m*m)/N);

	std::cout << "mean: " << m << std::endl;
	std::cout << "variance: " << var << std::endl;

	int sigma_cnt[3] = {0};

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(X[i] > (var * (j + 1)))
				sigma_cnt[j]++;
		}
	}

	for(int j = 0; j < 3; j++)
	{
		std::cout << ((double)sigma_cnt[j] * 100.)/N << "% of numbers greater than " << (j + 1) << "\u03C3" << std::endl;
	}

	free(X);
}
