#include <iostream>
using namespace std;


int main(void)
{
	int n = 0;
	int counter = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		if (i != n)
		{
			for (int j = n - i; j > 0; j--)
			{
				cout << ' ';
			}


			cout << '*';
			if (i == 1)
			{
				cout << endl;
				continue;
			}


			for (int j = (i - 1) * 2 - 1; j > 0; j--)
			{
				cout << ' ';
			}

			if (i != 1)
			{
				cout << '*';
			}
		}
		
		
		
		if (i == n)
		{
			for (int j = 0; j < 2 * n-1; j++)
			{
				cout << '*';
			}
		}

		cout << endl;
	}
}
