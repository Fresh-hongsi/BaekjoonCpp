#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int n = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ',')
		{
			n++;
		}
	}

	cout << n + 1;
	return 0;
}
