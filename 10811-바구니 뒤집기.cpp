#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> arr;

	int n = 0;
	int m = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		arr.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int s = 0;
		int e = 0;

		cin >> s >> e;

		reverse(arr.begin() + s-1, arr.begin() + e);
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}
