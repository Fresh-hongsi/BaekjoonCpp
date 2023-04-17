#include <iostream>
#include <algorithm>
#include <vector>
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
	cout << arr[1] + arr[2];
	return 0;
}
