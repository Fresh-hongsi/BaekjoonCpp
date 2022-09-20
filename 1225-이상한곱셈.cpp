//Math
//Implementation
//String

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	string a = "";
	string b = "";

	cin >> a >> b;

	long long sum = 0;

	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < b.length(); j++)
		{
			long long temp1 = a[i] - 48;
			long long temp2 = b[j] - 48;
			sum += (temp1 * temp2);
		}

		
	}

	cout << sum;
	return 0;
}
