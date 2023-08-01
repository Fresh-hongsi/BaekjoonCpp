#include <iostream>
using namespace std;

int  main(void)
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;

		cout << temp << ' ' << temp << '\n';
	}

	return 0;
}
