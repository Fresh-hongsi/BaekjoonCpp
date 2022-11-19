#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long int getgcd(long long int i1, long long int i2)
{
	long long int gcd1 = 1;

	long long limit = min(i1, i2);

	for (long long int i = 1; i <= limit; i++)
	{
		if ((i1 % i== 0) && (i2 % i == 0))
		{
			gcd1 = i;
		}
	}

	return gcd1;
}
int main(void)
{
	long long int a=0;
	long long int b=0;

	cin >> a >> b;

	long long int lcm = 0;
	long long int gcd = getgcd(a, b);
	lcm = gcd * (a / gcd) * (b / gcd);
	cout << lcm;
	return 0;
}
