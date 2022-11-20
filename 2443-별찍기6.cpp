#include <iostream>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	int j = 1;
	int t = 1;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= 2 * n - j; i++)
		{
			cout << '*';
		}
		j += 2;
		cout << '\n';
		for (int l = 0; l < t; l++)
		{
			cout << ' ';
		}
		t += 1;

	}
	
	return 0;
}
