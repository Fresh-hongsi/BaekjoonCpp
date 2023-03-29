#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	int k = 0;

	cin >> n >> k;

	vector<int>arr;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) {
			arr.push_back(i);

		}
	}
	
	if (arr.size() >= k)
	{
		cout << arr[k - 1];
	}
	else
	{
		cout << 0;
	}
	return 0;
}
