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

void quickSort(int front, int end, int* array)
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

		quickSort(front, i - 1, array);
		quickSort(i + 1, end, array);
	}

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

void hybrid(int front, int end, int* array,int kkk)
{
	if (front < end)
	{
		if (end - front < kkk)
		{
			for (int i = front; i < end + 1; i++)
			{
				int l = i;
				for (int k = i - 1; k > -1; k--)
				{
					if (k < front)
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
		else
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

			hybrid(front, i - 1, array,kkk);
			hybrid(i + 1, end, array,kkk);
		}

	}
}


void generate(int num,int random)
{
	int* array=new int[num];
	srand(time(NULL));
	for (int i = 0; i < num; i++)
	{
		array[i]=i+1;
		if (rand() % random == 0 && i!=0)
			swap(array[i],array[(rand() % i)]);
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
	generate(10000, 800);

	int num;
	int *data = read(num);
	int *ptr = read(num);
	int *pointer = read(num);

	double ts, te, quick, insert, hyb;

	ts = clock();
	quickSort(0, num - 1, pointer); 
	te = clock();
	quick = te-ts;

	ts = clock();
	insertSort(num, ptr);
	te = clock();
	insert = te - ts;

	ts = clock();
	hybrid(0, num - 1, data, 10);
	te = clock();
	hyb = te - ts;
	

	PrintArray(num,data);
	cout <<"quick sort: "<< quick<<" ms\n";
	cout << "insertion sort: " << insert << " ms\n";
	cout << "hybrid quick sort: " << hyb << " ms\n";

	return 0;
}
