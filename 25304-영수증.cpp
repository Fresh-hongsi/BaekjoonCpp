#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	long long rFee = 0;
	
	long long n = 0;
	cin >> rFee >> n;

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		long long a = 0;
		long long b = 0;

		cin >> a >> b;

		long long c = a * b;
		sum += c;
	}

	if (sum == rFee)
	{
		cout << "Yes";
	}

	else
	{
		cout << "No";
	}

	return 0;
}
