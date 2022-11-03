#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;
	cin >> tc;

	while (tc--)
	{
		int n = 0;
		cin >> n;

		int sit = 0;
		cin >> sit;
		int result = 0;
		vector<int> arr(sit + 1, 0);

		for (int i = 1; i <= n; i++)
		{
			int select = 0;
			cin >> select;

			if (arr[select] == 0)
			{
				arr[select] = 1;
			}

			else
			{
				result++;
			}
		}

		cout << result << '\n';
	}

	return 0;
}
