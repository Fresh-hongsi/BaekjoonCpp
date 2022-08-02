#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int a=0;
	int b=0;
	int c=0;
	int d=0;

	cin >> a >> b >> c >> d;

	int sum = (a + b + c + d);
	int min = sum / 60;
	int second = sum - (60 * min);
	cout << min << '\n' << second;
	return 0;
}
