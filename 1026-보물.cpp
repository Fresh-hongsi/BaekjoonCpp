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

	vector<int> arr1;
	vector<int> arr2;

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr1.push_back(temp);
	}

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr2.push_back(temp);
	}

	sort(arr1.begin(), arr1.end(), greater<int>());

	sort(arr2.begin(), arr2.end());

	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += (arr1[i] * arr2[i]);
	}

	cout << result;
	return 0;
}
