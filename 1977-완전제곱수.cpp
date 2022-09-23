#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M = 0;
	int N = 0;
	vector<int> arr;

	cin >> M >> N;
	int start = -1;
	for (int i = 0; i <= 100; i++)
	{
		if (i * i >= M && i*i<=N)
		{
			arr.push_back(i * i);
		}
	}

	if (arr.size() == 0)
	{
		cout << -1;
	}

	else
	{
		int sum = 0;
		start = arr[0];
		for (int i = 0; i < arr.size(); i++)
		{
			sum += arr[i];
		}

		cout << sum << '\n';
		cout << start << '\n';
	}

	return 0;
}
