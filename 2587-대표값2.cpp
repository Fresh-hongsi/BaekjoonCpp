#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num = 5;
	vector<int> arr;
	int center = 0;
	int sum = 0;

	for (int i = 0; i < num; i++)
	{
		int temp = 0;
		cin >> temp;
		arr.push_back(temp);
		sum += temp;
	}

	cout << sum / 5 << endl;

	sort(arr.begin(), arr.end());
	cout << arr[2];
	return 0;
}
