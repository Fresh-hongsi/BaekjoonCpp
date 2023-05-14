#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	for (int p = 0; p < n; p++)
	{
		int a, b, c = 0;
		cin >> a >> b >> c;

		int count = 0;

		for (int i = 1; i <= a; i++)
		{
			for (int j = 1; j <= b; j++)
			{
				for (int k = 1; k <= c; k++)
				{
					if ((i % j == j % k) && (j%k==k%i) && (i%j==k % i))
					{
						count++;
					}
				}
			}
		}

		cout << count << '\n';
		count = 0;
	}
	
	
}
