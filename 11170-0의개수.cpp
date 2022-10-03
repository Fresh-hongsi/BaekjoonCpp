#include <iostream>
#include <string>
#include <algorithm>
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
		int a = 0;
		int b = 0;
		cin >> a >> b;

		int result = 0;


		for (int i = a; i <= b; i++)
		{
			string k = to_string(i);
			for (int j = 0; j < k.length(); j++)
			{
				if (k[j] - 48 == 0)
				{
					result++;
					
				}
			}
		}

		cout << result << '\n';
	}
	return 0;
}
