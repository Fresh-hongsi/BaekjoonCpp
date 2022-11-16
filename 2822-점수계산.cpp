#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare1(pair<int, int>a, pair<int, int>b)
{
	return a.first >= b.first;
}

int main(void)
{
	vector<pair<int, int>> arr;

	for (int i = 1; i <= 8; i++)
	{
		int temp = 0;
		cin >> temp;

		arr.push_back(pair<int,int>(temp, i));
	}

	sort(arr.begin(), arr.end(), compare1);

	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += arr[i].first;
	}

	cout << sum << '\n';
	vector<int>arr2;
	for (int i = 0; i < 5; i++)
	{
		arr2.push_back(arr[i].second);
	}

	sort(arr2.begin(), arr2.end());
	for (int i = 0; i < 5; i++)
	{
		cout<<arr2[i] << ' ';
	}
	return 0;
}
	
