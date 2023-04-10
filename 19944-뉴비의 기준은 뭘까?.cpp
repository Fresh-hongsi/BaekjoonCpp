#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n = 0;
	int m = 0;

	cin >> n >> m;

	if (m <= 2)
	{
		cout << "NEWBIE!";
	}

	else if (m > 2 && m <= n)
	{
		cout << "OLDBIE!";
	}

	else
	{
		cout << "TLE!";
	}
	return 0;
}
