#include "average.h"

#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
	double data[] = { 1, 2, 3, 5 };
	const int DataSize = sizeof(data) / sizeof(data[0]);

	cout << "Input data:";
	for (int i = 0; i < DataSize; i++)
	{
		cout << " " << data[i];
	}

	cout
		<< "\n"
		<< "Output (average): "
		<< average(data, DataSize)
		<< "\n"
		;

	return 0;
}


