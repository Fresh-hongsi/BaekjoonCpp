#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	double a = 0;
	double b = 0;
	cin >> a >> b;
	double r = 0;
	double pi = 3.141592;

	r = 2 * a + (pi * 2 * b);

	cout << fixed;
	cout.precision(6);
	cout << r;
}
