#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;
	

	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += (i * i*i);
	}

	cout << sum;
	return 0;
}
