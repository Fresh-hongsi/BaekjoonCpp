#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		cout << s[0];
		for (int j = 1; j < s.length(); j++)
		{
			if (s[j - 1] == s[j])
			{
				continue;
			}
			else
			{
				cout << s[j];
			}
		}
		cout << '\n';

	}

	return 0;
}
