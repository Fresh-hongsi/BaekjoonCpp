#include <iostream>
using namespace std;

int main(void)
{
	int a = 0;
	cin >> a;

	int counter = 0;
	for (int i = 1; i <= a; i++)
	{
		cout << i << ' ';
		if (i % 6 == 0)
		{
			cout << "Go! ";
		}

	}

	if (a % 6 != 0)
	{
		cout << "Go! ";
	}
	
}
