#include <iostream>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	int a, b, c = 0;

	cin >> a >> b >> c;

	int result = 0;

	if (n <= a)
	{
		result += n;
	}
	else
	{
		result += a;
	}

	if (n <= b)
	{
		result += n;
	}
	else
	{
		result += b;
	}

	if (n <= c)
	{
		result += n;
	}
	else
	{
		result += c;
	}

	cout << result;
	return 0;


}
