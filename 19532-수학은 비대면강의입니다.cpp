#include <iostream>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b, c, d, e, f;
	bool flag = false;
	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; x++)
	{
		for (int y = -999; y <= 999; y++)
		{
			if ((a * x + b * y == c) && (d * x + e * y == f))
			{
				cout << x << ' ' << y;
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			break;
		}
	}

	return 0;
}
