#include <iostream>
using namespace std;

int main(void)
{
	int n = 28;

	int a, b;

	cin >> a >> b;

	int total = a * 8 + b * 3;

	int result = total - n;

	if (result <= 0)
	{
		cout << '0';
	}

	else
	{
		cout << result;
	}

	return 0;
}
