//math

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int>arr;

	for (int i = 0; i < 3; i++)
	{
		int temp = 0;
		cin >> temp;

		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	int sub1 = arr[1] - arr[0];
	int sub2 = arr[2] -arr[1];

	if (sub1 == sub2)
	{
		cout << arr[2] + sub2;
	}

	else
	{
		if (sub1 < sub2)
		{
			cout << arr[1] + sub1;
		}

		else
		{
			cout << arr[0] + sub2;
		}
	}

	
}
