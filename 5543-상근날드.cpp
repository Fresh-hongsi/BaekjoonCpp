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

	vector<int> hamburger;
	vector<int> beverage;

	for (int i = 0; i < 3; i++)
	{
		int temp = 0;
		cin >> temp;
		hamburger.push_back(temp);
	}

	for (int i = 0; i < 2; i++)
	{
		int temp = 0;
		cin >> temp;
		beverage.push_back(temp);
	}

	sort(hamburger.begin(), hamburger.end());
	sort(beverage.begin(), beverage.end());

	int result = hamburger[0] + beverage[0] - 50;
	cout << result;

	return 0;
}
