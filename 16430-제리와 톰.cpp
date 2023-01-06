#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int a = 0;
	int b = 0;

	cin >> a >> b;

	int c = b - a;

	for (int i = 1; i <= c; i++)
	{
		if (i % c == 0 && i % b == 0)
		{
			c = c / i;
			b = b / i;
		}
	}

	cout << c <<' '<< b;
	return 0;


}

