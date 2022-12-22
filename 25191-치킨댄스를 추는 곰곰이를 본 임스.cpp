#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int chi = 0;
	int coke = 0;
	int beer = 0;

	cin >> chi >> coke >> beer;

	int c1 = coke / 2;
	int b1 = beer;

	int r1 = c1 + b1;
	if (chi < r1)
	{
		cout << chi;
	}

	else
	{
		cout << r1;
	}

	return 0;
}
