#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	int cute=0;
	int notcute=0;
	while (n--)
	{
		int temp = 0;
		cin >> temp;
		if (temp == 1)
		{
			cute++;
		}
		else
		{
			notcute++;
		}
	}

	if (cute > notcute)
	{
		cout << "Junhee is cute!";
	}
	else
	{
		cout << "Junhee is not cute!";
	}

	return 0;
}
