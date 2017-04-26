#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	float in;

	if(argc == 1)
	{
		cout << "enter x: ";
		cin >> in;

		cout << setprecision(8) << "exp(" << in << ") = " << exp(in) << endl;
	}
	else if(argc == 2)
	{
		in = atof(argv[1]);
		cout << setprecision(8) << exp(in) << endl;
	}
	else
	{
		cout << "dickhead";
	}
}
