// C++ code
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int main()
{
	int num = 10000, random = 800;
	int* array = new int[num];
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		array[i] = i + 1;
		if (rand() % random == 0 && i != 0)
			swap(array[i], array[(rand() % i)]);
	}

	ofstream outfile;
	outfile.open("data.txt", ios::out);

	if (!outfile)
		cout << "ERROR";

	outfile << num << endl;

	for (int i = 0; i < num; i++)
	{
		outfile << array[i] << endl;
	}
	outfile.close();
	return 0;
}