#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void read(int &num, vector<int> &array)
{
	ifstream infile;
	infile.open("data.txt", ios::in);

	if (!infile)
		cout << "ERROR";

	int tempt;
	infile >> num;

	while (!infile.eof())
	{
		if (infile >> tempt)
			array.push_back(tempt);
	}

	infile.close();
}

void PrintArray(int num, vector<int> &array)
{
	ofstream outfile;
	outfile.open("output.txt", ios::out);

	if (!outfile)
		cout << "ERROR";

	outfile << num << endl;

	for (int i = 0; i < array.size(); i++)
	{
		outfile << array[i] << endl;
	}
	outfile.close();
}

void combine(vector<int> &array, int front, int mid,int end)
{
	int n1 = mid - front + 1;
	int n2 = end - mid;

	vector<int> L,R;

	for (int i = 0; i < n1; i++) 
	{
		L.push_back(array[front + i]);
	}
	for (int i = 0; i < n2; i++)
	{
		R.push_back(array[mid+1 + i]);
	}


	int i = 0, j = 0;
	L.push_back(999999999);
	R.push_back(999999999);

	for (int k = front; k < end+1; k++) 
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
	}
}

void divide( vector<int> &array, int front, int end)
{
	if (end - front > 0)
	{
		int mid = (front + end) / 2;
		divide(array, front, mid);
		divide( array, mid+1 , end);
		combine(array, front,mid, end);
	}
}

vector<int> mergeSort(vector<int> &array)
{
	divide(array, 0, array.size() - 1);
	return array;
}

int main() 
{
	vector<int> array;
	int num;
	read(num,array);

	PrintArray(num,mergeSort(array));
	return 0;
}