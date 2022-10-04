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

	int N = 0;
	vector<int> arr;


	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	int first = arr[0];
	cout << first<<' ';

	for (int i = 1; i < N; i++)
	{
		if (arr[i] == arr[i - 1])
			continue;

		else
		{
			cout << arr[i] << ' ';
		}
	}

	return 0;

}
