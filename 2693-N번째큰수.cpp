//sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int temp = 0;
			cin >> temp;
			arr.push_back(temp);
		}

		sort(arr.begin(), arr.end());
		cout << arr[arr.size() - 3] << '\n';
		arr.erase(arr.begin(), arr.end());
	}

	return 0;
}
