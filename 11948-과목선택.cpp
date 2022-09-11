#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<int> science;
	vector<int> society;

	for (int i = 0; i < 4; i++)
	{
		int temp = 0;
		cin >> temp;
		science.push_back(temp);
	}

	for (int i = 0; i < 2; i++)
	{
		int temp = 0;
		cin >> temp;
		society.push_back(temp);

	}

	sort(science.begin(), science.end());
	sort(society.begin(), society.end());

	int total = science[1] + science[2] + science[3];
	total = total + society[1];

	cout << total;
	return 0;
}
