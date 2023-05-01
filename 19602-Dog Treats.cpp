#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int s, m, l;

	cin >> s >> m >> l;

	int emotion = 1 * s + 2 * m + 3 * l;

	if (emotion >= 10)
	{
		cout << "happy";

	}

	else
	{
		cout << "sad";
	}

	return 0;
}
