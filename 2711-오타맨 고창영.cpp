#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int tc = 0;
	cin >> tc;

	while (tc--)
	{
		int idx = 0;
		string st;

		cin >> idx >> st;

		string front;
		string behind;
		string total;
		for (int i = 0; i < idx - 1; i++)
		{
			front.push_back(st[i]);
		}

		for (int i = idx; i < st.length(); i++)
		{
			behind.push_back(st[i]);
		}

		total = front + behind;

		cout << total << '\n';

	}

	return 0;
}
