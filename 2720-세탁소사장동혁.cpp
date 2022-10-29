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

	int t = 0;
	cin >> t;

	int q = 25;
	int d = 10;
	int n = 5;
	int p = 1;
	while (t--)
	{
		int total = 0;
		cin >> total;

		int a1 = 0;
		int a2 = 0;
		int a3 = 0;
		int a4 = 0;


		a1 = total / q;
		if (a1 > 0)
		{
			total = total - a1 * q;
		}

		a2 = total / d;
		if (a2 > 0)
		{
			total = total - a2 * d;
		}

		a3 = total / n;
		if (a3 > 0)
		{
			total = total - a3 * n;
		}

		a4 = total / p;
		if (a4 > 0)
		{
			total = total - a4 * p;
		}

		cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << '\n';

	}

	return 0;
}
