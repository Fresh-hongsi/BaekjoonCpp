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

	int num = 5;
	int sum = 0;
	vector<int> arr;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int temp = 0;
			cin >> temp;
			sum += temp;
		}
		arr.push_back(sum);
		sum = 0;

	}

	int max1 = arr[0];
	int idx = 0;
	

	for (int i = 1; i < 5; i++)
	{
		if (max1 < arr[i])
		{
			max1 = arr[i];
			idx = i;
		}
	}

	cout << idx+1 << ' ' << max1;
	return 0;







}
