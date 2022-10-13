#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> carnum;

	int denied = 0;
	int num = 0;

	cin >> denied;

	for (int i = 0; i < 5; i++)
	{
		int temp = 0;
		cin >> temp;

		carnum.push_back(temp);
	}


	for (int i = 0; i < 5; i++)
	{
		if (carnum[i] == denied)
		{
			num++;
		}
	}

	cout << num;
	return 0;

}
