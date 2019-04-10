// C++ code
#include <iostream>
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

	for(int i=0;i<num;i++)
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

void quickSort(int front,int end,int* array)
{
	if (front < end)
	{
		int i = front - 1, j = front;

		for (int k = front; k < end; k++)
		{
			if (array[k] < array[end])
			{
				i++;
				swap(array[i], array[k]);
			}
			j++;
		}
		i++;
		swap(array[i], array[end]);

		quickSort(front, i-1, array);
		quickSort(i + 1, end, array);
	}

}

int main()
{
	int num;
	int *data=read(num);
	quickSort(0,num-1,data);
	PrintArray(num, data);

	return 0;
}