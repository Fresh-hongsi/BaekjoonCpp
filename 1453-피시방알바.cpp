#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	int counter = 0;
	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);

	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == arr[i - 1])
		{
			counter++;
		}
	}

	cout << counter;
	return 0;
}
