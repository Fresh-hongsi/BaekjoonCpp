#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int a, b = 0;

	cin >> a >> b ;

	if (a + 7 * b > 30)
	{
		cout << '0';
	}

	else
	{
		cout << '1';
	}

	return 0;
}
