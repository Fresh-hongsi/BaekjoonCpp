	#include <iostream>
	#include <algorithm>
	#include <vector>
	using namespace std;

	int main(void)
	{
		int a, b, c, d = 0;

		cin >> a >> b >> c >> d;

		int m = a * b;
		int p = c * d;

		if (m > p)
		{
			cout << 'M';
		}

		else if (m < p)
		{
			cout << 'P';
		}

		else
		{
			cout << 'E';
		}

		return 0;
	}
