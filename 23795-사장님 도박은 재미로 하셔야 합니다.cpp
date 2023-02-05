#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int total = 0;

	while (true)
	{
		int temp = 0;
		cin >> temp;

		if (temp == -1)
		{
			break;
		}

		else
		{
			total += temp;
		}
	}

	cout << total;
	return 0;
}
