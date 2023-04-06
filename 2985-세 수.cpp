#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a = 0;
	int b = 0;
	int c = 0;

	cin >> a >> b >> c;

	if (a + b == c)
	{
		cout << a << '+' << b << '=' << c;
	}

	else if (a - b == c)
	{
		cout << a << '-' << b << '=' << c;
	}

	else if (a * b == c)
	{
		cout << a << '*' << b << '=' << c;
	}

	else if (a / b == c)
	{
		cout << a << '/' << b << '=' << c;
	}

	else if (a == b + c)
	{
		cout << a << '=' << b << '+' << c;
	}

	else if (a == b - c)
	{
		cout << a << '=' << b << '-' << c;
	}

	else if (a == b * c)
	{
		cout << a << '=' << b << '*' << c;
	}

	else if (a == b / c)
	{
		cout << a << '=' << b << '/' << c;
	}




	return 0;
}
