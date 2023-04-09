#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
	int a = 0;
	int b = 0;
	cin >> a >> b;

	double m = (double)(b - a) / 400;
	
	double result = 1 / (1 + pow(10, m));
	cout.fixed;
	cout.precision(10);
	cout<<result;
	return 0;
}
