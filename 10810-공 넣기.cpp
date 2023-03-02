#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	int arr[100] = { 0, };

	int n = 0;
	int m = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int s = 0;
		int e = 0;
		int k = 0;
		cin >> s >> e >> k;

		for (int j = s - 1; j <= e - 1; j++)
		{
			arr[j] = k;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}
