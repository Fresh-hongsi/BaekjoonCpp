#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int fruitNum = 0;
	int initial_length = 0;

	cin >> fruitNum >> initial_length;

	vector<int> fruitArr;

	for (int i = 0; i < fruitNum; i++)
	{
		int temp = 0;
		cin >> temp;

		fruitArr.push_back(temp);
	}

	sort(fruitArr.begin(), fruitArr.end());

	for (int i = 0; i < fruitNum; i++)
	{
		if (fruitArr[i] <= initial_length)
		{
			initial_length++;
		}

		else
		{
			break;
		}
	}

	cout << initial_length;
	return 0;
}
