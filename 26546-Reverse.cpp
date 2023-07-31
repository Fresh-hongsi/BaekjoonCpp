#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		int start = 0;
		int end = 0;

		cin >> start >> end;

		

		for (int i = 0; i < s.length(); i++)
		{
			if (i>=start && i<end)
			{
				continue;
			}
			else
			{
				cout << s[i];
			}
		}
		cout << '\n';
	}

	return 0;
}
