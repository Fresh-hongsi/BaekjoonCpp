#include <iostream>
using namespace std;

int main(void)
{
	int t = 0;
	cin >> t;

	int sum = 0;
	for (int i = 0; i < t; i++)
	{
		int temp = 0;
		cin >> temp;
		sum += temp;
	}

	cout << sum;
	return 0;
}
