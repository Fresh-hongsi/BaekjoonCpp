//Implementation

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int code = 0;
	cin >> code;

	if (code == 0)
	{
		cout << "YONSEI";
	}

	if (code == 1)
	{
		cout << "Leading the Way to the Future";
	}

	return 0;
}
