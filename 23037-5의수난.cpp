#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
	string a;
	cin >> a;


	int result = 0;

	for (int i = 0; i<a.length(); i++)
	{
		int k = a[i] - 48;
		result += (k*k*k*k*k);
	}

	cout << result;
	return 0;
}
