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


	int T = 0;
	cin >> T;

	while (T--)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;


		int gcd = 1;
		int lcm = 1;

		int max_num = a < b ? b : a;

		for (int i = 1; i <= max_num; i++)
		{
			if (a % i == 0 && b % i == 0)
			{
				gcd = i;
				
			}

		}

		for (int i = max_num; i <= a * b; i++)
		{
			if (i % a == 0 && i % b == 0)
			{
				lcm = i;
				break;
			}
		}

		
		cout << lcm << ' ' << gcd<<'\n';

	}

	return 0;
}
