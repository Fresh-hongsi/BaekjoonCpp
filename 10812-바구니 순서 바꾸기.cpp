#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr;

	int n = 0;
	int m = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		arr.push_back(i);
	}

	for (int l = 0; l < m; l++)
	{
		int i = 0;
		int j = 0;
		int k = 0;

		cin >> i >> j >> k;
		vector<int> arr1;
		vector<int> arr2;
		vector<int> arr3;
		vector<int> arr4;

		for (int t = 0; t < i-1; t++)
		{
			arr1.push_back(arr[t]);
		}

		for (int t = i - 1; t < k - 1; t++)
		{
			arr2.push_back(arr[t]);
		}

		for (int t = k-1 ; t <= j - 1; t++)
		{
			arr3.push_back(arr[t]);
		}

		for (int t = j ; t < n; t++)
		{
			arr4.push_back(arr[t]);
		}


		arr.clear();
		for (int t = 0; t < i - 1; t++)
		{
			arr.push_back(arr1[t]);
		}
		for (int t = 0; t < arr3.size(); t++)
		{
			arr.push_back(arr3[t]);
		}
		for (int t = 0; t < arr2.size(); t++)
		{
			arr.push_back(arr2[t]);
		}
		for (int t = 0; t < arr4.size(); t++)
		{
			arr.push_back(arr4[t]);
		}

		
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';

	}
	cout << '\n';

	return 0;
}
