#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

bool comp(pair<int, string>a, pair<int, string>b)
{
	if (a.first>b.first)
	{
		return true;
	}

	else
	{
		return false;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;
	cin >> tc;
	while (tc--)
	{

		vector<pair<int, string>> c;
		int n = 0;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int alchol;
			string univ;

			cin >> univ >> alchol;
			c.push_back(pair<int,string>(alchol, univ));
		}

		sort(c.begin(), c.end(),comp);

		cout << c[0].second << '\n';
	}

	return 0;
}
