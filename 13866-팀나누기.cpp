//implementation
//math

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> arr;

	for (int i = 0; i < 4; i++)
	{
		int skillStat = 0;
		cin >> skillStat;

		arr.push_back(skillStat);
	}

	sort(arr.begin(), arr.end());

	int minimum = arr[0] + arr[3] - arr[1] - arr[2];
	minimum = abs(minimum);
	cout << minimum;
	return 0;
}
