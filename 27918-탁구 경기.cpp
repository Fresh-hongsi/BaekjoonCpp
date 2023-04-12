#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		char temp = 0;
		cin >> temp;
		if (temp == 'D')
		{
			a++;
		}
		else
		{
			b++;
		}

		if (a == b + 2 || b == a + 2)
		{
			break;
		}
	}



	cout << a << ':' << b;
	return 0;
}
