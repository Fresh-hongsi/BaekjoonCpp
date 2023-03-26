#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int a1 = 0;
	int a0 = 0;
	int c = 0;
	int n0 = 0;

	cin >> a1 >> a0 >> c >> n0;

	if (a1 * n0 + a0 <= c * n0) //초항을 대입했을 때 범위 안에 들어가야함
	{

		if (a1 <= c) //기울기가 같거나 작아야함
		{
			cout << 1;
		}

		else
		{
			cout << 0;
		}
		
	}

	else
	{
		cout << 0;
	}
	return 0;
}
