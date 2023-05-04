#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b,c, r = 0;

	cin >> a >> b >> c;

	if (b >= c)
	{
		r = a - b + c;
	}

	else
	{
		r = a - c + b;
	}

	cout << r;

	return 0;
}
