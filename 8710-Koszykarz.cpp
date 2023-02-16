#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int k = 0;
	int w = 0;
	int m = 0;

	cin >> k >> w >> m;

	int result = (w - k) / m;

	if ((w - k) % m != 0)
	{
		result++;
	}

	cout << result;
	return 0;
}
