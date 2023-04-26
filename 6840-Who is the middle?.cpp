#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	
	vector<int> arr;

	for (int i = 0; i < 3; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());
	cout << arr[1];
	
	return 0;
}
