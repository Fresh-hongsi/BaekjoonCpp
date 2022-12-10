#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int>arr;

	string temp = "9780921418";

	for (int i = 0; i < 10; i++)
	{
		int k = temp[i] - 48;
		arr.push_back(k);
	}

	int a, b, c;
	cin >> a >> b >> c;

	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	int sum = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		if (i % 2 == 0)
		{
			sum += (arr[i] * 1);
		}
		else
		{
			sum += (arr[i] * 3);
		}
	}

	cout << "The 1-3-sum is " << sum;
	return 0;
}
