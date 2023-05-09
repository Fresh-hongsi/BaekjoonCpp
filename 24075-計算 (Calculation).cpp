#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;

	int sum = a + b;
	int sub = a - b;

	if (sum < sub)
	{
		cout << sub << endl << sum;
	}

	else
	{
		cout << sum << endl << sub;
	}

	return 0;
}
