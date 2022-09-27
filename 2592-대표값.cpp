#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	map<int,int> arr;
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		int temp = 0;
		cin >> temp;

		sum += temp;
		arr[temp]++;
	}

	int mean = sum / 10;
	
	int maximumCount = 0;
	int maximum = 0;
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		if (maximumCount < it->second)
		{
			maximumCount = it->second;
			maximum = it->first;
		}
	}

	cout << mean << '\n';
	cout << maximum;
	return 0;


}
