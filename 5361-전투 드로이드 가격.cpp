#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	while (n--)
	{
		int a, b, c, d, e = 0;
		cin >> a >> b >> c >> d >> e;

		double a1 = 350.34;
		double b1 = 230.90;
		double c1 = 190.55;
		double d1 = 125.30;
		double e1 = 180.90;

		double result = 0;

		result = (a * a1) + (b * b1) + (c * c1) + (d * d1) + (e * e1);

		cout << fixed;
		cout.precision(2);
		cout << '$' << result << '\n';
	}

	return 0;
	
}
