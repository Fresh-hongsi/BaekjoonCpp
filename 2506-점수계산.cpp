#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	vector<int> arr;

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	int score = arr[0];
	int cur = 1;

	for (int i = 1; i < N; i++)
	{
		if (arr[i - 1] == 1 && arr[i]==1)
		{
			cur++;
			score += cur;
		}

		else if (arr[i - 1] == 0 && arr[i] == 1)
		{
			cur = 1;
			score += 1;
		}

		else
		{
			continue;
		}
	}

	cout << score << endl;
	return 0;
}
