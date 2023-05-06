#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	double x, y, z = 0;
	cin >> x >> y >> z;

	double t = x + y;

	if (t <= z + 0.5)
	{
		cout << "1";
	}

	else
	{
		cout << "0";
	}

	return 0;
}
