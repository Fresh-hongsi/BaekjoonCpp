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

	int l = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	cin >> l >> a >> b >> c >> d;

	int t1 = a / c;
	if (a % c != 0)
	{
		t1 = t1 + 1;

	}

	int t2 = b / d;
	if (b % d != 0)
	{
		t2 = t2 + 1;
	}

	int t3 = max(t1, t2);

	cout << l - t3;
	return 0;

}
