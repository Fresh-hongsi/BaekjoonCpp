#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> man;
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		int temp = 0;
		cin >> temp;
		man.push_back(temp);
		sum += temp;
	}

	bool flag = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			int a = man[i];
			int b = man[j];

			if (sum - a - b == 100)
			{
				man[i] = 0;
				man[j] = 0;
				flag = true;
				break;
			}
		}

		if (flag == true)
			break;
	}

	for (int i = 0; i < 9; i++)
	{
		if (man[i] == 0)
		{
			continue;
		}

		else
		{
			cout << man[i] << '\n';
		}
	}

	return 0;
}
