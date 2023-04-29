#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define PI 3.141592
//area = pi * r * r;
//length= 2*pi*r
int main(void)
{
	double area;
	cin >> area;

	double result = 0;
	result = sqrt(area / PI)*2*PI;
	cout << fixed;
	cout.precision(10);
	cout << result;
	return 0;
}
