// C++ code
#include <iostream>
#include <vector>
#include <fstream>
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

void insertSort(int num, int* array)
{
	for (int i = 0; i < num; i++)
	{
		int l = i;
		for (int k = i - 1; k > -1; k--)
		{
			if (k < 0)
				break;
			else if (array[l] < array[k])
			{
				swap(array[l], array[k]);
				l = k;
			}
			else
				break;
		}
	}
}

int main()
{
	vector<int> array;
	int num;
	read(num, array);

	PrintArray(num, insertSort(array));
	return 0;
}