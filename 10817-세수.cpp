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

	int a = 0;
	int b = 0;
	int c = 0;

	cin >> a >> b >> c;

	vector<int> arr;

	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);

	sort(arr.begin(), arr.end());

	cout << arr[1];
	return 0;
}
