#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(void)
{
	string s;
	cin >> s;

	int r = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
		{
			r++;
		}

		
	}
	

	if (s[s.length() - 1] == '0')
	{
		for (int j = s.length() - 1; j>=0; j --)
		{
			if (s[j] == '0')
			{
				r--;
			}

			if (s[j] != '0')
			{
				break;
			}

		}
	}

	cout << r;
}
