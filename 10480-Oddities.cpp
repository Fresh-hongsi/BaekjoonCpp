#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		int temp1 = 0;

		cin >> temp;

		if (temp < 0)
		{
			temp1 = -temp;
			if (temp1 % 2 == 0)
			{
				cout << temp << " is even" << endl;
			}

			else
			{
				cout << temp << " is odd" << endl;

			}
		}

		if (temp == 0)
		{
			cout << temp << " is even" << endl;
		}

		if(temp>0)
		{
			if (temp % 2 == 0)
			{
				cout << temp << " is even" << endl;
			}

			else
			{
				cout << temp << " is odd" << endl;

			}
		}
	}

	return 0;
}
