// C++ code
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int* read(int &num)
{
	ifstream infile;
	infile.open("data.txt", ios::in);

	if (!infile)
		cout << "ERROR";

	int tempt;
	infile >> num;

	int* ptr = new int[num];

	for (int i = 0; i<num; i++)
	{
		if (infile >> tempt)
			ptr[i] = tempt;
	}

	infile.close();

	return ptr;
}

void PrintArray(int num, int* array)
{
	ofstream outfile;
	outfile.open("output.txt", ios::out);

	if (!outfile)
		cout << "ERROR";

	outfile << num << endl;

	for (int i = 0; i <num; i++)
	{
		outfile << array[i] << endl;
	}
	outfile.close();
}

void swap(int &a, int &b)
{
	int  c = a;
	a = b;
	b = c;
}

void selectSort(int num, int* array)
{
	for (int i = 0; i < num; i++)
	{
		int l = i;
		for (int k = i+1; k < num; k++)
		{
			if (array [k] < array [l])
				l=k;
		}
		swap(array[i], array[l]);
	}
}

void generate(int num, int random)
{
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
}

int main()
{
	generate(200, 5);

	int num;
	int* ptr = read(num);

	selectSort(num,ptr );
	PrintArray(num, ptr);

	return 0;
}
