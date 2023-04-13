#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{

	int a = 0;
	int b = 0;

	cin >> a >> b;

	int a1 = a / 2;
	int b1 = b / 2;

	int result = min(a1, b1);
	cout << result;
	return 0;
}
