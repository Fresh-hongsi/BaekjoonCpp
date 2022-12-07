#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int k = 0;
	cin >> k;
	int p = k - 1;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < p; j++)
		{
			cout << ' ';
		}
		p--;

		for (int q = 0; q < 2 * i + 1; q++)
		{
			cout << '*';
		}

		cout << '\n';

	}
	p = p + 2;
	k = k - 2;
	for (int i = k; i >= 0; i--)
	{
		for (int j = 0; j < p; j++)
		{
			cout << ' ';
		}
		p++;

		for (int q = 0; q < 2 * i + 1; q++)
		{
			cout << '*';
		}

		cout << '\n';

	}
	return 0;
}
