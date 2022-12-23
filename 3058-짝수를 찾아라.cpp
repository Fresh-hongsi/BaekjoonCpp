#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	while (tc--)
	{
		vector<int>arr;
		int sum = 0;
		for (int i = 0; i < 7; i++)
		{
			int temp = 0;
			cin >> temp;
			if (temp % 2 == 0)
			{
				arr.push_back(temp);
				sum += temp;
			}
			else
				continue;
			
		}
		sort(arr.begin(), arr.end());
		cout << sum << ' ' << arr[0] << '\n';
		
	}
	return 0;
}
