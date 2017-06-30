#include <iostream>
#include <string.h>
#include <ctime>
#include <cmath>

template<size_t N>
int check(int board[N][N])
{
	//check straight
	for(int i = 0; i < N; i++)
	{
		int nrow = 0, ncol = 0;

		for(int j = 0; j < N; j++)
		{
			nrow += board[i][j];
			ncol += board[j][i];
		}

		if(nrow > 1 || ncol > 1)
			return 0;
	}

	//check diagonals
	for(int i = 0; i < (2*N - 1); i++)
	{
		int ndiagr = 0, ndiagl = 0;

		for(int j = 0; j < N; j++)	//diagonal number
		{
			if((i - j) >= 0 && (i - j) < N)	//most diagonals don't have N entries
			{
				ndiagr += board[j][i - j];
				ndiagl += board[N - j - 1][i - j];
			}
		}

		if(ndiagl > 1 || ndiagr > 1)
			return 0;
	}

	return 1;
}

//returns 1 if it was able to place a queen in row y
//else returns 0 and leaves board untouched
template<size_t N>
int place(int board[N][N], int y)
{
	if(y >= N)
		return 1;

	for(int x = 0; x < N; x++)
	{
		board[y][x] = 1;

		if(check(board) && place(board, y + 1))
			return 1;
		else
			board[y][x] = 0;
	}
	return 0;
}

//print out board to screen
template<size_t N>
void print(int board[N][N])
{
	std::cout << "size: " << N << "x" << N << std::endl;

	for(int i = 0; i < N; i++)
		std::cout << "----";
	std::cout << "-" << std::endl;

	for(int y = 0; y < N; y++)
	{
		for(int i = 0; i < 2; i++)
		{
			std::cout << "|";
			for(int x = 0; x < N; x++)
			{
				if(board[y][x])
					std::cout << "XXX|";
				else
					std::cout << "   |";
			}
			std::cout << std::endl;
		}

		for(int i = 0; i < N; i++)
			std::cout << "----";
		std::cout << "-" << std::endl;
	}
}

//place nqueen queens randomly on NxN board and show board + output of check function
template<size_t N>
void test(int nqueen)
{
	int board[N][N] = {0};

	for(int i = 0; i < nqueen; i++)
	{
		board[rand()%N][rand()%N] = 1;
	}

	print<N>(board);
	std::cout << "^passes: " << check(board) << std::endl;
}

//runs ntest tests (no kidding)
template<size_t N>
void run_tests(int ntests, int nqueen)
{
	srand((unsigned int)time(0));

	for(int i = 0; i < ntests; i++)
		test<N>(nqueen);
}

int main()
{
	//run_tests<8>(1 3);
	//return 0;

	const int N = 8;

	int board[N][N] = {0};

	int success = place(board, 0);

	if(success)
	{
		std::cout << "successfully placed queens, ";
		print(board);
	}
	else
		std::cout << "was not able to place queens" << std::endl;

	return 0;
}
