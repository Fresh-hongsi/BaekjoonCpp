#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a = 0;
	int b = 0;

	int ch = 0;

	cin >> a >> b >> ch;

	int total = a + b;

	if (2 * ch <= total)
	{
		cout << total - 2 * ch;
	}

	else
	{
		cout << total;
	}

	return 0;
}
