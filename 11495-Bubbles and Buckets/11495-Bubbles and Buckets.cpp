#include <iostream>
#include <vector>
#include <fstream>	
using namespace std;


long long ans = 0;

void merge(vector<int> &array, int front, int mid, int end)
{
	vector<int> left(array.begin() + front, array.begin() + mid + 1),
				right(array.begin() + mid + 1, array.begin() + end + 1);
				//vector的結尾是null 所以尾巴要+1

	left.push_back(100000); //結尾放入大數,使vector不為空
	right.push_back(100000);
	for (int i = front; i <= end; i++)
	{
		if (left[0] < right[0])
		{
			array[i] = left[0];
			left.erase(left.begin());
		}
		else if (left[0] > right[0])
		{
			array[i] = right[0];
			if (left[0] != 100000) { 
				ans = ans + (left.size() - 1); }
			right.erase(right.begin());
		}
	}

}

void mergesort(vector<int>& array, int front, int end)
{
	if (front < end)
	{
		int mid = (front + end) / 2;
		mergesort(array, front, mid);
		mergesort(array, mid + 1, end);
		merge(array, front, mid, end);
	}
}


int main()
{
	ifstream file;	
	file.open("in1.txt", ios::in);
	while (true)
	{
		int limit = 0, inputx = 0;
		ans = 0;
		file >> limit;
		if (limit == 0) break;
		vector<int> numbers;
		for (int i = 0; i < limit; i++)
		{
			file >> inputx;
			numbers.push_back(inputx);
		}
		mergesort(numbers, 0, limit - 1);
		if (ans % 2 == 0 )
		{
			cout << "Carlos " << ans << endl;
		}
		else
		{
			cout << "Marcelo " << ans << endl;
		}
	}
	file.close();
}


