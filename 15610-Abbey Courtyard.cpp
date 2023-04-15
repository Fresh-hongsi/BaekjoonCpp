#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	double a = 0;
	cin >> a;

	double result = sqrt(a);
	result *= 4;


	cout << fixed;
	cout.precision(10);
	cout << result;
	return 0;
}
