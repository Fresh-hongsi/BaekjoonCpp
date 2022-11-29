#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> arr;

	for (int i = 0; i < 4; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
	}
	int total = 0;
	
	total = arr[0] * 56 + arr[1] * 24 + arr[2] * 14 + arr[3] * 6;
	cout << total;
	return 0;
}
