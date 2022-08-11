//Implementation

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{
	int n = 0;
	cin >> n;

	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}

	int v = 0;
	int count = 0;
	cin >> v;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == v)
		{
			count++;
		}
	}

	cout << count;
	return 0;
}
