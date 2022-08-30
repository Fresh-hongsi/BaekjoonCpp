#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	vector<int> arr;
	int a = 0;
	int b = 0;
	int c = 0;

	cin >> a >> b >> c;

	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);

	sort(arr.begin(), arr.end());

	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}
