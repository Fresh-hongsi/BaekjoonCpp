#include <iostream>
using namespace std;

int main(void)
{
	while (1)
	{
		int c = 0;
		cin >> c;
		if (c == 0)
		{
			break;
		}
		else
		{
			int result = 0;
			for (int i = 1; i <= c; i++)
			{
				result += i;
			}

			cout << result << endl;
		}
	}

	return 0;
}
