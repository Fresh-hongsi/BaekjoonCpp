#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<string> arr;

	string result;

	for (int i = 0; i < 5; i++)
	{
		string temp;
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[j].length()-1<i)
			{
				continue;
			}

			else
			{
				result.push_back(arr[j][i]);
			}
		}
	}

	cout << result;
	return 0;
}
