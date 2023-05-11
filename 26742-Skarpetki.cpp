#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	string s;

	cin >> s;
	int bCount = 0;
	int cCount = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'B')
		{
			bCount++;
		}

		else
		{
			cCount++;
		}
	}

	int result = (bCount / 2) + (cCount / 2);
	cout << result;
	return 0;
}
