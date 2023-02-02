#include <iostream>
using namespace std;

int main(void)
{
	int a = 0;
	cin >> a;

	int r1 = a - (a * 0.22);
	int r2 = a - (a * 0.2 * 0.22);

	cout << r1 << ' ' << r2;
	return 0;
}
