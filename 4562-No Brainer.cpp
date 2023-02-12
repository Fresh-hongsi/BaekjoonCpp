#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;

		if (a < b)
		{
			cout << "NO BRAINS" << endl;
		}

		else
		{
			cout << "MMM BRAINS" << endl;
		}
	}

	return 0;
}
