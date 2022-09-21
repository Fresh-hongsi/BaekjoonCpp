#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr;

	for (int i = 0; i < 7; i++)
	{
		int temp = 0;
		cin >> temp;
		if (temp % 2 == 1)
		{
			arr.push_back(temp);
		}

	
	}

	sort(arr.begin(), arr.end());
	
	int sum = 0;

	if (arr.size() == 0)
	{
		cout << -1 << '\n';

	}

	else
	{
		for (int i = 0; i < arr.size(); i++)
		{
			sum += arr[i];


		}

		cout << sum << '\n';
		cout << arr[0];
	}

	return 0;
	

}
