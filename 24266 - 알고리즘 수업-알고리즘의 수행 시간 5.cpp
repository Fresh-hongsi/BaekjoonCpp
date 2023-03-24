#include <iostream>
using namespace std;

int main(void)
{
	long long count = 0;
	long long n = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				count++;
			}
			
		}
	}

	cout << count << '\n';
	cout << 3;
	return 0;
}
