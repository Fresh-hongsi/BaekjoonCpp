#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int a, b = 0;

	cin >> a >> b;


	int r = a + b;
	
	while (1)
	{
		if (r > 12)
		{
			r -= 12;
		}

		else
		{
			break;
		}
	}
	cout << r;
	return 0;
}
