#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		int temp = 0;
		cin >> temp;

		if (temp < 40)
		{
			temp = 40;
		}
		sum += temp;
	}

	cout << sum / 5;
	return 0;
}
