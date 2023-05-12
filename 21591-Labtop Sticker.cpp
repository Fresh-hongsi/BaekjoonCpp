#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int a, b, c, d = 0;
	cin >> a >> b >> c >> d;

	if (c <= a - 2 && d <= b - 2)
	{
		cout << '1';
	}

	else
	{
		cout << '0';
	}

	return 0;
}
