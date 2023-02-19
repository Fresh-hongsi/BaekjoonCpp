#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		result += temp;

		if (i == n - 1)
		{
			break;
		}

		else
		{
			result -= 1;
		}
	}

	cout << result;
}
